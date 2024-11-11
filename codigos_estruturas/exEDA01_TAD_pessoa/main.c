#include <stdio.h>
#include <stdlib.h> // para o malloc
#include "pessoa.h"

int main(){

    Pessoa pessoa1;

    pessoa1 = criarPessoa("João", 30, 70, 5);
    imprimirPessoa(pessoa1);

    atualizarIdade(&pessoa1, 35);

    printf("\n\nPessoa apos alterar a idade");
    imprimirPessoa(pessoa1);

    // cria um vetor de pessoas estatico
    Pessoa vetPessoas1[3];

    vetPessoas1[0] = pessoa1;
    vetPessoas1[1] = criarPessoa("Maria", 45, 60, 10);
    vetPessoas1[2] = criarPessoa("José", 33, 33, 33);

    printf("\n\nVetor de pessoas (estático)");
    for(int i=0; i<3; i++){
        printf("\n\n=====\nPessoa %d\n", i+1);
        imprimirPessoa(vetPessoas1[i]);
    }

    // aloca dinamicamente memória para um vetor de Pessoas
    int tamInicial = 3;
    Pessoa* vetPessoas2 = (Pessoa*)malloc(
                         tamInicial*sizeof(Pessoa));

    if (vetPessoas2 == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }

    printf("\n\nVetor de pessoas (dinamico)");
    vetPessoas2[0] = pessoa1;
    vetPessoas2[1] = criarPessoa("Filomena", 22, 1.60, 65.0);
    vetPessoas2[2] = criarPessoa("Tutankamon", 54, 1.55, 60.0);

    for(int i=0; i<3; i++){
        printf("\n\n=====\nPessoa %d\n", i+1);
        imprimirPessoa(vetPessoas2[i]);
    }

    // expande o vetor para armazenar mais 2 pessoas
    int novoTam = 5;
    Pessoa* pessoas_realloc = (Pessoa*)realloc(vetPessoas2, novoTam * sizeof(Pessoa));

    if (pessoas_realloc == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }

    vetPessoas2 = pessoas_realloc;  // Atualiza o ponteiro para o novo bloco de memória

    // inicializa as novas posições do vetor
    vetPessoas2[3] = criarPessoa("Ana", 40, 75, 7);
    vetPessoas2[4] = criarPessoa("Carlos", 32, 85, 6);

    printf("\n\nVetor de pessoas (dinamico) -- apos expandir");
    for (int i = 0; i < novoTam; i++) {
        printf("\n\n=====\nPessoa %d\n", i+1);
        imprimirPessoa(vetPessoas2[i]);
    }

    return 0;
};
