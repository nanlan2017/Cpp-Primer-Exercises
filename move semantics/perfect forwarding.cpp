#include <iostream>

using namespace std;

void f2(int& m) { cout << "lvalue ref" << endl; }
void f2(int&& m) { cout << "rvalue ref" << endl; }
void f2(const int& m) { cout << "const lvalue ref" << endl; }
void f2(const int&& m) { cout << "const rvalue ref" << endl; }


template<typename T>
void f1(T&& t) 
{
	f2(forward<T>(t));
}

void f3(int&& t)
{
	
}


int main(int argc, char* argv[]) {
	int a;
	int b;
	const int c = 1;
	const int d = 0;

	f1(a);
	int&& r = a; // 右值引用不能绑定左值
	f3(a); // 右值引用不能绑定左值

	f1(move(b));
	f1(c);
	f1(move(d));
	system("pause");


	int&& kk = 3 + 5;
	f3(kk);
	kk = 4;
	f3(kk);
	f3(1 + 1);
}

void foo(int& m);


void bar()
{
	int m1 = 1;         // 左值
	int& m2 = m1;       // 左值引用
	int&& m3 = 4 + 5;   // 右值引用

	// 最多一个T后面只能跟两个&&
	typedef int& iR;
	typedef int&& iRR;

	iR a = m1;
	int& a2 = m1;

	 &iR & b = m1;		 // ▇▇ int&  & ——>  int&
	iR b2 = 1;           // b2是左值引用，不能绑定右值
	int&& b3 = m1;       // b3是右值引用,不能绑定左值
	iRR b4 = 1;

	iR && c = m1;        // ▇▇ int&  && ——> int&
	iR && c2 = 1;
	int& && c3 = m1;	 // "reference to reference is not allowded"

	iRR & d = m1;        // ▇▇ int&&  & ——> int&

	iRR && e = m1;
	iRR && e2 = 1;       // ▇▇ int&&  && ——> int&&
}

