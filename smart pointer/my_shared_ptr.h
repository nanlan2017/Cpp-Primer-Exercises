#ifndef MY_SHARED_PTR
#define MY_SHARED_PTR

/*
 T : 目标对象的类型
*/
template<typename T>
class shared_ptr
{
	//? 1. 这个构造参数的参数类型、数目完全不确定，所以是“可变参数”  
	//? 2. 参数是要完全转发给T的构造函数
	shared_ptr<T>()
	{
		
	}

private:
	T* _ptr;
	unsigned count;
};
#endif

