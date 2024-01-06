#include <iostream>
#include <fstream>
#include<Windows.h>
#include "Korisnik.h"
using namespace std;

void GlavniMeni();
void UnosPodatakaZaPrijavu();
int Baza(const string& username, const string& sifra);
void ProvjeraPostojanjaISifre(int postoji);
void KlijentFunkcije();
void RadnikZaTehnickiPregledFunkcije();
void RadnikZaRegistracijuFunkcije();
void AdminFunkcije();
void PotvrdaOdjave();
int tip_korisinika;

void Prijava(){
	int izbor;
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
			system("CLS");
			UnosPodatakaZaPrijavu();
		}
		else if (tip_korisinika == 2) {
			system("CLS");
			UnosPodatakaZaPrijavu();
		}
		else if (tip_korisinika == 3) {
			system("CLS");
			UnosPodatakaZaPrijavu();
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
	int postoji;
	string username;
	cout << "Vas username: ";
	cin >> username;
	string sifra;
	cout << "Vasa sifra: ";
	cin >> sifra;
	postoji = Baza(username, sifra);
	ProvjeraPostojanjaISifre(postoji);
}
int Baza(const string& username, const string& sifra) {
	if (tip_korisinika == 1) {
		ifstream fajl("Klijent.txt");
		string _username, _sifra;
		string temp1, temp2;
		while (fajl) {
			getline(fajl, temp1, ';');
			getline(fajl, temp2, ';');
			getline(fajl, _username, ';');
			getline(fajl, _sifra,';');
			if (_username == username && _sifra == sifra)
				return 1;
			else if (_username == username && _sifra != sifra)
				return 2;
		}
		return 3;
	}
	if (tip_korisinika == 2) {
		ifstream fajl("RadnikZaTehnicki.txt");
		string _username, _sifra;
		string temp1, temp2;
		while (fajl) {
			getline(fajl, temp1, ';');
			getline(fajl, temp2, ';');
			getline(fajl, _username, ';');
			getline(fajl, _sifra, ';');
			if (_username == username && _sifra == sifra)
				return 1;
			else if (_username == username && _sifra != sifra)
				return 2;
		}
		return 3;
	}
	if (tip_korisinika == 3) {
		ifstream fajl("RadnikZaRegistraciju.txt");
		string _username, _sifra;
		string temp1, temp2;
		while (fajl) {
			getline(fajl, temp1, ';');
			getline(fajl, temp2, ';');
			getline(fajl, _username, ';');
			getline(fajl, _sifra, ';');
			if (_username == username && _sifra == sifra)
				return 1;
			else if (_username == username && _sifra != sifra)
				return 2;
		}
		return 3;
	}
	else {
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
}
void ProvjeraPostojanjaISifre(int postoji) {
	if (postoji == 1) {
		system("CLS");
		cout << "Prijava uspjesna" << endl;
		Sleep(1000);
		system("CLS");
		if (tip_korisinika == 1)
			KlijentFunkcije();
		if (tip_korisinika == 2)
			RadnikZaTehnickiPregledFunkcije();
		if (tip_korisinika == 3)
			RadnikZaRegistracijuFunkcije();
		if (tip_korisinika == 4)
			AdminFunkcije();
	}
	else if (postoji == 2) {
		system("CLS");
		cout << "Unijeli ste pogresnu sifru" << endl;
		Sleep(1000);
		system("CLS");
		UnosPodatakaZaPrijavu();
	}
	else {
		system("CLS");
		cout << "Taj nalog ne postoji" << endl;
		Sleep(1000);
		system("CLS");
		UnosPodatakaZaPrijavu();
	}
}
void AdminFunkcije() {
	int admin_izbor;
	cout << "1. Odjava " << endl;
	//druge funkcije admina
	cout << "Odaberite neku od administratorskih funkcija: ";
	cin >> admin_izbor;
	if (admin_izbor == 1) {
		PotvrdaOdjave();
	}
}
void PotvrdaOdjave() {
	char potvrda_odjave;
	do {
		cout << "Da li ste sigurni da zelite da se odjavite sa sistema D/N? ";
		cin >> potvrda_odjave;
		if (potvrda_odjave == 'D') {
			system("CLS");
			cout << "Uspjesno ste se odjavili sa sistema " << endl;
			Sleep(1000);
			system("CLS");
			GlavniMeni();
		}
		else if (potvrda_odjave == 'N') {
			system("CLS");
			if (tip_korisinika == 1)
				KlijentFunkcije();
			if (tip_korisinika == 2)
				RadnikZaTehnickiPregledFunkcije();
			if (tip_korisinika == 3)
				RadnikZaRegistracijuFunkcije();
			if (tip_korisinika == 4)
				AdminFunkcije();
		}
		else
			cout << "Izabrali ste pogresnu opciju" << endl;
	} while (potvrda_odjave != 'D' && potvrda_odjave != 'N');
}
void KlijentFunkcije() {
	int klijent_izbor;
	cout << "1. Odjava " << endl;
	//druge funkcije klijenta
	cout << "Odaberite neku od klijentskih funkcija: ";
	cin >> klijent_izbor;
	if (klijent_izbor == 1) {
		PotvrdaOdjave();
	}
}
void RadnikZaTehnickiPregledFunkcije() {
	int radnik_za_tehnicki_pregled_izbor;
	cout << "1. Odjava " << endl;
	//druge funkcije radnika za tehnicki pregled
	cout << "Odaberite neku od funkcija u vezi tehnickog pregleda: ";
	cin >> radnik_za_tehnicki_pregled_izbor;
	if (radnik_za_tehnicki_pregled_izbor == 1) {
		PotvrdaOdjave();
	}
}
void RadnikZaRegistracijuFunkcije() {
	int radnik_za_registraciju_izbor;
	cout << "1. Odjava " << endl;
	//druge funkcije radnika za registraciju
	cout << "Odaberite neku od funkcija u vezi registracije vozila: ";
	cin >> radnik_za_registraciju_izbor;
	if (radnik_za_registraciju_izbor == 1) {
		PotvrdaOdjave();
	}
}