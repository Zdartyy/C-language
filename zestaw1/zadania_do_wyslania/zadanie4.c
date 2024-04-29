#include <stdio.h>
#include <string.h>

//Funkcja, która oblicza liczbę numerologiczną ciągu znaków
int numerology(char *s) {
    int suma = 0;
    int dlugosc = strlen(s);
    for (int i = 0; i < dlugosc; i++) { 
        suma = suma + s[i]; 
    }

    while (suma > 9) {
        int wynik1 = 0;
        while (suma != 0) {
            wynik1 = wynik1 + (suma % 10);
            suma = suma / 10;
        }
        suma = wynik1;
    }

    return suma;
}


int main(){
    char imie[100];
    printf("Podaj swoje imie oraz nazwisko: ");
    fgets(imie, sizeof(imie), stdin);

    char znak_spacji[] = " ";
    char* imie1 = strtok(imie, znak_spacji);
    char* nazwisko = NULL;
    char* schowek = NULL;
        while ((schowek = strtok(NULL, znak_spacji)) != NULL) {
            nazwisko = schowek;
        }

    printf("Liczba numerologiczna Twojego imienia to %d.\n", numerology(imie1));
    printf("Liczba numerologiczna Twojego nazwiska to %d.\n", numerology(nazwisko));
    printf("Liczba numerologiczna Twojego pełnego imienia to %d.\n", numerology(imie));

    return 0;
}
