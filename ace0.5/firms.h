#pragma once

#include <map>
#include <vector>
#include <fstream>

#include "firm.h"

#include "offer.h"

using namespace std;

class firms
{
public:
	// ������������.
	firms(void);
	firms(int n, double money, string model_name, int start);
	firms(int n, double money, double productivity, string model_name, int start);
	// ����� �����.
	void buy_raw(map<int, offer> &demand, map<int, offer> &supply);
	// ����� �����.
	map<int, double> set_vacancies();
	vector<int> fire();
	map<int, vector<int>> check_resumes(map<int, vector<int>> resumes);
	void hire(map <int, vector<int>> employers);
	// ������������.
	void produce();
	void produce_raw();
	void produce_consume();
	// ����� �������.
	map<int,offer> set_supply();
	void get_sales(map<int, double> sales);
	void get_buyers(map<int, int> buyers);
	// ��������.
	void learn(vector<vector<double>> rule_price, vector<vector<double>> rule_salary, vector<vector<double>> rule_plan);
	void learn_raw(int household_number, double consumption, double total);
	void learn_consume(int household_number, double consumption, double total);
	// ����� ����������.
	void print_info();
	// �������� ����������.
	void write_log(string model_name);
	// �������.
	void clear();
	vector<int> get_firm_ids();
	// ����������.
	double production();
	double consumption();
	double average_price();
	double average_salary();
	double gdp();
//	double inflation();
	int firm_number();

private:
	map<int, firm> _firms;
};

