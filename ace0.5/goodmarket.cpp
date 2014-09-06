#include "goodmarket.h"


goodmarket::goodmarket(void)
{
}

void goodmarket::set_supply(map<int, offer> supply)
{
	_supply = supply;
	_demand = supply;
}

map<int, double> goodmarket::get_sales()
{
	map<int, double> sales;
	for (map<int, offer>::iterator i = _supply.begin(); i != _supply.end(); ++i)
	{
		double stock = (i->second).get_count();
		double unsold = get_count(i->first, _demand);
		sales[i->first] = stock - unsold;
	}
	return sales;
}

map<int, int> goodmarket::get_buyers()
{
	map<int, int> buyers;
	for (map<int, offer>::iterator i = _supply.begin(); i != _supply.end(); ++i)
	{
		buyers[i->first] = (i->second).get_buyers();
	}
	return buyers;
}

void goodmarket::clear()
{
	_supply.clear();
	_demand.clear();
}

