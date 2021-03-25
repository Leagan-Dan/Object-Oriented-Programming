#include "Dacia.h"
#include "Car.h"
#include <cstring>
#include "Weather.h"
using namespace std;

Dacia::Dacia() {
	fuel_capacity = 50;
	fuel_consumption = 5;
	average_speed[Rain] = 55;
	average_speed[Sunny] = 65;
	average_speed[Snow] = 30;
	name = (char*)"Dacia";
}
float Dacia::Start(bool& b, int w, int length)
{
	int speed = average_speed[w];
	float time = fuel_capacity / fuel_consumption;
	float distance = time * speed;

	if (distance > length)
		b = 1;
	else
		b = 0;

	return (time * length / distance);

}
