/*
*	WarerCode group (c). Hash functions header.
*	Here performance some functions, which convert std::string (char*)
*	and some numerical types to size_t. 
*	Any functions have reverse (lossless prediction functions).
*	Also here are some template-argument functions and random-hash converters.
*	Modifiers:
*	s - symmetric			(bits swapping between half of value field)
*	c - copy				(bits coping and pasting in new field)
*	e - even/not-even		(bits with even order swapping with not even)
*	r - random				(bits randomly change position)
*	u - unique				(look at function definition)
*/

#ifndef HASH_H
#define HASH_H

#include <bitset>
#include <string>

constexpr int dsize = sizeof(double);

#define TRUE		1
#define FALSE		0
#define WORD		dsize
#define DOUBLE_MAX	1 << (WORD * 8) - 1
#define MAX_SIZE	sizeof(size_t)
#define MAX_DOUBLE	MAX_SIZE
#define MAX_POS_T	8 * MAX_SIZE - 1
#define MAX_BYTE	0xff

#define _CONST1	16

#if		dsize == 8
#undef	DOUBLE_MAX
#define	DOUBLE_MAX 0xFFFFFFFFFFFFFFFF
#elif	dsize == 4
#undef	DOUBLE_MAX
#define DOUBLE_MAX 0xFFFFFFFF
#undef	MAX_DOUBLE
#define MAX_DOUBLE 4
#endif

union u_double {
    double  dbl;
    char    data[sizeof(double)];
};

union u_float {
    float   flt;
    char    data[sizeof(float)];
};

template<typename T>
union field {
    T       value;
    char    data[sizeof(T)];
};

// lossless hashs	O(1)
extern inline const size_t string_to_int_u		(const std::string& line)	noexcept;
extern inline const size_t string_to_int_u		(const char* line)			noexcept;
extern inline const size_t string_to_int_e		(const std::string& line)	noexcept;
extern inline const size_t string_to_int_e		(const char* line)			noexcept;
extern inline const size_t string_to_int_s		(const std::string& line)	noexcept;
extern inline const size_t string_to_int_s		(const char* line)			noexcept;
extern inline const size_t string_to_int_c		(const std::string& line)	noexcept;
extern inline const size_t string_to_int_c		(const char* line)			noexcept;
extern inline const size_t double_to_int_c		(const double value)		noexcept;
extern inline const size_t double_to_int_e		(const double value)		noexcept;
extern inline const size_t double_to_int_s		(const double value)		noexcept;
extern inline const size_t int_to_hash_s		(const size_t value)		noexcept;
extern inline const size_t int_to_hash_e	    (const size_t value)		noexcept;

// reverse lossless hashs
extern inline const std::string	    int_to_string_u(size_t value)	noexcept;
extern inline const char*			int_to_charp_u(size_t value)	noexcept;
extern inline const std::string	    int_to_string_e(size_t value)	noexcept;
extern inline const char*			int_to_charp_e(size_t value)	noexcept;
extern inline const std::string	    int_to_string_s(size_t value)	noexcept;
extern inline const char*			int_to_charp_s(size_t value)	noexcept;
extern inline const std::string	    int_to_string_c(size_t value)	noexcept;
extern inline const char*			int_to_charp_c(size_t value)	noexcept;
extern inline const double			int_to_double_c(size_t value)	noexcept;
extern inline const double			int_to_double_e(size_t value)	noexcept;
extern inline const double			int_to_double_s(size_t value)	noexcept;
extern inline const size_t			hash_to_int_s(size_t value)		noexcept;
extern inline const size_t			hash_to_int_e(size_t value)		noexcept;

// general hashs
template<typename T>
extern constexpr size_t to_hash_s(const T& value)   noexcept;

template<typename T>
extern constexpr size_t to_hash_r(const T& value)   noexcept;

// random hashs

#endif
