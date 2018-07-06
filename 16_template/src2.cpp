//=====================================
// Name        : CppPrimer.cpp
// Author      : Caroline
// Version     : 1.0
// Description : Example, UTF-8
//=====================================
 
/*eclipse cdt, gcc 4.8.1*/
 
#include <iostream>
#include <vector>
#include <cstring>


//   https://blog.csdn.net/caroline_wendy/article/details/17219921#
using namespace std;
 
//����ģ��
template<unsigned N, unsigned M>
bool compare (const char (&p1)[N], const char (&p2)[M])
{
	std::cout << "size : " << N << " " << M << std::endl;
	return strcmp(p1, p2);
}
 
//ָ��
template<const char* C>
void pointerT(const char* str){
	std::cout << C << " " << str << std::endl;
}
 
//����
template<char (&ra)[9]>
void referenceT(const char* str){
	std::cout << ra << " " << str << std::endl;
}

//����ָ��
template<void (*F)(const char*)>
void fpointerT(const char* c) {
	F(c);
}

char ca[] = "Caroline"; //��ʼ��ָ��
char cr[9] = "Caroline"; //��ʼ������, ����һ����β����
void foo(const char* c) {std::cout << c << std::endl; }
 
int main(void)
{
	if(compare("Caroline", "Wendy")) {
		std::cout << "Caroline is long." << std::endl;
	} else {
		std::cout << "Wendy is long." << std::endl;
	}
 
	//�޷�ʹ�þֲ��������߶�̬������Ϊģ�����
	pointerT<ca>("Wendy"); //ָ��
 
	referenceT<cr>("Wendy"); //����
 
	fpointerT<foo>("Caroline Wendy"); //����ָ��
 
	return 0;
}
/*********************************************************
size : 9 6
Caroline is long.
Caroline Wendy
Caroline Wendy
Caroline Wendy
*********************************************************/


