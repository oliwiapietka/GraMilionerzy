#ifndef PYTANIE_JEDENGRACZ_H
#define PYTANIE_JEDENGRACZ_H

#include "Pytanie.h"

class Pytanie_jedengracz : public Pytanie {
private:
    int poprawna_odpowiedz;

public:
    Pytanie_jedengracz();
    Pytanie_jedengracz(const std::string& _tresc_pyt, int poprawna_odp, int nr_pyt);
    Pytanie_jedengracz(const Pytanie_jedengracz& pj);
    ~Pytanie_jedengracz();

    void wczytaj_pytania(std::string nazwa_pliku) override;
    int* getPoprawnaOdp() override;
    bool sprawdz_czy_powt(int pytania[], int i, int pytanie);
    Pytanie* wylosuj_pytanie(int poziom, int i, int nr_wylosowanych_pytan[]);
};

#endif