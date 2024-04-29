#include <stdio.h>
#include <time.h>

long rekurencja(int n);
int iteracja1(int n);
long iteracja2(int n);
void czas_wykonania(clock_t start, clock_t end);

int main() {
    int wyraz_n;
    clock_t start_1, end_1, start_2, end_2;
    
    printf("Podaj, który wyraz chcesz obliczyć: ");
    scanf("%d", &wyraz_n);


    printf("\nProgram liczący iteracyjnie:\n");
    start_1 = clock();
    printf("Oto twój wyraz: %ld\n", iteracja2(wyraz_n));
    end_1 = clock();
    czas_wykonania(start_1, end_1);


    /*printf("Program liczący rekurencyjnie:\n");
    start_2 = clock();
    printf("Oto twój wyraz: %ld\n", rekurencja(wyraz_n));
    end_2 = clock();
    czas_wykonania(start_2, end_2);
    */

    printf("Stosunek wyrazów: %lf\nZłoty podział: 1,618\n", (double)iteracja2(wyraz_n) / (double)iteracja2(wyraz_n - 1));

    return 0;
}

// Mozemy policzyc do 45 wyrazu //
long rekurencja(int n) {
    if (n == 1) {
        return 2;
    }
    else if (n == 2) {
        return 1;
    }
    else { 
        long wynik = rekurencja(n-1) + rekurencja(n-2);
        return wynik;
    }
}

// Mozemy policzyc do 45 wyrazu //
int iteracja1(int n) {
    if (n == 1) {
        return 2;
    }
        else if (n == 2) {
            return 1;
        }
        else {
            int a = 2;
            int b = 1;
            while (n != 2) {
                int c = a + b;
                n = n - 1;
                a = b;
                b = c;
                    
            }
            return b;
        }


}

// Rowniez mozemy policzyc do 45 wyrazu //
long iteracja2(int n) {
    if (n == 1) {
        return 2;
    }
        else if (n == 2) {
            return 1;
        }
        else {
            long a = 2;
            long b = 1;
            while (n != 2) {
                long c = a + b;
                n = n - 1;
                a = b;
                b = c;                   
            }
            return b;
        }


}

void czas_wykonania(clock_t start, clock_t end) {
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Czas wykonania: %f sekund\n\n", cpu_time_used);
}