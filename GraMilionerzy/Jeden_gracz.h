#ifndef JEDEN_GRACZ_H
#define JEDEN_GRACZ_H
#include "Gracz.h"

class Jeden_gracz : public Gracz
{
	bool poprawnosc_odpowiedzi;
	int wygrana;

public:
	Jeden_gracz();
	Jeden_gracz(const std::string& nazwa_gracza, bool poprawnosc_odp, int wygrana, int gwarantowana_wygrana);
	Jeden_gracz(const Jeden_gracz& wg);
	~Jeden_gracz();

	bool getPoprawnoscOdpowiedzi() const;
	double getCzasOdpowiedzi() const;
	int getWygrana() const;
	void setWygrana(int w);

	void wypisz_graczy() override;
};

#endif