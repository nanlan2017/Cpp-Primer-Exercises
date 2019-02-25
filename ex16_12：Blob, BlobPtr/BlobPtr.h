#ifndef BLOB_PTR_H
#define BLOB_PTR_H

#include <memory>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
相当于Blob中的一个元素
*/

template<typename T>
bool operator !=(const BlobPtr<T>& ptr1, const BlobPtr<T>& ptr2);

template<typename T>
class BlobPtr
{
public:
	//? types
	using size_type = typename vector<T>::size_type;

	//? 6 basics
	BlobPtr(shared_ptr<vector<T>> sp):
		_wptr(sp),
		cur(0){ }

	BlobPtr(shared_ptr<vector<T>> sp,size_type idx):
		_wptr(sp),
		cur(idx){ }

	//? operators
	operator bool()
	{
		return true;
	}
	// 指向下一个元素
	BlobPtr& operator++()  { cur++; return *this; }
	// 解引用
	T& operator *() const
	{
		auto sp = _wptr.lock();
		if (sp) {
			return (*sp)[cur];
		} else {
			throw std::runtime_error("unbounded BlobPtr !");
		}
	}

	//? const

	//? modifier
	

private:
	//x 这份资源我也要能访问它。但其生存期的管理（shared_ptr）我不能插手。这就是weak_ptr的定位
	weak_ptr<vector<T>> _wptr;
	size_t cur;

	//? friends
	friend class Blob<T>;

	// Blob<int> 有友元： f(int);
	/*
	friend bool operator ==(BlobPtr<T>& ptr1, BlobPtr<T>& ptr2);
	friend bool operator !=(BlobPtr<T>& ptr1, BlobPtr<T>& ptr2);
	*/
	friend bool operator ==<T>(const BlobPtr<T>& ptr1, const BlobPtr<T>& ptr2);
	friend bool operator !=<T>(const BlobPtr<T>& ptr1, const BlobPtr<T>& ptr2);
};

// 两个iterator相等： 同一collection的同一元素
/*
template<typename T>
bool operator ==(BlobPtr<T>& ptr1, BlobPtr<T>& ptr2)
{
	return ptr1->cur == ptr2->cur;
}

template<typename T>
bool operator !=(BlobPtr<T>& ptr1, BlobPtr<T>& ptr2)
{
	return ptr1->cur != ptr2->cur;
}
*/
template<typename T>
bool operator ==(const BlobPtr<T>& ptr1, const BlobPtr<T>& ptr2)
{
	return ptr1->cur == ptr2->cur;
}
template<typename T>
bool operator !=(const BlobPtr<T>& ptr1, const BlobPtr<T>& ptr2)
{
	//? 检验两个weak_ptr指向同一个对象？
	return ptr1.cur != ptr2.cur;
}
#endif


