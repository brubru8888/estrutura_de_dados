#include <stdio.h>
#include "lista_dupla_encadeada.h"

int main() {
    // Cria a lista
    Lista* lista = criarLista();

    // Insere elementos na lista
    insertTail(lista, 20);
    insertTail(lista, 5);
    insertTail(lista, 15);
    insertTail(lista, 10);
    insertTail(lista, 8);
    insertTail(lista, 18);

    // Exibe a lista desordenada
    printf("Lista inicial:");
    printLista(lista);

    // Testa a função busca antes da ordenação
    int valor_busca = 15;
    int posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("\nValor %d encontrado na posicao %d (busca linear).\n", valor_busca, posicao);
    } else {
        printf("\nValor %d nao encontrado (busca linear).\n", valor_busca);
    }

    // Testa a função busca antes da ordenação com um valor não presente na lista
    valor_busca = 56;
    posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("\nValor %d encontrado na posicao %d (busca linear).\n", valor_busca, posicao);
    } else {
        printf("\nValor %d nao encontrado (busca linear).\n", valor_busca);
    }

    // Ordena a lista e exibe a lista ordenada
    printf("\nChamando a funcao de ordenacao...");
    ordenar(lista);
    printf("\nLista ordenada:");
    printLista(lista);

    // Testa a função busca após a ordenação (agora busca binária)
    valor_busca = 15;
    posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("\nValor %d encontrado na posicao %d (busca binaria).\n", valor_busca, posicao);
    } else {
        printf("\nValor %d nao encontrado (busca binaria).\n", valor_busca);
    }

    // Testa a função busca após a ordenação com um valor não presente na lista
    valor_busca = 42;
    posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("\nValor %d encontrado na posicao %d (busca binaria).\n", valor_busca, posicao);
    } else {
        printf("\nValor %d nao encontrado (busca binaria).\n", valor_busca);
    }

    // Testa a função busca binária diretamente
    int valor_busca_bin = 10;
    posicao = buscaBinaria(lista, valor_busca_bin);
    if (posicao != -1) {
        printf("\nValor %d encontrado na posicao %d (busca binaria direta).\n", valor_busca_bin, posicao);
    } else {
        printf("\nValor %d nao encontrado (busca binaria direta).\n", valor_busca_bin);
    }

    // Libera a memória da lista
    clear(lista);
    free(lista);

    return 0;
}