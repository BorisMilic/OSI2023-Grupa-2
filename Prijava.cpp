#include <iostream>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iomanip>
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
void prikazi_sadrzaj_datoteke();
void aktiviraj_nalog();
void RezervacijaTerminaZaTehnicki();
void SacuvajTerminZaTehnicki(const string& datum, const string& vrijeme);
bool ProvjeriZauzetostTerminaZaTehnicki(const string& _datum, const string& _vrijeme);
void OtkazivanjeTerminaZaTehnicki();
void suspenduj_nalog();
bool pronadji_i_suspenduj_nalog(const std::string& tip, const std::string& korisnicko_ime);
void obrisi_nalog();
bool pronadji_i_obrisi_nalog(const std::string& tip, const std::string& korisnicko_ime);
void PlacanjeKazni(const string& iznos);
void BrisiKazne();

int tip_korisinika;
string username;

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
	cout << "Vas username: ";
	cin >> username;
	string sifra;
	cout << "Vasa sifra: ";
	cin >> sifra;
	postoji = Baza(username, sifra);
	ProvjeraPostojanjaISifre(postoji);
}
int Baza(const string& username, const string& sifra)
{
	string nazivDatoteke;

	if (tip_korisinika == 1)
	{
		nazivDatoteke = "Klijent.txt";
	}
	else if (tip_korisinika == 2)
	{
		nazivDatoteke = "Radnik_za_Tehnicki_Pregled.txt";
	}
	else if (tip_korisinika == 3)
	{
		nazivDatoteke = "Radnik_za_Registraciju.txt";
	}
	else if (tip_korisinika == 4)
	{
		nazivDatoteke = "Admin.txt";
	}

	ifstream fajl(nazivDatoteke);
	if (!fajl.is_open())
	{
		cerr << "Nemoguce otvoriti datoteku: " << nazivDatoteke << endl;
		return 3;
	}

	string linija;
	while (getline(fajl, linija))
	{
		istringstream iss(linija);
		string ime, prezime, korisnickoIme, lozinka;
		getline(iss, ime, ';');
		getline(iss, prezime, ';');
		getline(iss, korisnickoIme, ';');
		getline(iss, lozinka, ';');

		if (korisnickoIme == username && lozinka == sifra)
			return 1;
		else if (korisnickoIme == username && lozinka != sifra)
			return 2;
	}

	return 3; //nalog nije pronadjen
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

static void prikazi_sadrzaj_datoteke(const std::string& nazivDatoteke)
{
	std::ifstream datoteka(nazivDatoteke);

	if (!datoteka.is_open())
	{
		std::cerr << "Nemoguce otvoriti datoteku: " << nazivDatoteke << std::endl;
		return;
	}

	std::string linija;

	while (std::getline(datoteka, linija))
	{

		std::size_t pozicija = 0;
		std::string token;

		while ((pozicija = linija.find(';')) != std::string::npos)
		{
			token = linija.substr(0, pozicija);
			std::cout << token << " ";
			linija.erase(0, pozicija + 1);
		}

		std::cout << linija << std::endl;
	}

	datoteka.close();
}


void aktiviraj_nalog()
{
	std::ifstream neaktivniNalozi("neaktivni_nalozi.txt");

	if (!neaktivniNalozi.is_open())
	{
		std::cerr << "Nemoguce otvoriti datoteku sa neaktivnim nalozima." << std::endl;
		return;
	}

	std::ofstream tempFile("neaktivni_nalozi_temp.txt", std::ios::app);

	if (!tempFile.is_open())
	{
		std::cerr << "Nemoguce otvoriti privremenu datoteku." << std::endl;
		neaktivniNalozi.close();
		return;
	}

	std::string trazeniUsername;
	std::cout << "\nUnesite username koji zelite aktivirati (ili unesite KRAJ za povratak na prethodni meni): ";

	while (std::cin >> trazeniUsername && trazeniUsername != "KRAJ")
	{
		neaktivniNalozi.clear();
		neaktivniNalozi.seekg(0);

		std::string linija;
		bool pronadjen = false;

		while (std::getline(neaktivniNalozi, linija))
		{
			std::string prefiks = linija.substr(0, linija.find(';'));
			if (linija.find(trazeniUsername + ";") != std::string::npos)
			{
				pronadjen = true;

				std::ofstream izlaznaDatoteka;
				if (prefiks == "Klijent")
				{
					izlaznaDatoteka.open("Klijent.txt", std::ios::app);
				}
				else if (prefiks == "Radnik_za_Tehnicki_Pregled")
				{
					izlaznaDatoteka.open("Radnik_za_Tehnicki_Pregled.txt", std::ios::app);
				}
				else if (prefiks == "Radnik_za_Registraciju")
				{
					izlaznaDatoteka.open("Radnik_za_Registraciju.txt", std::ios::app);
				}
				else if (prefiks == "Admin")
				{
					izlaznaDatoteka.open("Admin.txt", std::ios::app);
				}

				if (izlaznaDatoteka.is_open())
				{
					size_t pozicija = linija.find(';') + 1;
					std::string podaci = linija.substr(pozicija);
					size_t pos = podaci.find_last_not_of(" \t\n\r\f\v");
					if (pos != std::string::npos)
						podaci.erase(pos + 1);

					izlaznaDatoteka << podaci << std::endl;
					izlaznaDatoteka.close();
					std::cout << "Nalog korisnik ciji je username: " << trazeniUsername << " je uspjesno aktiviran." << std::endl;
				}
				else
				{
					std::cerr << "Nemoguce otvoriti izlaznu datoteku za prefiks: " << prefiks << std::endl;
				}
			}
			else
			{
				tempFile << linija << std::endl;
			}
		}

		if (!pronadjen)
		{
			std::cout << "Korisnik ciji je username: " << trazeniUsername << " nije pronadjen." << std::endl;
		}

		std::cout << "Unesite sledeci username (ili unesite KRAJ za zavrsetak): ";
	}

	system("CLS");
	AdminFunkcije();
	//GlavniMeni();

	neaktivniNalozi.close();
	tempFile.close();

	if (std::remove("neaktivni_nalozi.txt") != 0 || std::rename("neaktivni_nalozi_temp.txt", "neaktivni_nalozi.txt") != 0)
	{
		std::cerr << "Nemoguce ukloniti originalnu datoteku sa neaktivnim nalozima ili preimenovati privremenu datoteku." << std::endl;
		return;
	}
}


void AdminFunkcije()
{
	int admin_izbor;
	cout << "1. Odjava " << endl;
	cout << "2. Aktivacija naloga " << endl;
	cout << "3. Suspendovanje naloga" << endl;
	cout << "4. Brisanje naloga " << endl;
	cout << "5. Ponistavanje sifre " << endl;

	//druge funkcije admina
	cout << "Odaberite neku od administratorskih funkcija: ";
	cin >> admin_izbor;
	if (admin_izbor == 1)
	{
		PotvrdaOdjave();
	}
	else if (admin_izbor == 2)
	{
		system("CLS");
		cout << "Neaktivni nalozi:" << endl;
		prikazi_sadrzaj_datoteke("neaktivni_nalozi.txt");
		
		aktiviraj_nalog();
	}

	else if (admin_izbor == 3)
	{
		//susprendovanje naloga
		suspenduj_nalog();
	}

	else if (admin_izbor == 4)
	{
		//brisanje naloga
		obrisi_nalog();
	}

	else if (admin_izbor == 5)
	{
		//ponistavanje sifre
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
	cout << "2. Rezervacija termina za tehnicki pregled " << endl;
	cout << "3. Otkazivanje termina za tehnicki pregled " << endl;
	cout << "4. Onlajn placanje kazni " << endl;
	//druge funkcije klijenta
	cout << "Odaberite neku od klijentskih funkcija: ";
	cin >> klijent_izbor;
	if (klijent_izbor == 1) {
		PotvrdaOdjave();
	}
	else if (klijent_izbor == 2) {
		system("CLS");
		RezervacijaTerminaZaTehnicki();
	}
	else if (klijent_izbor == 3) {
		system("CLS");
		OtkazivanjeTerminaZaTehnicki();
	}
	else if (klijent_izbor == 4) {
		system("CLS");
		int postoji_kazna = 0;
		string _username;
		string iznos;
		string trazeni_iznos;
		ifstream kazne("Kazne.txt");
		if (kazne.is_open()) {
			while (kazne)
			{
				getline(kazne, _username, ';');
				getline(kazne, iznos);
				if (username.compare(_username) == 0) {
					postoji_kazna = 1;
					trazeni_iznos = iznos;
				}
				if (kazne.eof())
					break;
			}
			kazne.close();
			if (postoji_kazna == 0) {
				system("CLS");
				cout << "Nemate neplacenih kazni ";
				Sleep(1500);
				system("CLS");
				KlijentFunkcije();
			}
			else
				PlacanjeKazni(trazeni_iznos);
		}
		else {
			cout << "Greska prilikom otvaranja fajla";
		}
	}
}
void RadnikZaTehnickiPregledFunkcije() {
	int radnik_za_tehnicki_pregled_izbor;
	cout << "1. Odjava " << endl;
	cout << "2. Prikaz zakazanih termina " << endl;
	//druge funkcije radnika za tehnicki pregled
	cout << "Odaberite neku od funkcija u vezi tehnickog pregleda: ";
	cin >> radnik_za_tehnicki_pregled_izbor;
	if (radnik_za_tehnicki_pregled_izbor == 1) {
		PotvrdaOdjave();
	}
	else if (radnik_za_tehnicki_pregled_izbor == 2)
	{
		char nazad;
		system("CLS");
		cout << "Pregled zakazanih tehnickih pregleda:" << endl;
		prikazi_sadrzaj_datoteke("ZakazaniTehnickiPregledi.txt");
		do {
			cout << "Za povratak nazad pritisnite N: ";
			cin >> nazad;
			if (nazad != 'N' && nazad != 'n')
				cout << "Izabrali ste nepostojecu opciju" << endl;
		} while (nazad != 'N' && nazad != 'n');
		if (nazad == 'N' || nazad == 'n') {
			system("CLS");
			RadnikZaTehnickiPregledFunkcije();
		}
	}
}
void RadnikZaRegistracijuFunkcije() {
	int radnik_za_registraciju_izbor;
	cout << "1. Odjava " << endl;
	cout << "2. Prikaz klijenata sa neplacenim kaznama " << endl;
	//druge funkcije radnika za registraciju
	cout << "Odaberite neku od funkcija u vezi registracije vozila: ";
	cin >> radnik_za_registraciju_izbor;
	if (radnik_za_registraciju_izbor == 1) {
		PotvrdaOdjave();
	}
	else if (radnik_za_registraciju_izbor == 2) {
		char nazad;
		system("CLS");
		cout << "Pregled klijenata koji imaju neplacene kazne:" << endl;
		prikazi_sadrzaj_datoteke("Kazne.txt");
		do {
			cout << "Za povratak nazad pritisnite N: ";
			cin >> nazad;
			if (nazad != 'N' && nazad != 'n')
				cout << "Izabrali ste nepostojecu opciju" << endl;
		} while (nazad != 'N' && nazad != 'n');
		if (nazad == 'N' || nazad == 'n') {
			system("CLS");
			RadnikZaRegistracijuFunkcije();
		}
	}
}
void RezervacijaTerminaZaTehnicki() {
	string datum;
	string vrijeme;
	cout << "Validni termini su puni sat i sat i pola, a vrijeme trajanja tehnickog pregleda je pola sata" << endl;
	cout << "Unesite zeljeni datum za tehnicki pregled (D.M.G): ";
	cin >> datum;
	cout << "Unesite zeljenu satnicu za tehnicki pregled (S:M): ";
	cin >> vrijeme;
	if (vrijeme[size(vrijeme) - 2] == ':')
		vrijeme.append("0");
	int sati = stoi(vrijeme);
	int minute;
	istringstream(vrijeme.substr(size(vrijeme) - 2, size(vrijeme) - 1)) >> minute;
	bool zauzet_termin = ProvjeriZauzetostTerminaZaTehnicki(datum, vrijeme);
	if (zauzet_termin == true) {
		system("CLS");
		cout << "Taj termin za tehnicki pregled je vec zauzet, molimo odaberite drugi" << endl;
		Sleep(1500);
		system("CLS");
		RezervacijaTerminaZaTehnicki();
	}
	else {
		if ((sati < 8 || sati >= 15) || (minute != 0 && minute != 30)) {
			system("CLS");
			cout << "Unijeli ste satnicu izvan radnog vremena ili nevalidnu satnicu" << endl;
			Sleep(2500);
			system("CLS");
			RezervacijaTerminaZaTehnicki();
		}
		else {
			char potvrda;
			cout << "Potvrdite unesene podatke (P/O): ";
			cin >> potvrda;
			if (potvrda == 'P' || potvrda == 'p')
				SacuvajTerminZaTehnicki(datum, vrijeme);
			else
			{
				system("CLS");
				cout << "Rezervacija termina za tehnicki pregled je otkazana." << endl;
				Sleep(1500);
				system("CLS");
				KlijentFunkcije();
			}
		}
	}
}
void SacuvajTerminZaTehnicki(const string& datum, const string& vrijeme) {
		ofstream outFile("ZakazaniTehnickiPregledi.txt", ios::app);
		if (outFile.is_open())
		{
			outFile << username << ";" << datum << ";" << vrijeme << endl;
			outFile.close();
			system("CLS");
			cout << "Vas termin za tehnicki pregled je uspjesno sacuvan." << endl;
			Sleep(1500);
			system("CLS");
			KlijentFunkcije();
		}
		else
		{
			cout << "Greska prilikom otvaranja datoteke." << endl;
		}
	}
bool ProvjeriZauzetostTerminaZaTehnicki(const string& _datum, const string& _vrijeme) {
	ifstream file("ZakazaniTehnickiPregledi.txt");
	string datum;
	string username;
	string vrijeme;
	while (file) {
		getline(file, username, ';');
		getline(file, datum, ';');
		getline(file, vrijeme);
		if (datum == _datum && vrijeme == _vrijeme)
			return true;
	}
	return false;
}
void OtkazivanjeTerminaZaTehnicki() {
	string datum;
	cout << "Unesite datum termina kojeg zelite otkazati (D.M.G): ";
	cin >> datum;
	string vrijeme;
	cout << "Unesite satnicu termina koju zelite otkazati (S:M): ";
	cin >> vrijeme;
	char potvrda_otkazivanja;
	cout << "Potvrdite otkazivanje (P/O): ";
	cin >> potvrda_otkazivanja;
	if (potvrda_otkazivanja == 'P' || potvrda_otkazivanja == 'p') {
		//SacuvajTerminZaTehnicki(datum, vrijeme);
		if (vrijeme[size(vrijeme) - 2] == ':')
			vrijeme.append("0");
		int sati = stoi(vrijeme);
		int minute;
		istringstream(vrijeme.substr(size(vrijeme) - 2, size(vrijeme) - 1)) >> minute;
		if ((sati < 8 || sati >= 15) || (minute != 0 && minute != 30)) {
			system("CLS");
			cout << "Unijeli ste satnicu izvan radnog vremena ili nevalidnu satnicu" << endl;
			Sleep(2500);
			system("CLS");
			OtkazivanjeTerminaZaTehnicki();
		}
		bool nema_termina = ProvjeriZauzetostTerminaZaTehnicki(datum, vrijeme);
		if (nema_termina == false) {
			system("CLS");
			cout << "Nije moguce brisanje nepostojeceg termina" << endl;
			Sleep(1500);
			system("CLS");
			OtkazivanjeTerminaZaTehnicki();
		}
		ifstream tehnicki_termini("ZakazaniTehnickiPregledi.txt");
		string _username, _datum, _vrijeme;
		int drugi_user = 0;
		string stari_datum = "";
		string staro_vrijeme = "";
		if (tehnicki_termini.is_open()) {
			ofstream novi_tehnicki_termini("temp.txt");
			while (tehnicki_termini) {
				getline(tehnicki_termini, _username, ';');
				getline(tehnicki_termini, _datum, ';');
				getline(tehnicki_termini, _vrijeme);
				if (stari_datum.compare(_datum) != 0 && staro_vrijeme.compare(_vrijeme) != 0) {
					if ((_datum.compare(datum) != 0 && _vrijeme.compare(vrijeme) != 0) || (_datum.compare(datum) == 0 && _vrijeme.compare(vrijeme) != 0) || (_datum.compare(datum) != 0 && _vrijeme.compare(vrijeme) == 0)) {
						novi_tehnicki_termini << _username << ";" << _datum << ";" << _vrijeme << endl;
					}
					if (_username.compare(username) != 0 && _datum.compare(datum) == 0 && _vrijeme.compare(vrijeme) == 0) {
						novi_tehnicki_termini << _username << ";" << _datum << ";" << _vrijeme << endl;
						drugi_user = 1;
					}
				}
				stari_datum = _datum;
				staro_vrijeme = _vrijeme;
			}
			tehnicki_termini.close();
			novi_tehnicki_termini.close();
			remove("ZakazaniTehnickiPregledi.txt");
			int preimenovan = rename("temp.txt", "ZakazaniTehnickiPregledi.txt");
			if (preimenovan == 0 && drugi_user != 1) {
				system("CLS");
				cout << "Termin uspjesno obrisan";
				Sleep(1500);
				system("CLS");
				KlijentFunkcije();
			}
			else {
				system("CLS");
				cout << "Odabrali ste termin drugog klijenta, unesite ponovo podatke";
				Sleep(2000);
				system("CLS");
				OtkazivanjeTerminaZaTehnicki();
			}
		}
		else
			cout << "Fajl ne postoji";
	}
	else {
		system("CLS");
		KlijentFunkcije();
	}
}
void suspenduj_nalog()
{
	int izbor;
	std::string tip_naloga;

	do
	{

		system("CLS");

		std::cout << "Izaberite vrstu naloga za suspendovanje:" << std::endl;
		std::cout << "1. Klijenti" << std::endl;
		std::cout << "2. Radnici za tehnicki pregled" << std::endl;
		std::cout << "3. Radnici za registraciju" << std::endl;
		std::cout << "4. Admini" << std::endl;
		std::cout << "5. Povratak na prethodni meni" << std::endl;
		std::cout << "Izbor: ";
		std::cin >> izbor;

		switch (izbor)
		{
		case 1:
			tip_naloga = "Klijent";
			system("CLS");
			cout << "Lista naloga klijenata koje mozete suspendovati:\n" << endl;
			prikazi_sadrzaj_datoteke("Klijent.txt");
			break;
		case 2:
			tip_naloga = "Radnik_za_Tehnicki_Pregled";
			system("CLS");
			cout << "Lista naloga radnika za teh. pregled koje mozete suspendovati:\n" << endl;
			prikazi_sadrzaj_datoteke("Radnik_za_Tehnicki_Pregled.txt");
			break;
		case 3:
			tip_naloga = "Radnik_za_Registraciju";
			system("CLS");
			cout << "Lista naloga radnika za registraciju koje mozete suspendovati:\n" << endl;
			prikazi_sadrzaj_datoteke("Radnik_za_Registraciju.txt");
			break;
		case 4:
			tip_naloga = "Admin";
			system("CLS");
			cout << "Lista naloga admina koje mozete suspendovati:\n" << endl;
			prikazi_sadrzaj_datoteke("Admin.txt");
			break;
		case 5:
			system("CLS");
			AdminFunkcije();
		default:
			system("CLS");
			std::cout << "Nevazeci izbor. Molimo izaberite ponovo." << std::endl;
			suspenduj_nalog();
			break;
		}

	} while (izbor < 1 || izbor > 5);


	std::string korisnicko_ime;
	std::cout << "\nUnesite username naloga koji zelite suspendovati (ili N za nazad): ";
	std::cin >> korisnicko_ime;

	if (korisnicko_ime == "N" || korisnicko_ime == "n")
	{
		system("CLS");
		suspenduj_nalog();
	}
	else
	{
		if (pronadji_i_suspenduj_nalog(tip_naloga, korisnicko_ime))
		{
			std::cout << "\nNalog korisnika " << korisnicko_ime << " je suspendovan." << std::endl;
			Sleep(2000);
		}
		else
		{
			std::cout << "\nNalog nije pronadjen ili se desila greska pri suspendovanju." << std::endl;
			Sleep(2000);
		}

		system("CLS");
		AdminFunkcije();
	}
}
bool pronadji_i_suspenduj_nalog(const std::string& tip, const std::string& korisnicko_ime)
{
	std::ifstream ulazna_datoteka(tip + ".txt");
	std::ofstream neaktivni_nalozi("neaktivni_nalozi.txt", std::ios::app);

	if (!ulazna_datoteka.is_open() || !neaktivni_nalozi.is_open())
	{
		std::cerr << "Nemoguce otvoriti datoteke." << std::endl;
		return false;
	}

	std::ofstream temp_datoteka(tip + "_temp.txt");

	if (!temp_datoteka.is_open())
	{
		std::cerr << "Nemoguce otvoriti privremenu datoteku." << std::endl;
		ulazna_datoteka.close();
		neaktivni_nalozi.close();
		return false;
	}

	std::string linija;
	bool nalog_pronadjen = false;

	while (std::getline(ulazna_datoteka, linija))
	{
		std::istringstream iss(linija);
		std::string ime, prezime, username, sifra, tip_naloga;
		int status;

		std::getline(iss, ime, ';');
		std::getline(iss, prezime, ';');
		std::getline(iss, username, ';');
		std::getline(iss, sifra, ';');
		iss >> status; 

		if (username == korisnicko_ime)
		{
			nalog_pronadjen = true;
			neaktivni_nalozi << tip + ";" + ime + ";" + prezime + ";" + username + ";" + sifra + ";" + std::to_string(status) << std::endl;
			//std::cout << linija << std::endl; 
		}
		else
		{
			temp_datoteka << linija << std::endl;
		}
	}

	ulazna_datoteka.close();
	temp_datoteka.close();
	neaktivni_nalozi.close();

	
	if (std::remove((tip + ".txt").c_str()) != 0 || std::rename((tip + "_temp.txt").c_str(), (tip + ".txt").c_str()) != 0)
	{
		std::cerr << "Nemoguce ukloniti originalnu datoteku ili preimenovati privremenu datoteku." << std::endl;
		return false;
	}

	return nalog_pronadjen;
}

void obrisi_nalog()
{
	int izbor;
	std::string tip_naloga;

	do
	{

		system("CLS");

		std::cout << "Izaberite vrstu naloga za brisanje:" << std::endl;
		std::cout << "1. Klijenti" << std::endl;
		std::cout << "2. Radnici za tehnicki pregled" << std::endl;
		std::cout << "3. Radnici za registraciju" << std::endl;
		std::cout << "4. Admini" << std::endl;
		std::cout << "5. Povratak na prethodni meni" << std::endl;
		std::cout << "Izbor: ";
		std::cin >> izbor;

		switch (izbor)
		{
		case 1:
			tip_naloga = "Klijent";
			system("CLS");
			cout << "Lista naloga klijenata koje mozete obrisati:\n" << endl;
			prikazi_sadrzaj_datoteke("Klijent.txt");
			break;
		case 2:
			tip_naloga = "Radnik_za_Tehnicki_Pregled";
			system("CLS");
			cout << "Lista naloga radnika za teh. pregled koje mozete obrisati:\n" << endl;
			prikazi_sadrzaj_datoteke("Radnik_za_Tehnicki_Pregled.txt");
			break;
		case 3:
			tip_naloga = "Radnik_za_Registraciju";
			system("CLS");
			cout << "Lista naloga radnika za registraciju koje mozete obrisati:\n" << endl;
			prikazi_sadrzaj_datoteke("Radnik_za_Registraciju.txt");
			break;
		case 4:
			tip_naloga = "Admin";
			system("CLS");
			cout << "Lista naloga admina koje mozete obrisati:\n" << endl;
			prikazi_sadrzaj_datoteke("Admin.txt");
			break;
		case 5:
			system("CLS");
			AdminFunkcije();
		default:
			system("CLS");
			std::cout << "Nevazeci izbor. Molimo izaberite ponovo." << std::endl;
			suspenduj_nalog();
			break;
		}

	} while (izbor < 1 || izbor > 5);


	std::string korisnicko_ime;
	std::cout << "\nUnesite useername naloga koji zelite obrisati (ili N za nazad): ";
	std::cin >> korisnicko_ime;

	if (korisnicko_ime == "N" || korisnicko_ime == "n")
	{
		system("CLS");
		obrisi_nalog();
		//AdminFunkcije();
	}
	else
	{
		if (pronadji_i_obrisi_nalog(tip_naloga, korisnicko_ime))
		{
			std::cout << "\nNalog korisnika " << korisnicko_ime << " je obrisan." << std::endl;
			Sleep(2000);
		}
		else
		{
			std::cout << "\nNalog nije pronadjen ili se desila greska pri brisanju." << std::endl;
			Sleep(2000);
		}

		system("CLS");
		AdminFunkcije();
	}
}

bool pronadji_i_obrisi_nalog(const std::string& tip, const std::string& korisnicko_ime)
{
	std::ifstream ulazna_datoteka(tip + ".txt");
	std::ofstream temp_datoteka(tip + "_temp.txt");

	if (!ulazna_datoteka.is_open() || !temp_datoteka.is_open())
	{
		std::cerr << "Nemoguce otvoriti datoteke." << std::endl;
		return false;
	}

	std::string linija;
	bool nalog_pronadjen = false;

	while (std::getline(ulazna_datoteka, linija))
	{
		std::istringstream iss(linija);
		std::string ime, prezime, username, sifra;
		int status;

		std::getline(iss, ime, ';');
		std::getline(iss, prezime, ';');
		std::getline(iss, username, ';');
		std::getline(iss, sifra, ';');
		iss >> status;

		if (username == korisnicko_ime)
		{
			nalog_pronadjen = true;

		}
		else
		{
			temp_datoteka << linija << std::endl;
		}
	}

	ulazna_datoteka.close();
	temp_datoteka.close();

	if (std::remove((tip + ".txt").c_str()) != 0 || std::rename((tip + "_temp.txt").c_str(), (tip + ".txt").c_str()) != 0)
	{
		std::cerr << "Nemoguce ukloniti originalnu datoteku ili preimenovati privremenu datoteku." << std::endl;
		return false;
	}

	return nalog_pronadjen;
}
void PlacanjeKazni(const string& iznos) {
	char potvrda;
	int broj_kartice;
	cout << "Imate " << iznos << " neplacenih kazni" << endl;
	do {
		cout << "Da li zelite da platite vase kazne D/N? ";
		cin >> potvrda;
		if (potvrda != 'D' && potvrda != 'N') {
			cout << "Unijeli ste nepostojecu opciju" << endl;
		}
	} while ((potvrda != 'D' && potvrda != 'N'));
	if (potvrda == 'D') {
		cout << "Unesite broj kartice: ";
		cin >> broj_kartice;
		BrisiKazne();
		system("CLS");
		cout << "Placanje kazni izvrseno uspjesno";
		Sleep(2000);
		system("CLS");
		KlijentFunkcije();
	}
	else if (potvrda == 'N') {
		system("CLS");
		KlijentFunkcije();
	}
}
void BrisiKazne() {
	ofstream temp_fajl("Kazne_temp.txt");
	ifstream kazne("Kazne.txt");
	string _username;
	string iznos;
	int preimenuj;
	if (kazne.is_open()) {
		while (kazne) {
			if (kazne.eof())
				break;
			getline(kazne, _username, ';');
			getline(kazne, iznos);
			if (_username.compare(username) != 0 && _username.compare("") != 0)
				temp_fajl << _username << ";" << iznos << endl;
		}
		temp_fajl.close();
		kazne.close();
		remove("Kazne.txt");
		preimenuj = rename("Kazne_temp.txt", "Kazne.txt");
	}
	else
		cout << "Greska prilikom otvaranja fajla";
}