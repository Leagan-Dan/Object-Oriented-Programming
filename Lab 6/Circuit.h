#pragma once
#include "Car.h"
#include "Toyota.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
class Circuit
{
private:
	int length;
	int weather;
	int cars;
	float timpfinal[10];
	bool aTerminat[10];
	Car* masina[10];
public:
	Circuit();
	void SetLength(int n);
	void SetWeather(int n);
	void AddCar(Car* c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinis();
};

