#include "Toyota.h"
#include "Car.h"
#include <cstring>
#include "Weather.h"
using namespace std;

Toyota::Toyota() {
	fuel_capacity = 70;
	fuel_consumption = 3;
	average_speed[Rain] = 66;
	average_speed[Sunny] = 75;
	average_speed[Snow] = 40;
	name = (char*)"Toyota";
}
float Toyota::Start(bool& b, int w, int length)
{
	int speed = average_speed[w];
	float time = fuel_capacity / fuel_consumption;
	float distance = time * speed;

	if (distance > length)
		b = 0;
	else
		b = 1;

	return (time * length / distance);

}
