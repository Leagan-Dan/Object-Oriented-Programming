#include "Ford.h"
#include "Car.h"
#include <cstring>
#include "Weather.h"
using namespace std;

Ford::Ford() {
	fuel_capacity = 5;
	fuel_consumption = 3;
	average_speed[Rain] = 76;
	average_speed[Sunny] = 85;
	average_speed[Snow] = 50;
	name = (char*)"Ford";
}
float Ford::Start(bool& b, int w, int length)
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
