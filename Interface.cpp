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
		listaSensorow.wyswietl();
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
		listaUserow.wyswietl();
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

void Interface::help()
{
	cout << "Lista komend:" << endl;
	cout<< "login [login] [haslo] - loguje do systemu" << endl;
	cout << "Dodaj czujnik [name]" << endl;
	cout << "Dodaj uzytkownika [l][p][a]" << endl;
	cout << "logout " << endl;

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
		cin >> komenda;

		if (komenda == "exit")
		{
			ok = 1;
			check = 0;
		}
		if (komenda == "adds")
		{
			ok = 1;
			cin >> p1;
			dodajSensor(p1);

		}
		if (komenda == "login")
		{
			ok = 1;
			cout << "Podaj login: "; cin >> p1;
			cout << "Podaj haslo: "; cin >> p2;
			if (zaloguj(p1, p2)) cout << "Zalogowano" << endl;
			else cout << "Nieprawid³owy login lub has³o" << endl;


		}


		if (ok == 0) cout << "Niepoprawna Komenda";
	}

}