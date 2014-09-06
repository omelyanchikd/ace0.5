#include "firms.h"


firms::firms(void)
{
}

firms::firms(int n, double money, string model_name, int start)
{
	for (int i = start; i < n + start; i++)
	{
		_firms[i+1] = (firm(money));
	}
	ofstream fout;
	ostringstream fn;
	for (int i = start + 1; i < n + start + 1; i++)
	{
		fn<<model_name<<"_salary"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";
		fout.close();
		fn.str("");
		fn<<model_name<<"_price"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";
		fout.close();
		fn.str("");;
		fn<<model_name<<"_sold"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";
		fout.close();
		fn.str("");
		fn<<model_name<<"_workers"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
		fn<<model_name<<"_money"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";	
		fout.close();
		fn.str("");
		fn<<model_name<<"_profit"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
		fn<<model_name<<"_desired"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
		fn<<model_name<<"_stock"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
	}
	fn<<model_name<<"_average_price.txt";
	fout.open(fn.str(), ios::trunc);
    fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_average_salary.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_gdp.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_consumption.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_production.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_firm_number.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
}

firms::firms(int n, double money, double productivity, string model_name, int start)
{
	for (int i = start; i < n + start; i++)
	{
		_firms[i+1] = (firm(money, productivity));
	}
	ofstream fout;
	ostringstream fn;
	for (int i = start + 1; i < n + start + 1; i++)
	{
		fn<<model_name<<"_salary"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";
		fout.close();
		fn.str("");
		fn<<model_name<<"_price"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";
		fout.close();
		fn.str("");;
		fn<<model_name<<"_sold"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";
		fout.close();
		fn.str("");
		fn<<model_name<<"_workers"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
		fn<<model_name<<"_money"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";	
		fout.close();
		fn.str("");
		fn<<model_name<<"_profit"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
		fn<<model_name<<"_desired"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
		fn<<model_name<<"_stock"<<"_firm_"<<i<<".txt";
		fout.open(fn.str(), ios::trunc);
		fout<<"";		
		fout.close();
		fn.str("");
	}
	fn<<model_name<<"_average_price.txt";
	fout.open(fn.str(), ios::trunc);
    fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_average_salary.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_gdp.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_consumption.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_production.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
	fn<<model_name<<"_firm_number.txt";
	fout.open(fn.str(), ios::trunc);
	fout<<"";
	fout.close();
	fn.str("");
}

void firms::buy_raw(map<int, offer> &demand, map<int, offer> &supply)
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
			(i->second).buy_consume(demand, supply);			
	}
}

map<int, double> firms::set_vacancies()
{
	map<int, double> vacancies;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
//		if ((i->second).getworkers() < (i->second).getdesired())
//		{
			vacancies[i->first] = (i->second).getsalary();			
//		}
	}
	return vacancies;
}

vector<int> firms::fire()
{
	vector<int> fired;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		if ((i->second).getworkers() > (i->second).getdesired())
		{
			vector<int> decision = (i->second).fire();
			fired.insert(fired.end(),decision.begin(), decision.end());
			decision.clear();
		}
	}
	return fired;
}

map<int, vector<int>> firms::check_resumes(map<int, vector<int>> resumes)
{
	map<int, vector<int>> invites;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		invites[i->first] = (i->second).checkresumes(resumes[i->first]);
	}
	return invites;
}

void firms::hire(map<int, vector<int>> employers)
{
	vector<int> ids;
	ids.clear();
	ids = get_firm_ids();
	for (int i = 0; i < ids.size(); i++)
	{
		if (employers.find(ids[i]) != employers.end())
		{
			_firms[ids[i]].hire(employers[ids[i]]);
		}
	}
}

void firms::produce()
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).produce();
	}
}

void firms::produce_raw()
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).produce_raw();
	}
}

void firms::produce_consume()
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).produce_consume();
	}
}

map<int, offer> firms::set_supply()
{
	map<int, offer> supply;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		supply[i->first] = offer((i->second).getprice(), (i->second).getstock());
	}
	return supply;
}

void firms::get_sales(map<int, double> sales)
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).getsales(sales[i->first]);
	}
}

void firms::get_buyers(map<int, int> buyers)
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).get_buyers(buyers[i->first]);
	}
}

void firms::learn(vector<vector<double>> rules_price, vector<vector<double>> rules_salary, vector<vector<double>> rules_plan)
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).learn(rules_price, rules_salary, rules_plan);
	}
}

void firms::learn_raw(int household_number, double consumption, double total)
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).learn_raw(household_number, consumption, total);
	}
}

void firms::learn_consume(int household_number, double consumption, double total)
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).learn_consume(household_number, consumption, total);
	}
}

void firms::write_log(string model_name)
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		(i->second).write_log(model_name, i->first);
		//_log.setfirmaction(i->first, (i->second).getaction());
	}	
	ofstream fout;
	ostringstream fn;
	fn<<model_name<<"_average_price.txt";
	fout.open(fn.str(), ios_base::app);
	fout<<average_price()<<" ";;
	fout.close();
	fn.str("");
	fn<<model_name<<"_average_salary.txt";
	fout.open(fn.str(), ios_base::app);
	fout<<average_salary()<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_gdp.txt";
	fout.open(fn.str(), ios_base::app);
	fout<<gdp()<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_consumption.txt";
	fout.open(fn.str(), ios_base::app);
	fout<<consumption()<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_production.txt";
	fout.open(fn.str(), ios_base::app);
	fout<<production()<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_firm_number.txt";
	fout.open(fn.str(), ios_base::app);
	fout<<firm_number()<<" ";
	fout.close();
	fn.str("");
}

void firms::clear()
{
	_firms.clear();
}

void firms::print_info()
{
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		cout<<"Firm "<<i->first<<": "<<endl;
		(i->second).printinfo();
	}
}

double firms::production()
{
	double sum = 0;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		sum += (i->second).getstock(); // * (i->second).getprice();
	}
	return sum;
}

double firms::consumption()
{
	double sum = 0;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		sum += (i->second).getsold();
	}
	return sum;
}

double firms::average_price()
{
	double sum = 0;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		sum += (i->second).getprice();
	}
	return sum/firm_number();
}

double firms::average_salary()
{
	double sum = 0;
	int workers = 0;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		sum += (i->second).getsalary() * (i->second).getworkers();
		workers += (i->second).getworkers();
	}
	return sum/workers;
}

double firms::gdp()
{
	double sum = 0;
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		sum += (i->second).getprice() * (i->second).getstock();
	}
	return sum;
}

int firms::firm_number()
{
	return _firms.size();
}

vector<int> firms::get_firm_ids()
{
	vector<int> ids;
	ids.clear();
	for (map<int, firm>::iterator i = _firms.begin(); i != _firms.end(); ++i)
	{
		ids.push_back(i->first);
	}
	return ids;
}