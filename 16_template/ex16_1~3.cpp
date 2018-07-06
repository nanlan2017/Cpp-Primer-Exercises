#include <string>

//x 习题16.1.1 模板实例化的含义？
/*
实例化 instantiation(不同于初始化initial-ize), 
是指 template function被使用时，根据实参来推断出其template arguments，并使用此推断值代替模板参数，得到一个普通定义的过程。
*/

//X compare
template<typename Ty>
//constexpr 
int compair(const Ty& v1,const Ty& v2)
{
	if (v1 < v2) return -1;
	if (v1 > v2) return 1;
	return 0;
}

