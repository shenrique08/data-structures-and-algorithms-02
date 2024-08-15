#include <stdio.h>
#include <stdbool.h>



void bubbleSort(int vetor[], int tamanho_vetor) {

    for (int i = 0; i < tamanho_vetor; i++) {
        // a cada iteração, trocou receberá false
        bool trocou = false;
        for (int j = 0; j < tamanho_vetor - 1 - i; j++) {

            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
                trocou = true;
            }
        }


        // caso não tenha havido nenhuma troca, então o vetor já está ordenado
        // e posso parar o looping
        if (!trocou) {
            break;
        }
    }

}




int main() {
    int numeros[] = {32, 43, 23, 312, 54};

    bubbleSort(numeros, 5);
    printf("VETOR ORDENADO\n");
    for (int i = 0; i < 5; i++) {
        printf("[%d] ", numeros[i]);
    }
    
    printf("\n");

    return 0;
}