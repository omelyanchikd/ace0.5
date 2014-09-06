#pragma once

#include <vector>
#include <map>

#include <fstream>
#include <sstream>

#include "household.h"

using namespace std;

class households
{
public:
	// ������������.
	households(void);
	households(int n, double money, string model_name);
	// ����� �����.
	map<int, vector<int>> search_work(map<int,double> vacancies);
	map<int, vector<int>> choose_employee(map<int, vector<int>> invites, map<int, double> vacancies);
	void quit(vector<int> fired);
	void update_salary(map<int, double> salaries);
	// ������������.
	void get_income();
	// ����� �������.
	void buy(map<int, offer> &demand, map<int, offer> &supply);
	// �������� ����������.
	void write_log(string model_name);
	// ����� ����������.
	void print_info();
	// �������.
	void clear();
	// ����������.
	double unemployment();
	int household_number();
	double consumption();
	// Entry & exit of households
	void die();
	void birth();
	// Timelim
	void step();
private:
	map<int, household> _households;
	int _last_id;
};

