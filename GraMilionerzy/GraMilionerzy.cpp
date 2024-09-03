#include "Gra.h"
#include "Gra_jednoosobowa.h"
#include "Gra_wieloosobowa.h"

int main() {
    srand((unsigned)time(NULL));
    Gra* gra = new Gra();
    gra->rozpocznij();
    delete gra;
    return 0;
}