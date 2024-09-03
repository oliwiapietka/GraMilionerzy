#include "Gracz.h"

Gracz::Gracz() : nazwa_gracza("gracz"), nast_gracz(nullptr) {}
Gracz::Gracz(const std::string& nazwa_gracza) : nazwa_gracza(nazwa_gracza), nast_gracz(nullptr) {}
Gracz::Gracz(const Gracz& g) : nazwa_gracza(g.nazwa_gracza), nast_gracz(nullptr) {}

Gracz::~Gracz()
{
	delete nast_gracz;
	nast_gracz = nullptr;
}

Gracz* Gracz::getNast()
{
	return nast_gracz;
}

void Gracz::setNast(Gracz* nast)
{
	nast_gracz = nast;
}

std::string Gracz::getNazwaGracza() const {
	return nazwa_gracza;
}

void Gracz::wypisz_graczy()
{
	std::cout << "\nNazwa gracza: " << nazwa_gracza << std::endl;
}

