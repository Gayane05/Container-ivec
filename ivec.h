#pragma once
#include <iostream>

class ivec
{
	using iterator = int*;
	using const_iterator = const int*;

	friend std::ostream& operator<<(std::ostream& out, const ivec& ob);
	friend std::istream& operator>>(std::ostream& in, ivec& ob);

private:
	int iSize;
	int* ptr = nullptr;
	int iCapacity;


public:
	
	iterator it = nullptr;
	const_iterator const_it = nullptr;

	ivec(const int& s = 0, const int& v = 0);
	ivec(const ivec& rOb);
	~ivec();

	ivec& operator=(const ivec& rOb);

	void reserve(const int&);
	void resize(int n, int val = 0);

	void push_back(const int& val);
	void pop_back();

	int& operator[](const int&) const;
	int& at(int i) const;

	int size() const;
	int capacity() const;

	bool empty() const;
	void clear();

	int& back() const;
	int& front() const;

	iterator begin() const;
	iterator end() const;

	iterator erase(iterator position);
	iterator erase(iterator begin, iterator end);

	iterator insert(iterator position, const int& val);
	void insert(iterator position, const int& n, const int& val);
	void insert(iterator position, iterator begin, iterator end);


};