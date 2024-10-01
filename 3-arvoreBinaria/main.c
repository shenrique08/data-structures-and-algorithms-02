#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_binaria.h"




// Função para carregar o arquivo completo em uma ABB
void carregar_arquivo_completo(No** raiz, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    char linha[300];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Registro registro;
        char *token = strtok(linha, ";");

        // Lê o CEP como string (com hífen)
        if (token != NULL) strncpy(registro.cep, token, sizeof(registro.cep));  
        token = strtok(NULL, ";");
        // Lê o estado
        if (token != NULL) strncpy(registro.estado, token, sizeof(registro.estado));  
        token = strtok(NULL, ";");
        // Lê a cidade
        if (token != NULL) strncpy(registro.cidade, token, sizeof(registro.cidade));  
        token = strtok(NULL, ";");
        // Lê o endereço
        if (token != NULL) strncpy(registro.endereco, token, sizeof(registro.endereco));  

        *raiz = inserir_no(*raiz, registro);
    }

    fclose(arquivo);
}

// Função para carregar as primeiras 20 linhas do arquivo em uma ABB
void carregar_primeiras_linhas(No** raiz, const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    char linha[300];
    int contador = 0;
    while (fgets(linha, sizeof(linha), arquivo) && contador < 20) {
        Registro registro;
        char *token = strtok(linha, ";");

        // Lê o CEP como string (com hífen)
        if (token != NULL) strncpy(registro.cep, token, sizeof(registro.cep));  
        token = strtok(NULL, ";");
        // Lê o estado
        if (token != NULL) strncpy(registro.estado, token, sizeof(registro.estado));  
        token = strtok(NULL, ";");
        // Lê a cidade
        if (token != NULL) strncpy(registro.cidade, token, sizeof(registro.cidade));  
        token = strtok(NULL, ";");
        // Lê o endereço
        if (token != NULL) strncpy(registro.endereco, token, sizeof(registro.endereco));  

        *raiz = inserir_no(*raiz, registro);
        contador++;
    }

    fclose(arquivo);
}

int main() {
    No* arvore_completa = criar_arvore();
    No* arvore_20_linhas = criar_arvore();
    
    // 1. Leia o arquivo texto completo e preencha uma ABB
    carregar_arquivo_completo(&arvore_completa, "cepPontoEVirgula.txt");

    // Exemplo de pesquisa por CEPs (utilizando CEPs formatados com hífen)
    const char* ceps_para_pesquisar[] = {"12345-678", "87654-321", "11223-344", "44332-211", "33445-566"};
    int num_ceps = sizeof(ceps_para_pesquisar) / sizeof(ceps_para_pesquisar[0]);
    printf("== Pesquisa de CEPs na ABB Completa ==\n");
    for (int i = 0; i < num_ceps; i++) {
        No* encontrado = pesquisar_no(arvore_completa, ceps_para_pesquisar[i]);
        if (encontrado) {
            printf("CEP encontrado: %s - %s - %s - %s\n", encontrado->registro.cep, encontrado->registro.cidade, encontrado->registro.estado, encontrado->registro.endereco);
        } else {
            printf("CEP %s não encontrado.\n", ceps_para_pesquisar[i]);
        }
    }

    // Exibe altura, maior e menor valor da árvore completa
    printf("\n== Informações da ABB Completa ==\n");
    printf("Altura da ABB: %d\n", calcular_altura(arvore_completa));
    
    No* menor = encontrar_menor(arvore_completa);
    if (menor) {
        printf("Menor CEP: %s - %s - %s - %s\n", menor->registro.cep, menor->registro.cidade, menor->registro.estado, menor->registro.endereco);
    }
    
    No* maior = encontrar_maior(arvore_completa);
    if (maior) {
        printf("Maior CEP: %s - %s - %s - %s\n", maior->registro.cep, maior->registro.cidade, maior->registro.estado, maior->registro.endereco);
    }

    // 2. Leia as primeiras 20 linhas do arquivo texto e preencha uma nova ABB
    carregar_primeiras_linhas(&arvore_20_linhas, "cepPontoEVirgula.txt");

    // Exibir os CEPs considerando os percursos central, pré-fixado e pós-fixado
    printf("\n== Percursos na ABB das Primeiras 20 Linhas ==\n");

    printf("\nPercurso Central:\n");
    percurso_em_ordem(arvore_20_linhas);

    printf("\nPercurso Pré-Fixado:\n");
    percurso_pre_ordem(arvore_20_linhas);

    printf("\nPercurso Pós-Fixado:\n");
    percurso_pos_ordem(arvore_20_linhas);

    // Libera a memória das árvores
    liberar_arvore(arvore_completa);
    liberar_arvore(arvore_20_linhas);

    return 0;
}
