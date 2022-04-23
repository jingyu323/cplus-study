#pragma once
#include<iostream>
#include<string>

using namespace std;

class Quote
{
    public:
	Quote() = default;

    Quote(const string& book, double sales_price)
		:bookNo(book), price(sales_price)
	{
		//cout << "Quote(const string& book, double sales_price):bookNo(book), price(sales_price)" << endl;		
	}
    //拷贝控制成员
	Quote(const Quote& quote)
	{
		cout << "Quote(const Quote& quote)" << endl;
		this->bookNo = quote.bookNo;
		this->price = quote.price;
	}
Quote(Quote&& quote)noexcept
	{
		//cout << "Quote(Quote&& quote) noexcept" << endl;
		this->bookNo = std::move(quote.bookNo);
		this->price = std::move(quote.price);
	}

	Quote& operator=(const Quote& quote)
	{
		//cout << "Quote& operator=(const Quote& quote)"<<endl;
		this->~Quote();
		this->bookNo = quote.bookNo;
		this->price = quote.price;
		return *this;
	}
	Quote& operator=(Quote&& quote) noexcept
	{
		//cout << "Quote& operator=(Quote&& quote) noexcept" << endl;
		this->~Quote();
		this->bookNo = std::move(quote.bookNo);
		this->price = std::move(quote.price);
		return *this;
	}
    string isbn() const { return bookNo; }
	//返回给定数量的书籍的销售总额
	//派生类负责改写并使用不同的折扣计算方法
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
	//分别显示每个类的数据成员
	virtual void debug() const
	{
		cout << "bookNo:" << bookNo << "  price:" << price << " ";
	}
	//virtual ~Quote() = default;	//对析构函数进行动态绑定
	virtual ~Quote()
	{
		//cout << "virtual ~Quote()" << endl;
	}
	//该虚函数返回当前对象的一份动态分配的拷贝
	virtual Quote* clone() const &
	{
		return new Quote(*this);
	}
	virtual Quote* clone()&&
	{
		return new Quote(std::move(*this));
	}
    private:
	string bookNo;	//书籍的ISBN号
    protected:
	double price = 0.0;




};