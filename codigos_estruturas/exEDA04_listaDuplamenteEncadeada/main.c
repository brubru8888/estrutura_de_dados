#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteEncadeada.h"

int main()
{

    Lista* lista = criarLista();

    printf("\nEstá vazia? %d", isEmpty(lista));

    printf("\nTamanho: %d", getSize(lista));

    insertHead(lista, 10);
    printLista(lista);

    insertHead(lista, 5);
    printLista(lista);

    insertTail(lista, 3);
    printLista(lista);

    insert(lista, 8, 2);
    printLista(lista);

    insertTail(lista, 9);
    printLista(lista);

    insertHead(lista, 8);
    printLista(lista);

    insert(lista, 7, 4);
    printLista(lista);

    return 0;
}
