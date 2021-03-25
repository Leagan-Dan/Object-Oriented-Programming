#include "Car.h"
#pragma once
class Toyota : public Car {
public:
	Toyota();
	float Start(bool&, int, int);
	char* getName() override;
};
