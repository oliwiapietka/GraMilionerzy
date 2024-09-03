#ifndef WIELE_GRACZY_H
#define WIELE_GRACZY_H
#include "Gracz.h"

class Wiele_graczy : public Gracz
{
	double czas_odpowiedzi;
	bool poprawnosc_odpowiedzi;

public:
	Wiele_graczy();
	Wiele_graczy(const std::string& nazwa_gracza, double czas_odp, bool poprawnosc_odp);
	Wiele_graczy(const Wiele_graczy& wg);
	~Wiele_graczy();

	double getCzasOdpowiedzi() const;
	bool getPoprawnoscOdpowiedzi() const;

	void wypisz_graczy() override;
};

#endif