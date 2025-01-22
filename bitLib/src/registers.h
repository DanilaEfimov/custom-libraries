/****************************************************
*	WarerCode group 2025 (c).
*	register.h header calls general bit's macros
*	present header set configuration settings and define
*	general structures
****************************************************/

#ifndef REGISTERS_H
#define REGISTERS_H

#include <bitset>
#include <ostream>

#define TRUE		1
#define FALSE		0
#define x8			0x08
#define x16			0x10
#define x32			0x20
#define x86			0x20
#define x64			0x40
#define x8reg		unsigned char
#define x16reg		unsigned short
#define x32reg		unsigned int
#define x86reg		x32reg
#define x64reg		unsigned long long int
#define _MAX_SIZE	sizeof(size_t)
#define _MAX_POS	(_MAX_SIZE * 8  - 1)

constexpr int _int_size		= sizeof(int);
constexpr int _size_t_size	= sizeof(size_t);

#if		_size_t_size == 4
#undef	x8reg
#define x8reg	unsigned char
#undef	x16reg
#define x16reg	unsigned short
#undef	x32reg
#define x32reg	size_t
#undef	x86reg
#define x86reg	x32reg
#undef	x64reg
#define x64reg	x32reg
#pragma message("WARNING::using x32reg definition of x64reg macro\n")
#endif

#define _x8_MAX		1 << x8 - 1
#define _x16_MAX	1 << x16 - 1
#define _x32_MAX	1 << x32 - 1
#define _x64_MAX	1 << x64 - 1

typedef std::bitset<8>	// general purpose sub-registers
AL, CL, DL, BL,
AH, CH, DH, BH;

typedef std::bitset<16>	// general purpose registers
AX, CX, DX, BX,
SI, DI, BP, SP,
CS, DS, ES, SS,
IP, FLAGS;

typedef std::bitset<32>	// extended general purpose registers
EAX, ECX, EDX, EBX,
ESI, EDI, EBP, ESP,
ECS, EDS, EES, ESS,
EIP, EFLAGS;

typedef std::bitset<64>	// reextended general purpose registers
RAX, RCX, RDX, RBX,
RSI, RDI, RBP, RSP,
RCS, RDS, RES, RSS,
RIP, RFLAGS;

enum {
	_AL, _CL, _DL, _BL,
	_AH, _CH, _DH, _BH,
	_AX = 0, _CX, _DX, _BX,
	_SI, _DI, _BP, _SP,
	_CS, _DS, _ES, _SS,
	_EAX = 0, _ECX, _EDX, _EBX,
	_ESI, _EDI, _EBP, _ESP,
	_ECS, _EDS, _EES, _ESS,
	_RAX = 0, _RCX, _RDX, _RBX,
	_RSI, _RDI, _RBP, _RSP,
	_RCS, _RDS, _RES, _RSS,
	_IP = 0, _FLAGS,
};

typedef bool bit;		// prime memory containers
typedef x8reg byte;

////////////////////////////////////////



////////////////////////////////////////

// register's accessors
extern inline x8reg		x8bitReg(int code)	noexcept;
extern inline x16reg	x16bitReg(int code)	noexcept;
extern inline x32reg	x32bitReg(int code)	noexcept;

////////////////////////////////////////

// register's systems
struct x8register {
	x8reg value;
	x8register(x8reg _value = 0) { value = _value; };
	x8reg operator=(x8reg _right){ value = _right; };
	std::ostream& operator<<(std::ostream& _in) { _in << value; return _in; };
	x8reg operator++(int) { value++; return value; };
	x8reg operator--(int) { value--; return value; };
	x8reg operator++() {
		bit head = 1 & value ? TRUE : FALSE;
		value >>= 1;
		value |= (x8reg)head << 7;
		return value;
	};
	x8reg operator--() {
		bit head = (x8reg)1 << 7 & value ? TRUE : FALSE;
		value <<= 1;
		value |= (x8reg)head;
		return value;
	};
	friend std::ostream& operator<<(std::ostream& _in, const x8register& _reg) {
		_in << _reg.value; return _in;
	};
};

struct x16register {
	x16reg value;
	x16register(x16reg _value = 0)	{ value = _value; };
	x16reg operator=(x16reg _right) { value = _right; };
	x16reg operator++(int) { value++; return value; };
	x16reg operator--(int) { value--; return value; };
	x16reg operator++() {
		bit head = 1 & value ? TRUE : FALSE;
		value >>= 1;
		value |= (x16reg)head << 15;
		return value;
	};
	x16reg operator--() {
		bit head = (x16reg)1 << 15 & value ? TRUE : FALSE;
		value <<= 1;
		value |= (x16reg)head;
		return value;
	};
	friend std::ostream& operator<<(std::ostream& _in, const x16register& _reg) {
		_in << _reg.value; return _in;
	};
};

struct x32register {
	x32reg value;
	x32register(x32reg _value = 0) { value = _value; };
	x32reg operator=(x32reg _right){ value = _right; };
	x32reg operator++(int) { value++; return value; };
	x32reg operator--(int) { value--; return value; };
	x32reg operator++() {
		bit head = 1 & value ? TRUE : FALSE;
		value >>= 1;
		value |= (x32reg)head << 31;
		return value;
	};
	x32reg operator--() {
		bit head = (x32reg)1 << 31 & value ? TRUE : FALSE;
		value <<= 1;
		value |= (x32reg)head;
		return value;
	};
	friend std::ostream& operator<<(std::ostream& _in, const x32register& _reg) {
		_in << _reg.value; return _in;
	};
};

struct x64register {
	x64reg value;
	x64register(x64reg _value = 0) { value = _value; };
	x64reg operator=(x64reg _right){ value = _right; };
	x64reg operator++(int) { value++; return value; };
	x64reg operator--(int) { value--; return value; };
	x64reg operator++() {
		bit head = 1 & value ? TRUE : FALSE;
		value >>= 1;
		value |= (x64reg)head << 63;
		return value;
	};
	x64reg operator--() {
		bit head = (x64reg)1 << 63 & value ? TRUE : FALSE;
		value <<= 1;
		value |= (x64reg)head;
		return value;
	};
	friend std::ostream& operator<<(std::ostream& _in, const x64register& _reg) { 
		_in << _reg.value; return _in; 
	};
};

#endif