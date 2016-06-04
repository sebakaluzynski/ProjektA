#include "ListSensor.h"

ListSensor::ListSensor()
{
	first = NULL;
	last = NULL;
	counter = 0;
}

bool ListSensor::AddSensor(string n)
{
	if (findSensor(n) == NULL) {
		Sensor* tempLast = last;
		last = new Sensor(n, tempLast);
		if (tempLast == NULL)
		{
			first = last;
		}
		else
		{
			last->previous = tempLast;
			tempLast->next = last;
		}
		return 1;
	}
	else return 0;
}


Sensor* ListSensor::findSensor(string n)
{
	Sensor* finder = first;
	while ((finder != NULL) && (finder->checkName(n) == 0))
	{
		finder = finder->next;
	}
	return finder;
}

bool ListSensor::DeleteSensor(string n)
{
	Sensor* victim = findSensor(n);
	if (victim != NULL)
	{
		if (victim->next != NULL) victim->next->previous = victim->previous;
		if (victim->previous != NULL) victim->previous->next = victim->next;
		delete victim;
		return 1;
	}
	else
	{
		return 0;
	}
}
void ListSensor::showSensors()
{
	Sensor* finder = first;	
	if (finder == NULL) cout << "Nie ma zainstalowanych czujników" << endl;
	else cout << endl << "LISTA CZUJNIKOW" << endl;
	while ((finder != NULL))
	{	
		cout << finder->name << endl;
		finder = finder->next;
	}

}