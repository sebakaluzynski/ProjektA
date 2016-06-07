#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>
#include "ListUsers.h"
#include "Sensor.h"
#include "User.h"
#include "ListSensor.h"

using namespace std;

class Interface
{
	ListSensor listaSensorow;
	ListUsers listaUserow;
	Sensor sensor;
	User* uzytkownik;
public:
	bool check;
	Interface();
	bool zaloguj(string, string);
	void wyloguj();
	bool jestzalogowany();
	bool mauprawnienia();
	bool wyswietlSensory();
	bool wyswietlUsers();
	bool dodajSensor(string);
	bool dodajUser(string, string, int);
	bool deleteUser(string);
	bool deleteSensor(string);
	void help();
	void loop();
	bool logout();

};