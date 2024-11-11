#ifndef AVLTREE
#define AVLTREE

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* left;
    struct Node* right;
    // em arvores AVL precisamos saber a altura do n� para verificar o balanceamento
    int height;
} Node;

typedef struct{
    Node* root;
}Tree;

Node* createNode(int data);

Tree* createTree();

Node* insert( Node* node, int data );

int search( Node* node, int data );

Node* getMaxNode( Node* node );

Node* getMinNode( Node* node );

Node* deleteNode( Node* node, int data, char filhoSubstituto);

int getHeight(Node *node);
int getBalance(Node *node);


void strPreorder(Node *node);
void strInorder(Node *node);
void strPostorder(Node *node);

int max(int a, int b);



#endif
