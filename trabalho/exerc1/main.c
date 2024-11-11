#include <stdio.h>
#include <stdlib.h>

#include "pilhaDinamica.h"
#include "fila_estaticaCircular.h"

// termos definidos como globais para ter a garantia de que eles estaro com os valores iniciais após a função
Fila* fila;
Pilha* pilha;

int verificaBalanceamento(Fila *fila, Pilha* pilha){
    // 0 - False
    // 1 - True

    //filaAux irá guardar todos os caracteres presentes em fila e será usado para voltar a fila para o estado inicial
    Fila* filaAux;
    filaAux = criarFila(getSize(fila));

    int balanceado = 1;

    if(isEmpty(fila)) //se fila está vazia, segundo as regras passadas no exercício, devemos considerar que a fila está balanceada
        return 1;
    else{
        // se fila não esá vazia, é necessário realizar a verificação
        while(!isEmpty(fila)){

            // leitura e salvamento do primeiro termo da fila
            char termoFila = dequeue(fila);
            enqueue(filaAux,termoFila);


            if(termoFila == ')' || termoFila == ']' || termoFila == '}'){
                //encontramos um ponto de fechamento
                if(isEmptyPilha(pilha)){
                    // se a pilha estiver vazia quer dizer que temos mais termos de fechamento que termos de abertura, ou seja, está desbalanciada
                    balanceado = 0;
                }
                else{
                    char ultimoTermoPilha = pop(pilha); // pegamos o ultimo termo de abertura lido da fila (guardado em uma pilha)
                    // verificamos se há o par formado () [] {}
                    if(ultimoTermoPilha=='(' && termoFila!=')' ||
                        ultimoTermoPilha=='[' && termoFila!=']'||
                        ultimoTermoPilha=='{' && termoFila!='}'){
                        balanceado = 0;
                    }
                }

            }
            else{
                // guarda todos os termos de abertura da fila ( , [ e {
                push(pilha, termoFila);
            }
        }
    }
    if(!isEmptyPilha(pilha)){
        // pilha ainda tem termos restantes, ou seja, lista tinha número impar de dados. Logo, não está balanceado
        balanceado = 0;
    }
    clearPilha(pilha); // retorna pilha para o estado inicial = vazio


    //voltar fila para estado inicial
    clear(fila);
    while(!isEmpty(filaAux))
        enqueue(fila, dequeue(filaAux));


    return balanceado;
}

int main(void){
    // Inicializa a fila e a pilha vazia
    pilha = criarPilha();
    int CAPACITY = 20;
    fila = criarFila(CAPACITY);

    enqueue(fila, '{');
    enqueue(fila, '(');
    enqueue(fila, '{');
    enqueue(fila, '}');
    enqueue(fila, ')');
    printf("Fila:");
    imprimir(fila);

    int retorno = verificaBalanceamento(fila,pilha);
    if(retorno == 1)
        printf("\n=> A fila está: Balanceada\n");
   else
        printf("\n=> A fila está: Desbalanceada\n");


    // Teste balanceada
    enqueue(fila, '}');
    printf("\nFila:");
    imprimir(fila);

    retorno = verificaBalanceamento(fila,pilha);
    if(retorno == 1)
        printf("\n=> A fila está: Balanceada\n");
    else
        printf("\n=> A fila está: Desbalanceada\n");
    return 0;

}
