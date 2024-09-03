#include "Prowadzacy.h"
#include <iostream>

void Prowadzacy::napis() {
    std::cout << "    ==       ==   ==   ==          ==      ===      == =      =   ========   =======     ========   ==      ==  " << std::endl;
    std::cout << "    ==       ==   ==   ==          ==    =     =    ==  =     =   ==         ==     =         ==     ==    ==   " << std::endl;
    std::cout << "    = =     = =   ==   ==          ==   =       =   ==   =    =   ==         ==     =        ==       ==  ==    " << std::endl;
    std::cout << "    =  =   =  =   ==   ==          ==   =       =   ==    =   =   ========   =======        ==          ==      " << std::endl;
    std::cout << "    =   = =   =   ==   ==          ==   =       =   ==     =  =   ==         ==     =      ==           ==      " << std::endl;
    std::cout << "    =    =    =   ==   ==          ==    =     =    ==      = =   ==         ==      =    ==            ==      " << std::endl;
    std::cout << "    =         =   ==   =========   ==      ===      ==       ==   ========   ==       =  =========      ==      " << std::endl;
}

void Prowadzacy::wyjasnienie_zasad() {
    std::cout << "\n=================================================================================================================" << std::endl;
    std::cout << "Witamy w grze milionerzy! " << std::endl;
    std::cout << "W tej grze gracz ma mozliwosc zmierzenia sie z 12 pytaniami i zawalczenia o milion zlotych. $$$" << std::endl;
    std::cout << "Pytania sa zamkniete i dotycza wiedzy ogolnej. " << std::endl;
    std::cout << "=================================================================================================================" << std::endl;
}

void Prowadzacy::wyjasnienie_zasad_wieloosobowej() {
    std::cout << "\n=======================================================================================================================" << std::endl;
    std::cout << "Pierwsza tura rozgrywki to rywalizacja o fotel gracza. " << std::endl;
    std::cout << "Kazdy z graczy musi odpowiedziec na dosc proste pytanie, polegajace na ulozenie wyrazen chronologicznie." << std::endl;
    std::cout << "Liczy sie tu przede wszystkim refleks - szybsza odpowiedz daje szanse na zasiadanie na fotelu gracza i walke o wygrana." << std::endl;

    std::cout << "Kolejnosc wpisywania odpowiedzi bedzie zgodna z kolejnoscia podawania nazw graczy. " << std::endl;
    std::cout << "Twoja odpowiedz ma sie skladac z 4 cyfr, ktore maja zostac ulozone chronologicznie wzgledem pytania." << std::endl;
    std::cout << "Podanie odpowiedzi w zlym formacie bedzie skutkowalo wydluzonym czasem odpowiedzi. " << std::endl;
    std::cout << "Czas jest liczony od momentu wyswietlenia pytania do momentu podania odpowiedzi w odpowiednim formacie." << std::endl;
    std::cout << "=======================================================================================================================" << std::endl;
}

void Prowadzacy::wyjasnienie_zasad_jednoosobowej() {
    std::cout << "\n====================================================================================================================" << std::endl;
    std::cout << "Rozpoczeto tryb jednoosobowy." << std::endl;
    std::cout << "W konsoli wyswietli sie pytanie jednokrotnej odpowiedzi wraz z mozliwymi odpowiedziami o numerach 1, 2, 3, 4." << std::endl;
    std::cout << "Twoim zadaniem jest wybranie jednej poprawnej odpowiedzi (1, 2, 3 lub 4) sposrod 4 mozliwych." << std::endl;
    std::cout << "Mozesz wykorzystac 3 kola ratunkowe, ich dzialanie polega na wyeliminowaniu dwoch niepoprawnych odpowiedzi." << std::endl;
    std::cout << "====================================================================================================================" << std::endl;
}

void Prowadzacy::gotowosc_gracza(int i, std::string nazwy_graczy[6]) {
    std::cout << "\n\nCzy gracz o nazwie: " << nazwy_graczy[i] << " jest gotowy do gry? Podaj Y kiedy bedziesz gotowy: ";
}

void Prowadzacy::typ_rozgrywki() {
    std::cout << "\nCzy chcesz aby:" << std::endl;
    std::cout << "1. Pytania stawaly sie trudniejsze stopniowo" << std::endl;
    std::cout << "2. Wybrac poziom trudnosci (pytania pozostana na wybranym poziomie przez cala rozgrywke)" << std::endl;
}

void Prowadzacy::trudnosc_rozgrywki() {
    std::cout << "\nWybierz poziom gry:" << std::endl;
    std::cout << "1. Latwy" << std::endl;
    std::cout << "2. Sredni" << std::endl;
    std::cout << "3. Trudny" << std::endl;
    std::cout << "4. Zaawansowany" << std::endl;
}

void Prowadzacy::prog_gwarantowany(int wartosc_pytan[], int i) {
    std::cout << "\n=================================================================================" << std::endl;
    std::cout << "Osiagnales prog gwarantowany " << wartosc_pytan[i] << " zlotych" << std::endl;
    std::cout << "Oznacza to, ze nawet jesli podasz niepoprawna odpowiedz to otrzymasz " << wartosc_pytan[i] << " zlotych!" << std::endl;
    std::cout << "=================================================================================" << std::endl;
}

void Prowadzacy::kontynuacja_gry(int wartosc_pytan[], int i) {
    std::cout << "\n\nChcesz: " << std::endl;
    std::cout << "1. Kontynuowac gre" << std::endl;
    std::cout << "2. Odejsc z wygrana " << wartosc_pytan[i] << " zlotych" << std::endl;
}

void Prowadzacy::wygrana(int wygrana, std::string nazwa_gracza) {
    std::cout << "\n=======================================" << std::endl;
    std::cout << "Koniec rozgrywki gracza o nazwie '" << nazwa_gracza << "'." << std::endl;
    std::cout << "Wygrana: " << wygrana << " zlotych!" << std::endl;
    std::cout << "=======================================" << std::endl;
}

void Prowadzacy::wygrana_wielegraczy(std::string nazwa_gracza) {
    std::cout << "\n=================================================" << std::endl;
    std::cout << "Do kolejnego etapu gry przechodzi gracz '" << nazwa_gracza << "'!" << std::endl;
    std::cout << "=================================================" << std::endl;
}

void Prowadzacy::wersja_gry() {
    std::cout << "\nChcesz zagrac w wersje gry: " << std::endl;
    std::cout << "1. Jednoosobowa: " << std::endl;
    std::cout << "2. Wieloosobowa: " << std::endl;
}
