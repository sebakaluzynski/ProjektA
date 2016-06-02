#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Sensor
{
	
public:
	Sensor* previous;
	Sensor* next;
	string name;
	Sensor(string, Sensor*);
	float getValue();
	bool checkName(string);

};