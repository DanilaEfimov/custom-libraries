#include "registers.h"

/////////////////////////////////////

static x8reg	x8bit_reg	= 0;
static x16reg	x16bit_reg	= 0;
static x32reg	x32bit_reg	= 0;
static x64reg	x64bit_reg	= 0;

// register's accessors
inline x8reg x8bitReg(int code) noexcept {
	switch (code) {
	case _AH: __asm {mov x8bit_reg, ah }; break;
	case _CH: __asm {mov x8bit_reg, ch }; break;
	case _DH: __asm {mov x8bit_reg, dh }; break;
	case _BH: __asm {mov x8bit_reg, bh }; break;
	case _AL: __asm {mov x8bit_reg, al }; break;
	case _CL: __asm {mov x8bit_reg, cl }; break;
	case _DL: __asm {mov x8bit_reg, dl }; break;
	case _BL: __asm {mov x8bit_reg, bl }; break;
	default:
		break;
	}
	return x8bit_reg;
}

inline x16reg x16bitReg(int code) noexcept {
	switch (code) {
	case _AX: __asm {mov x16bit_reg, ax }; break;
	case _CX: __asm {mov x16bit_reg, cx }; break;
	case _DX: __asm {mov x16bit_reg, dx }; break;
	case _BX: __asm {mov x16bit_reg, bx }; break;
	case _SI: __asm {mov x16bit_reg, si }; break;
	case _DI: __asm {mov x16bit_reg, di }; break;
	case _BP: __asm {mov x16bit_reg, bp }; break;
	case _SP: __asm {mov x16bit_reg, sp }; break;
	default:
		break;
	}
	return x16bit_reg;
}

inline x32reg x32bitReg(int code) noexcept {
	switch (code) {
	case _EAX: __asm {mov x32bit_reg, eax }; break;
	case _ECX: __asm {mov x32bit_reg, ecx }; break;
	case _EDX: __asm {mov x32bit_reg, edx }; break;
	case _EBX: __asm {mov x32bit_reg, ebx }; break;
	case _ESI: __asm {mov x32bit_reg, esi }; break;
	case _EDI: __asm {mov x32bit_reg, edi }; break;
	case _EBP: __asm {mov x32bit_reg, ebp }; break;
	case _ESP: __asm {mov x32bit_reg, esp }; break;
	default:
		break;
	}
	return x16bit_reg;
}
