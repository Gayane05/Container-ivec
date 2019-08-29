#include <iostream>
#include "ivec.h"


std::ostream& operator<<(std::ostream& out, const ivec& ob)
{
	for (int i = 0; i < ob.iSize; ++i)
	{
		out << " " << ob.ptr[i];
	}
	return out;
}


ivec::ivec(const int& s, const int& v) :iSize(s)
{
	//std::cout << "Constructor Called!" << std::endl;
	iCapacity = iSize + 2;
	ptr = new int[iCapacity];
	const_it = ptr;
	it = ptr;
	for (int i = 0; i < iSize; ++i)
	{
		ptr[i] = v;
	}
}


ivec::ivec(const ivec& rOb)
{
	//std::cout << "Copy constructor Called!" << std::endl;
	iSize = rOb.iSize;
	iCapacity = rOb.iCapacity;
	ptr = new int[iCapacity];
	const_it = ptr;
	it = ptr;

	for (int i = 0; i < iSize; ++i)
	{
		ptr[i] = rOb.ptr[i];
	}
}


ivec::~ivec()
{
	delete[] ptr;
	ptr = nullptr;
	const_it = ptr;
	//std::cout << "Destructor Called!" << std::endl;
}


ivec& ivec::operator=(const ivec& rOb)
{
	if (ptr != rOb.ptr)
	{
		iSize = rOb.iSize;
		iCapacity = iSize + 2;
		delete[] ptr;
		ptr = new int[iCapacity];
		const_it = ptr;
		it = ptr;

		for (int i = 0; i < iSize; ++i)
		{
			ptr[i] = rOb.ptr[i];
		}
	}
	return *this;
}


void ivec::reserve(const int& n)
{
	if (n > iCapacity)
	{
		delete[] ptr;
		ptr = new int[n];
		it = ptr;
		iCapacity = n;
	}
}


void ivec::resize(int n, int val)
{
	if (n >= iCapacity)
	{
		int* temp = new int[n + 2];
		for (int i = 0; i < iSize; ++i)
		{
			temp[i] = ptr[i];
		}

		delete[] ptr;
		ptr = temp;
		it = ptr;

		for (int i = iSize; i < n; ++i)
		{
			ptr[i] = val;
		}
		iSize = n;
		iCapacity = n + 2;
	}

	else if (n < iSize)
	{
		int* tmp = new int[iCapacity];
		for (int i = 0; i < n; ++i)
		{
			tmp[i] = ptr[i];
		}

		delete[] ptr;

		ptr = tmp;
		iSize = n;
		it = ptr;
	}

	else if (n >= iSize && n < iCapacity)
	{
		for (int i = 0; i < n - iSize; ++i)
		{
			push_back(val);
		}
		iSize = n;
	}
}


void ivec::push_back(const int& val)
{
	if (iSize == iCapacity)
	{
		int* temp = new int[iSize + 2];
		for (int i = 0; i < iSize; ++i)
		{
			temp[i] = ptr[i];
		}
		temp[iSize] = val;
		
		delete[] ptr;
		++iSize;
		iCapacity = iSize + 2;
		ptr = temp;
		it = ptr;
	}
	else
	{
		ptr[iSize] = val;
		++iSize;
	}
}


void ivec::pop_back()
{
	int* tmp = new int[iCapacity - 1];
	for (int i = 0; i < iSize - 1; ++i)
	{
		tmp[i] = ptr[i];
	}
	--iSize;

	delete[] ptr;
	ptr = tmp;

	it = ptr;
}


int& ivec:: operator[](const int& i) const
{
	return ptr[i];
}


int& ivec::at(int i) const
{
	if (i >= 0 && i < iSize)
	{
		return ptr[i];
	}
	else
	{
		throw std::out_of_range("error");
	}
}


int ivec::size() const
{
	return iSize;
}


int ivec::capacity() const
{
	return iCapacity;
}


bool ivec::empty() const
{
	return iSize == 0;
}


void ivec::clear()
{
	delete[] ptr;
	ptr = new int[iSize];
	iSize = 0;
	iCapacity = 0;
}


