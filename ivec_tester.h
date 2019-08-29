#pragma once

class ivec_tester
{
	void test_constructor();
	void test_copy_constructor();
	void test_destructor();
	
	void test_assignment_operator();

	void test_reserve();
	void test_resize();

	void test_push_back();
	void test_pop_back();

	void test_index_operator();
	void test_at();

	void test_size();
	void test_capacity();
	
	void test_empty();
	void test_clear();
	
	void test_front();
	void test_back();
	
	void test_begin();
	void test_end();
	
	void test_erase();
	void test_insert();

public:
	void Test();
};