#pragma once
#include"Disc_quote.h"


class Bulk_quote :public Disc_quote
{
public:
    Bulk_quote() = default;
	using Disc_quote::Disc_quote;//继承Disc_quote的构造函数

Bulk_quote(const Bulk_quote& bulk_quote):Disc_quote(bulk_quote)
	{
		//cout << "Bulk_quote(const Bulk_quote& bulk_quote)" << endl;
	}
	Bulk_quote(Bulk_quote&& bulk_quote) noexcept :Disc_quote(std::move(bulk_quote))
	{
		//cout << "Bulk_quote(Bulk_quote&& bulk_quote) noexcept :Disc_quote(bulk_quote)" << endl;
	}
	Bulk_quote& operator=(const Bulk_quote& bulk_quote)
	{
		//cout << "Bulk_quote& operator=(const Bulk_quote& bulk_quote) 开始" << endl;
		this->~Bulk_quote();
		Disc_quote::operator=(bulk_quote);
		//cout << "Bulk_quote& operator=(const Bulk_quote& bulk_quote) 结束" << endl;
		return *this;
	}
	Bulk_quote& operator=(Bulk_quote&& bulk_quote)noexcept
	{
		//cout << "Bulk_quote& operator=(Bulk_quote&& bulk_quote)noexcept 开始" << endl;
		Disc_quote::operator=(std::move(bulk_quote));
		//cout << "Bulk_quote& operator=(Bulk_quote&& bulk_quote)noexcept 结束" << endl;
		return *this;
	}
	double net_price(size_t) const override;
	//分别显示每个类的数据成员
	void debug() const override
	{
		Quote::debug();
		cout << "min_qty:" << quantity << " discount:" << discount << " ";
	}
	Bulk_quote* clone() const & override
	{
		return new Bulk_quote(*this);
	}
	Bulk_quote* clone()&& override
	{
		return new Bulk_quote(std::move(*this));
	}
	virtual ~Bulk_quote() override
	{
		//cout << "virtual ~Bulk_quote() override" << endl;
	}



};