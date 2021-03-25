#pragma once
class Car
{
public:
	char* name;
	int fuel_capacity;
	int fuel_consumption;
	int average_speed[3];
	virtual float Start(bool&, int, int) = 0;
private:
	
};

