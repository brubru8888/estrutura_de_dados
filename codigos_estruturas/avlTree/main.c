#include <stdio.h>
#include <stdlib.h>

#include "avlTree.h"
#include "avlTree.c"

int main()
{

    Tree* tree = createTree();

    printf("\n\nInsert 17");
    tree->root = insert(tree->root, 3);

    printf("\n\nInsert 6");
    tree->root = insert(tree->root, 2);

    printf("\n\nInsert 35");
    tree->root = insert(tree->root, 1);


    printf("\n\nAltura da raiz, %d", getHeight(tree->root));
    printf("\n\nBalanceamento da raiz, %d", getBalance(tree->root));


/*
    printf("\n\nBuscar 14\n");
    int achou = search(tree->root, 100);
    printf("%d", achou);

    Node* node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);

    node = getMaxNode(tree->root);
    printf("\n\nMaior: %d", node->data);

    printf("\n\nPercurso pr�-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso p�s-ordem\n");
    strPostorder(tree->root);

    printf("\n\ndeleteNode(4)\n");
    node = deleteNode(tree->root, 4, 'D');

    node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);
*/

    printf("\n\nPercurso pr�-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso p�s-ordem\n");
    strPostorder(tree->root);
}
