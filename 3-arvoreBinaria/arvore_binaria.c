#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_binaria.h"

No* criar_arvore() {
    return NULL;
}

No* criar_no(Registro registro) {
    No* novo = (No*)malloc(sizeof(No));
    novo->registro = registro;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* inserir_no(No *raiz, Registro registro) {
    if (raiz == NULL) {
        return criar_no(registro);
    }
    if (registro.cep < raiz->registro.cep) {
        raiz->esquerda = inserir_no(raiz->esquerda, registro);
    } else if (registro.cep > raiz->registro.cep) {
        raiz->direita = inserir_no(raiz->direita, registro);
    }
    return raiz;
}

No* pesquisar_no(No *raiz, int cep) {
    if (raiz == NULL || raiz->registro.cep == cep) {
        return raiz;
    }
    if (cep < raiz->registro.cep) {
        return pesquisar_no(raiz->esquerda, cep);
    } else {
        return pesquisar_no(raiz->direita, cep);
    }
}

No* encontrar_menor(No *raiz) {
    No* atual = raiz;
    while (atual && atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual;
}

No* encontrar_maior(No *raiz) {
    No* atual = raiz;
    while (atual && atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual;
}

void percurso_em_ordem(No *raiz) {
    if (raiz != NULL) {
        percurso_em_ordem(raiz->esquerda);
        printf("CEP: %d - Cidade: %s - Estado: %s - Endereço: %s\n", raiz->registro.cep, raiz->registro.cidade, raiz->registro.estado, raiz->registro.endereco);
        percurso_em_ordem(raiz->direita);
    }
}

void percurso_pre_ordem(No *raiz) {
    if (raiz != NULL) {
        printf("CEP: %d - Cidade: %s - Estado: %s - Endereço: %s\n", raiz->registro.cep, raiz->registro.cidade, raiz->registro.estado, raiz->registro.endereco);
        percurso_pre_ordem(raiz->esquerda);
        percurso_pre_ordem(raiz->direita);
    }
}

void percurso_pos_ordem(No *raiz) {
    if (raiz != NULL) {
        percurso_pos_ordem(raiz->esquerda);
        percurso_pos_ordem(raiz->direita);
        printf("CEP: %d - Cidade: %s - Estado: %s - Endereço: %s\n", raiz->registro.cep, raiz->registro.cidade, raiz->registro.estado, raiz->registro.endereco);
    }
}

int calcular_altura(No *raiz) {
    if (raiz == NULL) {
        return -1;
    } else {
        int altura_esquerda = calcular_altura(raiz->esquerda);
        int altura_direita = calcular_altura(raiz->direita);
        return (altura_esquerda > altura_direita ? altura_esquerda : altura_direita) + 1;
    }
}

void liberar_arvore(No *raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}
