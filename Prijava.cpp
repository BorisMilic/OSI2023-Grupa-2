#include <iostream>
#include <fstream>
#include "Korisnik.h"
using namespace std;
void GlavniMeni();
void UnosPodatakaZaPrijavu();
int AdminBaza(const string& username, const string& sifra);
void ProvjeraPostojanjaISifre(int postoji_admin);
void Prijava(){
	int izbor;
	int tip_korisinika;
	do {
		cout << "1. Prijava na sistem" << endl;
		cout << "2. Povratak na glavni meni" << endl;
		cout << "Izaberite opciju: ";
		cin >> izbor;
		if (izbor < 1 || izbor>2) {
			system("CLS");
			cout << "Ta opcija ne postoji, molimo Vas odaberite jednu od postojecih opcija" << endl;
		}
	} while (izbor < 1 || izbor>2);
	if (izbor == 1) {
		system("CLS");
		do {
			cout << "1. Klijent" << endl;
			cout << "2. Radnik za tehnicki pregled" << endl;
			cout << "3. Radnik za registraciju vozila" << endl;
			cout << "4. Sistemski administrator" << endl;
			cout << "Odaberite Vas tip naloga: ";
			cin >> tip_korisinika;
			if (tip_korisinika < 1 || tip_korisinika>4) {
				system("CLS");
				cout << "Ta opcija ne postoji, molimo Vas odaberite jednu od postojecih opcija" << endl;
			}
		}while (tip_korisinika < 1 || tip_korisinika>4);
		if (tip_korisinika == 1) {

		}
		else if (tip_korisinika == 2) {

		}
		else if (tip_korisinika == 3) {

		}
		else if (tip_korisinika == 4) {
			system("CLS");
			UnosPodatakaZaPrijavu();
		}
	}
	else {
		system("CLS");
		GlavniMeni();
	}
}
void UnosPodatakaZaPrijavu() {
	string username;
	cout << "Vas username: ";
	cin >> username;
	string sifra;
	cout << "Vasa sifra: ";
	cin >> sifra;
	int postoji_admin = AdminBaza(username, sifra);
	ProvjeraPostojanjaISifre(postoji_admin);
}
int AdminBaza(const string& username, const string& sifra) {
	ifstream fajl("Admin.txt");
	string _username, _sifra;
	while (fajl) {
		getline(fajl, _username, ';'); 
		getline(fajl, _sifra); 
		if (_username == username && _sifra == sifra)
			return 1;
		else if (_username == username && _sifra != sifra)
			return 2;
	}
	return 3;
}
void ProvjeraPostojanjaISifre(int postoji_admin) {
	if (postoji_admin == 1) {
		system("CLS");
		cout << "Prijava uspjesna";
		//administratorski dio
	}
	else if (postoji_admin == 2) {
		system("CLS");
		cout << "Unijeli ste pogresnu sifru" << endl;
		UnosPodatakaZaPrijavu();
	}
	else {
		system("CLS");
		cout << "Taj admin ne postoji" << endl;
		UnosPodatakaZaPrijavu();
	}
}