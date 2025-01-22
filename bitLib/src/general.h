#ifndef GENERAL_H
#define GENERAL_H

#include "registers.h"

template<typename T>
union field {
    T       value;
    char    data[sizeof(T)];
};

// swapping

template<typename T>
extern inline void swap(T& _Left, T& _Right) noexcept;

template<typename T>
extern inline void swapBit(T& _Left, T& _Right, int pos) noexcept;

// General functions:
template<typename T>
inline void setBits(T& value, int left, int right) {
	const int size = sizeof(T) * 8;
	if (left < right) { return; };
	if (left > _MAX_POS || left > size - 1) { return; };
	size_t dt = left - right;
	x64reg clone = TRUE << dt;
	for (size_t i = 0; i < dt; i++) {
		value = (value | clone);
	}
};

template<typename T>
inline void setBit(T& value, int pos) {
	const int size = sizeof(T) * 8;
	if (pos > _MAX_POS || pos > size - 1) { return; }
	else {
		x64reg mask = 1 << pos;
		value = (value | mask);
	}
};

template<typename T>
inline void resetBits(T& value, int left, int right) {
	const int size = sizeof(T) * 8;
	if (left < right) { return; };
	if (left > _MAX_POS || left > size - 1) { return; };
	size_t dt = left - right;
	x64reg clone = TRUE << dt;
	for (size_t i = 0; i < dt; i++) {
		value = (value & clone) ? (value ^ clone) : value;
	}
};

template<typename T>
inline void resetBit(T& value, int pos) {
	const int size = sizeof(T) * 8;
	if (pos > _MAX_POS || pos > size - 1) { return; }
	else {
		x64reg mask = ~(1 << pos);
		value = (value & mask);
	}
};

template<typename T>
inline void invertBit(T& value, int pos) {
	const int size = sizeof(T) * 8;
	if (pos > _MAX_POS || pos > size - 1) { return; }
	else {
		x64reg mask = 1 << pos;
		value = (value ^ mask);
	}
}

template<typename T>
inline void invertBits(T& value, int left, int right) {
	const int size = sizeof(T) * 8;
	if (left < right) { return; };
	if (left > _MAX_POS || left > size - 1) { return; };
	size_t dt = left - right;
	x64reg clone = 1 << right;
	for (size_t i = 0; i <= dt; i++) {
		value ^= clone;
		clone <<= 1;
	}
};

template<typename T>
inline void invert(T& value) {
	value = ~value;
};

template<typename T>
inline void lShift(T& value) {
	const int size = sizeof(T) * 8;
	bit head = 1 << (size - 1) & value ? TRUE : FALSE;
	value <<= 1;
	value |= head ? 1 << 1 : 0;
}

template<typename T>
inline void rShift(T& value) {
	const int size = sizeof(T) * 8;
	bit head = 1 & value ? TRUE : FALSE;
	value >>= 1;
	value |= head ? 1 << (size - 1) : 0;
};

template<typename T>
inline void lShift(T& value, int count) {
	const int size = sizeof(T) * 8;
	count %= size;
	const int offset = size - count;
	T clone(value);
	clone >>= offset;
	value <<= count;
	value |= clone;
};

template<typename T>
inline void rShift(T& value, int count) {
	const int size = sizeof(T) * 8;
	count %= size;
	const int offset = size - count;
	T clone(value);
	clone <<= offset;
	value >>= count;
	value |= clone;
};
#endif