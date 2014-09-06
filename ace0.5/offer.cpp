#include "offer.h"

boost::mt19937 random_generator(1000);

offer::offer(void)
{
	_count = 0;
	_price = 0;
	_buyers = 0;
}

offer::offer(double price, double count)
{
	_price = price;
	_count = count;
	_buyers = 0;
}

void offer::new_buyer()
{
	_buyers++;
}

double offer::get_price()
{
	return _price;
}

double offer::get_count()
{
	return _count;
}

int offer::get_buyers()
{
	return _buyers;
}

double get_count(int firmid, map<int, offer> good)
{
	for (map<int,offer>::iterator i = good.begin(); i != good.end(); ++i)
	{
		if (i->first == firmid)
			return ((i->second).get_count());
	}
	return 0;
}

// Разобраться с генератором псевдослучайных чисел.
int get_random(map<int, offer> good)
{
	vector<double> probabilities;
	for(map<int, offer>::iterator i = good.begin(); i != good.end(); ++i)
	{
		probabilities.push_back(1/(i->second).get_price());
	}
	boost::random::discrete_distribution<> get_rand(probabilities.begin(), probabilities.end());
	return get_rand(random_generator);
}

bool can_buy(double money, map<int, offer> good)
{
	for (map<int,offer>::iterator i = good.begin(); i != good.end(); ++i)
	{
		if (money >= (i->second).get_price())
			return true;
	}
	return false;
}

void offer::set_count(double count)
{
	_count = count;
}