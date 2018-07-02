#ifndef HAS_PTR_H
#define HAS_PTR_H

#include "compile_options.h"

#include <string>

using namespace  std;

#ifdef VALUE_SEMANTICS

#ifdef COPY_AND_SWAP
class HasPtr
{
public:
	friend void swap(HasPtr& lhs, HasPtr& rhs) noexcept;

	// T();   T("...");
	HasPtr(const string& s = string()) :
		_ps(new string(s)), i(0)
	{
	}

	HasPtr(const HasPtr& rhs) :
		_ps(new string(*rhs._ps)), i(rhs.i)
	{
	}

	HasPtr& operator =(HasPtr rhs__)
	{
		::swap(*this, rhs__);
		return *this;
	}

	bool operator >(const HasPtr& rhs) {
		return strcmp(	(*_ps).c_str(),	(*rhs._ps).c_str());
	}

	~HasPtr()
	{
		delete _ps;
	}
private:
	string*   _ps;
	int       i;
};

inline 
void swap(HasPtr& lhs, HasPtr& rhs) {
	std::swap(lhs._ps,rhs._ps);
	std::swap(lhs.i, rhs.i);
}


#else
class HasPtr
{
public:
	// T();   T("...");
	HasPtr(const string& s = string()) :
		_ps(new string(s)), i(0)
	{
	}

	HasPtr(const HasPtr& rhs) :
		_ps(new string(*rhs._ps)), i(rhs.i)
	{
	}

	HasPtr& operator =(const HasPtr& rhs)
	{
		auto newp = new string(*rhs._ps);
		delete _ps;
		_ps = newp;

		i = rhs.i;
		return *this;
	}

	~HasPtr()
	{
		delete _ps;
	}
private:
	string*   _ps;
	int       i;
};

#endif


#elif defined(REFERENCE_SEMANTICS)

class HasPtr {

public:
	class RefCounter {
	public:
		unsigned count = 0;
		void operator ++() {
			count++;
		}
		void operator --() {
			count--;
		}
		bool operator ==(const unsigned num) {
			return count == num;
		}
	};

	// ����ʱ��count++ -> 1
	// T();   T("...");
	HasPtr(const string& s = string()) :
		_ps(new string(s)), 
		i(0) 
	{
		_counter = new RefCounter;
		++(*_counter);
	}

	// ����ʱ����Ŀ��instance����counter
	HasPtr(const HasPtr& rhs) :
		_ps(rhs._ps), 
		i(rhs.i),
		_counter(rhs._counter)
	{
		++(*_counter);
	}

	HasPtr& operator =(const HasPtr& rhs) 
	{
		// ����ָ���Ը�ֵ������Դ=ԭ��Դ����������ȶ�����Դ��������+1���ٻ�ͷȥ����ԭ��Դ������ͷ�
		++(*rhs._counter);

		// ԭ��Դ���������-1
		--(*_counter);
		if (*_counter == 0) {
			delete _counter;
			delete _ps;
		}

		// ����Դ���������+1
		_counter = rhs._counter;
		_ps = rhs._ps;
		i = rhs.i;

		return *this;
	}

	// ����ʱ��count--. ��count=0,���ͷŹ���� string instance�� ref-counter instance
	~HasPtr() 
	{
		--(*_counter);
		if (*_counter == 0) {
			delete _counter;
			delete _ps;
		}
	}


private:
	RefCounter* _counter;
	string*   _ps;
	int       i;
};
#endif


#endif

