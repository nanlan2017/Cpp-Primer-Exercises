#ifndef STRVEC_H
#define STRVEC_H

#include <string>

using namespace std;

/************************************************
实现一个Vector，只能保存string
其内部使用动态数组来保存数据。
具有自动扩容的能力（使用allocator）
************************************************/
class StrVec
{
	using size_t = unsigned int;
public:

	StrVec() :_elments(nullptr), _first_free(nullptr), _cap(nullptr){}
	StrVec(const StrVec& copyobj);
	StrVec& operator =(const StrVec& right);
	~StrVec();

	void push_back(string& str);

	size_t size() const { return _cap - _first_free; }
	size_t capacity() const {	return _cap - _elments;	}
	string* begin() const {	return _elments;	}
	string* end() const {	return _first_free;	}
	
private:
	void chk_n_alloc()           // 保证至少有容纳一个元素的空间
	{	if (size()==capacity()) reallocate();	}

	                             // 分配内存，并拷贝给定范围内的元素
	pair<string*, string*> alloc_n_copy(const string*, const string*);

	void free();                 // 释放当前内存
	void reallocate();           // 重新分配更大的内存，并拷贝现有元素过去

	allocator<string> alloc;	 // 4个功能：allocate(),deallocate();  construct(),destroy()

	string* _elments;            // 指向动态数组中首元素
	string* _first_free;         // 指向空闲区第一个元素
	string* _cap;                // 指向动态数组末尾后

};

#endif

