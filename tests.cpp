#include "Core/flower_common.hpp"
#include "gtest/gtest.h"

TEST(Flower_Stack, empty_stack) {
	using namespace flower::fvm;
	Stack st;
	ASSERT_EQ(st.getTop(), nullptr);
	ASSERT_EQ(st.getSize(), 0);
}
TEST(Flower_Stack, stack_push) {
	using namespace flower::fvm;
	Stack st;
	st.push<FInt>(123);
	st.push<FDouble>(5.6);
	st.push<FBool>(true);
	ASSERT_EQ(st.getSize(), 13);
}
TEST(Flower_Stack, stack_pop) {
	using namespace flower::fvm;
	Stack st;
	st.push<FInt>(123);
	st.push<FDouble>(5.6);
	st.push<FBool>(true);
	ASSERT_EQ(st.pop<FBool>(), true);
	ASSERT_EQ(st.pop<FDouble>(), 5.6);
	ASSERT_EQ(st.pop<FInt>(), 123);
	ASSERT_EQ(st.getSize(), 0);
}
TEST(Flower_Stack, stack_peek) {
	using namespace flower::fvm;
	Stack st;
	st.push<FInt>(123);
	st.push<FDouble>(5.6);
	st.push<FBool>(true);
	ASSERT_EQ(st.peek<FBool>(), true);
	ASSERT_EQ(st.getSize(), 13);
}
TEST(Flower_Stack, stack_get) {
	using namespace flower::fvm;
	Stack st;
	st.push<FInt>(123);
	st.push<FDouble>(5.6);
	st.push<FBool>(true);
	ASSERT_EQ(st.get<FDouble>(4), 5.6);
	ASSERT_EQ(st.get<FInt>(0), 123);
	ASSERT_EQ(st.get<FBool>(12), true); 

}
TEST(Flower_Stack, stack_set) {
	using namespace flower::fvm;
	Stack st;
	st.push<FInt>(123);
	st.push<FDouble>(5.6);
	st.push<FBool>(true);
	st.set<FDouble>(6.9, 4);
	ASSERT_EQ(st.get<FDouble>(4), 6.9);
}
TEST(Flower_Bytecode, instruction_size) {
	using namespace flower::fvm;
	ASSERT_EQ(sizeof(Instruction), 1);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}