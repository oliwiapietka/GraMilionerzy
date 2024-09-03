#include "Pytanie_wielegraczy.h"
#include <fstream>
#include <sstream>

Pytanie_wielegraczy::Pytanie_wielegraczy() : Pytanie(), poprawna_odpowiedz{} {}
Pytanie_wielegraczy::Pytanie_wielegraczy(const std::string& _tresc_pyt, int poprawna_odp[4], int nr_pyt) : Pytanie(_tresc_pyt, nr_pyt) {
    for (int i = 0; i < 4; ++i) {
        poprawna_odpowiedz[i] = poprawna_odp[i];
    }
}
Pytanie_wielegraczy::Pytanie_wielegraczy(const Pytanie_wielegraczy& pw) : Pytanie(pw) {
    for (int i = 0; i < 4; ++i) {
        poprawna_odpowiedz[i] = pw.poprawna_odpowiedz[i];
    }
}
Pytanie_wielegraczy::~Pytanie_wielegraczy() {}

int* Pytanie_wielegraczy::getPoprawnaOdp() {
    return &poprawna_odpowiedz[0];
}

/*
 * Metoda wczytuje pytania z pliku o podanej nazwie.
 * @param nazwa_pliku nazwa pliku, z ktorego wczytywane sa pytania
 */
void Pytanie_wielegraczy::wczytaj_pytania(std::string nazwa_pliku) {
    std::ifstream stream(nazwa_pliku);
    if (!stream.is_open()) {
        //nie otwarto pliku
        std::cout << "\n\nNie otwarto pliku o nazwie " << nazwa_pliku;
        exit(1);
    }

    std::string wiersz;
    while (std::getline(stream, wiersz)) {
        int nr_pytania;
        std::string tresc_pytania;

        //znajdujemy pozycje, od ktorej rozpoczyna sie odpowiedz na pytanie 
        size_t pos = wiersz.size() - 4;
        //wczytujemy 4 ostatnie znaki wierszu jako poprawna odpowiedz
        std::istringstream ss(wiersz.substr(pos));
        for (int i = 0; i < 4; ++i) {
            ss >> poprawna_odpowiedz[i];
        }

        //wyodrebnienie numeru pytania i tresci pytania
        std::istringstream ss2(wiersz.substr(0, pos));
        ss2 >> nr_pytania;
        std::getline(ss2, tresc_pytania);

        Pytanie_wielegraczy* pom = new Pytanie_wielegraczy(tresc_pytania, poprawna_odpowiedz, nr_pytania);

        //utworzenie listy
        if (!getNast()) {
            setNast(pom);
        }
        else {
            Pytanie* aktualny = getNast();
            while (aktualny->getNast() != nullptr) {
                aktualny = aktualny->getNast();
            }
            aktualny->setNast(pom);
        }
    }

    //zamkniecie pliku
    stream.close();
}