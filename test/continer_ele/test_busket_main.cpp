#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <algorithm>

#include "Basket.h"

using namespace std;

int main(int argc, char** argv)//
{
	//打开文件（存放Quote对象的数据）
	if (argc != 2)
	{
		cerr << "文件名错误" << endl;
		return -1;
	}
	ifstream in("15.28.txt");
	if (!in)
	{
		cerr << "打开文件失败" << endl;
		return -1;
	}
	Basket basket;
	string isbn_price;//存储一行的内容
	//将每一行存入vector容器中
	while (getline(in, isbn_price))
	{
		stringstream isbn_price2(isbn_price);
		string isbn;
		double price;
		size_t quantity;
		double discount;
		isbn_price2 >> isbn >> price >> quantity >> discount;
		//basket.push_back(make_shared<Bulk_quote>(isbn, price, quantity, discount));
		basket.add_item(Bulk_quote(isbn, price, quantity, discount));
	}
	in.close();//关闭文件

	basket.total_receipt(cout);
	return 0;
}