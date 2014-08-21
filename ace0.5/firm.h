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
	firm (double money);
	// ������� �����
	double buy(offer& good, double& available, double& spent);
	void buy_raw(map<int, offer> &demand);
	//-----Labor-market-----//
	vector<int> checkresumes(vector<int> resumes);         //Check income resumes and select appropriate candidates   
	void hire(int id);                 //Hire final candidates 
	void hire(vector<int> ids);
	vector<int> fire();				   // Fire extra workers.
	void fire(int id);
	//-----Good-market-----//
	void getsales(int sold);//, int buyers);             //Get money from sales   
	//-----Production-----//
	void produce();
	void produce_raw();
	void produce_consume();
	// ������ ���������� � ���.
	void write_log(string model_name, int firm_id);
	//������ � ������� ����������
	int getstock();
	double getprice();
	double getsalary();
	int getsold();
	int getworkers();
	vector<int> getworkerids();
	double getmoney();
	double getprofit();
	int getdesired();
	double getaction();
	void printinfo();
	// �������� � ��������� �������� ���������� �� ���� ������.
	void learn(vector<vector<double>> rule_price, vector<vector<double>> rule_salary, vector<vector<double>> rule_plan);
	double set(vector<double> state, vector<vector<double>> rule);
	
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
	int _sold;
	vector <int> _workers_ids;
	int _resume_number;
	double _raw;
	double _bought;
//	int _buyers;
	//-----Calculations-----//
	double _money;
	double _profit;
	int _desired_workers;
	int _stock;
	// Rule learning.
	int get_state_profit();
	int get_state_sold();
	int get_state_workers();
	// Rule action.
	void set_price(int state);
	void set_salary(int state);
	void set_workers(int state);

};

bool is_in(int val, vector<int> x);
