#include <stdio.h>

void inkrementacja(int * b) {
    /* operacja na lokalizacji w pamięci, więc jej efekt odczujemy w funkcji main */
	*b = *b + 1;
}

int inkrementacja_przez_wartosc(int a){
    /* operacja działa tylko na lokalnej, przesłoniętej wartości, więc nie ma efektu w main */
    a = a + 1;
}

int main(void) {
	int zmienna = 7;
    inkrementacja_przez_wartosc(zmienna);
	printf("%d \n", zmienna);

    /* musimy przekazać adres do zmiennej, korzystając z & */
	inkrementacja(&zmienna);
	printf("%d \n", zmienna);

	return 0;
}
