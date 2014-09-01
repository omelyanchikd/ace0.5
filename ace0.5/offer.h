#pragma once

#include <map>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/discrete_distribution.hpp>

using namespace std;

class offer
{
public:
	offer(void);
	offer(double price, double count): _price(price), _count(count)
	{
	}
	double get_price();
	double get_count();
	
	void set_count(double count);

	int getid();

private:
	double _count;
	double _price;
};

int get_random(map<int, offer> good);

double get_count(int firmid, map<int, offer> good);

bool can_buy(double money, map<int, offer> good);

