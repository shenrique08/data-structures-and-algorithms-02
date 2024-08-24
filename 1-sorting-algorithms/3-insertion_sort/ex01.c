#include <stdio.h>


void insertionSort(int vetor[], int tam) 
{
    int i, j, chave;

    // Loop principal que percorre o vetor a partir do segundo elemento (índice 1)
    for (i = 1; i < tam; i++) {
        chave = vetor[i]; // Armazena o valor atual para comparar e possivelmente mover
        j = i - 1;

        // Este laço move os elementos maiores que 'aux' uma posição para frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j]; // Move o elemento para a direita
            j--; // Move para o elemento anterior
        }

        // Insere o valor armazenado em 'chave' na posição correta
        vetor[j + 1] = chave;
    }
}



int main() {

    int numeros[] = {60, 30, 10, 20, 40, 90, 70, 80, 50};

    insertionSort(numeros, 9);
    printf("VETOR ORDENADO\n");
    for (int i = 0; i < 9; i++) {
        printf("[%d] ", numeros[i]);
    }

    return 0;
}