#ifndef FLOWER_OPCODES_H
#define FLOWER_OPCODES_H
#include<cstdint>
namespace flower {
	namespace fvm {
		enum class Instruction : uint8_t {
			HLT, //stops execution of VM
			NOP, //does nothing
			ILOAD, //loads integer into register given offset in bytes from base pointer
			ILOADA, //loads integer into accumulator given offset in bytes from base pointer
			IPOP, //pops an integer off the stack into register
			IPOPA, //pops an integer off the stack into accumulator
			IPEEK, //loads (without popping) integer at the top of the stack into the register
			IPEEKA, //loads (without popping) integer at the top of the stack into the accumulator
			ISTORE, //copies integer from accumulator to location referenced by offset in bytes from base pointer
			IPUSH, //pushes integer from accumulator onto the stack
			IPUSHV, //pushes an integer value onto the stack given the integer to push
			LLOAD, //loads long into register given offset in bytes from base pointer
			LLOADA, //loads long into accumulator given offset in bytes from base pointer
			LPOP, //pops a long off the stack into register
			LPOPA, //pops a long off the stack into accumulator
			LPEEK, //loads (without popping) long at the top of the stack into the register
			LPEEKA, //loads (without popping) long at the top of the stack into the accumulator
			LSTORE, //copies long from accumulator to location referenced by offset in bytes from base pointer
			LPUSH, //pushes long from accumulator onto the stack
			LPUSHV, //pushes a long value onto the stack given the long to push
			BLOAD, //loads bool into register given offset in bytes from base pointer
			BLOADA, //loads bool into accumulator given offset in bytes from base pointer
			BPOP, //pops a bool off the stack into register
			BPOPA, //pops a bool off the stack into accumulator
			BPEEK, //loads (without popping) bool at the top of the stack into the register
			BPEEKA, //loads (without popping) bool at the top of the stack into the accumulator
			BSTORE, //copies bool from accumulator to location referenced by offset in bytes from base pointer
			BPUSH, //pushes bool from accumulator onto the stack
			BPUSHV, //pushes a bool value onto the stack given the bool to push
			ALOAD, //loads byte into register given offset in bytes from base pointer
			ALOADA, //loads byte into accumulator given offset in bytes from base pointer
			APOP, //pops a byte off the stack into register
			APOPA, //pops a byte off the stack into accumulator
			APEEK, //loads (without popping) byte at the top of the stack into the register
			APEEKA, //loads (without popping) byte at the top of the stack into the accumulator
			ASTORE, //copies byte from accumulator to location referenced by offset in bytes from base pointer
			APUSH, //pushes byte from accumulator onto the stack
			APUSHV, //pushes a byte value onto the stack given the byte to push
			CLOAD, //loads char into register given offset in bytes from base pointer
			CLOADA, //loads char into accumulator given offset in bytes from base pointer
			CPOP, //pops a char off the stack into register
			CPOPA, //pops a char off the stack into accumulator
			CPEEK, //loads (without popping) char at the top of the stack into the register
			CPEEKA, //loads (without popping) char at the top of the stack into the accumulator
			CSTORE, //copies char from accumulator to location referenced by offset in bytes from base pointer
			CPUSH, //pushes char from accumulator onto the stack
			CPUSHV, //pushes a char value onto the stack given the char to push
			FLOAD, //loads float into register given offset in bytes from base pointer
			FLOADA, //loads float into accumulator given offset in bytes from base pointer
			FPOP, //pops a float off the stack into register
			FPOPA, //pops a float off the stack into accumulator
			FPEEK, //loads (without popping) float at the top of the stack into the register
			FPEEKA, //loads (without popping) float at the top of the stack into the accumulator
			FSTORE, //copies float from accumulator to location referenced by offset in bytes from base pointer
			FPUSH, //pushes float from accumulator onto the stack
			FPUSHV, //pushes a float value onto the stack given the float to push
			DLOAD, //loads doubleinto register given offset in bytes from base pointer
			DLOADA, //loads double into accumulator given offset in bytes from base pointer
			DPOP, //pops a doubleoff the stack into register
			DPOPA, //pops a double off the stack into accumulator
			DPEEK, //loads (without popping) double at the top of the stack into the register
			DPEEKA, //loads (without popping) double at the top of the stack into the accumulator
			DSTORE, //copies double from accumulator to location referenced by offset in bytes from base pointer
			DPUSH, //pushes double from accumulator onto the stack
			DPUSHV, //pushes a double value onto the stack given the char to push
			ISWAP, //swaps contents of integer accumulator and register
			ICOPY, //copies value in integer register into integer accumulator
			FSWAP, //swaps contents of floating point accumulator and register
			FCOPY, //copies value in floating point register into accumulator
		};
	}
}






#endif
