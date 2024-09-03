#include "Pytanie_jedengracz.h"
#include <fstream>
#include <sstream>

Pytanie_jedengracz::Pytanie_jedengracz() : Pytanie(), poprawna_odpowiedz(0) {}

Pytanie_jedengracz::Pytanie_jedengracz(const std::string& _tresc_pyt, int poprawna_odp, int nr_pyt)
    : Pytanie(_tresc_pyt, nr_pyt), poprawna_odpowiedz(poprawna_odp) {}

Pytanie_jedengracz::Pytanie_jedengracz(const Pytanie_jedengracz& pj) : Pytanie(pj), poprawna_odpowiedz(pj.poprawna_odpowiedz) {}

Pytanie_jedengracz::~Pytanie_jedengracz()
{
    delete nast_pyt;
    nast_pyt = nullptr;
}

int* Pytanie_jedengracz::getPoprawnaOdp() {
    return &poprawna_odpowiedz;
}

/*
 * Metoda wczytuje pytania z pliku o podanej nazwie.
 * @param nazwa_pliku nazwa pliku, z ktorego wczytywane sa pytania
 */
void Pytanie_jedengracz::wczytaj_pytania(std::string nazwa_pliku) {
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

        //wyszukanie ostatniego wystapienia 1, 2, 3, 4 w wierszu
        size_t pozycja = wiersz.find_last_of("1234");
        //pobranie tekstu od okreslonej pozycji i zamiana na int 
        poprawna_odpowiedz = std::stoi(wiersz.substr(pozycja));

        //wyodrebnienie numeru pytania i tresci pytania
        std::istringstream ss(wiersz.substr(0, pozycja));
        ss >> nr_pytania;
        std::getline(ss, tresc_pytania);

        Pytanie_jedengracz* pom = new Pytanie_jedengracz(tresc_pytania, poprawna_odpowiedz, nr_pytania);

        //utworzenie listy
        if (!nast_pyt) {
            nast_pyt = pom;
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

/*
 * Metoda sprawdza, czy pytanie o numerze 'pytanie' zostalo juz wczesniej wylosowane.
 * @param pytania[] tablica przechowujaca numery wczesniej wylosowanych pytan
 * @param i aktualny numer pytania (liczony od 0)
 * @param pytanie numer pytania, ktore ma zostac sprawdzone
 * @return true, jesli pytanie zostalo juz wczesniej wylosowane, w przeciwnym razie false
 */
bool Pytanie_jedengracz::sprawdz_czy_powt(int pytania[], int i, int pytanie) {
    for (int j = 0; j < i; ++j) {
        if (pytania[j] == pytanie) {
            return true;
        }
    }
    return false;
}

/*
* Metoda losuje pytania z przedzialu zaleznego od poziomu.
* @param poziom wybrany poziom pytan
* @param i aktualny numer pytania (liczony od 0)
* @param nr_wylosowanych_pytan[] tablica przechowujaca numery wczesniej wylosowanych pytan
* @return wskaznik do obiektu Pytania
*/
Pytanie* Pytanie_jedengracz::wylosuj_pytanie(int poziom, int i, int nr_wylosowanych_pytan[]) {
    //utworzenie listy z pytaniami 
    Pytanie* lista_pytan_poziom = new Pytanie_jedengracz();
    //wczytanie do listy pytan z pliku o nazwie "pytania_jedengracz.txt"
    lista_pytan_poziom->wczytaj_pytania("pytania_jedengracz.txt");

    Pytanie* wylosowane_pytanie;

    //pytanie bedzie losowane dopoki nie bedzie rozne od wczesniej wylosowanych pytan
    do {
        //zaleznie od poziomu pytanie zostanie wylosowane z innego przedzialu
        if (poziom == 1) {
            wylosowane_pytanie = lista_pytan_poziom->wylosuj_pytanie_z_przedzialu(lista_pytan_poziom, 1, 25);
        }
        else if (poziom == 2) {
            wylosowane_pytanie = lista_pytan_poziom->wylosuj_pytanie_z_przedzialu(lista_pytan_poziom, 26, 50);
        }
        else if (poziom == 3) {
            wylosowane_pytanie = lista_pytan_poziom->wylosuj_pytanie_z_przedzialu(lista_pytan_poziom, 51, 75);
        }
        else {
            wylosowane_pytanie = lista_pytan_poziom->wylosuj_pytanie_z_przedzialu(lista_pytan_poziom, 76, 100);
        }
    } while (sprawdz_czy_powt(nr_wylosowanych_pytan, i, wylosowane_pytanie->getNrPytania()));

    wylosowane_pytanie->wypisz_pytanie();

    //delete lista_pytan_poziom;////////////////////////////???????????????????????????????????????????????????????
    return wylosowane_pytanie;
}





