#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>



void bubbleSort(int vet[], int tamanho, bool reversed) {
    int i, j, aux;
    bool trocou;

    for (i = 0; i < tamanho - 1; i++) {
        trocou = false;  

        for (j = 0; j < tamanho - 1 - i; j++) {
            if (!reversed) {
                if (vet[j] > vet[j + 1]) {
                    aux = vet[j];
                    vet[j] = vet[j + 1];
                    vet[j + 1] = aux;
                    trocou = true;
                }
            } else {
                if (vet[j] < vet[j + 1]) {
                    aux = vet[j];
                    vet[j] = vet[j + 1];
                    vet[j + 1] = aux;
                    trocou = true;
                }
            }
        }

        if (!trocou) {
            break;
        }
    }
}



void mostrarTabela(float tempo, int numComparacao, int numTroca)
{
    printf("10.000 numeros ordenados\n\n[TEMPO] = %f\n[Nro Comparacoes] = %d\n[Nro Trocas] = %d\n\n", tempo, numComparacao, numTroca);
}





int main() 
{
    srand(time(NULL));
    int *numeros;

    printf("NÚMEROS GERADOS\n");
    // Gerar e imprimir 100 números aleatórios entre 1 e 100
    for (int i = 0; i < 20; i++) {
        numeros[i] = (rand() % 100) + 1;  // rand() % 100 gera número entre 0 e 99, somando 1 fica entre 1 e 100
        printf("[%d] ", numeros[i]);
    }

    printf("\n\nNumeros ordenados em ordem CRESCENTE pelo BUBBLE SORT\n");
    bubbleSort(numeros, 20, false);
    for(int i = 0; i < 20; i++) {
        printf("[%d] ", numeros[i]);
    }

    printf("\n\nNumeros ordenados em ordem DECRESCENTE pelo BUBBLE SORT\n");
    bubbleSort(numeros, 20, true);
    for(int i = 0; i < 20; i++) {
        printf("[%d] ", numeros[i]);
    }





    return 0;
}