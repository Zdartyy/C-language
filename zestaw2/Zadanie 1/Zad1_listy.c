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

struct Node {
    struct Dane dane;
    struct Node* next;
};

struct Node* nowy(struct Node* lastNode, struct Dane dane) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dane = dane;
    newNode->next = NULL;

    if (lastNode != NULL) {
        lastNode->next = newNode;
    }
    return newNode;
}

// zobrazowanie naszej listy //
void wypisz_liste(struct Node* head) {

    struct Node* temp = head;
    int i = 0;

    while (temp != NULL) {
        printf("Element%d: %s %s %s %d %d\n", i, temp->dane.imie, temp->dane.nick, temp->dane.klasa, temp->dane.poziom, temp->dane.zdrowie);
        temp = temp->next;
        i++;
    }
}

/* 
    nie mozemy zastosowac wyszukiwania polowkowego, poniewaz w liscie jednokierunkowej 
    zeby dotrzec do srodka listy musimy przejsc po wszystkich poprzednich elementach, co juz
    zaczyna byc nieefektywne i nie jest latwo podzelic liste na polowy, a wyszukiwanie binarne
    na tym polega, by caly czas dzielic na pol
*/

struct Node* wyszukiwanie_liniowe(struct Node* head, char* imie, int* numer) {

    struct Node* temp = head;
    *numer = 0;

    while (temp != NULL) {
        if (strcmp(temp->dane.imie, imie) == 0) {
            return temp;
        }
        temp = temp->next;
        (*numer)++;
    }
    return NULL;
}



int main() {

	FILE *plik;
	plik = fopen("zestaw2zad1.txt", "r");

	if (plik == NULL) {
		printf("Nie można odczytac pliku");
		return 1;
	}

	struct Node* head = NULL;
    struct Node* lastNode = NULL;
    struct Dane temp;

    for (int i = 0; i < MAX_DANE; i++) {

        if (fscanf(plik, "%[^,], %[^,], %[^,], %d, %d\n", temp.imie, temp.nick, temp.klasa, &temp.poziom, &temp.zdrowie) == 5) {
            lastNode = nowy(lastNode, temp);
                if (head == NULL) {
                    head = lastNode;
                }
        } 
        else {
            printf("Nie moge wczytac danych");
        }
    }
    
	wypisz_liste(head);
	
	char imie[20];
    printf("Podaj imie gracza, którego chcesz wyszukac: ");
    scanf("%s", imie);
	
    int numer;
	struct Node* znaleziony = wyszukiwanie_liniowe(head, imie, &numer);

    if (znaleziony != NULL) {
        printf("Element %s zostal znaleziony i jest %d elementem w liscie\n", znaleziony->dane.imie, numer);
    }
    else {
        printf("Element nie znaleziony\n");
    }

    fclose(plik);

	return 0;
}