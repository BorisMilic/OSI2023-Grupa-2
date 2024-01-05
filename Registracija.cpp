#include <iostream>
#include"Klijent.h"
#include<Windows.h>
using namespace std;
void GlavniMeni();
void KlijentPodaci();
void RadnikPodaci();
void RadnikPodaci2();
void AdminPodaci();

void Registracija(){
	int izbor;
	do {
		cout << "Odaberite vrstu naloga za registraciju" << endl;
		cout << "1. Klijent" << endl;
		cout << "2. Radnik za tehnicki pregled" << endl;
		cout << "3. Radnik za registraciju vozila" << endl;
		cout << "4. Sistemski administrator" << endl;
		cout << "5. Povratak na glavni meni" << endl;
		cout << "Izaberite opciju: ";
		cin >> izbor;
		if (izbor < 1 || izbor>5) {
			system("CLS");
			cout << "Ta opcija ne postoji, molimo Vas odaberite jednu od postojecih opcija" << endl;
		}
	} while (izbor < 1 || izbor>5);
	if (izbor == 1) {
		system("CLS");
		KlijentPodaci();
		Sleep(1000);
		system("CLS");
		GlavniMeni();
	}
	else if (izbor == 2) {
		system("CLS");
		RadnikPodaci();
		Sleep(1000);
		system("CLS");
		GlavniMeni();
	}
	else if (izbor == 3) {
		system("CLS");
		RadnikPodaci2();
		Sleep(1000);
		system("CLS");
		GlavniMeni();
	}
	else if (izbor == 4) {
		system("CLS");
		AdminPodaci();
		Sleep(1000);
		system("CLS");
		GlavniMeni();
	}
	else if (izbor == 5) {
		system("CLS");
		GlavniMeni();
	}
}