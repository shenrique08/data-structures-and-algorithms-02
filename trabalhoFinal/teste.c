#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main() {
    // Set the locale to support Brazilian Portuguese UTF-8
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Open the file in binary mode ("rb") to properly handle special characters
    FILE *arquivo = fopen("eleicoes2024.CSV", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char linha[256]; // Buffer to store each line
    int count = 0; // Counter to keep track of lines read

    // Read and print the first 5 lines
    while (fgets(linha, sizeof(linha), arquivo) != NULL ) {
         // Print the current line
        count++;
    }

    printf("\n\n%d\n\n", count);
    fclose(arquivo); // Close the file
    return 0;
}
