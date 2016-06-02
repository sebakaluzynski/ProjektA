#pragma once
#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "User.h"

using namespace std;

class ListUsers {

	User* first;
	User* last;
public:
	int counter;
	ListUsers();
	User* findUser(string);
	bool AddUser(string,string,int);
	bool DeleteUser(string);
	void showUsers();
};