#include "Mazda.h"
#include "Car.h"
#include <cstring>
#include "Weather.h"
using namespace std;

Mazda::Mazda() {
	fuel_capacity = 80;
	fuel_consumption = 4;
	average_speed[Rain] = 80;
	average_speed[Sunny] = 85;
	average_speed[Snow] = 60;
	name = (char*)"Mazda";
}
float Mazda::Start(bool& b, int w, int length)
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
