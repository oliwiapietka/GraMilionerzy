#include "Jeden_gracz.h"

Jeden_gracz::Jeden_gracz(const std::string& nazwa_gracza, bool poprawnosc_odp, int _wygrana, int _gwarantowana_wygrana) : Gracz(nazwa_gracza)
{
	poprawnosc_odpowiedzi = poprawnosc_odp;
	wygrana = _wygrana;
}

Jeden_gracz::Jeden_gracz() : poprawnosc_odpowiedzi(false), wygrana(0) {};
Jeden_gracz::Jeden_gracz(const Jeden_gracz& wg) : Gracz(wg), poprawnosc_odpowiedzi(wg.poprawnosc_odpowiedzi), wygrana(wg.wygrana) {};

Jeden_gracz::~Jeden_gracz()
{
	delete nast_gracz;
	nast_gracz = nullptr;
}

bool Jeden_gracz::getPoprawnoscOdpowiedzi() const { return poprawnosc_odpowiedzi; }

int Jeden_gracz::getWygrana() const { return wygrana; }

void Jeden_gracz::setWygrana(int w) {
	if (w > 0) {
		wygrana = w;
	}
}

double Jeden_gracz::getCzasOdpowiedzi() const { return 0; }

void Jeden_gracz::wypisz_graczy()
{
	Gracz::wypisz_graczy();
	std::cout << "Poprawnosc odpowiedzi: " << poprawnosc_odpowiedzi << std::endl;
}