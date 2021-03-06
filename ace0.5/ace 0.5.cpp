// ace 0.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "world.h"


int _tmain(int argc, _TCHAR* argv[])
{
	srand(1);
	int n = 2, m = 100, i = 10;
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
	world earth1(n,m,1000,0, choice, "ace2");//model);//, "output_lviv_month_price.txt", "output_lviv_month_salary.txt", "output_lviv_month_plan.txt");
//	world earth2(n,m,1000,0, choice, "ace2");
	for (int iteration = 0; iteration < i; iteration++)
	{
		earth1.step(0.1);
//		earth2.step(0.1);
		cout<<"Iteration "<<iteration<<endl;
		//earth.printinfo();
	}
	for (int iteration = 0; iteration < 2 * i; iteration++)
	{
		earth1.step(0.15);
//		earth2.step(0.1);
		cout<<"Iteration "<<iteration<<endl;
		//earth.printinfo();
	}
//	earth._log.printinfo();
	cin>>n;
	return 0;
}

