#include <stdio.h>

int pierwsze[1000000];
int sito_eratostenesa(int n);
void wypisz_pierwsze(int n);


int main() {
    int n; 
    printf("Podaj ilość pierwszych liczb pierwszych: "); 
    scanf("%d", &n); 
    printf("Pierwsze %d liczb pierwszych to:\n", n); 
    wypisz_pierwsze(n); 
    return 0;
}



// funkcja, która "przesiewa" liczby pierwsze

int sito_eratostenesa(int n) {

    for (int i = 0; i <= 1000000; i++) {            // Ustawienie wszystkich wartości na 1 - liczby pierwsze, 0 - liczby złożone
        pierwsze[i] = 1;
    }

    pierwsze[0] = 0; 
    pierwsze[1] = 0;                                //0 i 1 to liczby niepierwsze

    for (int i = 2; i * i <= n; i++) { 
        if (pierwsze[i]) { 
            for (int j = i * i; j < n; j = j + i) { 
                pierwsze[j] = 0;
            }
        }
    }

    return pierwsze[1000000]; 
}

// Funkcja, która wypisuje n pierwszych liczb pierwszych

void wypisz_pierwsze(int n) {

    pierwsze[1000000] = sito_eratostenesa(n*n); 
    int licznik = 0; 
    int i = 2; 
        while (licznik < n) { 
            if (pierwsze[i]) { 
                printf("%d ", i); 
                licznik++; 
            }
            i++; 
        }
        
    printf("\n"); 
}
