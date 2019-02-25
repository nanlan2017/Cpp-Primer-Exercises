#include <string>
#include <iostream>

using namespace std;

#define Print_Type(obj) do{std::cout << typeid(obj).name() << std::endl;}while(0)

//x 接受任意类型、长度的数组的引用

template<typename T, unsigned N>
void print2(const T(*parray)[N]) // parray:一个指针，指向类型为Tval,长度为N的const数组
{
	Print_Type(T);
	Print_Type(parray);
	
	for (unsigned i=0; i< N; i++) { //TODO 竟然无法打印？！！
		cout << *parray << endl;
		++parray;
	}
	cout <<"----------------------------------"<< endl;
	
}

template <typename T, unsigned N> 
void print_array(const T (&arr)[N])
{
	Print_Type(T);
	Print_Type(arr);
	
    /*for (const auto& elem : arr) {
        std::cout << elem;
		std::cout << std::endl;
    }*/
	cout <<"----------------------------------"<< endl;

}

template<typename Arr>
void print(Arr const& arr)
{
	Print_Type(Arr);
	Print_Type(arr);

    for (auto const& elem : arr)
        std::cout << elem << std::endl;

	cout <<"----------------------------------"<< endl;
}

// the same as std::begin
template<typename T, unsigned size>
T* begin_def(T(&arr)[size])
{
	Print_Type(arr);
    return arr;
}


// the same as std::end
template<typename T, unsigned size>
T* end_def(T (&arr)[size])
     //We usually don't use a function name which is the same as the function of standard libary
     //This should not be const
{
	Print_Type(arr);
    return arr + size;
}

int main_16_4()
{
    std::string s[] = { "ssss", "aaa", "ssssss" };
    char c[] = { 'a', 'b', 'c', 'd' };
    int  i[] = { 1,2,3 };

    print(i);
    print(c);
    print(s);
	cout <<"===================================================="<< endl;
	print_array(i);
    print_array(c);
    print_array(s);
	cout <<"===================================================="<< endl;
	print2(&i);
    print2(&c);
    print2(&s);
	
    return 0;
}

int main_16_5()
{
    std::string s[] = { "sssss","ss","ss","ssssszzzz" };
    std::cout << *(begin_def(s)+1) << std::endl;
    std::cout << *(end_def(s) - 1) << std::endl;
    return 0;
}

int main(int argc, char* argv[])
{
	main_16_5();
	system("pause");
}
