#include "Gra_wieloosobowa.h"

/*
 * Metoda wczytuje od odpowiedz uzytkownika, ktora musi byc liczba czterocyfrowa skladajaca sie z cyfr 1, 2, 3 i 4, gdzie kazda z cyfr wystepuje tylko raz.
 * @return liczba liczba w poprawnym formacie pobrana od uzytkownika
 */
int Gra_wieloosobowa::wczytaj_pyt_chronologiczne() {
    int liczba;
    while (!(std::cin >> liczba) || std::cin.peek() != '\n' ||
        (liczba != 1234 && liczba != 1243 && liczba != 1324 && liczba != 1342 && liczba != 1423 && liczba != 1432 &&
            liczba != 2134 && liczba != 2143 && liczba != 2314 && liczba != 2341 && liczba != 2413 && liczba != 2431 &&
            liczba != 3124 && liczba != 3142 && liczba != 3214 && liczba != 3241 && liczba != 3412 && liczba != 3421 &&
            liczba != 4123 && liczba != 4132 && liczba != 4213 && liczba != 4231 && liczba != 4312 && liczba != 4321))
    {
        std::cout << "\n\nBledne dane, odpowiedz musi skladac sie z cyfr: 1, 2, 3, 4 bez powtorzen, popraw: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return liczba;
}

/*
 * Metoda pobiera nazwy graczy i robi do pliku wpis dotyczacy wyboru nazw graczy.
 * @param ilosc_osob_w_grze liczba liczba graczy
 * @param nazwy_graczy[] tablica przechowujaca nazwy graczy
 */
void Gra_wieloosobowa::wczytaj_nazwy_graczy(int ilosc_osob_w_grze, std::string nazwy_graczy[]) {
    int ilosc_graczy = 0;
    for (int i = 0; i < ilosc_osob_w_grze; ++i)
    {
        std::string nazwa_gracza = wczytaj_nazwe_gracza(nazwy_graczy, ilosc_graczy);
        wpisz_do_pliku("rozgrywka.txt", "Wybor nazwy gracza: ", nazwa_gracza);
        nazwy_graczy[i] = nazwa_gracza;
        ilosc_graczy++;
    }
}

/*
 * Metoda odpowiada za przeprowadzenie rozgrywki dla wielu graczy.
 * Pobiera nazwy graczy, wypisuje pytania i pobiera odpowiedz.
 * Sprawdza czas i poprawnosc odpowiedzi i wyznacza wygranego.
 * @return nazwa_wygranego_gracza nazwa gracza, ktory wygral rozgrywke w trybie wieloosobowym
 */
std::string Gra_wieloosobowa::gra_wielegraczy() {
    Gracz* lista_graczy = nullptr;
    Gracz* pom = nullptr;
    Pytanie* lista_pytan_wielegraczy = nullptr;

    std::string nazwy_graczy[6];
    bool poprawnosc_odp[6];
    bool czy_koniec_rozgrywki = false;
    std::string nazwa_wygranego_gracza;

    Prowadzacy prowadzacy;
    lista_pytan_wielegraczy = new Pytanie_wielegraczy();

    std::cout << "\nW ile osob chcesz zagrac (min 2, max 6): " << std::endl;
    int ilosc_osob_w_grze = wczytaj_naturalna(2, 6);
    wczytaj_nazwy_graczy(ilosc_osob_w_grze, nazwy_graczy);

    prowadzacy.wyjasnienie_zasad_wieloosobowej();

    lista_pytan_wielegraczy->wczytaj_pytania("pytania_wielegraczy.txt");

    while (!czy_koniec_rozgrywki) {
        for (int i = 0; i < ilosc_osob_w_grze; ++i) {
            prowadzacy.gotowosc_gracza(i, nazwy_graczy);
            wczytaj_y();

            std::cout << "\n";
            //wypisanie pytania
            Pytanie* wylosowane_pytanie = lista_pytan_wielegraczy->wypisz_pytanie_z_przedzialu(lista_pytan_wielegraczy, 101, 105);
            wpisz_do_pliku("rozgrywka.txt", "Wylosowanie pytania dla gracza ", nazwy_graczy[i]);
            //wczytanie czasu wyswietlenia pytania
            clock_t start = clock();
            //pobranie odpowiedzi od gracza
            int odp_gracza = wczytaj_pyt_chronologiczne();
            wpisz_do_pliku("rozgrywka.txt", "Pobranie odpowiedzi gracza ", nazwy_graczy[i]);
            //wczytanie czasu odpowiedzi zgodnej z zadanym formatem
            clock_t koniec = clock();
            //pobranie poprawnej odpowiedzi
            int* poprawne_odpowiedzi = wylosowane_pytanie->getPoprawnaOdp();
            //obliczenie czasu odpowiedzi
            double czas_odpowiedzi = (double)(koniec - start) / CLOCKS_PER_SEC;
            bool czy_poprawna = true;

            if (odp_gracza != poprawne_odpowiedzi[0]) {
                //odpowiedz niepoprawna
                czy_poprawna = false;
            }

            if (czy_poprawna) {
                //odpowiedz poprawna
                std::cout << "Poprawna odpowiedz!" << std::endl;
                std::cout << "Czas odpowiedzi: " << czas_odpowiedzi << std::endl;
                wpisz_do_pliku("rozgrywka.txt", "Poprawna odpowiedz udzielona przez gracza ", nazwy_graczy[i]);
                wpisz_do_pliku_z_double("rozgrywka.txt", "Czas odpowiedzi: ", czas_odpowiedzi);
                poprawnosc_odp[i] = true;
            }
            else {
                //odpowiedz niepoprawna
                std::cout << "Odpowiedz niepoprawna!" << std::endl;
                std::cout << "Czas odpowiedzi: " << czas_odpowiedzi << std::endl;
                wpisz_do_pliku("rozgrywka.txt", "Niepoprawna odpowiedz udzielona przez gracza ", nazwy_graczy[i]);
                wpisz_do_pliku_z_double("rozgrywka.txt", "Czas odpowiedzi: ", czas_odpowiedzi);
                poprawnosc_odp[i] = false; 
            }

            pom = new Wiele_graczy(nazwy_graczy[i], czas_odpowiedzi, czy_poprawna);

            //utworzenie listy graczy
            if (lista_graczy == nullptr)
            {
                lista_graczy = pom;
            }
            else
            {
                Gracz* aktualny = lista_graczy;
                while (aktualny->getNast() != nullptr)
                {
                    aktualny = aktualny->getNast();
                }
                aktualny->setNast(pom);
            }

        }

        Gracz* aktualny_gracz = lista_graczy;
        Gracz* wygrany = nullptr;

        while (aktualny_gracz) {
            if (aktualny_gracz->getPoprawnoscOdpowiedzi()) {
                //jesli gracz udzielil poprawnej odpowiedzi
                if (!wygrany || aktualny_gracz->getCzasOdpowiedzi() < wygrany->getCzasOdpowiedzi()) {
                    //nie ma wygranego lub czas odpowiedzi aktualnego gracza jest krotszy od czasu odpowiedzi poprzedniego gracza, ktory udzielil poprawna odpowiedz
                    wygrany = aktualny_gracz;
                    nazwa_wygranego_gracza = wygrany->getNazwaGracza();
                }
                else if (aktualny_gracz->getCzasOdpowiedzi() == wygrany->getCzasOdpowiedzi()) {
                    //jesli czas odpowiedzi jest taki sam
                    wygrany = nullptr;
                }
            }
            aktualny_gracz = aktualny_gracz->getNast();
        }

        if (wygrany != nullptr) {
            //jesli jest wygrany
            czy_koniec_rozgrywki = true;
            prowadzacy.wygrana_wielegraczy(wygrany->getNazwaGracza());
            wpisz_do_pliku("rozgrywka.txt", "Wygrany gracz: ", wygrany->getNazwaGracza());
            wpisz_do_pliku_z_double("rozgrywka.txt", "Czas odpowiedzi wygranego gracza: ", wygrany->getCzasOdpowiedzi());
        }
        else {
            delete lista_graczy;
            lista_graczy = nullptr;
        }
    }

    return nazwa_wygranego_gracza;
}

void Gra_wieloosobowa::rozpocznij() {
    //rozpoczecie rozgrywki dla wielu graczy
	gra_wielegraczy();
}