
#include <memory>


// array是一个类型为_Ty的数组的引用。（别名）
template<typename _Ty,unsigned SIZE> constexpr 
unsigned getSize(const _Ty(&array)[SIZE]) // 这样去接受数组（实例化时就能确定数组类型、长度）
{
	return SIZE;
}


