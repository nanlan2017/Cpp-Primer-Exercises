#include <iostream>
using namespace std;

/*******************************************************
//x ��
//? Ϊʲô

//TODO move:��һ����ֵǿ��תΪ��ֵ�����䡮û�á�����ɽӹܡ���> ������rvalue�βε��ƶ�����/�ƶ���ֵ
//TODO ��ʱ���Ǹ�instance���������Ҫ��û�á��ˣ���move()һ�·ϵ�����

//TODO  ����ɽӹܵ���Դ����ֵold����,��moveһ����ƥ��ӹܣ�  new( move(old) );    new = move(old);
//TODO  ����ɽӹܵ���Դ��rvalue���֣� new( <-temp);
������������������������������������������������������������������������������������������������������������*/

// HasPtrMemͨ�� Res* ����һ��������Res���󸱱���
class HasPtrMem
{
	using Res = int;
public:
	HasPtrMem() :_d(new Res(0)) {}

	HasPtrMem(const HasPtrMem& rhs) :
		_d(new Res(*rhs._d))
	{
	}

	// �ÿ��Խӹܵ�instance ������ʱ��Res "��Ϊ����"
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

	// �ÿ��Խӹܵ�instance ����ֵ����ʱ��Res "��Ϊ����"
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
	HasPtrMem a = getTemp(); // �������죡
	HasPtrMem b;
	b = a;                   // ������ֵ
	HasPtrMem c(move(a));	 // ��aת�ɡ��ɽӹܵġ���ֵ��ȥƥ�䡰�ӹܹ��캯������
	*a._d;
}

/*
HugeMem������ǡ����ƶ�����
�~�~ ���ƶ����캯��/�ƶ���ֵ����  �����˸����͵�instance2 �ӹ� instance1�� ������Ϊ��ʽ��
�~�~ ������ָ����е�Res������ͨ��ָ�뻻�� �ӹܣ�
�~�~ ����ֱ��T���е���Դ����ͨ����T�Ͷ����Դ��� �ƶ���ʽ�����ƶ�����û����Ļ�,��ƥ�俽����
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
		_elements(new int(*rhs._elements)) // ��̬���鲻�����������ġ�����
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
		res(1024)	//TODO �Ҳ���������д����ָ��ֵ������������ָ���乹���������
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
T f(){  return obj; }  ��  T ret(obj); ����ret�����ʱ����
�~�~�~ ���obj�����ְ���������ֵ��
*/
Moveable getTemp2()
{
	Moveable temp = Moveable(); // Ĭ�Ϲ���+ �ƶ�����
	return temp;                // �~�~�~�~�~ �������ж�temp�ǽ���ֵ��������temp ����> 'ret' ���ƶ�
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
void forwardValue(T& val) // lvalue reference:ֻ������ֵ
{
	__processValue(val); //��ֵ����������ֵ
}

template <typename T>
void __processValue(T&& val) // universal reference: �ɽ�����ֵ/��ֵ
{
}

int main()
{
	int&& t = 1; // t������һ����ֵ��  t��һ����ֵ��
	forwardValue(t);
	int k = 1;	// k��һ����ֵ
	forwardValue(k);
	forwardValue(1); // 

	int i = 1;
	__processValue(i);
	__processValue(1);
	return 0;
}


