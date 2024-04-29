#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int main() {
    int n = 100;                                                              // liczba prób //
    int c = 0;
                                                                                  // trafienia //
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) {

        float x = (float)rand() / (float)(RAND_MAX);                     // zawsze dostaniemy liczbe <= 1 //
        float y = (float)rand() / (float)(RAND_MAX);

        if (sqrt(x*x + y*y) < 1) {
            c++;
        }
    }

    float Pi = ((float)c / (float)n) * 4;

    printf("Liczba prób: %d\nLiczba trafień: %d\n", n, c);
    printf("Nasze przybliżenie pi: %lf\nRzeczywiste przybliżenie pi: 3.14159265359\n", Pi);

    return 0;
}