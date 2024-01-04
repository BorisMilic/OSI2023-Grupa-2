#include<iostream>
#include"Korisnik.h"
#include"RadnikZaTehnickiPregled.h"
using namespace std;
void RadnikPodaci() {
	string ime;
	string prezime;
	string username;
	string sifra;
	cout << "Registracija radnika" << endl;
	cout << "Unesite ime: ";
	cin >> ime;
	cout << "Unesite prezime: ";
	cin >> prezime;
	cout << "Unesite zeljeni username: ";
	cin >> username;
	cout << "Unesite sifru: ";
	cin >> sifra;
	RadnikTehnickiPregled novi;
	novi.SetIme(ime);
	novi.SetPrezime(prezime);
	novi.SetSifra(sifra);
	novi.SetUserName(username);
}
