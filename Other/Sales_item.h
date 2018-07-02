#ifndef _SALES_ITEM_H_
#define _SALES_ITEM_H_

#include "common_tools.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_item
{
public:
	Sales_item() = default;

	Sales_item& operator =(const Sales_item& rhs) {

		return *(Sales_item*)0;
	}

	Sales_item& operator +=(const Sales_item& rhs) {

		return *(Sales_item*)0;
	}

	friend Sales_item operator +(const Sales_item& lhs,const Sales_item& rhs);
	friend istream&  operator >> (istream& cin, Sales_item& book);
	friend ostream& operator <<(ostream& cout,const Sales_item& book);

private:
	string isbn;    // 书ISBN
	double price;   // 单价
	int amount;     // 数量
	double money;   // 总价
};

inline 
istream&  operator >>(istream& cin, Sales_item& book) {
	cin >> book.isbn;
	cin >> book.price;
	cin >> book.amount;
	return cin;
}

inline
ostream& operator<<(ostream& cout, const Sales_item& book) {

	return *(ostream*)0;
}

/*=========================================================================*/
inline
void usecase_Sales_item() {
	Sales_item book;
	cin >> book;
	//cout << book << endl();
}

#endif // _SALES_ITEM_H_

