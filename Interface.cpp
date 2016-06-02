#include "Interface.h"

Interface::Interface() {
	uzytkownik = NULL;
	listaSensorow = ListSensor();
	listaUserow = ListUsers();
	listaUserow.AddUser("seba", "jakari", 1);
	check = 1;
}

bool Interface::zaloguj(string l, string p)
{
	User* userTemp = listaUserow.findUser(l);
	if (userTemp == NULL) return 0;
	if (userTemp->checkPassword(p) == 1)
	{
		uzytkownik = userTemp;
		return 1;
	}
	else return 0;
}
void Interface::wyloguj()
{
	uzytkownik = NULL;
}
bool Interface::jestzalogowany() {

	if (uzytkownik != NULL) return 1;
	else return 0;

}
bool Interface::mauprawnienia() {

	if (jestzalogowany() == 0) return 0;
	if (uzytkownik->access()) return 1;
	else return 0;

}
bool Interface::wyswietlSensory()
{
	if (jestzalogowany())
	{
		listaSensorow.showSensors();
		return 1;
	}
	else
	{
		cout << "NIe masz uprawnien";
		return 0;
	}
}
bool Interface::wyswietlUsers()
{
	if (mauprawnienia())
	{
		listaUserow.showUsers();
		return 1;
	}
	else
	{
		cout << " Nie masz uprawnien";
		return 0;
	}
}
bool Interface::dodajUser(string l, string p, int a )
{
	if (mauprawnienia())
	{
		listaUserow.AddUser(l, p, a);
		return 1;
	}
	else
	{
		cout << " Nie masz uprawnien";
		return 0;
	}
}
bool Interface::dodajSensor(string n)
{
	if (mauprawnienia())
	{
		listaSensorow.AddSensor(n);
		return 1;
	}
	else
	{
		cout << " Nie masz uprawnien";
		return 0;
	}
}
bool Interface::logout()
{
	if (jestzalogowany())
	{
		cout << "Wylogowano";
		return 1;
	} 
	else
	{
		cout << "Nie jestes zalogowany";
		return 0;
	}
}



void Interface::help()
{
	cout << "Lista komend:" << endl;
	cout << "login [login] [haslo] - loguje do systemu" << endl;
	cout << "adduser [login][password][access]" << endl;
	cout << "addsensor [name] - dodaje sensory" << endl;
	cout << "deleteuser [name]" << endl;
	cout << "deletesensor [name]" << endl;
	cout << "showsensors - pokazuje wszystkie sensory" << endl;
	cout << "showusers - pokazuje wszystkich uzytkownikow" << endl;
	cout << "logout - wylogowuje" << endl;

}

void Interface::loop()
{
	string p1, p2, p3;
	help();
	string komenda;
	bool ok;
	while (check == 1)
	{
		cout << endl;
		ok = 0;
		cout << "Wpisz komende: ";  cin >> komenda;

		if (komenda == "logout")
		{
			ok = 1;
			check = 0;
			logout();
		}
		if (komenda == "addsensor")
		{
			ok = 1;
			if (jestzalogowany()) {
				cout << "Podaj nazwe czujnika: "; cin >> p1;
				dodajSensor(p1);
			}
			else
			{
				cout << "Musisz sie zalogowac";
			}
		}
		if (komenda == "login")
		{
			ok = 1;
			cout << "Podaj login: "; cin >> p1;
			cout << "Podaj haslo: "; cin >> p2;
			if (zaloguj(p1, p2)) cout << "Zalogowano" << endl;
			else cout << "Nieprawidlowy login lub haslo" << endl;
		}

		if (ok == 0) cout << "Niepoprawna Komenda";
	}

}