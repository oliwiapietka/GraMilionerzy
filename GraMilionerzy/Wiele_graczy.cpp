#include "Wiele_graczy.h"

Wiele_graczy::Wiele_graczy(const std::string& nazwa_gracza, double czas_odp, bool poprawnosc_odp) : Gracz(nazwa_gracza)
{
	czas_odpowiedzi = czas_odp;
	poprawnosc_odpowiedzi = poprawnosc_odp;
};

Wiele_graczy::Wiele_graczy() : czas_odpowiedzi(0), poprawnosc_odpowiedzi(false) {};
Wiele_graczy::Wiele_graczy(const Wiele_graczy& wg) : Gracz(wg), czas_odpowiedzi(wg.czas_odpowiedzi), poprawnosc_odpowiedzi(wg.poprawnosc_odpowiedzi) {};

Wiele_graczy::~Wiele_graczy()
{
	delete nast_gracz;
	nast_gracz = nullptr;
}

double Wiele_graczy::getCzasOdpowiedzi() const { return czas_odpowiedzi; }
bool Wiele_graczy::getPoprawnoscOdpowiedzi() const { return poprawnosc_odpowiedzi; }

void Wiele_graczy::wypisz_graczy()
{
	Gracz::wypisz_graczy();
	std::cout << "Czas odpowiedzi: " << czas_odpowiedzi << std::endl;
	std::cout << "Poprawnosc odpowiedzi: " << poprawnosc_odpowiedzi << std::endl;
}