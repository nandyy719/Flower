#ifndef FVM_H
#define FVM_H
#include<fstream>
#include<iostream>
#include "flower_common.hpp"
namespace flower {
	namespace fvm {
		class VM {
		public:
			VM(Instruction* code, size_t size = 1048576) : ip(code), stack(size), retp(nullptr), i0(0), i1(0), f0(0.0), f1(0.0) { //
				if (code == nullptr) {
					std::cerr << "Invalid pointer to code\n";
					exit(1);
				}
			}
			Instruction* execute() {
				Instruction* next = nullptr;
				switch (*ip) {
				case Instruction::NOP:
					next = ++ip;
					break;

				}

				return next;

			}
			void run() {
				while (*ip != Instruction::HLT) {
					ip = execute();
					if (ip == nullptr) {
						std::cerr << "Invalid instruction pointer\n";
						exit(1);
					}
				}

			}
		
		private:
			Instruction* ip; //instruction pointer
			Instruction* retp; //return address
			Stack stack; //data stack
			FLong i0; //integer accumulator
			FLong i1; // integer register
			FDouble f0; //floating-point accumulator
			FDouble f1; // floating-point register
			
		};
	}
}

#endif