#include <stdio.h>
#include <string.h>

int words_count(char* s) {

    int length = strlen(s);
    char nonwords[] = " ,.";
    int count = 0;

    for ( int i = 0; i < length; i++) {

        while (i < length) {
            if ( strchr(nonwords, s[i]) != NULL) break;
            i++;
        }
        count++;

        while (i < length) {
            if ( strchr(nonwords, s[i]) == NULL) break;
            i++;
        }
    }

    return count;
}

int main() {

    char s[] = "elo";
    printf("Twoje słowo to: %s\n", s);
    printf("Liczba słow: %d\n", words_count(s));
    
    return 0;
}