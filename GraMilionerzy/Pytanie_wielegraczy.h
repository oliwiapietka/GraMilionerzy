#ifndef PYTANIE_WIELEGRACZY_H
#define PYTANIE_WIELEGRACZY_H

#include "Pytanie.h"

class Pytanie_wielegraczy : public Pytanie {
private:
    int poprawna_odpowiedz[4];

public:
    Pytanie_wielegraczy();
    Pytanie_wielegraczy(const std::string& _tresc_pyt, int poprawna_odp[4], int nr_pyt);
    Pytanie_wielegraczy(const Pytanie_wielegraczy& pw);
    ~Pytanie_wielegraczy();

    void wczytaj_pytania(std::string nazwa_pliku) override;
    int* getPoprawnaOdp() override;
};

#endif
