#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "stdlib.h"

#include "offer.h"

using namespace std;

class firm 
{

public:

	//-----Constructor-----//
	firm(void);
	firm(double money);
	firm(double money, int desired, double productivity);
	// ������� �����
	double buy(offer& good, double& available, double& spent);
	void buy_consume(map<int, offer> &demand, map<int, offer> &supply);
	//-----Labor-market-----//
	vector<int> checkresumes(vector<int> resumes);         //Check income resumes and select appropriate candidates   
	void hire(int id);                 //Hire final candidates 
	void hire(vector<int> ids);
	vector<int> fire();				   // Fire extra workers.
	void fire(int id);
	//-----Good-market-----//
	void getsales(double sold);             //Get money from sales  
	void get_buyers(int buyers);
	//-----Production-----//
	void produce();
	void produce_raw();
	void produce_consume();
	// ������ ���������� � ���.
	void write_log(string model_name, int firm_id);
	//������ � ������� ����������
	double getstock();
	double getprice();
	double getsalary();
	double getsold();
	int getworkers();
	vector<int> getworkerids();
	double getmoney();
	double getprofit();
	int getdesired();
	double get_raw_money();
	double get_bought();
	double getaction();
	void printinfo();
	// �������� � ��������� �������� ���������� �� ���� ������.
	void learn(vector<vector<double>> rule_price, vector<vector<double>> rule_salary, vector<vector<double>> rule_plan);
	void learn_raw(int household_number, double consumption, double production, double gdp, double consumed);
	void learn_consume(int household_number, double consumption, double production, double gdp, double consumed);
	double set(vector<double> state, vector<vector<double>> rule);
	// ������
	double pay_tax(double tax);
	// Timer
	void step();
	
private:
	
	//-----Exogenous-parameters-----//
	double _elasticity; 
	double _productivity;
	double _raw_need;
	//-----Parameters-----//
	double _price;
	double _salary;
	double _plan;
	//-----Reaction-----//
	double _sold;
	vector <int> _workers_ids;
	int _resume_number;
	double _raw;
	double _bought;
	int _buyers;
	//-----Calculations-----//
	double _money;
	double _profit;
	int _desired_workers;
	double _stock;
	// Rule learning.
	int get_state_profit();
	int get_state_sold();
	int get_state_workers();
	// Rule action.
	void set_price(int state);
	void set_salary(int state);
	void set_workers(int state);
	// Part of sold
	double _salary_money;
	double _raw_money;
	// Learning
	vector<double> _sales;
	double sum_sales();
	// Timer
	int _t;


};

bool is_in(int val, vector<int> x);
