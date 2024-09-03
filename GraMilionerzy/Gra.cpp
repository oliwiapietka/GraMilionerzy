#define _CRT_SECURE_NO_WARNINGS
#include "Gra.h"
#include "Gra_wieloosobowa.h"
#include "Gra_jednoosobowa.h"
#include "Prowadzacy.h"

#define MAX 20

void Gra::gra_jedengracz(std::string nazwa_gracza) {};

std::string Gra::gra_wielegraczy() {
    return "";
};

/*
 * Metoda odpowiada za wczytanie liczby 1 lub 2.
 * @return liczba wczytana liczba
 */
int Gra::wczytaj1lub2() {
    int liczba;
    while (!(std::cin >> liczba) || std::cin.peek() != '\n' || (liczba != 1 && liczba != 2))
    {
        std::cout << "\n\nBledne dane, podaj 1 lub 2: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return liczba;
}

/*
 * Metoda wczytuje aktualny czas, zapisuje go w tablicy znakow czas w formacie.
 * @param czas[] tablica przechowujaca wczytany czas
 */
void Gra::wczytaj_aktualny_czas(char czas[MAX]) {
    time_t aktualny_czas = time(NULL);
    struct tm* info_czas = localtime(&aktualny_czas);
    czas[MAX];
    strftime(czas, MAX, "%d.%m.%Y %H:%M:%S", info_czas);
}

/*
 * Metoda robi wpis z komunikatem i nazwa gracza do pliku.
 * @param nazwa_pliku plik do ktorego ma zostac zrobiony wpis
 * @param komunikat komunikat, ktory ma zostac wpisany do pliku
 * @param nazwa_gracza nazwa gracza, ktora ma zostac wpisana do pliku
 */
void Gra::wpisz_do_pliku(std::string nazwa_pliku, std::string komunikat, std::string nazwa_gracza)
{
    //otwarcie pliku w trybie append
    std::ofstream stream(nazwa_pliku, std::ios_base::app);
    if (!stream.is_open())
    {
        //nie otwarto pliku
        std::cerr << "\n\nNie otwarto pliku o nazwie " << nazwa_pliku;
    }

    char czas[MAX];
    wczytaj_aktualny_czas(czas);
    stream << czas << " " << komunikat;
    if (nazwa_gracza != "brak") {
        stream << nazwa_gracza;
    }
    stream << "\n";

    //zamkniecie pliku
    stream.close();
}

/*
 * Metoda robi wpis z komunikatem i danymi typu double do pliku.
 * @param nazwa_pliku plik do ktorego ma zostac zrobiony wpis
 * @param komunikat komunikat, ktory ma zostac wpisany do pliku
 * @param dane dane typu double, ktore maja zostac wpisane do pliku
 */
void Gra::wpisz_do_pliku_z_double(std::string nazwa_pliku, std::string komunikat, double dane)
{
    //otwarcie pliku w trybie append
    std::ofstream stream(nazwa_pliku, std::ios_base::app);
    if (!stream.is_open())
    {
        //nie otwarto pliku
        std::cerr << "\n\nNie otwarto pliku o nazwie " << nazwa_pliku;
    }

    char czas[MAX];
    wczytaj_aktualny_czas(czas);
    stream << czas << " " << komunikat;
    if (dane >= 0) {
        stream << dane;
    }
    stream << "\n";

    //zamkniecie pliku
    stream.close();
}

/*
 * Wczytuje liczbe naturalna z danego zakresu liczb i przeprowadza kontrole poprawnosci danych.
 * @param ograniczenie_dolne liczba od ktorej wczytana liczba ma byc wieksza
 * @param ograniczenie_gorne liczba od ktorej wczytana liczba ma byc mniejsza
 */
int Gra::wczytaj_naturalna(int ograniczenie_dolne, int ograniczenie_gorne)
{
    int liczba;
    while (!(std::cin >> liczba) || std::cin.peek() != '\n' || liczba <= 0 || liczba > ograniczenie_gorne || liczba < ograniczenie_dolne)
    {
        std::cout << "\n\nBledne dane, popraw: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return liczba;
}

/*
 * Wczytuje napis i przeprowadza kontrole poprawnosci danych.
 * @param napis wczytany napis
 */
void Gra::wczytaj_string(std::string& napis)
{
    while (!(std::cin >> napis) || napis.length() > MAX)
    {
        std::cout << "\nBledne dane, popraw: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

/*
 * Wczytuje nazwe gracza, przy czym sprawdza czy nazwa gracza nie jest taka sama jak nazwa ktoregos z poprzednich graczy.
 * @param poprzednie_nazwy nazwy poprzednich uzytkownikow w danej rozgrywce
 * @param ilosc_poprzenich_graczy ilosc poprzednich graczy w danej rozgrywce
 * @return nazwa wczytana nazwa gracza
 */
std::string Gra::wczytaj_nazwe_gracza(const std::string* poprzednie_nazwy, int ilosc_poprzednich_graczy) {
    std::string nazwa;

    std::cout << "Podaj nazwe gracza: ";
    wczytaj_string(nazwa);
    if (poprzednie_nazwy != nullptr && ilosc_poprzednich_graczy >= 0) {
        for (int i = 0; i < ilosc_poprzednich_graczy; ++i) {
            while (nazwa == poprzednie_nazwy[i]) {
                std::cout << "Ta nazwa jest juz zajeta, podaj inna: " << std::endl;
                wczytaj_string(nazwa);
            }
        }
    }

    return nazwa;
}

/*
 * Wczytuje znak y i przeprowadza kontrole poprawnosci danych.
 * @return litera pobrana litera
 */
char Gra::wczytaj_y()
{
    char litera;
    while (!(std::cin >> litera) || std::cin.peek() != '\n' || toupper(litera) != 'Y') {
        std::cout << "Bledne dane, podaj y lub n: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return litera;
}

/*
 * Wczytuje znak y lub n i przeprowadza kontrole poprawnosci danych.
 * @return litera pobrana litera
 */
char Gra::wczytaj_yn()
{
    char litera;
    while (!(std::cin >> litera) || std::cin.peek() != '\n' || (toupper(litera) != 'Y' && toupper(litera) != 'N')) {
        std::cout << "Bledne dane, podaj y lub n: " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return litera;
}

//void Gra::rozpocznij() {
//    Prowadzacy prowadzacy;
//    prowadzacy.napis();
//
//    char odp;
//    do {
//        prowadzacy.wyjasnienie_zasad();
//        prowadzacy.wersja_gry();
//        int wybor_wersji_gry = wczytaj1lub2();
//
//        wpisz_do_pliku("rozgrywka.txt", "Rozpoczeto gre.", "brak");
//
//        if (wybor_wersji_gry == 1) {
//            Gra_jednoosobowa gra_jednoosobowa;
//            gra_jednoosobowa.gra_jedengracz("");
//        }
//        else if (wybor_wersji_gry == 2) {
//            Gra_wieloosobowa gra_wieloosobowa;
//            std::string nazwa_gracza = gra_wieloosobowa.gra_wielegraczy();
//            Gra_jednoosobowa gra_jednoosobowa;
//            gra_jednoosobowa.gra_jedengracz(nazwa_gracza);
//        }
//
//        std::cout << "\nCzy chcesz zagrac jeszcze raz? (y/n): " << std::endl;
//        odp = wczytaj_yn();
//
//    } while (toupper(odp) == 'Y');
//}

/*
 * Pobiera od uzytkownika wybor wersji gry i zaleznie od wybranej wersji przeprowadza odpowiedni typ rozgrywki.
 */
void Gra::rozpocznij() {
    Prowadzacy prowadzacy;
    prowadzacy.napis();

    char odp;
    do {
        prowadzacy.wyjasnienie_zasad();
        //wybor wersji gry
        prowadzacy.wersja_gry();
        int wybor_wersji_gry = wczytaj1lub2();

        wpisz_do_pliku("rozgrywka.txt", "Rozpoczeto gre.", "brak");

        Gra* gra = nullptr;
        Gra* gra2 = nullptr;
        if (wybor_wersji_gry == 1) {
            gra = new Gra_jednoosobowa();
        }
        else if (wybor_wersji_gry == 2) {
            gra = new Gra_wieloosobowa();
            gra2 = new Gra_jednoosobowa();
        }

        if (gra) {
            if (wybor_wersji_gry == 2) {
                //gra wieloosobowa
                //nazwa gracza - nazwa wygranego gracza, ktory ma przejsc do trybu gry jednoosobowej
                std::string nazwa_gracza = gra->gra_wielegraczy();
                gra2->gra_jedengracz(nazwa_gracza);
            }
            else {
                gra->gra_jedengracz("");
            }

            delete gra;
            if (gra2 != nullptr) {
                delete gra2;
            }
        }

        std::cout << "\nCzy chcesz zagrac jeszcze raz? (y/n): " << std::endl;
        odp = wczytaj_yn();

    } while (toupper(odp) == 'Y');
}

