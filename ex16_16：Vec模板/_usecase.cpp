#include "Vec.h"
#include <iostream>

int main(int argc, char* argv[])
{
	//X 新建Vec，其中有10个元素
	Vec<int> veci{ 1,2,3 };

	//X 添加元素，使其这块内存不够。自动重新分配个2倍大的内存，并拷贝元素过去
	veci.push_back(4);

	//X 随时按下标访问vec中的元素
	auto iter = veci.begin();
	while (iter!= veci.end()) {
		cout << *iter << endl;
	}


	//? 接受一个谓词，可遍历此Vec种的元素、对每个元素进行操作（如打印）
	//vec.traverseAct([]() {std::cout<<});
}
