#pragma once
#include <string>
#include "Sensor.h"

using namespace std;

class ListSensor {

	Sensor* first;
	Sensor* last;
public:


	int counter;
	ListSensor();
	Sensor* findSensor(string);
	bool AddSensor(string);
	bool DeleteSensor(string);
	void showSensors();
};