#include <string>

//x ϰ��16.1.1 ģ��ʵ�����ĺ��壿
/*
ʵ���� instantiation(��ͬ�ڳ�ʼ��initial-ize), 
��ָ template function��ʹ��ʱ������ʵ�����ƶϳ���template arguments����ʹ�ô��ƶ�ֵ����ģ��������õ�һ����ͨ����Ĺ��̡�
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

