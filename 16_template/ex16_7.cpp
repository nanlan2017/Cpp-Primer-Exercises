
#include <memory>


// array��һ������Ϊ_Ty����������á���������
template<typename _Ty,unsigned SIZE> constexpr 
unsigned getSize(const _Ty(&array)[SIZE]) // ����ȥ�������飨ʵ����ʱ����ȷ���������͡����ȣ�
{
	return SIZE;
}


