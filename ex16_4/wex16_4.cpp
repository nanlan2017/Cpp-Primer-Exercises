#include <vector>
#include <string>

using namespace std;

using T_Iter = vector<int>::iterator;
T_Iter& find(T_Iter& begin,const T_Iter& end, int val)
{
	for (; begin != end && *begin != val; ++begin);
	return begin;
}


