#include "Bulk_queto.h"


//覆盖基类的函数版本以实现基于大量购买的折扣政策
double Bulk_quote::net_price(size_t cnt) const 
{
	if (cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}