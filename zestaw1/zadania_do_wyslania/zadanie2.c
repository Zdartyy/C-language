#include <stdio.h>

int suma(int liczba);
int liczba_numerologiczna(int wynik_dnia, int wynik_miesiąca, int wynik_roku);


// funkcja głowna, wczytuje date oraz wypisuje liczbe numerologiczna

int main() {

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

	int wynik_koncowy = liczba_numerologiczna(dzien, miesiac, rok);

 	if (wynik_koncowy == 11 || wynik_koncowy == 22 || wynik_koncowy == 33) {
    	printf("Oto twoja liczba numerologiczna: %d. Jest to liczba mistrzowska\n", wynik_koncowy);
    } else {  	
		printf("Oto twoja liczba numerologiczna: %d\n", wynik_koncowy);
    }

	return 0;
}


//funkcja, która sumuje cyfry w liczbie//

int suma(int liczba) {
	int wynik=0;
		while(liczba!=0) {
			wynik = wynik + (liczba%10);
			liczba = liczba / 10;
		}

	return wynik;
}

//funkcja, która liczy liczbe numerologiczną//

int liczba_numerologiczna(int wynik_dnia, int wynik_miesiąca, int wynik_roku){

	int wynik = suma(wynik_dnia) + suma(wynik_miesiąca) + suma(wynik_roku);

	if (wynik == 11 || wynik == 22 || wynik == 33) {
		return wynik;
	} else { 
		wynik = suma(wynik);
		return wynik;
	}
	
}
