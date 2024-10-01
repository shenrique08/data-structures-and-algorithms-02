#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct Registro {
    int cep;
    char estado[3];
    char cidade[100];
    char endereco[200];
} Registro;

typedef struct No {
    Registro registro;
    struct No *esquerda;
    struct No *direita;
} No;

// Funções da Árvore Binária de Pesquisa
No* criar_arvore();
No* inserir_no(No *raiz, Registro registro);
No* remover_no(No *raiz, int cep);
No* pesquisar_no(No *raiz, int cep);
No* encontrar_menor(No *raiz);
No* encontrar_maior(No *raiz);
void percurso_em_ordem(No *raiz);
void percurso_pre_ordem(No *raiz);
void percurso_pos_ordem(No *raiz);
int calcular_altura(No *raiz);
void liberar_arvore(No *raiz);

#endif
