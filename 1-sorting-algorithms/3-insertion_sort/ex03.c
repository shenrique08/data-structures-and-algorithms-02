/*
  Lázaro Joabe Nunes Soares - 12211BCC022
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10000

void criaVetorOrdenado(int *vet) {
  srand(time(NULL));
  int num;
  int x = 0;
  int i;
  int m = 1;
  for (i = 0; i < TAM; i++) {
    num = rand() % m + x;
    x = num + 1;
    m++;
    vet[i] = num;
  }
}

void criaVetorAleatorio(int *vet) {
  srand(time(NULL));
  int num;
  int i;
  for (i = 0; i < TAM; i++) {
    num = rand() % TAM;
    vet[i] = num;
  }
}

void criaVetorInvertido(int *vet) {
  srand(time(NULL));
  int num;
  int i;
}

void bubbleSort(int arr[], int n, int *qtdComparacoes, int *qtdTrocas) {
  int i, j, temp;
  bool trocou = false;
  *qtdTrocas = 0;
  *qtdComparacoes = 0;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      *qtdComparacoes += 1;
      if (arr[j] > arr[j + 1]) {
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        *qtdTrocas += 1;
        trocou = true;
      }
    }
    if (!trocou) {
      break;
    }
  }
}



void selectionSort(int arr[], int n, int *qtdComparacoes, int *qtdTrocas) {
  int i, j, min_idx, temp;
  *qtdTrocas = 0;
  *qtdComparacoes = 0;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      *qtdComparacoes += 1;
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
    *qtdTrocas += 1;
  }
}

void insertionSort(int arr[], int n, int *qtdTrocas, int *qtdComparacoes) {
  int i, j, temp;
  {
    for (i = 1; i < n; i++) {
      temp = arr[i];
      *qtdComparacoes += 1;
      for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
        *qtdTrocas += 1;
        arr[j + 1] = arr[j];
      }

      *qtdTrocas += 1;
      arr[j + 1] = temp;
    }
  }
}

void shellSort(int vetor[], int n, int *qtdComparacoes, int *qtdTrocas) {
  int i, j, h = 1;
  int aux;
  *qtdTrocas = 0;
  *qtdComparacoes = 0;

  // Determina o intervalo inicial usando a sequência de Knuth
  do {
    h = h * 3 + 1;
  } while (h < n);
  do {
    h /= 3; // Reduz o intervalo a cada iteração

    for (i = h; i < n; i++) {
      aux = vetor[i]; // Guarda o elemento atual
      j = i;

      // Desloca os elementos do intervalo h para encontrar a posição correta
      *qtdComparacoes += 1;
      while (vetor[j - h] > aux) {
        *qtdTrocas += 1;
        vetor[j] = vetor[j - h];
        j -= h;

        if (j < h)
          break; // Verifica se j ficou menor que h para evitar acesso fora dos
                 // limites
      }

      *qtdTrocas += 1;
      vetor[j] = aux; // Coloca o elemento no local correto
    }
  } while (h != 1); // Repete até que o intervalo seja 1
}

float calculaTempo(int cod, int arr[], int n) {
  float tempo;
  time_t inicio;
  time_t fim;
  switch (cod) {
  case 1:
    inicio = clock();
    bubbleSort(arr, n, 0, 0);
    fim = clock();
    tempo = (float)(fim - inicio) / CLOCKS_PER_SEC;
    break;
  case 2:
    inicio = clock();
    selectionSort(arr, n, 0, 0);
    fim = clock();
    tempo = (float)(fim - inicio) / CLOCKS_PER_SEC;
    break;
  case 3:
    inicio = clock();
    insertionSort(arr, n, 0, 0);
    fim = clock();
    tempo = (float)(fim - inicio) / CLOCKS_PER_SEC;
    break;
  case 4:
    inicio = clock();
    shellSort(arr, n, 0, 0);
    fim = clock();
    tempo = (float)(fim - inicio) / CLOCKS_PER_SEC;
    break;
  }
  return tempo;
}


void mostrarTabela(float tempo, int *numComparacao, int *numTroca, char tipoOrdenacao[])
{
    printf("Valor de entrada com 10.000 numeros inteiros %s\n\n[TEMPO] = %f\n[Nro Comparacoes] = %d\n[Nro Trocas] = %d\n\n", tipoOrdenacao, tempo, *numComparacao, *numTroca);
}

int main(void) 
{
  float tempo;
  int qtdComparacoess, qtdTrocass;
  int *vet = malloc(TAM * sizeof(int));
  criaVetorOrdenado(vet);
  printf("------BUBBLE SORT -------");
  bubbleSort(vet, TAM, &qtdComparacoess, &qtdTrocass);
  tempo = calculaTempo(1, vet, TAM);
  //mostrarTabela(tempo, qtdComparacoes, &qtdTrocas, "[ordenados]");
  //free(vet);
  return 0;
}