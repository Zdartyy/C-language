#include <stdio.h>

int main (){

    int liczba;
    printf("podaj liczbe liczb: ");
    scanf("%d", &liczba);

    char tablica[liczba];

    printf("podaj liczby: ");
    for (int i = 0; i < liczba; i++) {
    printf("podaj liczbe %d : ", i);
    scanf("%d", &tablica[i]);
    }

    int suma=0;
    for(int i = 0; i < liczba- 1; i++){
        suma = suma + tablica[0];
    }
    int wynik = suma % 2;

    if (wynik) printf("NIEparzysta\n");

    else printf("parzysta\n");

    return 0;
}