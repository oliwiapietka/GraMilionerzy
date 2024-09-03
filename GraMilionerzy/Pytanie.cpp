#include <iostream>
#include <string>

#include "Pytanie.h"

Pytanie::Pytanie() : tresc_pytania(""), nr_pytania(0), nast_pyt(nullptr) {}
Pytanie::Pytanie(const std::string& tresc_pyt, int nr_pyt) : tresc_pytania(tresc_pyt), nr_pytania(nr_pyt), nast_pyt(nullptr) {}
Pytanie::Pytanie(const Pytanie& p) : tresc_pytania(p.tresc_pytania), nr_pytania(p.nr_pytania), nast_pyt(nullptr) {}

Pytanie::~Pytanie()
{
    delete nast_pyt;
    nast_pyt = nullptr;
}

Pytanie* Pytanie::getNast() const { return nast_pyt; }
void Pytanie::setNast(Pytanie* nast) {
    nast_pyt = nast;
}

int Pytanie::getNrPytania() const { return nr_pytania; }

/*
 * Losuje liczbe naturalna z danego zakresu liczb.
 * @param ograniczenie_dolne liczba od ktorej wylosowana liczba ma byc wieksza
 * @param ograniczenie_gorne liczba od ktorej wylosowana liczba ma byc mniejsza
 */
int Pytanie::losuj_naturalna(int ograniczenie_dolne, int ograniczenie_gorne) {
    int liczba = rand() % (ograniczenie_gorne - ograniczenie_dolne) + ograniczenie_dolne;
    return liczba;
}

void Pytanie::wypisz_pytanie()
{
    std::cout << tresc_pytania << std::endl;
}

/*
 * Metoda odpowiada za wylosowanie pytania z przedzialu.
 * @param wsk wskaznik na pytanie
 * @param ograniczenie_dolne liczba od ktorej wylosowana liczba ma byc wieksza
 * @param ograniczenie_gorne liczba od ktorej wylosowana liczba ma byc mniejsza
 * @return pom wskaznika na wylosowane pytanie
 */
Pytanie* Pytanie::wylosuj_pytanie_z_przedzialu(Pytanie* wsk, int ograniczenie_dolne, int ograniczenie_gorne) {
    Pytanie* pom = wsk;

    //wylosowanie liczby naturalnej z przedzialu
    int wylosowana_liczba = losuj_naturalna(ograniczenie_dolne, ograniczenie_gorne);
    while (pom) {
        if (pom->nr_pytania == wylosowana_liczba) {
            //pytanie o numerze rownym wylosowanej liczbie
            break;
        }
        pom = pom->getNast();
    }

    return pom;
}

/*
 * Metoda odpowiada za wylosowanie pytania z przedzialu i wypisania go.
 * @param wsk wskaznik na pytanie
 * @param ograniczenie_dolne liczba od ktorej wylosowana liczba ma byc wieksza
 * @param ograniczenie_gorne liczba od ktorej wylosowana liczba ma byc mniejsza
 * @return pom wskaznika na wylosowane pytanie
 */
Pytanie* Pytanie::wypisz_pytanie_z_przedzialu(Pytanie* wsk, int ograniczenie_dolne, int ograniczenie_gorne) {
    //wylosowanie pytania
    Pytanie* pom = wylosuj_pytanie_z_przedzialu(wsk, ograniczenie_dolne, ograniczenie_gorne);
    //wypisanie pytania
    pom->wypisz_pytanie();
    return pom;
}