int& ivec::back() const
{
	return ptr[iSize - 1];
}


int& ivec::front() const
{
	return ptr[0];
};


ivec::iterator ivec::begin() const
{
	return it;
}


ivec::iterator ivec::end() const
{
	return &(it[iSize]);
}


ivec::iterator ivec::erase(iterator position)
{
	if (position < this->begin() || (position >= this->end()))
	{
		std::cout << "Can't erase this position's value" << std::endl;
		throw std::out_of_range("error");
	}
	else if (position == (ptr + iSize - 1))
	{
		--iSize;
	}
	else
	{
		auto it = (this->end());
		int* tmp = new int[iCapacity];
		while (ptr != position)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}
		
		++ptr;
		
		while (ptr != it)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}

		tmp -= iSize - 1;
		ptr -= iSize;
		--iSize;
		
		delete[] ptr;
		ptr = tmp;
		it = ptr;
	}
	return position;
}


ivec::iterator ivec::erase(iterator begin, iterator end)
{
	if (end > ptr + iSize || (begin < ptr) || (begin > end || begin == end))
	{
		std::cout << "Can't erase this positions value " << std::endl;
		throw std::out_of_range("error");
	}

	else
	{
		auto it = (this->end());
		int k = 0;

		int* tmp = new int[iCapacity];
		while (ptr != begin)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
			++k;
		}

		ptr = end;

		while (ptr != it)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
			++k;
		}

		tmp -= k;
		ptr -= iSize;
		iSize = k;

		delete[] ptr;
		ptr = tmp;
		it = ptr;
	}
	return end;
}


ivec::iterator ivec::insert(iterator position, const int& val)
{
	if (position < this->begin() || position > this->end())
	{
		std::cout << "Can't insert in this position" << std::endl;
		throw std::out_of_range("error");
	}

	else if (position == this->end() && iSize != iCapacity)
	{
		ptr[iSize] = val;
		++iSize;
	}
	else
	{
		auto it = (this->end());
		int* tmp = new int[iCapacity];
		while (ptr != position)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}

		*tmp = val;

		++tmp;
		while (ptr != it)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}

		tmp -= iSize + 1;
		ptr -= iSize;
		++iSize;

		delete[] ptr;
		ptr = tmp;
		it = ptr;
	}

	return position;
}


void ivec::insert(ivec::iterator position, const int& n, const int& val)
{
	if (position < this->begin() || position > this->end())
	{
		std::cout << "Can't insert in this position" << std::endl;
		throw std::out_of_range("error");
	}
	else
	{
		auto it = (this->end());
		int* tmp;

		if (iSize + n > iCapacity)
		{
			tmp = new int[iSize + n + 2];
		}
		else
		{
			tmp = new int[iCapacity];
		}

		while (ptr != position)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}

		for (int i = 0; i < n; ++i)
		{
			*tmp = val;
			++tmp;
		}

		while (ptr != it)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}

		tmp -= iSize + n;
		ptr -= iSize;

		delete[] ptr;
		ptr = tmp;

		iSize += n;
		iCapacity = n + 2;
		it = ptr;
	}
}


void ivec::insert(iterator position, iterator begin, iterator end)
{
	if (position < this->begin() || position > this->end())
	{
		std::cout << "Can't insert in this position" << std::endl;
		throw std::out_of_range("error");
	}
	else
	{
		int* tmp = nullptr;

		int n = 0;
		while (begin < end)
		{
			++begin;
			++n;
		}
		begin -= n;

		auto it = (this->end());
		if (iSize + n > iCapacity)
		{
			tmp = new int[iSize + n + 2];
		}
		else
		{
			tmp = new int[iCapacity];
		}

		 
		while (ptr != position)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}

		n = 0;
		while(begin < end)
		{
			*tmp = *begin;
			++begin;
			++tmp;
			++n;
		}


		
		while (ptr != it)
		{
			*(tmp) = *(ptr);
			++tmp;
			++ptr;
		}

		tmp -= iSize + n;
		ptr -= iSize;

		delete[] ptr;
		ptr = tmp;
		iSize += n;
		iCapacity = iSize + 2;
		it = ptr;
	}
}