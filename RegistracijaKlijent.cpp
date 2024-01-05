#include<iostream>
#include<fstream>
#include"Korisnik.h"
#include"Klijent.h"
using namespace std;
void KlijentPodaci() {
	string ime;
	string prezime;
	string username;
	string sifra;
	string broj_telefona;
	string opstina_stanovanja;
	string ulica_stanovanja;
	int broj;
	cout << "Registracija klijenta" << endl;
	cout << "Unesite ime: ";
	cin >> ime;
	cout << "Unesite prezime: ";
	cin >> prezime;
	cout << "Unesite zeljeni username: ";
	cin >> username;
	cout << "Unesite sifru: ";
	cin >> sifra;
	cout << "Unesite broj telefona: ";
	cin >> broj_telefona;
	cout << "Unesite opstinu stanovanja: ";
	cin >> opstina_stanovanja;
	cout << "Unesite ulicu stanovanja: ";
	cin >> ulica_stanovanja;
	cout << "Unesite broj kuce/stana: ";
	cin >> broj;
	Klijent novi(broj_telefona, opstina_stanovanja, ulica_stanovanja, broj);
	novi.SetIme(ime);
	novi.SetPrezime(prezime);
	novi.SetSifra(sifra);
	novi.SetUserName(username);

	char potvrda;
	cout << "Potvrdite unesene podatke (P/O): ";
	cin >> potvrda;
	if (potvrda == 'P' || potvrda == 'p')
	{
		// Cuvanje neaktivnih naloga u datoteci "neaktivni_nalozi.txt"
		ofstream outFile("neaktivni_nalozi.txt", ios::app);
		if (outFile.is_open())
		{

			outFile << "Klijent;" << ime << ";" << prezime << ";" <<username<< ";" << sifra << ";" << (novi.GetStatus() ? "0" : "1") << endl;
			outFile.close();
			cout << "Vas nalog ce biti kreiran nakon aktivacije." << endl;

		}
		else
		{
			cout << "Greska prilikom otvaranja datoteke." << endl;
		}
	}
	else
	{
		cout << "Registracija otkazana." << endl;
	}
}

