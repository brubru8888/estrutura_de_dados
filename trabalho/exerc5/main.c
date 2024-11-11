#include <stdio.h>


#include "lista_ligada_cruzada.h"

int main() {
    // Criando duas matrizes esparsas 5x5 para teste
    SparseMatrix* matriz1 = criarMatriz(5, 5);
    SparseMatrix* matriz2 = criarMatriz(5, 5);

    // Inserindo valores em matriz1
    printf("Inserindo valores na matriz1...\n");
    inserir(matriz1, 5, 0, 0);     
    inserir(matriz1, 10, 0, 2);   
    inserir(matriz1, 15, 2, 0);    
    inserir(matriz1, 20, 2, 2);    
    inserir(matriz1, 25, 1, 1);
    printf("Imprimindo a matriz1:\n");    
    imprimir(matriz1);

    // Inserindo valores em matriz2
    printf("Inserindo valores na matriz2...\n");
    inserir(matriz2, 10, 0, 1);  
    inserir(matriz2, 25, 2, 1);
    inserir(matriz2, 35, 1, 0);  
    inserir(matriz2, 40, 2, 2); 
    inserir(matriz2, 5, 1, 1);
    printf("Imprimindo a matriz2:\n");   
    imprimir(matriz2);

    // Testando a busca de elementos
    printf("Buscando elementos em matriz1:\n");
    printf("Elemento em (0,1): %d\n", buscar(matriz1, 0, 2)); // Deve retornar 10
    printf("Elemento em (3,2): %d\n", buscar(matriz1, 2, 0)); // Deve retornar 15
    printf("Elemento em (1,4): %d\n", buscar(matriz1, 1, 4)); // Deve retornar 0

    // Removendo um elemento e imprimindo novamente
    printf("Removendo elemento em (2,2) de matriz1...\n");
    remover(matriz1, 2, 2);
    printf("Imprimindo a lista 1:\n");  
    imprimir(matriz1);

    // Testando soma interna dos elementos de matriz1
    printf("Soma interna de todos os elementos de matriz1: %d\n", somaInterna(matriz1));

    // Somando matriz1 e matriz2 em uma nova matriz
    printf("Somando matriz1 e matriz2...\n");
    SparseMatrix* matrizSoma = somar(matriz1, matriz2);
    printf("Resultado da soma de matriz1 e matriz2:\n");
    imprimir(matrizSoma);

    // Teste de atualização ao inserir zero (elemento deve ser removido)
    printf("Inserindo valor 0 em (2,1) de matrizSoma (deve remover o elemento)...\n");
    inserir(matrizSoma, 0, 2, 1);
    printf("Imprimindo a matrizSoma:\n");  
    imprimir(matrizSoma);

    printf("\nEsparsidade: %.2f\n", calculaEsparsidade(matriz1));


    //Liberando a memória das matrizes
    freeMatrix(matriz1);
    freeMatrix(matriz2);
    freeMatrix(matrizSoma);

    return 0;
}