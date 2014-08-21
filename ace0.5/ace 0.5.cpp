// ace 0.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "world.h"


int _tmain(int argc, _TCHAR* argv[])
{
	srand(1);
	int n = 2, m = 100, i = 50;
	string model;
/*	cout<<"Input initial number of firms: "<<endl;
	cin>>n;
	cout<<"Input initial number of households: "<<endl;
	cin>>m;
	cout<<"Input initial number of iterations: "<<endl;
	cin>>i;//*/
//	cout<<"Input model name: ";
//	cin>>model;
	scenario choice (random, value, salary_price_desired, profit);
	world earth(n,m,10,0, choice, "ace");//model);//, "output_lviv_month_price.txt", "output_lviv_month_salary.txt", "output_lviv_month_plan.txt");
	for (int iteration = 0; iteration < i; iteration++)
	{
		earth.step();
		cout<<"Iteration "<<iteration<<endl;
		//earth.printinfo();
	}
//	earth._log.printinfo();
	cin>>n;
	return 0;
}

