#include "buffer.h"

inline char* resize_buffer() {
	char* clone = new char[size];
	for (size_t i = 0; i < size; i++) {
		clone[i] = bit_buffer[i];
	}
	if (size >= MAX_BUFFER_SIZE) { delete[] clone; return bit_buffer; };
	bit_buffer = new char[size * 2];
	size *= 2;
	for (size_t i = 0; i < size; i++) {
		bit_buffer[i] = i < size / 2 ? clone[i] : 0b00000000;
	}
	delete[] bit_buffer;
	return bit_buffer;
};

inline char* divide() {
	char* clone = new char[(size + 1) / 2];
	for (size_t i = 0; i < (size + 1) / 2; i++) {
		clone[i] = bit_buffer[i];
	}
	delete[] bit_buffer;
	bit_buffer = new char[(size + 1) / 2] {};
	size = (size + 1) / 2;
	return bit_buffer;
};

inline char* swap() {
	for (size_t i = 0; i < size; i++) {
		char clone = bit_buffer[i];
		bit_buffer[i] = bit_buffer[size - i];
		bit_buffer[size - i] = clone;
	}
	return bit_buffer;
};

inline void clear() {
	for (size_t i = 0; i < size; i++) {
		bit_buffer[i] = 0b00000000;
	}
};

inline char* new_buffer() {
	return new char[BUFFER_SIZE];
};

inline int trueBits() noexcept {
	int count = 0;
	for (size_t i = 0; i < size; i++) {
		byte trigger = 1;
		for (size_t j = 0; j < 8; j++) {
			count += bit_buffer[i] & trigger ? TRUE : FALSE;
			trigger <<= 1;
		}
	}
	return count;
};

inline int falseBits() noexcept {
	return size * 8 - trueBits();
};

inline bit getBit(int pos) noexcept {
	if (size * 8 <= pos) { return FALSE; };
	int base = pos / 8;
	int offset = pos % 8;
	byte value = 1 << offset;
	value &= bit_buffer[base];
	return value ? TRUE : FALSE;
};

inline byte getByte(int pos) noexcept {
	pos %= 8;
	return bit_buffer[pos];
};

inline void setBit(int pos) noexcept {
	pos %= size * 8;
	int base = pos / 8;
	int offset = pos % 8;
	byte value = 1 << offset;
	bit_buffer[base] |= value;
};

inline void resetByte(int pos) noexcept {
	pos = pos % 8;
	bit_buffer[pos] = 0b00000000;
};

inline void resetBit(int pos) noexcept {
	pos %= size * 8;
	int base = pos / 8;
	int offset = pos % 8;
	byte value = ~(1 << offset);
	bit_buffer[base] &= value;
};
