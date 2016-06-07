#include "Interface.h"

Interface::Interface(){
	uzytkownik = NULL;
	listaSensorow = ListSensor();
	listaUserow = ListUsers();
	sensor = Sensor();
	srand(time(NULL));
	//inicjalizacja uzytkowników	0 - brak uprawnien	1 - ma uprawnienia
	listaUserow.AddUser("admin", "admin", 1);
	listaUserow.AddUser("kot", "alik", 0);
	//inicjalizacja sensorów
	listaSensorow.AddSensor("sensor1");
	listaSensorow.AddSensor("sensor2");
	listaSensorow.AddSensor("sensor3");

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
		cout << "DODANO UZYTOWNIKA" << endl;

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
		cout << "DODANO CZUJNIK" << endl;
		return 1;
	}
	else
	{
		cout << " Nie masz uprawnien";
		return 0;
	}
}
bool Interface::deleteUser(string n)
{
	if (mauprawnienia())
	{
		listaUserow.DeleteUser(n);
		cout << "USUNIETO UZYTKOWNIKA" << endl;
		return 1;
	}
	else
	{
		cout << "Nie masz uprawnien";
		return 0;
	}
}
bool Interface::deleteSensor(string n)
{
	if (mauprawnienia())
	{
		listaSensorow.DeleteSensor(n);
		cout << "USUNIETO CZUJNIK" << endl;

		return 1;
	}
	else
	{
		cout << "Nie masz uprawnien";
		return 0;
	}
}

bool Interface::logout()
{
	if (jestzalogowany())
	{
		cout << "Wylogowano";
		check = 1;
		return 1;
	} 
	else
	{
		system("cls");
		cout << "NIE JESTES ZALOGOWANY" << endl << endl;
		loop();
	}
}

void Interface::help()
{
	cout << "Lista komend:" << endl;
	cout << "-------------------------------" << endl;
	cout << "login - loguje do systemu" << endl;
	cout << "adduser - dodaje uzytkownika" << endl;
	cout << "addsensor - dodaje sensory" << endl;
	cout << "deleteuser - usuwa uzytkownikow" << endl;
	cout << "deletesensor - usuwa sensory" << endl;
	cout << "showsensors - pokazuje wszystkie sensory" << endl;
	cout << "showusers - pokazuje wszystkich uzytkownikow" << endl;
	cout << "checktemp - sprawdza temperature na wybranym czujniku" << endl;
	cout << "clear - czysci konsole" << endl;
	cout << "exit - zamyka konsole" << endl;
	cout << "logout - wylogowuje" << endl;
}

void Interface::loop()
{
	check = 1;
	string p1, p2;
	int access;
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
			logout();
		}
		if (komenda == "addsensor")
		{
			ok = 1;
			cout << "Podaj nazwe czujnika: "; cin >> p1;
			dodajSensor(p1);
		}
		if (komenda == "adduser")
		{
			ok = 1;
			cout << "Podaj login nowego uzytkownika: "; cin >> p1;
			cout << "Podaj haslo nowego uzytkownika: "; cin >> p2;
			cout << "Podaj uprawnienia [brak - 0 admin - 1 ]: "; cin >> access;
			dodajUser(p1, p2, access);
		}
		if (komenda == "login")
		{
			ok = 1;
			cout << "Podaj login: "; cin >> p1;
			cout << "Podaj haslo: "; cin >> p2;
			if (zaloguj(p1, p2)) cout << "Zalogowano" << endl;
			else cout << "Nieprawidlowy login lub haslo" << endl;
		}
		if (komenda == "showsensors")
		{
			ok = 1;
			wyswietlSensory();
		}
		if (komenda == "showusers")
		{
			ok = 1;
			wyswietlUsers();
		}
		if (komenda == "deletesensor")
		{
			ok = 1;
			cout << "Podaj nazwe czujnika ktory chcesz usunac: "; cin >> p1;
			deleteSensor(p1);
		}
		if (komenda == "deleteuser")
		{
			ok = 1;
			cout << "Podaj nazwe uzytkownika ktorego chcesz usunac: "; cin >> p1;
			deleteUser(p1);
		}
		if (komenda == "checktemp")
		{
			ok = 1;
			cout << "Podaj nazwe sensora, z ktorego chcesz odczytac temperature: "; cin >> p1;
			if(listaSensorow.findSensor(p1))
			{
				cout << "Temperatura wynosi: ";
				sensor.getValue();
			}
			else 
				cout << "Nie ma takiego czujnika";
			
		}
		if (komenda == "clear")
		{
			ok = 1;
			system("cls");
			help();
		}
		if (komenda == "exit")
		{
			exit(0);
		}

		if (ok == 0) cout << "Niepoprawna Komenda";
	}
}