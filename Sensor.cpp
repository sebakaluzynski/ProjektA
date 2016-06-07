#include "Sensor.h"
Sensor::Sensor(string n, Sensor* prev)
{
	name = n;
	previous = prev;
}

Sensor::Sensor(){}

bool Sensor::checkName(string n)
{
	if (n == name)
		return 1;
	else
		return 0;
}

void Sensor::getValue()
{
	temperature = ((rand() % 30) + 9);
	cout << temperature;
}