#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>

using namespace std;

// �ǹ�����ϵ�һ�� vector<string> ��Wrapper��
class StrBlob
{
public:
	using size_type = vector<string>::size_type;

	StrBlob() :
		_data(make_shared<vector<string>>()){ }

	// C++ 11�����ˡ��б��ʼ����//TODO
	StrBlob(initializer_list<string> il):
		_data(make_shared<vector<string>>())
	{
		_data->assign(il);
	}


	size_type size() const
	{
		return _data->size();
	}

	bool empty() const
	{
		return _data->empty();
	}


private:
	shared_ptr<vector<string>> _data;
};


#endif

