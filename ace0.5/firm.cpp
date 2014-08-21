#include "firm.h"


firm::firm(void)
{
	//-----Exogenous parameters-----//
	_elasticity = 0; 
	_productivity = 0;
	_raw_need = 4;
	_price = 5;
	//-----Parameters-----//
	_price = 0;
	_salary = 0;
	_plan = 0;
	//-----Reaction-----//
	_sold = 0;
	_resume_number = 0;
	_raw = 0;
//	_buyers = 0;
	_bought = 0;
	//-----Calculations-----//
	_money = 0;
	_profit = 0;
	_desired_workers = 0;
}

firm::firm(double money)
{
	//-----Exogenous parameters-----//
	_elasticity = -1.5; 
	_productivity = 5;
	_raw_need = 4;
	//-----Parameters-----//
	_salary = 10;
	_plan = 0;
	_price = 5;//_salary/_productivity * ( 1 / (1 + 1 / _elasticity));
	//-----Reaction-----//
	_sold = 0;
	_resume_number = 0;
	_raw = 0;
//	_buyers = 0;
	_bought = 0;
	//-----Calculations-----//
	_money = money;
	_profit = 0;
}

void firm::buy_raw(map<int, offer> &demand)
{ 
	_raw = 0;
	_bought = 0;
	double available = _raw_need * _workers_ids.size(), spent = 0;
	while ((spent < _raw_need * _workers_ids.size()) && (demand.size() > 0))
    {
        map<int,offer>::iterator j = demand.begin();
		int rand = get_random(demand);
		for (int i = 0; i < rand; i++)
		{
			j++;
		}
        _bought += buy(j->second, available, spent);
		if ((j->second).get_count() == 0)
		{
			demand.erase(j);
		}
    }
	_raw = spent;
}

double firm::buy(offer& good, double& available, double& spent)
{
	if (good.get_count() >= available)
	{
		spent += available;
		good.set_count(good.get_count() - available);
		return available * good.get_price();
	/*	spent += floor(available/good.get_price()) * available;
		good.set_count(good.get_count() - floor(available/good.get_price()));	//*/	
	}
	else
	{
		spent += good.get_count();
		available -= good.get_count();
		double bought = good.get_count() * good.get_price();
		good.set_count(0);
		return bought;
		
	}
	return 0;
}

vector<int> firm::checkresumes(vector<int> resumes)
{
   _resume_number = resumes.size();
   vector <int> invite;
   for (int i = 0; i < resumes.size(); i++)
   {
	   if (is_in(resumes[i], _workers_ids))
		   invite.push_back(resumes[i]);
   }
   _workers_ids.clear(); 
   int _workers = invite.size();
   if (_desired_workers > _workers)
   {
	   if (resumes.size() == 0)
          return resumes;
       do
       {
           int j = rand()/(double)RAND_MAX * (resumes.size() - 1);		      
           invite.push_back(resumes[j]);
           resumes.erase(resumes.begin() + j);
       }
       while ((invite.size() < resumes.size()) && (invite.size() < _desired_workers - _workers));
   }
   return invite;
}

void firm::hire(vector<int> ids)
{
	for (int i = 0; i < ids.size(); i++)
	{
		_workers_ids.push_back(ids[i]);
	}
}

void firm::hire(int id)
{
	_workers_ids.push_back(id);	
}

vector<int> firm::fire()
{
	vector<int> fired;	
	while (_workers_ids.size() > _desired_workers)
	{
           int j = rand()/(double)RAND_MAX * (_workers_ids.size() - 1);	
		   fired.push_back(_workers_ids[j]);
		   _workers_ids.erase(_workers_ids.begin() + j);		   
	}
	return fired;
}

void firm::getsales(int sold)//, int buyers)
{
	_sold = sold;
//	_buyers = buyers;
	_profit = _price * _sold - _salary * _workers_ids.size() - _bought;
	_money += _profit;
}

void firm::produce()
{
	_stock = _productivity * _workers_ids.size(); //sqrtf(_workers_ids.size());
//	_money -= _salary * _workers_ids.size();
}

void firm::produce_consume()
{
	if (_raw_need * _workers_ids.size() == _raw)
	{
		_stock = _productivity * _workers_ids.size();
	}
	else
	{
		_stock = _productivity * _raw/_raw_need;
	}
//	_raw = 0;
}

void firm::produce_raw()
{
	_stock = _productivity * _workers_ids.size();
}

int firm::getstock()
{
	return _stock;
}

double firm::getprice()
{
	return _price;
}

double firm::getsalary()
{
	return _salary;
}

int firm::getsold()
{
	return _sold;
}

int firm::getworkers()
{
	return _workers_ids.size();
}

vector<int> firm::getworkerids()
{
	return _workers_ids;
}

double firm::getmoney()
{
	return _money;
}

double firm::getprofit()
{
	return _profit;
}

int firm::getdesired()
{
	return _desired_workers;
}

void firm::printinfo()
{
	cout<<"Price: "<<_price<<endl;
	cout<<"Salary: "<<_salary<<endl;	
	cout<<"Sold: "<<_sold<<endl;
	cout<<"Workers: "<<endl;
	for (int i = 0; i < _workers_ids.size(); i++)
	{
		cout<<_workers_ids[i]<<endl;
	}
	cout<<"Number of workers: "<<_workers_ids.size()<<endl;
	cout<<"Number of income resumes: "<<_resume_number<<endl;
	cout<<"Money: "<<_money<<endl;
	cout<<"Profit: "<<_profit<<endl;
	cout<<"Desired workers: "<<_desired_workers<<endl;
	cout<<"Stock: "<<_stock<<endl;
}

void firm::write_log(string model_name, int firm_id)
{
	ofstream fout;
	ostringstream fn;
	fn<<model_name<<"_salary"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_salary<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_price"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_price<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_sold"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_sold<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_workers"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_workers_ids.size()<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_money"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_money<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_profit"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_profit<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_desired"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_desired_workers<<" ";
	fout.close();
	fn.str("");
	fn<<model_name<<"_stock"<<"_firm_"<<firm_id<<".txt";
	fout.open(fn.str(), ios_base::app);
	fout<<_stock<<" ";
	fout.close();
	fn.str("");
}


void firm::learn(vector<vector<double>> rules_price, vector<vector<double>> rules_salary, vector<vector<double>> rules_plan)
{

}

double firm::set(vector<double> state, vector<vector<double>> rules)
{
	for (int i = 0; i < rules.size(); i++)
	{
		int j = 0;
		for (j = 0; j < rules[i].size() - 2; j += 2)
		{
			if (!((rules[i][j] <= state[j/2]) && (state[j/2] < rules[i][j+1])))
				break;
		}
		if (j == rules.size() - 2)
			return (rules[i][j] + rand()/(double)RAND_MAX * (rules[i][j+1] - rules[i][j]));
	}
	int choice = rand() % rules.size();
	return (rules[choice][rules[choice].size()-2] + rand()/(double)RAND_MAX * (rules[choice][rules[choice].size()-1] - rules[choice][rules[choice].size()-2]));
}

bool is_in(int val, vector<int> x)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == val)
			return true;
	}
	return false;
}