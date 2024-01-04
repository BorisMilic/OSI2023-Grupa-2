#pragma once
#include<string>
using namespace std;
class Korisnik {
private:
	string ime;
	string prezime;
	string username;
	string sifra;
public:
	const void SetIme(string _ime);
	const void SetPrezime(string _prezime);
	const void SetUserName(string _username);
	const void SetSifra(string _sifra);
	//void Prijava();
	//Korisnik(string _ime, string _prezime, string _username, string _sifra):ime(_ime),prezime(_prezime),username(_username),sifra(_sifra){}
};