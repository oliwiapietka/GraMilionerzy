#ifndef GRA_H
#define GRA_H
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "Wiele_graczy.h"
#include "Pytanie_jedengracz.h"
#include "Pytanie_wielegraczy.h"
#include "Prowadzacy.h"

#define MAX 20

class Gra {
private:
    std::string nazwy_graczy[6];
    int ilosc_graczy;
    Gracz* lista_graczy;
    Pytanie* lista_pytan_wielegraczy;
public:
    Gra() : ilosc_graczy(0), lista_graczy(nullptr), lista_pytan_wielegraczy(nullptr) {}
    ~Gra() {
        delete lista_graczy;
        delete lista_pytan_wielegraczy;
    }

    virtual void rozpocznij(); //?? czy virtual
    void wpisz_do_pliku(std::string nazwa_pliku, std::string komunikat, std::string nazwa_gracza);
    void wpisz_do_pliku_z_double(std::string nazwa_pliku, std::string komunikat, double dane);
    void wczytaj_aktualny_czas(char czas[MAX]);
    int wczytaj1lub2();
    int wczytaj_naturalna(int ograniczenie_dolne, int ograniczenie_gorne);
    void wczytaj_string(std::string& str);
    std::string wczytaj_nazwe_gracza(const std::string* poprzednie_nazwy, int ilosc_poprzednich_graczy);
    char wczytaj_y();
    char wczytaj_yn();
    virtual void gra_jedengracz(std::string nazwa_gracza);
    virtual std::string gra_wielegraczy();
};

#endif