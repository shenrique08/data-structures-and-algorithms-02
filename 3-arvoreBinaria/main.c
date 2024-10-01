#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_binaria.h"

// Função para carregar o arquivo completo e preencher a ABB
void carregar_arquivo_completo(No** raiz, const char* nome_arquivo) 
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    char linha[300];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Registro registro;
        char *token = strtok(linha, ";");
        
        if (token != NULL) registro.cep = atoi(token); // Lê o CEP
        token = strtok(NULL, ";");
        if (token != NULL) strncpy(registro.estado, token, sizeof(registro.estado)); // Lê o estado
        token = strtok(NULL, ";");
        if (token != NULL) strncpy(registro.cidade, token, sizeof(registro.cidade)); // Lê a cidade
        token = strtok(NULL, ";");
        if (token != NULL) strncpy(registro.endereco, token, sizeof(registro.endereco)); // Lê o endereço
        
        *raiz = inserir_no(*raiz, registro);
    }

    fclose(arquivo);
}

// Função para carregar apenas as primeiras 20 linhas do arquivo e preencher uma ABB
void carregar_primeiras_20_linhas(No** raiz, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[300];
    int linha_contador = 0;

    while (linha_contador < 20 && fgets(linha, sizeof(linha), arquivo)) {
        Registro registro;
        char *token = strtok(linha, ";");
        
        if (token != NULL) registro.cep = atoi(token); // Lê o CEP
        token = strtok(NULL, ";");
        if (token != NULL) strncpy(registro.estado, token, sizeof(registro.estado)); // Lê o estado
        token = strtok(NULL, ";");
        if (token != NULL) strncpy(registro.cidade, token, sizeof(registro.cidade)); // Lê a cidade
        token = strtok(NULL, ";");
        if (token != NULL) strncpy(registro.endereco, token, sizeof(registro.endereco)); // Lê o endereço
        
        *raiz = inserir_no(*raiz, registro);
        linha_contador++;
    }

    fclose(arquivo);
}

int main() {
    No* raiz_completa = criar_arvore();
    No* raiz_primeiras_20 = criar_arvore();

    // Carrega o arquivo completo para a primeira árvore
    printf("Carregando o arquivo completo...\n");
    carregar_arquivo_completo(&raiz_completa, "cepPontoEVirgula.txt");

    // Parte 1: Apresenta informações sobre a ABB completa
    printf("\n--- Árvore com o arquivo completo ---\n");

    // Pesquisa por alguns CEPs de exemplo
    int ceps_para_pesquisa[] = {12345678, 87654321, 11223344, 44332211, 33445566};
    int num_ceps = sizeof(ceps_para_pesquisa) / sizeof(ceps_para_pesquisa[0]);

    printf("Realizando pesquisas por CEPs...\n");
    for (int i = 0; i < num_ceps; i++) {
        No* encontrado = pesquisar_no(raiz_completa, ceps_para_pesquisa[i]);
        if (encontrado) {
            printf("CEP encontrado: %d - %s - %s - %s\n", encontrado->registro.cep, encontrado->registro.cidade, encontrado->registro.estado, encontrado->registro.endereco);
        } else {
            printf("CEP %d não encontrado.\n", ceps_para_pesquisa[i]);
        }
    }

    // Exibe a altura, maior e menor valor
    printf("\nAltura da ABB: %d\n", calcular_altura(raiz_completa));
    
    No* menor_completa = encontrar_menor(raiz_completa);
    if (menor_completa) {
        printf("Menor CEP: %d - %s - %s - %s\n", menor_completa->registro.cep, menor_completa->registro.cidade, menor_completa->registro.estado, menor_completa->registro.endereco);
    }

    No* maior_completa = encontrar_maior(raiz_completa);
    if (maior_completa) {
        printf("Maior CEP: %d - %s - %s - %s\n", maior_completa->registro.cep, maior_completa->registro.cidade, maior_completa->registro.estado, maior_completa->registro.endereco);
    }

    // Carrega apenas as primeiras 20 linhas para a segunda árvore
    printf("\nCarregando as primeiras 20 linhas do arquivo...\n");
    carregar_primeiras_20_linhas(&raiz_primeiras_20, "cepPontoEVirgula.txt");

    // Parte 2: Apresenta informações sobre a ABB com as primeiras 20 linhas
    printf("\n--- Árvore com as primeiras 20 linhas ---\n");

    // Exibe os percursos da ABB de 20 linhas
    printf("\nPercurso em Ordem:\n");
    percurso_em_ordem(raiz_primeiras_20);

    printf("\nPercurso Pré-Ordem:\n");
    percurso_pre_ordem(raiz_primeiras_20);

    printf("\nPercurso Pós-Ordem:\n");
    percurso_pos_ordem(raiz_primeiras_20);

    // Libera a memória das árvores
    liberar_arvore(raiz_completa);
    liberar_arvore(raiz_primeiras_20);

    return 0;
}
