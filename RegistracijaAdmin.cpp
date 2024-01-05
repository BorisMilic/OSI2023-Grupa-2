#include <iostream>
#include <fstream>
#include "Korisnik.h"
#include "Admin.h"

using namespace std;

void AdminPodaci() {
    string ime;
    string prezime;
    string username;
    string sifra;

    cout << "Registracija admina" << endl;
    cout << "Unesite ime: ";
    cin >> ime;
    cout << "Unesite prezime: ";
    cin >> prezime;
    cout << "Unesite zeljeni username: ";
    cin >> username;
    cout << "Unesite sifru: ";
    cin >> sifra;

    Admin novi;
    novi.SetIme(ime);
    novi.SetPrezime(prezime);
    novi.SetSifra(sifra);
    novi.SetUserName(username);

    char potvrda;
    cout << "Potvrdite unesene podatke (P/O): ";
    cin >> potvrda;

    if (potvrda == 'P' || potvrda == 'p') {
        ofstream outFile("neaktivni_nalozi.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Admin;" << ime << ";" << prezime << ";" << username << ";" << sifra << ";" << (novi.GetStatus() ? "0" : "1") << endl;
            outFile.close();
            cout << "Nalog admina ce biti kreiran nakon aktivacije." << endl;
        }
        else {
            cout << "Greska prilikom otvaranja datoteke." << endl;
        }
    }
    else {
        cout << "Registracija otkazana." << endl;
    }
}