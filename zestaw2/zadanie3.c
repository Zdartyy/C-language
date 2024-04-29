#include <stdio.h>
#include <stdlib.h>

void multiply_matrix(int a, int b, float array[a][b], float x) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            array[i][j] = array[i][j] * x;
        }
    }
}



void add_matrix(int a, int b, float array_x[a][b], float array_y[a][b], float array[a][b]) {

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            array[i][j] = array_x[i][j] - array_y[i][j];
        }
    }
}

void make_matrix(int rows, int cols, float array[rows][cols]) {

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Podaj liczbe: ");
            scanf("%f", &array[i][j]);
        }
    }

}

void printMatrix(int rows, int cols, float array[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    float array1[2][2];         //gw
    float array2[2][2];         //rw
    float array[2][2];
    float matrixG[2][2];
    float stala;

    make_matrix(2, 2, array1);
    printf("Podaj 2 macierz\n");
    make_matrix(2, 2, array2);
    

    //printf("Podaj stała: ");
    //scanf("%f", &stala);
    //multiply_matrix(2, 2, array2, stala);
    
    printf("\n");

    printMatrix(2, 2, array1);
    printMatrix(2, 2, array2);

    //add_matrix(2, 2, array1, array2, array);
    //printMatrix(2, 2, array);

    multiply_matrix(2, 2, array1, 2);
    printMatrix(2, 2, array1);

    multiply_matrix(2, 2, array1, (0.5));
    printMatrix(2, 2, array1);
    printMatrix(2, 2, array2);


    add_matrix(2, 2, array2, array1, matrixG);
    printMatrix(2, 2, array1);
    printMatrix(2, 2, array2);

    
    printMatrix(2, 2, matrixG);


    return 0;
}