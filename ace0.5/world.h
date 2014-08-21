#pragma once

#include "firms.h"
#include "households.h"

#include "labormarket.h"
#include "goodmarket.h"

#include "macro.h"

#include "offer.h"

#include "scenario.h"

#include <vector>
#include <map>

class world
{
public:
	
	world(void);
	world(int firmnuumber, int householdnumber, double firmmoney, double householdmoney, scenario choice, string model_name);
	world(int firmnuumber, int householdnumber, double firmmoney, double householdmoney, scenario choice, string model_name, string rules_price, string rules_salary, string rules_plan);
	
	void step();

	void printinfo();

//	data _log;
	macro _statistics;

private:

	firms _firms_consume;
	firms _firms_raw;
	households _households;
	
	labormarket _labormarket;
	goodmarket _goodmarket;
	goodmarket _rawmarket;

	vector<vector<double>> _rules_price;
	vector<vector<double>> _rules_salary;
	vector<vector<double>> _rules_plan;

	scenario _scenario;

	string _model;
	
	void get_statistics();		// ���������� �������� �������������� �����������.

};

