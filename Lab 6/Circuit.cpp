#include "Circuit.h"
#include "Car.h"
#include <iostream>
using namespace std;

Circuit::Circuit() {
	cars = 0;
}
void Circuit::SetLength(int n)
{
	this->length = n;
}
void Circuit::SetWeather(int n)
{
	this->weather = n;
}
void Circuit::AddCar(Car* c)
{
	masina[cars] = c;
	cars++;
}
void Circuit::Race()
{	
	for (int i = 0; i < cars; i++)
	{
		bool b = false;
		timpfinal[i] = length / masina[i]->Start(b, weather, length);
		aTerminat[i] = b;
	}
}
void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < cars; i++)
	{
		if (aTerminat[i] != 0)
		{
			cout << masina[i]->name << " - " << timpfinal[i]<<endl;
		}
	}
	cout << endl;
}
void Circuit::ShowWhoDidNotFinis()
{
	{
		for (int i = 0; i < cars; i++)
		{
			if (aTerminat[i] == 0)
			{
				cout << masina[i]->name << "nu a terminat cursa" << endl;
			}
		}
		cout << endl;
	}
}