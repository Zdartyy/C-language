#include <stdio.h>
int main(){
    int dzien, miesiac, rok;

    printf("Podaj dzien urodzenia: ");
    scanf("%d",&dzien);
        while(dzien<1 || dzien>31){
            printf("Dzień jest nieprawidłowy, podaj poprawny: ");
            scanf("%d",&dzien);
        }

    printf("Podaj miesiac urodzenia: ");
    scanf("%d",&miesiac);
        while(miesiac<1 || miesiac>12){
             printf("Miesiąc jest nieprawidłowy, podaj poprawny: ");
             scanf("%d",&miesiac);
        }

    printf("Podaj rok urodzenia: ");
    scanf("%d",&rok);
        while(rok<0 || rok>2024){
            printf("Rok jest nieprawidłowy, podaj poprawny: ");
            scanf("%d",&rok);
        }

    int wynik0 = 0;
        while(dzien != 0){
            wynik0 = wynik0 + (dzien % 10);
            dzien = dzien / 10;
        }

    int wynik1 = 0;
        while(miesiac != 0){
            wynik1 = wynik1 + (miesiac % 10);
            miesiac= miesiac / 10;
        }

    int wynik2 = 0;
        while(rok != 0){
            wynik2= wynik2 + (rok % 10);
            rok= rok / 10;
        }


    int suma=wynik0+wynik1+wynik2;
    int wynik=0;
        while(suma != 0){
            wynik = wynik + (suma % 10);
            suma = suma / 10;
        }

    if(wynik == 11 || wynik == 22 || wynik == 33) {
        printf("Oto twoja liczba numerologiczna: %d. Jest to liczba mistrzowska\n", wynik);
    }
        else {
        printf("Oto twoja liczba numerologiczna: %d\n", wynik);
        }




    return 0;

}
