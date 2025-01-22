/*
*	WarerCode group 2025 (c). Bit_t class header.
*	Here performed real bit type like part of static
*	byte array. So we have some issues:
*	without getters ([] operator) and setters (() operator) this
*	class equals bit stack. We can se only top bit in same scope.
*	But it too can be usefull. E.g. we have to write bool values
*	in cycle.
*	_____________________________________________________________
*	Default new bit set in 1.
*/

#ifndef BIT_H
#define BIT_H

#define USED_BUFFER_SIZE	256
#define MAX_BUFFER_SIZE		1 << (sizeof(size_t) * 8) - 1
#define TRUE	1
#define FALSE	0

static char* bits = new char[USED_BUFFER_SIZE];
static size_t used = 0;
static size_t size_ = USED_BUFFER_SIZE;

struct bit_t
{
	bit_t() {
		bits[used / 8] |= 1 << (used % 8);
		if (used == size_ * 8) { resize(); };
		used++;
	};
	~bit_t() {
		used--;
		if (used == size_ * 4) { divide(); };
		bits[used / 8] &= 1 << ~(used % 8);
	};
	inline bool operator!() const {
		size_t byte = (used - 1) / 8;
		size_t bit = (used - 1) % 8;
		bits[byte] ^= 1 << bit;
		bool res = bits[byte] & 1 << bit ? TRUE : FALSE;
		return res;
	};
	inline bool operator++() const {
		size_t byte = (used - 1) / 8;
		size_t bit = (used - 1) % 8;
		bits[byte] |= 1 << bit;
		bool res = bits[byte] & 1 << bit ? TRUE : FALSE;
		return res;
	};
	inline bool operator--() const {
		size_t byte = (used - 1) / 8;
		size_t bit  = (used - 1) % 8;
		bits[byte] &= ~(1 << bit);
		bool res = bits[byte] & 1 << bit ? TRUE : FALSE;
		return res;
	};
	inline bool operator[](int pos) const {
		pos %= used;
		int base = pos / 8;
		int offset = pos % 8;
		bool res = bits[base] & (1 << offset) ? TRUE : FALSE;
		return res;
	};	// for get value
	inline void operator()(int pos) const {
		pos %= used;
		int base = pos / 8;
		int offset = pos % 8;
		bits[base] &= ~(1 << offset);
	};	// for reset value
private:
	inline void resize() {
		char* clone = new char[size_];
		for (size_t i = 0; i < size_; i++) {
			clone[i] = bits[i];
		}
		if (size_ >= MAX_BUFFER_SIZE) { delete[] clone; return; };
		bits = new char[size_ * 2];
		size_ *= 2;
		for (size_t i = 0; i < size_ / 2; i++) {
			bits[i] = clone[i];
		}
		delete[] clone;
	};
	inline void divide() {
		if (size_ == 1) { return; };
		char* clone = new char[size_ / 2];
		for (size_t i = 0; i < size_ / 2; i++) {
			clone[i] = bits[i];
		}
		bits = new char[size_ / 2];
		size_ /= 2;
		for (size_t i = 0; i < size_; i++) {
			bits[i] = clone[i];
		}
		delete[] clone;
	};
};

#endif