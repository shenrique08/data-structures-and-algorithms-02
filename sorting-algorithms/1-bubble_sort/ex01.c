#include <stdio.h>

/* bubble sort mais ineficiente */
/* 
   Percorre todo o vetor n² vezes, ou seja, executa operações mesmo
   que o vetor já esteja ordenado 
*/
void bubble_sort01(int vector[], int lenght_vector) {
    int aux;

    for (int i = 0; i < lenght_vector; i++) {
        for (int j = 0; j < lenght_vector - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}



int main() {
    int test_vector[] = {7, 2, 8, 5, 4};
    bubble_sort01(test_vector, 5);

    for (int i = 0; i < 5; i++) {
        printf("[%d] ", test_vector[i]);
    }

    printf("\n");

    return 0;
}