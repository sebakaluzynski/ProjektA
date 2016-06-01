#include "ListUsers.h"

ListUsers::ListUsers()
{
	first = NULL;
	last = NULL;
	counter = 0;
}

bool ListUsers::AddUser(string l, string p, int a)
{
	if (findUser(l) == NULL) {
		User* tempLast = last;
		last = new User(l, p, a, tempLast);
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

User* ListUsers::findUser(string l)
{
	User* finder = first;
	while ((finder != NULL) && (finder->checkLogin(l) == 0))
	{
		finder = finder->next;
	}
	return finder;
}

bool ListUsers::DeleteUser(string l)
{
	User* victim = findUser(l);
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


void ListUsers::wyswietl()
{
	User* finder = first;
	while ((finder != NULL))
	{
		cout << finder->login<<endl;
		finder = finder->next;
	}
}