#include "Mercedes.h"
#include "Car.h"
#include <cstring>
#include "Weather.h"
using namespace std;

Mercedes::Mercedes() {
	fuel_capacity = 1;
	fuel_consumption = 3;
	average_speed[Rain] = 100;
	average_speed[Sunny] = 115;
	average_speed[Snow] = 60;
	name = (char*)"Mercedes";
}
float Mercedes::Start(bool& b, int w, int length)
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
