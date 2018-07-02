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
ָ���Ա���������»��߿�ͷ����
*/
class QueryResult;

class TextQuery {
	using line_no = vector<string>::size_type;
public:
	TextQuery(ifstream& fin);
	QueryResult query(const string& word);

private:
	/*
	�����϶��������ģ���ҷ��ʵĶ���ͬһ��instance

	������һ����
	�����dataӦ�÷Ŷ��ϣ�Ϊ����ջ������

	������������
	���� ǰ��/�ײ㷽����ջ�ϣ�Ȼ�����ô�������/�ϲ�ĺ�����
	�����ڵײ�ִ�����������ջ���١�
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

