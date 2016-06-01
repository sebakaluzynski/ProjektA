#include "Sensor.h"
Sensor::Sensor(string n, Sensor* prev)
{
	name = n;
	previous = prev;
}
bool Sensor::checkName(string n)
{
	if (n == name)
		return 1;
	else
		return 0;
}