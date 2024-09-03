#ifndef PROWADZACY_H
#define PROWADZACY_H
#include <string>

class Prowadzacy {
public:
	void napis();
	void wyjasnienie_zasad();
	void wyjasnienie_zasad_wieloosobowej();
	void wyjasnienie_zasad_jednoosobowej();
	void gotowosc_gracza(int i, std::string nazwy_graczy[6]);
	void typ_rozgrywki();
	void trudnosc_rozgrywki();
	void prog_gwarantowany(int wartosc_pytan[], int i);
	void kontynuacja_gry(int wartosc_pytan[], int i);
	void wygrana(int wygrana, std::string nazwa_gracza);
	void wygrana_wielegraczy(std::string nazwa_gracza);
	void wersja_gry();
};

#endif