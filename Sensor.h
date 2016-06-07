#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>

using namespace std;

class Sensor
{
	
public:
	Sensor* previous;
	Sensor* next;
	string name;
	Sensor(string, Sensor*);
	Sensor();
	int temperature;
	void getValue();
	bool checkName(string);

};