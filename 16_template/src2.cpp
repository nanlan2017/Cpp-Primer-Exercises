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
 
//整型模板
template<unsigned N, unsigned M>
bool compare (const char (&p1)[N], const char (&p2)[M])
{
	std::cout << "size : " << N << " " << M << std::endl;
	return strcmp(p1, p2);
}
 
//指针
template<const char* C>
void pointerT(const char* str){
	std::cout << C << " " << str << std::endl;
}
 
//引用
template<char (&ra)[9]>
void referenceT(const char* str){
	std::cout << ra << " " << str << std::endl;
}

//函数指针
template<void (*F)(const char*)>
void fpointerT(const char* c) {
	F(c);
}

char ca[] = "Caroline"; //初始化指针
char cr[9] = "Caroline"; //初始化引用, 包含一个结尾符号
void foo(const char* c) {std::cout << c << std::endl; }
 
int main(void)
{
	if(compare("Caroline", "Wendy")) {
		std::cout << "Caroline is long." << std::endl;
	} else {
		std::cout << "Wendy is long." << std::endl;
	}
 
	//无法使用局部变量或者动态变量作为模板参数
	pointerT<ca>("Wendy"); //指针
 
	referenceT<cr>("Wendy"); //引用
 
	fpointerT<foo>("Caroline Wendy"); //函数指针
 
	return 0;
}
/*********************************************************
size : 9 6
Caroline is long.
Caroline Wendy
Caroline Wendy
Caroline Wendy
*********************************************************/


