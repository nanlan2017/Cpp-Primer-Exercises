/*
//例子2：
template<class T,int MAXSIZE> class List{
private:
	T elems[MAXSIZE];  
public:
	void Print(){ cout<<"The maxsize of list is "<<MAXSIZE; }
};
 
const int num1 = 9; ;//全局变量
static int num2= 9; ;//全局变量
const int num3 = 9; ;//局部变量
 
List<int,num1> list; //正确
List<int,num2> list2; //错误
List<int,num3> list3; //正确
 
//再看一个关于指针和字符串比较特别的例子
//例子3：
template<char const* name>
class pointerT{
 
};
 char a[] = "saaa";;//全局变量
 char a2[] = "saaa";;//局部变量，写在main函数里面
 char *b = "saaa";//全局变量
 char *const c = "saaa";//全局变量，顶层指针，指针常量
 
 
pointerT<"testVarChar">  p1;//错误
 
pointerT<a>  p2;//正确
pointerT<a2>  p22;//错误，局部变量不能用作非类型参数
pointerT<b>  p3;//错误，error C2975:“pointerT”的模板参数无效，应为编译时常量表达式
pointerT<c>  p4;//错误，error C2970: “c”: 涉及带有内部链接的对象的表达式不能用作非类型参数
*/