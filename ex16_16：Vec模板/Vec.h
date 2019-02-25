#ifndef VEC_H
#define VEC_H

#include <memory>
#include <vector>
#include <string>

using namespace std;

/*

*/
template<typename T>
class Vec
{
public:
	//? types
	using size_type = typename allocator<T>::size_type;
		

	//? 6 basics
	//? ���캯���еĴ����������ꡰ����Ա��Ĭ�ϳ�ʼ��������ߵģ�
	Vec() :
		_elements(nullptr),
		_first_free(nullptr),
		_cap(nullptr){ }

	Vec(initializer_list<T> il)
	{
		// �ȷ��乻��Ŀռ�
		auto count = il.size();
		T* begin = _elements = _first_free = alloc.allocate(count);
		_cap = _elements + count;

		// �����list���Ԫ���ƶ����˿�
		auto iter = il.begin();
		for (size_type i =0; i<count; ++i) {
			alloc.construct(begin++, move(*iter++));
		}
	}

	Vec(const Vec& rhs)
	{
		auto pair = alloc_new_copy(rhs.begin, rhs.end());
		_elements = pair.first;
		_cap = _first_free = pair.second;
	}

	Vec& operator =(const Vec& rhs);
	~Vec() { free(); }

	//? operators
	T* operator [](size_type idx) const { return _elements + idx; }

	//? const
	size_type capacity() const { return _cap - _elements; }
	size_type size() const { return _first_free - _elements; }
	T* begin() const { return _elements; }
	T* end() const { return _cap; }

	//? modifier
	void push_back(const T& t)
	{
		chk_need_alloc();
		alloc.construct(_first_free++, t);
	}

	//? 

private:
	T* _elements;
	T* _first_free;
	T* _cap;

	/*
	4�����ܽӿڣ�
		allocate: ����Count��Ԫ�صĿռ䣬�����׵�ַ��
		construct:  ��ĳ��λ�ã�T*������T���͵Ĺ����������һ��Tʵ��
		destroy: ����ĳ��λ�õ�Tʵ��
		deallocate: �ջ���ĳ��λ��Ϊ��ͷ��Count��Ԫ�صĿռ�
	*/
	static allocator<T> alloc;

	void chk_need_alloc()
	{
		if (size() == capacity()) reAllocate();
	}

	void reAllocate()
	{
		size_type count = size();
		auto newStart = alloc.allocate(2*count);
		// copy��Ч�ʵ͡���ط�ԭ������Դ��û�ã������ͷţ��������ƶ���
		/*
		uninitialized_copy_n(_elements, size(), newStart);
		free();
		*/
		T* src = _elements;
		T* dest = newStart;
		for(size_type i=0; i<count;++i) {
			alloc.construct(dest++, move(*src++));
		}
		free();
		_elements = newStart;
		_first_free = _elements + count;
		_cap = _elements + 2 * count;
	}

	void free()
	{
		if (_elements) {
			//destory��Ԫ�أ�Ȼ��deallocate���ռ�
			for (auto pt = _elements; pt < _first_free; ++pt) {
				alloc.destroy(pt);
			}
			alloc.deallocate(_elements, _cap - _elements);
		}
	}

	// ����b,e����������Ԫ�ؿ���һ�ݡ����µ�һ������һ����
	pair<T*, T*> alloc_new_copy(T* b, T* e)
	{
		auto data = alloc.allocate(e - b);
		return {data, uninitialized_copy(b,e,data) };
	}

	//? friends
};

#endif


