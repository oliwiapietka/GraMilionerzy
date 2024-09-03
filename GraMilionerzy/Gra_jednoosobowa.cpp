#include "Gra_jednoosobowa.h"

/*
 * Metoda odpowiada za przeprowadzenie rozgrywki dla jednego gracza.
 * @param nazwa_gracza nazwa gracza
 * Jezeli wczesniej zostal przeprowadzony tryb wieloosobowy to metoda ta przyjmie nazwe gracza, ktory wygral rozgrywke w trybie wieloosobowym.
 */
void Gra_jednoosobowa::gra_jedengracz(std::string nazwa_gracza) {
	//sprawdzenie czy mamy podana nazwe gracza, jesli nie - pobranie nazwy gracza
	if (nazwa_gracza == "") {
		nazwa_gracza = wczytaj_nazwe_gracza(nullptr, -1);
		wpisz_do_pliku("rozgrywka.txt", "Wybor nazwy gracza: ", nazwa_gracza);
	}
	Jeden_gracz gracz(nazwa_gracza, false, 0, 0);

	Prowadzacy prowadzacy;
	//wypisanie w konsoli zasad gry
	prowadzacy.wyjasnienie_zasad_jednoosobowej();
	//pobranie od gracza gotowosci do gry
	prowadzacy.gotowosc_gracza(0, &nazwa_gracza);
	char gotowosc = wczytaj_y();

	Kolo_ratunkowe kolo_ratunkowe;
	
	//pobranie od gracza wybranego typu rozgrywki: 1.pytania staja sie stopniowo trudniejsze 2.wybor stalego poziomu trudnosci
	prowadzacy.typ_rozgrywki();
	int typ_rozgrywki = wczytaj1lub2();
	
	wpisz_do_pliku("rozgrywka.txt", "Wybor typu rozgrywki", "");

	//jezeli gracz wybral staly poziom - wybor trudnosci rozgrywki od 1-najlatwiejszy do 4-najtrudniejszy
	int trudnosc_rozgrywki;
	int poziom_pytania = 1;
	if (typ_rozgrywki == 2) {
		prowadzacy.trudnosc_rozgrywki();
		trudnosc_rozgrywki = wczytaj_naturalna(1, 4);
		poziom_pytania = trudnosc_rozgrywki;
	}

	bool poprawnosc_odpowiedzi = true;
	int odpowiedz;
	int wartosc_pytan[12] = { 500, 1000, 2000, 5000, 10000, 20000, 40000, 75000, 125000, 250000, 500000, 1000000 };
	int nr_wylosowanych_pytan[12];
	char wykorzystanie_kola;

	for (int i = 0; i < 12; ++i) {
		std::cout << "\n\nPytanie o wartosci " << wartosc_pytan[i] << " zlotych:" << std::endl;

		//jezeli  gracz wybral rosnacy poziom gry - poziom pytan wzrasta co 3 pytania
		if (typ_rozgrywki == 1 && (i + 1) % 3 == 0) {
			poziom_pytania++;
		}

		Pytanie_jedengracz pytanie;
		//wylosowanie pytania
		Pytanie* wylosowane_pytanie = pytanie.wylosuj_pytanie(poziom_pytania, i, nr_wylosowanych_pytan);
		//wczytanie numeru wylosowanego pytania
		nr_wylosowanych_pytan[i] = wylosowane_pytanie->getNrPytania();

		//jezeli sa dostepne kola ratunkowe sprawdzenie czy gracz chce skorzystac z kola ratunkowego
		if (kolo_ratunkowe.getIloscKol() > 0) {
			std::cout << "\nCzy chcesz skorzystac z kola ratunkowego? (Y/N)" << std::endl;
			wykorzystanie_kola = wczytaj_yn();
			if (toupper(wykorzystanie_kola) == 'Y') {
				//uzycie kola ratunkowego
				kolo_ratunkowe.uzyj_kola_ratunkowego(*wylosowane_pytanie->getPoprawnaOdp());
				wpisz_do_pliku("rozgrywka.txt", "Skorzytsanie z kola ratunkowego przez gracza ", nazwa_gracza);
			}
		}		

		//pobranie odpowiedzi gracza
		std::cout << "\nPodaj odpowiedz: ";
		odpowiedz = wczytaj_naturalna(1, 4);
		wpisz_do_pliku("rozgrywka.txt", "Pobranie odpowiedzi gracza ", nazwa_gracza);

		//bledna odpowiedz
		if (*wylosowane_pytanie->getPoprawnaOdp() != odpowiedz) {
			poprawnosc_odpowiedzi = false;
			std::cout << "Bledna odpowiedz! " << std::endl;
			std::cout << "Poprawna odpowiedz to: " << *wylosowane_pytanie->getPoprawnaOdp() << std::endl;
			wpisz_do_pliku("rozgrywka.txt", "Podanie blednej odpowiedzi przez gracza ", nazwa_gracza);
			delete wylosowane_pytanie;
			break;
		}
		else {
			//poprawna odpowiedz
			poprawnosc_odpowiedzi = true;
			std::cout << "Poprawna odpowiedz! " << std::endl;
			wpisz_do_pliku("rozgrywka.txt", "Podanie prawidlowej odpowiedzi przez gracza ", nazwa_gracza);
			//udzielenie poprawnej odpowiedzi na 2 i 7 pytanie powoduje osiagniecie progu gwarantowanego
			if (i == 1 || i == 6) {
				wpisz_do_pliku("rozgrywka.txt", "Osiagniecie progu gwarantowanego przez gracza: ", nazwa_gracza);
				prowadzacy.prog_gwarantowany(wartosc_pytan, i);
				//ustawienie wygranej na gwarantowana kwote
				gracz.setWygrana(wartosc_pytan[i]);
			}
		}

		//pobranie od uzytkownika odpowiedzi czy chce kontynuowac gre czy odejsc z kwota o wartosci ostatniego pytania
		if (i != 1 && i != 6) {
			prowadzacy.kontynuacja_gry(wartosc_pytan, i);
			int zakonczenie_gry = wczytaj1lub2();
			if (zakonczenie_gry == 2) {
				//zakonczenie gry i ustawienie wygranej na wartosc ostatniego pytania 
				gracz.setWygrana(wartosc_pytan[i]);
				delete wylosowane_pytanie;
				break;
			}
		}

		delete wylosowane_pytanie;
	}
	wpisz_do_pliku("rozgrywka.txt", "Koniec rozgrywki gracza ", gracz.getNazwaGracza());
	wpisz_do_pliku_z_double("rozgrywka.txt", "Wygrana: ", gracz.getWygrana());
	prowadzacy.wygrana(gracz.getWygrana(), gracz.getNazwaGracza());
}

void Gra_jednoosobowa::rozpocznij() {
	//rozpoczecie rozgrywki dla jednego gracza
	gra_jedengracz("");
}