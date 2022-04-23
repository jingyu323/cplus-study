#include "Basket.h"

//打印每本书的总价和购物篮中所有书的总价
double Basket::total_receipt(ostream& os) const
{
	double sum = 0.0;	//保存实时计算出的总价格
	//iter指向ISBN相同的一批元素中的第一个
	//uper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
	//for (auto iter = items.cbegin(); iter != items.cend(); ++iter)
	{
		//我们知道在当前的Basket中至少有一个该关键字的元素
		//打印该书籍对应的项目
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale:" << sum << endl;	//打印最终的总价格
	return sum;
}