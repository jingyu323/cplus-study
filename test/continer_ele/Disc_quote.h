#pragma once
#include"Quote.h"

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
    
Disc_quote(const std::string& book, double price, std::size_t qty, double disc)
		:Quote(book, price), quantity(qty), discount(disc) 
	{
		//cout << "Disc_quote(const std::string& book, double price, std::size_t qty, double disc):Quote(book, price), quantity(qty), discount(disc) " << endl;		
	}
	//拷贝控制成员
	Disc_quote(const Disc_quote& disc_quote):Quote(disc_quote)
	{
		//cout << "Disc_quote(const Disc_quote& disc_quote):Quote(disc_quote)"<<endl;
		this->quantity = disc_quote.quantity;
		this->discount = disc_quote.discount;
	}
Disc_quote(Disc_quote&& disc_quote) noexcept :Quote(std::move(disc_quote))
	{
		//cout << "Disc_quote(Disc_quote&& disc_quote) noexcept :Quote(std::move(disc_quote))" << endl;
		this->quantity = std::move(disc_quote.quantity);
		this->discount = std::move(disc_quote.discount);
	}
	Disc_quote& operator=(const Disc_quote& disc_quote)
	{
		//cout << "Disc_quote& operator=(const Disc_quote& disc_quote) 开始" << endl;
		this->~Disc_quote();
		Quote::operator=(disc_quote);
		this->quantity = disc_quote.quantity;
		this->discount = disc_quote.discount;
		//cout << "Disc_quote& operator=(const Disc_quote& disc_quote) 结束" << endl;
		return *this;
	}
	Disc_quote& operator=(Disc_quote&& disc_quote) noexcept
	{
		//cout << "Disc_quote& operator=(Disc_quote&& disc_quote) noexcept 开始"<<endl;
		this->~Disc_quote();
		Quote::operator=(std::move(disc_quote));
		this->quantity = std::move(disc_quote.quantity);
		this->discount = std::move(disc_quote.discount);
		//cout << "Disc_quote& operator=(Disc_quote&& disc_quote) noexcept 结束" << endl;
		return *this;
	}
	double net_price(std::size_t)const = 0;	//纯虚函数
	virtual ~Disc_quote() override
	{
		//cout << "virtual ~Disc_quote()" << endl;
	}

    protected:
	std::size_t quantity = 0;	//折扣使用的购买量
	double discount = 0.0;	//表示折扣的小数值    


};