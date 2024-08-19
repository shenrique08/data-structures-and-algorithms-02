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
        if (minIndex != i) {
            aux = vetor[minIndex];
            vetor[minIndex] = vetor[i];
            vetor[i] = aux;
        }
    }

}


void selectionSortDecrescente(int vetor[], int n) {
    int i, j, maxIndex, temp;

    for (i = 0; i < n - 1; i++) {
        maxIndex = i; // Assumir que o maior é o primeiro elemento não ordenado
        for (j = i + 1; j < n; j++) {
            if (vetor[j] > vetor[maxIndex]) {
                maxIndex = j; // Atualizar o índice do maior elemento
            }
        }
        // Trocar o maior elemento encontrado com o primeiro elemento não ordenado
        if (maxIndex != i) {
            temp = vetor[i];
            vetor[i] = vetor[maxIndex];
            vetor[maxIndex] = temp;
        }
    }
}



int main() {

    int numeros[] = {7, 2, 8, 5, 4};

    printf("VETOR ORDENADO\n");
    selectionSort(numeros, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\nVETOR ORDENADO EM ORDEM DECRESCENTE\n");
    selectionSortDecrescente(numeros, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n\n");


    return 0;
}