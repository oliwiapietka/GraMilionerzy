#ifndef GRA_JEDNOOSOBOWA_H
#define GRA_JEDNOOSOBOWA_H
#include "Gra.h"
#include "Jeden_gracz.h"
#include "Kolo_ratunkowe.h"

class Gra_jednoosobowa : public Gra {
public:
    void gra_jedengracz(std::string nazwa_gracza);
    void rozpocznij();
};

#endif