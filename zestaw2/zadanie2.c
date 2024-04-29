#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
 
char guess(int guess_number) {
    char letter = 'a' + (guess_number % 26);
    return letter;
}

/* funkcja dostarczona do zadania */
bool letters_remaining(bool * guessed, int len) {
    int i = 0;
    for (i = 0; i < len; i++)
        if(!guessed[i])
            return true;
    return false;
}

/* funkcja dostarczona do zadania; trzeba zmodyfikowaÄ w pĂłĹşniejszych podpunktach */
int play(char * word) {
    int n = 0, i, len;
    char letter;

    bool * guessed = (bool *)calloc(len = strlen(word), sizeof(bool));

    while (letters_remaining(guessed, len)){
        letter = guess(n++);
        for (i = 0; i < len; i++)
            if (tolower(word[i]) == letter)
                guessed[i] = true;
    }

    free(guessed);
    return n;
}

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Provide a word in command line\n");
        return 0;
    }
    
    char* word = argv[1];
    int result = play(word);
    printf("You guessed the word in %d guesses\n", result);

    return 0;
}