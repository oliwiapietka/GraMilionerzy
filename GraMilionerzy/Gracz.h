#ifndef GRACZ_H
#define GRACZ_H
#include <iostream>
#include <string>

class Gracz
{
protected:
	std::string nazwa_gracza;
	Gracz* nast_gracz;

public:
	Gracz();
	Gracz(const std::string& nazwa_gracza);
	Gracz(const Gracz& g);
	~Gracz();

	Gracz* getNast();
	void setNast(Gracz* nast);

	virtual double getCzasOdpowiedzi() const = 0;
	virtual bool getPoprawnoscOdpowiedzi() const = 0;
	virtual void wypisz_graczy();
	std::string getNazwaGracza() const;
};

#endif