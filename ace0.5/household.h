#pragma once

#include <vector>
#include <map>
#include <iostream>

#include "stdlib.h"

#include "offer.h"

using namespace std;

class household
{
public:
	//������������ ������
	household(void);
	household(double money);
	//���������� �� ����� �����
	vector<int> searchwork(map<int, double> labordemand);
	int chooseemployee(vector<int> proposals, map<int, double> labordemand);
	//��������� ������

	/*������*/
	void work(); 
	void quit();

	/*������� �� �����������*/
	void gethelp();

	//���������� �� ����� �������
	double consumptionbudget();
	void buy_goods(map<int, offer> &demand, map<int,offer> &supply);
	void buy(offer& good, double& available, double& spent);
	//������ � ������� ����������
	bool is_employed();
	int get_employee();
	double getsalary();
	double getmoney();
	double getreservation();
	double getconsumption();
	int get_starve();
	int get_fed();
	void set_fed(int fed);
	void set_salary(double salary);
	void printinfo();
	void step();


private:
	//������� �������
	double _salary;
	bool _employed;
	bool _active;
	int _employee;
	//���������� ����������
	double _money;
	double _reservation_wage;
	double _consumption_budget;
	double _mean_income;
	// Entry & exit parameters
	int _starve;
	int _fed;
	int _t;
};

