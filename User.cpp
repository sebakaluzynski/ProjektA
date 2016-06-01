#include "User.h"

User::User(string l, string p, int a, User* prev )
{
	login = l;
	password = p;
	uprawnienia = a;

	previous = prev;
	next = NULL;
}


bool User::checkLogin(string l)
{
	if (l == login)
		return 1;
	else
		return 0;
}
bool User::checkPassword(string p)
{
	if (p == password)
		return 1;
	else
		return 0;
}

bool User::access()
{
	if (uprawnienia == 1) return 1;
	else return 0;
}