#ifndef _WJH_COMMON_
#define _WJH_COMMON_

/******************************************************************************************
	= Java里对任何返回类型T,都可以return null;  我要的就是这么个 null

设计思路：
	我给你一个类型T，
	你帮我维护一个T类型的instance，它是在堆上唯一的，且提供==判断某个实例是否为它。

作用：
	提供一个T类型的空对象（代表状态为空的T型对象）。
1. 在堆上构造一个T类型的instance
2. 任何需要返回 “空T” 的地方，都引用此instance
3. 

T& foo() {
	return *(T*)0; // 消除编译警告，但不安全。
}
===========================================================================================
T& foo() {
	return NULL_OBJ<T>.ret(); // 消除编译警告,且引用的是安全的对象。
}

T t = foo();
if(t== 【t-null】){
	
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
	当程序中使用 NullInstance<Dog> nullDog 时，
	内存中就有了NullInstance<Dog>::theOnly这个全局指针变量
	*/
	T* theOnly = nullptr;

private:
};


/*===============================  本模块的测试样例  =========================================*/

// 判断它们是否同时引用的这个“空实例”
template<typename T> inline
bool operator==(T& instance, NullInstance<T>&& nullobj) {
	return &instance == nullobj.theOnly;
}

void usecase__NullInstance();

}

#endif // _WJH_COMMON_