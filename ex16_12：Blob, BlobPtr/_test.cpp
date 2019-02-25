#include "Blob.h"
#include "BlobPtr.h"

int main(int argc, char* argv[])
{
	initializer_list<int> il{2,5,8,3,0};
	Blob<int> intBlob(il);

	BlobPtr<int> ibptr = intBlob.begin();

	// const�� �Ѷ�ʧ�� �����ʽ��Ϊconst������ר�ŵĺ�����
	auto endIter = intBlob.end();
	while (ibptr != endIter) {	//? ���ʹ const T �Ķ���� non-const�Ķ��� �в��ȣ� ��û�б�Ҫ��
		cout << *ibptr;
		++ibptr;
	}
	system("pause");
}
