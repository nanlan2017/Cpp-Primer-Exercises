#ifndef BLOB_H
#define BLOB_H

#include <memory>
#include <vector>
#include <iostream>

using namespace std;

//? Blob��һ��������������ʵ����һ��vector��Wrapper
//? BlobPtr ����������ķ����������ʾ���vector��iteratorһ����

template<typename T> class BlobPtr;

/*
//? ��shared_ptrʵ�� pointer-like
		���Blob�ײ��vector��Դ�ǿ����ɶ��Blob������ģ�
*/
template<typename T>
class Blob
{
public:
	//? types
	typedef typename vector<T>::size_type size_type;

	//? 6 basics
	// Ĭ�Ϲ���
	Blob():
		_data(make_shared<vector<T>>()){ }

	Blob(initializer_list<T> il):
		_data(make_shared<vector<T>>(il)){ }

	//x ����/�ƶ����졢������ֵ���ƶ���ֵ������pointer-like�Ķ�����˵������shared_ptr��Ĭ����Ϊ�Ϳ��ԣ�����ֱ�Ӹ�ֵ��

	~Blob() = default;
	
	//? operators

	//? const
	size_type size() const { return _data->size(); }
	bool empty() const { return _data->empty(); }
	vector<T>& data() const { return *_data; }

	// ��ȡ�ľ��Ƕ����Ǹ����󣬿�ֱ�Ӳ����������ǿ���������
	T& front()
	{
		check(0, "front on empty blob");
		return _data->front();
	}
	T& back()
	{
		check(0, "back on empty blob");
		return _data->back();
	}

	BlobPtr<T> begin() const
	{
		return BlobPtr<T>(_data);
	}

	const BlobPtr<T> cbegin() const //? ������ʱ����Ļ�����Ϊ�ö����ṩ���ƶ����캯���ˣ����մ�Ҳ���Կ����������������ð󶨾��У�
	{
		return BlobPtr<T>(_data);
	}

	BlobPtr<T> end() const
	{
		return BlobPtr<T>(_data,size());
	}

	const BlobPtr<T> cend() const
	{
		return BlobPtr<T>(_data,size());
	}

	//? modifiers
	void push_back(const T& t){ _data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty blob");
		_data->pop_back();
	}

private:
	shared_ptr<vector<T>> _data;

	// ���data[i]���Ϸ����򷵻ش�����Ϣ��msg
	void check(size_type i, const string& msg) const
	{ if (i >= size()) { throw out_of_range(msg); } }

	//? friends
};

#endif

