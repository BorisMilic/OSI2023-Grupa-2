#include <iostream>
#include<fstream>
#include<string>
using namespace std;
void Registracija();
void Prijava();
void GlavniMeni();
int main()
{
	GlavniMeni();
	return 0;
}
void GlavniMeni() {
	int izbor;
	do {
		cout << "1. Registracija na sistem" << endl;
		cout << "2. Prijava na sistem" << endl;
		cout << "Izaberite opciju: ";
		cin >> izbor;
		if (izbor < 1 || izbor>2) {
			system("CLS");
			cout << "Ta opcija ne postoji, molimo Vas odaberite jednu od postojecih opcija" << endl;
		}
	} while (izbor < 1 || izbor>2);
	system("CLS");
	if (izbor == 1)
		Registracija();
	else 
		Prijava();
}