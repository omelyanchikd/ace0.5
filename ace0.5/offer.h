#pragma once

#include <map>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/discrete_distribution.hpp>

using namespace std;

class offer
{
public:
	offer(void);
	offer(double price, double count);
	double get_price();
	double get_count();
	int get_buyers();
	
	void set_count(double count);

	int getid();

	void new_buyer();

private:
	double _count;
	double _price;
	int _buyers;
};

int get_random(map<int, offer> good);

double get_count(int firmid, map<int, offer> good);

bool can_buy(double money, map<int, offer> good);

