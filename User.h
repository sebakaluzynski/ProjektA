#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class User
{
	//string login;
	string password;
	int uprawnienia;
	int id;

public:
	User(string, string, int, User*);
	User* previous;
	User* next;
	string login;
	bool checkLogin(string log);
	bool checkPassword(string pass);
	bool access();
};