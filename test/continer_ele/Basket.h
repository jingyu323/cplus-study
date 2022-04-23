#pragma once
#include<iostream>
#include<string>
#include<set>
//#include"Quote.h"
#include "Bulk_queto.h"
#include "print_total.sh"
using namespace std;

class Basket
{
public:

//Basket使用合成的默认构造函数和拷贝控制成员
	void add_item(const shared_ptr<Quote>& sale)
	{
		s.insert(sale);
	}
	//打印每本书的总价和购物篮中所有书的总价
	double total_receipt(ostream&) const;
	void add_item(const Quote& sale)	//拷贝给定的对象
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote&& sale)	//移动给定对象
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}
private:
	//该函数用于比较shared_ptr,multiset成员会用到它
	static bool compare(const shared_ptr<Quote>& lhs,
		const shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}
	//multiset保存多个报价，按照compare成员排序
	multiset<shared_ptr<Quote>, decltype(compare)*> items{ compare };

};