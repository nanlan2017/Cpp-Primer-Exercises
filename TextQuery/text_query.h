#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <iostream>

using namespace std;


/*
指针成员变量：以下划线开头命名
*/
class QueryResult;

class TextQuery {
	using line_no = vector<string>::size_type;
public:
	TextQuery(ifstream& fin);
	QueryResult query(const string& word);

private:
	/*
	拷贝肯定是垃圾的，大家访问的都是同一个instance

	方案（一）：
	这个大data应该放堆上，为各个栈所共享。

	方案（二）：
	放在 前面/底层方法的栈上，然后按引用传给后面/上层的函数。
	最后会在底层执行完后自行清栈销毁。
	*/
	
	shared_ptr<vector<string>> _file;
	shared_ptr<map<string, set<line_no>>> _wm;
	//map<string, shared_ptr<set<line_no>>> _wm;
	//shared_ptr<map<string, shared_ptr<set<line_no>>>> _wm;
};

class QueryResult {
	using line_no = vector<string>::size_type;
public:
	string word;
	set<line_no>::size_type count;
	shared_ptr<set<line_no>> _lines;
	shared_ptr<vector<string>> _file;
};

void runQueries(ifstream& fin);

void print(const QueryResult& qs);

#endif

