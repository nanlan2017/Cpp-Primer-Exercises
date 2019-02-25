


//X *********************************************************************************************************************
//? 就因为C++里很多参数/返回采用T形式的对象的值传递，就不得不控制对象的拷贝/移动构造、赋值
//? 同时，由于对象既可能在栈上，也可能在堆上，就要考虑指针/引用的对象的生命周期。

//? 实际上我在java里从没用过clone()去拷贝一个instance：那里的instance都是放在堆上的，
//? Java里的'引用变量'就是shared_ptr.
//  什么时候需要主动去 拷贝一个instance呢？  除非是值持有语义的两个实例，一个需要拷贝另一个的资源（业务功能意义上）

//  同时，如果堆上的共享的instance都由 shared_ptr去访问它，则也不需要担心释放了。 这个资源只有make_shared才会创建，不会被拷贝了。
//X *********************************************************************************************************************

template <bool Condition,typename Then, typename Else>
struct  IF
{
	typedef Then RET;
};

template <typename Then, typename Else>
struct  IF<false,Then,Else>
{
	typedef Else RET;
};

int main(int argc, char* argv[])
{
	IF<(1 + 2 > 4), short, int>::RET i;
}
