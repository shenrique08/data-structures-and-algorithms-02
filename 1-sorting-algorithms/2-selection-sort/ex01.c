#include <stdio.h>


void selectionSort(int vetor[], int tamanho) {
    int i, j, minIndex, aux;

    for (i = 0; i < tamanho - 1; i++) {
        // o índice do valor mínimo começa no zero, mas a cada "troca", 
        // o valor mínimo será mudado para a posição seguinte
        minIndex = i;

        // loop para encontrar o menor valor e guardar sua posição
        for(j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[minIndex]) {
                minIndex = j;
            }
        }

        // aqui será realizada a troca dos elementos a cada iteração
        // baseado no índice do menor valor
        aux = vetor[minIndex];
        vetor[minIndex] = vetor[i];
        vetor[i] = aux;
    }

}



int main() {

    int numeros[] = {7, 2, 8, 5, 4};

    printf("VETOR ORDENADO\n");
    selectionSort(numeros, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }


    return 0;
}