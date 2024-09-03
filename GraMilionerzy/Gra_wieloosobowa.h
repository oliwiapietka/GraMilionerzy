#ifndef GRA_WIELOOSOBOWA_H
#define GRA_WIELOOSOBOWA_H
#include "Gra.h"
#include "Gra_jednoosobowa.h"

class Gra_wieloosobowa : public Gra {
public:
    std::string gra_wielegraczy();
    void rozpocznij();
    int wczytaj_pyt_chronologiczne();
    void wczytaj_nazwy_graczy(int ilosc_osob_w_grze, std::string nazwy_graczy[]);
};

#endif