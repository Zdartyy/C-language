#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DANE 11

struct Dane {
	char imie[20];
	char nick[20];
	char klasa[20];
	int poziom;
	int zdrowie;
};

int wyszukiwanie_polowkowe(struct Dane tablica[], char* imie) {

	int prawo = 11;
    int lewo = 0;
    
	while (lewo <= prawo) {

    int srodek = lewo + (prawo - lewo) / 2;
    int porownanie = strcmp(tablica[srodek].imie, imie);

    	if (porownanie == 0) {
        	return srodek;
    	}

    	if (porownanie < 0) {
        	lewo = srodek + 1;
		}

    	else {
        	prawo = srodek - 1;
		}
	}
	return -1;
}

int main() {

	FILE *plik;
	plik = fopen("zestaw2zad1.txt", "r");

	if (plik == NULL) {
		printf("Nie można odczytac pliku");
		return 1;
	}

	struct Dane* tablica;
	tablica = (struct Dane*)malloc(MAX_DANE*sizeof(struct Dane));

	for (int i = 0; i < MAX_DANE; i++) {
		if ( fscanf(plik, "%[^,], %[^,], %[^,], %d, %d\n", tablica[i].imie, tablica[i].nick, tablica[i].klasa, &tablica[i].poziom, &tablica[i].zdrowie) == 5) {
		}
		else {
			printf("Nie moge wczytac danych");
		}
	}

	//pętla pomocnicza do zobrazowania naszych tablic//
	for ( int i = 0; i < MAX_DANE; i++) {
		printf("Tablica%d: %s %s %s %d %d\n", i, tablica[i].imie, tablica[i].nick, tablica[i].klasa, tablica[i].poziom, tablica[i].zdrowie);
	}

	char imie[20];
    printf("Podaj imie gracza, którego chcesz wyszukac: ");
    scanf("%s", imie);

	int numer = wyszukiwanie_polowkowe(tablica, imie);
	if (numer != -1) {
        printf("Znaleziono imie w tablicy nr %d\n", numer);
	}
    else {
       printf("Nie znaleziono imienia\n");
	}

	free(tablica);
	fclose(plik);

	return 0;
}