#ifndef STRVEC_H
#define STRVEC_H

#include <string>

using namespace std;

/************************************************
ʵ��һ��Vector��ֻ�ܱ���string
���ڲ�ʹ�ö�̬�������������ݡ�
�����Զ����ݵ�������ʹ��allocator��
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
	void chk_n_alloc()           // ��֤����������һ��Ԫ�صĿռ�
	{	if (size()==capacity()) reallocate();	}

	                             // �����ڴ棬������������Χ�ڵ�Ԫ��
	pair<string*, string*> alloc_n_copy(const string*, const string*);

	void free();                 // �ͷŵ�ǰ�ڴ�
	void reallocate();           // ���·��������ڴ棬����������Ԫ�ع�ȥ

	allocator<string> alloc;	 // 4�����ܣ�allocate(),deallocate();  construct(),destroy()

	string* _elments;            // ָ��̬��������Ԫ��
	string* _first_free;         // ָ���������һ��Ԫ��
	string* _cap;                // ָ��̬����ĩβ��

};

#endif

