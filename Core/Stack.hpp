#ifndef FLOWER_STACK_H
#define FLOWER_STACK_H
#include "types.hpp"
#include<iostream>
namespace flower {
	namespace fvm {
		class Stack {
		public:
			
			//default stack size is 1 MB
			Stack(size_t size = 1048576) : buffer(new FByte[size]), sp(nullptr), bp(buffer), curSize(0) {
				if (!buffer) {
					std::cerr << "Failed to acquire memory for stack\n";
					exit(1);
				}
			}

			//only one stack for the vm, no copying or moving ownership of stacks
			Stack(const Stack& other) = delete;
			Stack(Stack&& other) = delete;
			Stack& operator=(const Stack& other) = delete;
			Stack& operator=(Stack&& other) = delete;

			template<typename T>
			FByte* push(const T& data) {
				T* tmp;
				tmp = sp == nullptr ? reinterpret_cast<T*>(buffer) : reinterpret_cast<T*>(sp);
				*tmp = data;
				tmp++;
				sp = reinterpret_cast<FByte*>(tmp);
				curSize += sizeof(T);
				return sp;
			}
			FByte* getTop() {
				return sp;
			}
			template<typename T>
			T pop() {
				T* tmp = reinterpret_cast<T*>(sp);
				tmp--;
				sp = reinterpret_cast<FByte*>(tmp);
				curSize -= sizeof(T);
				return *tmp;

			}
			template<typename T>
			T peek() {
				T* tmp = reinterpret_cast<T*>(sp);
				tmp--;
				return *tmp;
			}
			template<typename T>
			T get(size_t offset) { //gets value stored offset bytes above the base pointer
				T* tmp = reinterpret_cast<T*>(bp + offset);
				return *tmp;
			}
			template<typename T>
			void set(const T& val, size_t offset) {
				T* tmp = reinterpret_cast<T*>(bp + offset);
				*tmp = val;
			}
			size_t getSize() { return curSize; }

			~Stack() {
				delete[] buffer;
				sp = nullptr;
				bp = nullptr;
			}

		private:
			FByte* buffer;
			FByte* bp;
			FByte* sp;
			size_t curSize; //current size of the stack in bytes
			friend class VM;
		};
	}
}

#endif