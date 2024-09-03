#ifndef PYTANIE_H
#define PYTANIE_H
#include <iostream>
#include <string>

class Pytanie {
protected:
    std::string tresc_pytania;
    int nr_pytania;
    Pytanie* nast_pyt;

public:
    Pytanie();
    Pytanie(const std::string& tresc_pyt, int nr_pyt);
    Pytanie(const Pytanie& p);
    ~Pytanie();

    Pytanie* getNast() const;
    void setNast(Pytanie* nast);

    int getNrPytania() const;

    void wypisz_pytanie();
    
    virtual void wczytaj_pytania(std::string nazwa_pliku) = 0;
    virtual int* getPoprawnaOdp() = 0;//???
    Pytanie* wypisz_pytanie_z_przedzialu(Pytanie* wsk, int ograniczenie_dolne, int ograniczenie_gorne);
    Pytanie* wylosuj_pytanie_z_przedzialu(Pytanie* wsk, int ograniczenie_dolne, int ograniczenie_gorne);

    int losuj_naturalna(int ograniczenie_dolne, int ograniczenie_gorne);
};

#endif
