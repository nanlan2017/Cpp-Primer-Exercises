#include "Vec.h"
#include <iostream>

int main(int argc, char* argv[])
{
	//X �½�Vec��������10��Ԫ��
	Vec<int> veci{ 1,2,3 };

	//X ���Ԫ�أ�ʹ������ڴ治�����Զ����·����2������ڴ棬������Ԫ�ع�ȥ
	veci.push_back(4);

	//X ��ʱ���±����vec�е�Ԫ��
	auto iter = veci.begin();
	while (iter!= veci.end()) {
		cout << *iter << endl;
	}


	//? ����һ��ν�ʣ��ɱ�����Vec�ֵ�Ԫ�ء���ÿ��Ԫ�ؽ��в��������ӡ��
	//vec.traverseAct([]() {std::cout<<});
}
