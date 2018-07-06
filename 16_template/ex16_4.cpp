#include <vector>
#include <initializer_list>

using namespace std;

template<typename T_Iter,typename T_Val>
auto find(const T_Iter& begin,const T_Iter& end,T_Val val)
{
	for (; begin != end && *begin != val; ++begin);
	return begin;

}

void main_16_3()
{
	initializer_list<int> ini{3,5};
	vector<int> ivec;
	ivec.assign(ini);



	vector<int>::iterator& iter = ivec.begin();
}