#pragma once

#include "offer.h"

#include <vector>
#include <map>

using namespace std;

class goodmarket
{
public:
	goodmarket(void);

	void set_supply(map<int, offer> supply);	

	map<int,double> get_sales();

	map<int, int> get_buyers();

	map<int, offer> _demand;
	map<int, offer> _supply;

	void clear();

};

