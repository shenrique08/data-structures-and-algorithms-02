#include <stdio.h>

void bubbleSort2(int vector[], int lenght) 
{
    for (int i = 0; i < lenght; i++) {
        // a cada iteração, diminui-se a comparação com o último elemento ordenado
        for (int j = 0; j < lenght - 1 - i; j++) {
            if (vector[j] > vector[j + 1]) {
                // troca de elementos adjacentes
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }
}

int main () 
{
    int vetor_test[] = {7, 2, 8, 5, 4};
    bubbleSort2(vetor_test, 5);

    printf("VETOR ORDENADO:\n");
    for (int i = 0; i < 5; i ++) {
        printf("[%d] ", vetor_test[i]);
    }

    printf("\n");

    return 0;
}