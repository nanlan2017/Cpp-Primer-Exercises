#ifndef _WJH_COMMON_
#define _WJH_COMMON_

/******************************************************************************************
	= Java����κη�������T,������return null;  ��Ҫ�ľ�����ô�� null

���˼·��
	�Ҹ���һ������T��
	�����ά��һ��T���͵�instance�������ڶ���Ψһ�ģ����ṩ==�ж�ĳ��ʵ���Ƿ�Ϊ����

���ã�
	�ṩһ��T���͵Ŀն��󣨴���״̬Ϊ�յ�T�Ͷ��󣩡�
1. �ڶ��Ϲ���һ��T���͵�instance
2. �κ���Ҫ���� ����T�� �ĵط��������ô�instance
3. 

T& foo() {
	return *(T*)0; // �������뾯�棬������ȫ��
}
===========================================================================================
T& foo() {
	return NULL_OBJ<T>.ret(); // �������뾯��,�����õ��ǰ�ȫ�Ķ���
}

T t = foo();
if(t== ��t-null��){
	
}
******************************************************************************************/

// *(Type*)0
#define NULLOBJ(Type) *(Type*)0
#include <iostream>

namespace wjh 
{

template<typename T>
class NullInstance {
public:

	NullInstance() {
		if (theOnly == nullptr) {
			theOnly = new T();
		}
		std::cout << "the \"master" << typeid(T).name() << "\" intance just created @" << theOnly << std::endl;
	}

	//static
	T& get() {
		return *theOnly;
	}

	// if(t == Null)
	friend bool operator==(T& instance,NullInstance<T>&& nullobj);


	/*
	��������ʹ�� NullInstance<Dog> nullDog ʱ��
	�ڴ��о�����NullInstance<Dog>::theOnly���ȫ��ָ�����
	*/
	T* theOnly = nullptr;

private:
};


/*===============================  ��ģ��Ĳ�������  =========================================*/

// �ж������Ƿ�ͬʱ���õ��������ʵ����
template<typename T> inline
bool operator==(T& instance, NullInstance<T>&& nullobj) {
	return &instance == nullobj.theOnly;
}

void usecase__NullInstance();

}

#endif // _WJH_COMMON_