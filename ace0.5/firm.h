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
	firm(double money, double productivity);
	// Закупка сырья
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
	// Запись информации в лог.
	void write_log(string model_name, int firm_id);
	//Доступ к частной информации
	double getstock();
	double getprice();
	double getsalary();
	double getsold();
	int getworkers();
	vector<int> getworkerids();
	double getmoney();
	double getprofit();
	int getdesired();
	double getaction();
	void printinfo();
	// Обучение и изменение основных параметров на базе правил.
	void learn(vector<vector<double>> rule_price, vector<vector<double>> rule_salary, vector<vector<double>> rule_plan);
	void learn_raw(int household_number, double consumption, double total);
	void learn_consume(int household_number, double consumption, double total);
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

};

bool is_in(int val, vector<int> x);
