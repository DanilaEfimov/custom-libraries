/***********************************************
*	WarerCode group 2025 (c).
*	present header defines static bit's buffer
*	and bit's interface.
***********************************************/

#ifndef BUFFER_H
#define BUFFER_H

#define TRUE		1
#define FALSE		0
#define BUFFER_SIZE 128
#define BYTE		1
#define BIT			1
#define WORD		sizeof(size_t)
#define DWORD		2 * sizeof(size_t)
#define MAX_BUFFER_SIZE		1 << (sizeof(size_t)) - 1 

static char* bit_buffer		= new char[BUFFER_SIZE];
static int size				= BUFFER_SIZE;

typedef bool bit;
typedef unsigned char byte;

// bit buffer interface
extern inline char* resize_buffer();
extern inline char* divide();
extern inline char* swap();
extern inline char* new_buffer();
extern inline void clear();

// bit byte operations
extern inline int trueBits()			noexcept;
extern inline int falseBits()			noexcept;
extern inline bit getBit(int pos)		noexcept;
extern inline byte getByte(int pos)		noexcept;
extern inline void setBit(int pos)		noexcept;
extern inline void resetByte(int pos)	noexcept;
extern inline void resetBit(int pos)	noexcept;

#endif