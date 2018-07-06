#include <iostream>
using namespace std;

/*******************************************************
//x 付
//? 为什么

//TODO move:把一个左值强制转为右值：让其‘没用’、变可接管——> 以适配rvalue形参的移动构造/移动赋值
//TODO 有时你那个instance并不是真的要‘没用’了，你move()一下废掉它。

//TODO  如果可接管的资源以左值old出现,就move一下以匹配接管：  new( move(old) );    new = move(old);
//TODO  如果可接管的资源以rvalue出现： new( <-temp);
——————————————————————————————————————————————————————*/

// HasPtrMem通过 Res* 持有一个独立的Res对象副本。
class HasPtrMem
{
	using Res = int;
public:
	HasPtrMem() :_d(new Res(0)) {}

	HasPtrMem(const HasPtrMem& rhs) :
		_d(new Res(*rhs._d))
	{
	}

	// 用可以接管的instance 来构造时：Res "移为己用"
	HasPtrMem(HasPtrMem&& rTemp) noexcept:
		_d(rTemp._d)
	{
		rTemp._d = nullptr;
	}

	HasPtrMem& operator =(const HasPtrMem& rhs)
	{
		Res* newRes = new Res(*rhs._d);
		delete _d;
		_d = newRes;
		return *this;
	}

	// 用可以接管的instance 来赋值给我时：Res "移为己用"
	HasPtrMem& operator =(HasPtrMem&& rTemp) noexcept
	{
		delete _d;
		_d = rTemp._d;
		rTemp._d = nullptr;
		return *this;
	}

	~HasPtrMem() { delete _d; }

	Res* _d;
};

HasPtrMem getTemp()
{
	return HasPtrMem();
}


void main1()
{
	HasPtrMem a = getTemp(); // 拷贝构造！
	HasPtrMem b;
	b = a;                   // 拷贝赋值
	HasPtrMem c(move(a));	 // 将a转成“可接管的”右值，去匹配“接管构造函数”。
	*a._d;
}

/*
HugeMem类对象是“可移动”的
▇▇ 其移动构造函数/移动赋值函数  定义了该类型的instance2 接管 instance1的 具体行为方式。
▇▇ 对于用指针持有的Res，可以通过指针换向 接管；
▇▇ 对于直接T持有的资源，可通过该T型对象自带的 移动方式进行移动。（没定义的话,就匹配拷贝）
*/

class HugeMem
{
public:
	HugeMem(int sz) :
		size(sz>0 ? sz : 1),
		_elements(new int[size])
	{
	}

	HugeMem(const HugeMem& rhs) :
		size(rhs.size),
		_elements(new int(*rhs._elements)) // 动态数组不是这样拷贝的。。。
	{
		for (int i = 1, *iter = _elements; i<size; i++) {
			iter = new int(*(rhs._elements + i));
		}
	}

	HugeMem(HugeMem&& rTemp) noexcept:
		size(rTemp.size),
		_elements(rTemp._elements)
	{
		rTemp._elements = nullptr;
	}

	~HugeMem() { delete[] _elements; }

	int size;
	int* _elements;
};


class Moveable
{
public:
	Moveable() :
		_i(new int(3)),
		res(1024)	//TODO 我擦！括号里写的是指定值啊！（类类型指定其构造参数！）
	{
	}	

	//Moveable(const Moveable& rhs) = default;

	Moveable(Moveable&& rTemp) noexcept:
		_i(rTemp._i),
		res(move(rTemp.res))
	{
		rTemp._i = nullptr;
	}

	~Moveable()
	{
		delete _i;
	}

	int* _i;
	HugeMem res;
};


/*
T f(){  return obj; }  则  T ret(obj); 生成ret这个临时变量
▇▇▇ 这个obj有名字啊，不是左值吗？
*/
Moveable getTemp2()
{
	Moveable temp = Moveable(); // 默认构造+ 移动构造
	return temp;                // ▇▇▇▇▇ 编译器判断temp是将亡值（？），temp ——> 'ret' 是移动
}

void main2()
{
	cout << is_rvalue_reference<decltype(getTemp2())>::value << endl;
	Moveable a(getTemp2()); // 
}

int main3(int argc, char* argv[]) {
	main2();

	typedef const int T;
	typedef T& TR;
	TR& v = 1;

	return 0;
}


template <typename T>
void forwardValue(T& val) // lvalue reference:只接受左值
{
	__processValue(val); //右值参数会变成左值
}

template <typename T>
void __processValue(T&& val) // universal reference: 可接受左值/右值
{
}

int main()
{
	int&& t = 1; // t引用了一个右值。  t是一个左值。
	forwardValue(t);
	int k = 1;	// k是一个左值
	forwardValue(k);
	forwardValue(1); // 

	int i = 1;
	__processValue(i);
	__processValue(1);
	return 0;
}


