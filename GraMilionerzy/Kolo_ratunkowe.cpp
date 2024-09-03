#include "Kolo_ratunkowe.h"

Kolo_ratunkowe::Kolo_ratunkowe() : ilosc_kol(3) {}
Kolo_ratunkowe::Kolo_ratunkowe(int ilosc) : ilosc_kol(ilosc) {}
Kolo_ratunkowe::Kolo_ratunkowe(const Kolo_ratunkowe& k) : ilosc_kol(k.ilosc_kol) {}
Kolo_ratunkowe::~Kolo_ratunkowe() {}

int Kolo_ratunkowe::getIloscKol() {
	return ilosc_kol;
}

/*
 * Losuje liczbe naturalna z danego zakresu liczb.
 * @param ograniczenie_dolne liczba od ktorej wylosowana liczba ma byc wieksza
 * @param ograniczenie_gorne liczba od ktorej wylosowana liczba ma byc mniejsza
 */
int Kolo_ratunkowe::losuj_naturalna(int ograniczenie_dolne, int ograniczenie_gorne) {
	int liczba = rand() % (ograniczenie_gorne - ograniczenie_dolne) + ograniczenie_dolne;
	return liczba;
}

/*
 * Metoda realizuje logike uzycia kola ratunkowego.
 * @param poprawna_odpowiedz poprawna odpowieedz na pytanie
 */
void Kolo_ratunkowe::uzyj_kola_ratunkowego(int poprawna_odpowiedz) {
	if (ilosc_kol > 0) {
		//jesli sa jeszcze dostepne kola ratunkowe
		ilosc_kol--;
		std::cout << "\nEliminacja dwoch niepoprawnych odpowiedzi." << std::endl;
		std::cout << "Ktoras z tych odpowiedzi jest poprawna: ";
		int wylosowana;
		//losuj naturalna dopoki nie bedzie rozna od poprawnej odpowiedzi
		do {
			wylosowana = losuj_naturalna(1, 4);
		} while (wylosowana == poprawna_odpowiedz);

		//kolejnosc wypisania odpowiedzi mozliwych do wyboru ma byc rosnaca
		if (poprawna_odpowiedz < wylosowana) {
			std::cout << poprawna_odpowiedz << " lub " << wylosowana << std::endl;
		}
		else {
			std::cout << wylosowana << " lub " << poprawna_odpowiedz << std::endl;
		}
		std::cout << "Zuzyto " << 3-ilosc_kol << " kolo ratunkowe. Mozesz wykorzystac jeszcze " << ilosc_kol << "!" << std::endl;
	}
	else {
		std::cout << "Wykorzystano wszystkie mozliwe kola ratunkowe!" << std::endl;
	}
}