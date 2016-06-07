#include <iostream>
#include <conio.h>
#include <string>
#include "ListUsers.h"
#include "Sensor.h"
#include "User.h"
#include "ListSensor.h"
#include "Interface.h"
using namespace std;

void main()
{
	Interface interfejs;
	interfejs.loop();
	
	_getch();
}