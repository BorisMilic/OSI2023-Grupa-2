#include<iostream>
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
}
