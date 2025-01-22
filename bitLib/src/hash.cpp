#include "hash.h"
#include <ctime>

static inline size_t sizeP(const char* line) {
	size_t res = 0;
	for (size_t i = 0; i < MAX_SIZE && line[i] != '\0'; res++, i++);
	return res;
};

static inline size_t bitCopy(union u_double value) {
	size_t res = 0;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		size_t mask = value.data[i];
		res |= mask << (i * 8);
	}
	return res;
}

inline const size_t string_to_int_u(const std::string& line) noexcept {
	size_t res = 0;
	size_t size = line.size();
	if (size == 0) { return res; };
	size_t ideal = line[0] % _CONST1;
	size_t seed = 1 + size % ideal;
	size_t pos = 0;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		char temp = line[pos];
		size_t mask = temp << (i * 8);
		res |= mask;
		pos = (pos + ideal) % size;
	}
	return res;
}

inline const size_t string_to_int_u(const char* line) noexcept {
	size_t res = 0;
	size_t size = sizeP(line);
	if (size == 0) { return res; };
	size_t ideal = line[0] % _CONST1;
	size_t seed = 1 + size % ideal;
	size_t pos = 0;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		char temp = line[pos];
		size_t mask = temp << (i * 8);
		res |= mask; 
		pos = (pos + ideal) % size;
	}
	return res;
}

inline const size_t string_to_int_e(const std::string& line) noexcept {
	size_t res = 0;
	size_t size = line.size();
	size_t shift = size / MAX_SIZE;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		char temp = line[i * shift];
		char mask = temp & 1 ? 0b10000000 : 0b00000000;
		temp |= mask;
		res |= size_t(temp) << (i * 8);
	}
	return res;
}

inline const size_t string_to_int_e(const char* line) noexcept {
	size_t res = 0;
	size_t size = sizeP(line);
	size_t shift = size / MAX_SIZE + 1;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		char temp = line[(i * shift) % size];
		char mask = temp & 1 ? 0b10000000 : 0b00000000;
		temp >>= 1;
		temp |= mask;
		size_t compliment = temp;
		res |= compliment << (i * 8);
	}
	return res;
}

inline const size_t string_to_int_s(const std::string& line) noexcept {
	size_t res = 0;
	size_t size = line.size();
	size_t shift = size / (2 * MAX_SIZE);
	for (size_t i = 0; i < MAX_SIZE; i++) {
		for (size_t j = 0; j < 8; j++) {
			size_t leftPos = (i + shift) * 8 + j;
			size_t rightPos = size * 8 - (leftPos);
			bool leftBit = line[leftPos / 8] & (1 << (8 - j - 1)) ? TRUE : FALSE;
			bool rightBit = line[rightPos / 8] & (1 << j) ? TRUE : FALSE;
			if (leftBit) { res |= 1 << (MAX_POS_T - j); };
			if (rightBit) { res |= 1 << j; };
		}
	}
	return res;
}

inline const size_t string_to_int_s(const char* line) noexcept {
	size_t res = 0;
	size_t size = sizeP(line);
	size_t shift = size / (2 * MAX_SIZE);
	size_t min = MAX_SIZE < size ? MAX_SIZE : size;
	for (size_t i = 0; i < min; i++) {
		for (size_t j = 0; j < 8; j++) {
			size_t matPos = i * 8 + j;
			size_t leftPos = (i + shift) * 8 + j;
			size_t rightPos = size * 8 - (leftPos);
			bool leftBit = line[leftPos / 8] & (1 << (8 - j - 1)) ? TRUE : FALSE;
			bool rightBit = line[rightPos / 8] & (1 << j) ? TRUE : FALSE;
			if (leftBit) { res |= 1 << (MAX_POS_T - matPos); };
			if (rightBit) { res |= 1 << matPos; };
		}
	}
	return res;
}

inline const size_t string_to_int_c(const std::string& line) noexcept {
	size_t res = 0;
	size_t size = line.size();
	size_t shift = size / 8;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		char temp = line[i * shift];
		res |= size_t(temp) << (i * 8);
	}
	return res;
}

inline const size_t string_to_int_c(const char* line) noexcept {
	size_t res = 0;
	size_t size = sizeP(line);
	size_t shift = size / 8;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		char temp = line[i * shift];
		res |= size_t(temp) << (i * 8);
	}
	return res;
}

inline const size_t double_to_int_c(const double value) noexcept {
	size_t res = 0;
	union u_double val;
	val.dbl = value;
	res = bitCopy(val);
	return res;
}

inline const size_t double_to_int_e(const double value) noexcept
{
	return size_t();
}

inline const size_t double_to_int_s(const double value) noexcept
{
	return size_t();
}

inline const size_t int_to_hash_s(const size_t value) noexcept
{
	return size_t();
}

inline const size_t int_to_hash_e(const size_t value) noexcept
{
	return size_t();
}
// reverse functions
inline const std::string int_to_string_u(size_t value) noexcept
{
	return std::string();
}

inline const char* int_to_charp_u(size_t value) noexcept
{
	return nullptr;
}

inline const std::string int_to_string_e(size_t value) noexcept
{
	return std::string();
}

inline const char* int_to_charp_e(size_t value) noexcept
{
	return nullptr;
}

inline const std::string int_to_string_s(size_t value) noexcept
{
	return std::string();
}

inline const char* int_to_charp_s(size_t value) noexcept
{
	return nullptr;
}

inline const std::string int_to_string_c(size_t value) noexcept
{
	return std::string();
}

inline const char* int_to_charp_c(size_t value) noexcept
{
	return nullptr;
}

inline const double int_to_double_c(size_t value) noexcept
{
	return 0.0;
}

inline const double int_to_double_e(size_t value) noexcept
{
	return 0.0;
}

inline const double int_to_double_s(size_t value) noexcept
{
	return 0.0;
}

inline const size_t hash_to_int_s(size_t value) noexcept
{
	return size_t();
}

inline const size_t hash_to_int_e(size_t value) noexcept
{
	return size_t();
}


template<typename T>
inline constexpr size_t to_hash_s(const T& value)	noexcept
{
	return size_t();
}

template<typename T>
constexpr size_t to_hash_r(const T& value)	noexcept
{
	return size_t();
}
