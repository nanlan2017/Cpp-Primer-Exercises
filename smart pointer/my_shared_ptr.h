#ifndef MY_SHARED_PTR
#define MY_SHARED_PTR

/*
 T : Ŀ����������
*/
template<typename T>
class shared_ptr
{
	//? 1. �����������Ĳ������͡���Ŀ��ȫ��ȷ���������ǡ��ɱ������  
	//? 2. ������Ҫ��ȫת����T�Ĺ��캯��
	shared_ptr<T>()
	{
		
	}

private:
	T* _ptr;
	unsigned count;
};
#endif

