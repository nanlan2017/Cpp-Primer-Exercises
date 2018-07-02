#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>

using namespace std;

// 是共享堆上的一个 vector<string> 的Wrapper类
class StrBlob
{
public:
	using size_type = vector<string>::size_type;

	StrBlob() :
		_data(make_shared<vector<string>>()){ }

	// C++ 11新增了‘列表初始化’//TODO
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

