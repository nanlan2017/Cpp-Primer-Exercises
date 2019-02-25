#ifndef BLOB_PTR_H
#define BLOB_PTR_H

#include <memory>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
�൱��Blob�е�һ��Ԫ��
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
	// ָ����һ��Ԫ��
	BlobPtr& operator++()  { cur++; return *this; }
	// ������
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
	//x �����Դ��ҲҪ�ܷ����������������ڵĹ���shared_ptr���Ҳ��ܲ��֡������weak_ptr�Ķ�λ
	weak_ptr<vector<T>> _wptr;
	size_t cur;

	//? friends
	friend class Blob<T>;

	// Blob<int> ����Ԫ�� f(int);
	/*
	friend bool operator ==(BlobPtr<T>& ptr1, BlobPtr<T>& ptr2);
	friend bool operator !=(BlobPtr<T>& ptr1, BlobPtr<T>& ptr2);
	*/
	friend bool operator ==<T>(const BlobPtr<T>& ptr1, const BlobPtr<T>& ptr2);
	friend bool operator !=<T>(const BlobPtr<T>& ptr1, const BlobPtr<T>& ptr2);
};

// ����iterator��ȣ� ͬһcollection��ͬһԪ��
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
	//? ��������weak_ptrָ��ͬһ������
	return ptr1.cur != ptr2.cur;
}
#endif


