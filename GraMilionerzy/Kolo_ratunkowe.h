#ifndef KOLO_RATUNKOWE_H
#define KOLO_RATUNKOWE_H
#include <iostream> 

class Kolo_ratunkowe
{
	int ilosc_kol;
public:
	Kolo_ratunkowe();
	Kolo_ratunkowe(int ilosc_kol);
	Kolo_ratunkowe(const Kolo_ratunkowe& k);
	~Kolo_ratunkowe();

	int getIloscKol();

	int losuj_naturalna(int ograniczenie_dolne, int ograniczenie_gorne);
	void uzyj_kola_ratunkowego(int poprawna_odpowiedz);
};

#endif