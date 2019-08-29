#include "ivec_tester.h"
#include "ivec.h"
#include <iostream>
#include <sstream>

void ivec_tester::test_constructor()
{
	std::ostringstream strm;
	{
		ivec v;
		if (v.size() != 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{strm.str()});
		}
		if (v.capacity() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v.begin() == nullptr)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(2);
		if (v[0] != 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(1,3);
		if (v[0] != 3)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}


void ivec_tester::test_copy_constructor()
{
	std::ostringstream strm;
	{
		ivec v1(2, 4);
		ivec v2{ v1 };
		if (v2.size() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v2.const_it == v1.const_it)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v2.capacity() != 4)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v2[0] != 4 || v2[1] != 4)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}



void ivec_tester::test_assignment_operator()
{
	std::ostringstream strm;

	ivec v1(4, 9);
	ivec v2;
	v2 = v1;
	if (v2.size() != 4)
	{
		strm << "Error on line " << __LINE__;
		throw std::logic_error(std::string{ strm.str() });
	}
	if (v2.capacity() != 6)
	{
		strm << "Error on line " << __LINE__;
		throw std::logic_error(std::string{ strm.str() });
	}
	for (int i = 0; i < 4; ++i)
	{
		if (v2[i] != 9)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	if (v2.const_it == v1.const_it)
	{
		strm << "Error on line " << __LINE__;
		throw std::logic_error(std::string{ strm.str() });
	}
}


void ivec_tester::test_reserve()
{
	std::ostringstream strm;

	{
		ivec v;
		v.reserve(3);
		if (v.capacity() < 3)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(7);
		v.reserve(3);
		if (v.capacity() < 3)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}


void ivec_tester::test_resize()
{
	std::ostringstream strm;
	{
		ivec v;
		v.resize(2);
		if (v.size() != 2 || v.capacity() != 4)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v[0] != 0 || v[1] != 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(1, 2);
		v.resize(3, 5);
		if (v.size() != 3 || v.capacity() != 5)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v[1] != 5 || v[2] != 5)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(4);
		v.resize(1);
		if (v.size() != 1 || v.capacity() != 6)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v[0] != 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v[1] == 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}

void ivec_tester::test_push_back()
{
	std::ostringstream strm;

	{
		ivec v;
		v.push_back(3);
		if (v.size() != 1)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v[0] != 3)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(3, 2);
		v.push_back(5);
		if (v.size() != 4)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}

void ivec_tester::test_pop_back()
{
	std::ostringstream strm;
	{
		ivec v(2,4);
		int size = v.size();

		v.pop_back();
		if (size == v.size())
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}

void ivec_tester::test_size()
{
	std::ostringstream strm;
	{
		ivec v(2, 4);
		if (v.size() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v;
		if (v.size() != 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}

void ivec_tester:: test_capacity()
{
	std::ostringstream strm;
	{
		ivec v(2, 4);
		if (v.capacity() != 4)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v;
		if (v.capacity() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}

}


void ivec_tester::test_empty()
{
	std::ostringstream strm;
	{
		ivec v;
		if (v.empty() == false)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(2, 1);
		if (v.empty() == true)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}


void ivec_tester::test_index_operator()
{
	std::ostringstream strm;
	{
		ivec v(2,1);

		if (v[0] !=1 || v[1] != 1)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}

void ivec_tester::test_at()
{
	std::ostringstream strm;
	{
		ivec v(2);
		if (v.at(0) != 0 || v.at(1) != 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(3, 1);
		try
		{
			v.at(4);
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		catch (std::out_of_range  const& e)
		{
		}
	}
}




void ivec_tester::test_front()
{
	std::ostringstream strm;
	{
		ivec v(2, 1);
		if (v.front() != 1)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v;
		v.push_back(5);
		v.push_back(3);
		if (v.front() != 5)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}


void ivec_tester::test_back()
{
	std::ostringstream strm;
	{
		ivec v(2, 1);
		if (v.back() != 1)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v;
		v.push_back(5);
		v.push_back(3);
		if (v.back() != 3)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}

void ivec_tester::test_begin()
{
	std::ostringstream strm;
	{
		ivec v(2, 5);
		if (5 != *(v.begin()))
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (&(v[0]) != v.begin())
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	
}


void ivec_tester::test_end()
{
	std::ostringstream strm;
	{
		ivec v(2, 5);
		if (5 == *(v.end()))
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (&(v[2]) != v.end())
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}

}

void ivec_tester::test_clear()
{
	std::ostringstream strm;
	{
		ivec v(2, 8);
		v.clear();
		if (v.size() != 0)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}

	{
		ivec v(3);
		v.clear();
		if (v.begin() == nullptr)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}


void ivec_tester::test_erase()
{
	std::ostringstream strm;
	{
		ivec v1;
		try
		{
			v1.erase(v1.begin()-1);
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		catch (std::out_of_range  const& e)
		{
		}
	}
	{
		ivec v(2);
		v.push_back(1);
		v.push_back(2);
		v.erase(v.begin());
		if (v[0] == 1 || v[1] == 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v.size() == 2 || v.capacity() == 3)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(2, 3);
		v.push_back(4);
		v.push_back(7);

		v.erase(v.begin(),v.begin()+2);
		if (v[0] == 3 || v[1] == 3)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v.size() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}


		try
		{
			v.erase(v.end());
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		catch (std::out_of_range  const& e)
		{
		}
	}
}
void ivec_tester::test_insert() 
{
	std::ostringstream strm;
	{
		ivec v;
		v.insert(v.begin(), 2);
		if (v[0] != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v.size() != 1 || v.capacity() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v(1, 9);
		v.insert(v.begin() + 1, 4);
		if (v[1] != 4)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v.size() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		try
		{
			v.insert(v.begin() - 2, 7);
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		catch (std::out_of_range  const& e)
		{
		}
		try
		{
			v.insert(v.end() + 1, 7);
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		catch (std::out_of_range  const& e)
		{
		}
	}
	{
		ivec v(1, 6);
		v.insert(v.end(),5);
		if (v[1] != 5)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v1(2, 7);
		v1.insert(v1.begin() + 1, 3, 9);
		if (v1[1] != 9 || v1[2] != 9 || v1[3] != 9)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
		if (v1.size() != 5)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
	{
		ivec v1(2, 3);
		ivec v2;

		v2.insert(v2.begin(), v1.begin(), v1.end());
		

		if (v2[0] != 3 || v2[1] != 3 || v2.size() != 2)
		{
			strm << "Error on line " << __LINE__;
			throw std::logic_error(std::string{ strm.str() });
		}
	}
}

void ivec_tester::Test()
{
	bool testOK = true;
	try 
	{
		test_constructor();
		test_copy_constructor();

		test_assignment_operator();

		test_reserve();
		test_resize();

		test_push_back();
		test_pop_back();

		test_index_operator();
		test_at(); 
		
		test_size();
		test_capacity();
		
		test_empty();
		test_clear();

		test_front();
		test_back();

		test_begin();
		test_end();
		
		test_erase();
		test_insert();
	}
	catch (std::logic_error const& e)
	{
		testOK = false;
		std::cout << "Test failed!"<<e.what();
	}
	if (testOK)
	{
		std::cout << "Test Succeeded!" << std::endl;
	}
}