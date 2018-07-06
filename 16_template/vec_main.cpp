/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       02  Feb 2014
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
//!
//! Exercise 16.16:
//! Rewrite the StrVec class (§ 13.5, p. 526) as a template named Vec.
//!
//? 书中的 Blob<T>内部数组组织使用vector实现。
//? 而 书中实现的vector 是用 动态数组+allocator实现。
//? “动态数组”，就是用new T[] 建立在堆内存上的数组。（但你只能通过几个T类型的指针去定位它，而不能用下标）

#include "vec.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    Vec<int> v = {1,2,3,4,5};

    Vec<int> v2;

    v2 = v;
    std::cout << v2.capacity() << "\n";
    v2.push_back(99);
    v2.resize(2,2);

    for (auto t : v2)
        std::cout << t << " ";


    std::cout << v2.capacity() << "\n";

    return 0;
}

//template<typename T, U, typename K> void f1();

template<class T>
struct Deleter
{
    void operator()(T* p) 
    {
        delete[] p;
    }
};

