#include <stdio.h>
#include <stdlib.h>
#include "pilhaDinamica.h"

int main() {
    Pilha* pilha = criarPilha();

    push(pilha, 5);
    printf("\npush(5)");
    imprimirPilha(pilha);

    push(pilha, 3);
    printf("\npush(3)");
    imprimirPilha(pilha);

    push(pilha, 9);
    printf("\npush(9)");
    imprimirPilha(pilha);

    printf("Size: %d\n", size(pilha));

    printf("\npop()");
    int valor = pop(pilha);
    imprimirPilha(pilha);

    printf("\npop()");
    valor = pop(pilha);
    imprimirPilha(pilha);

    printf("Vazia?: %d\n", isEmpty(pilha));

    printf("\npop()");
    valor = pop(pilha);
    imprimirPilha(pilha);

    printf("Vazia?: %d\n", isEmpty(pilha));

    printf("\npop()");
    valor = pop(pilha);
    imprimirPilha(pilha);

    push(pilha, 2);
    printf("\n\npush(2)");
    imprimirPilha(pilha);

    push(pilha, 14);
    printf("\npush(14)");
    imprimirPilha(pilha);

    printf("\nVazia?: %d\n", isEmpty(pilha));

    printf("\nclear()");
    clear(pilha);
    printf("\nVazia?: %d\n", isEmpty(pilha));

    free(pilha);

    return 0;
}

