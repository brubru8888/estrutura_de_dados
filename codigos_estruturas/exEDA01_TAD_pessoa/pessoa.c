#include <stdio.h>
#include <string.h>

#include "pessoa.h"

Pessoa criarPessoa(const char* nome, int idade, float peso, float altura){

    Pessoa pessoa;

    // copia a string nome para dentro de pessoa.nome
    strncpy(pessoa.nome, nome, sizeof(pessoa.nome) - 1);

    pessoa.nome[sizeof(pessoa.nome)-1] = '0'; // garantir que termine com nulo

    pessoa.idade = idade;
    pessoa.peso = peso;
    pessoa.altura = altura;

    return pessoa;
}

void atualizarIdade(Pessoa* pessoa, int idade){
    pessoa->idade = idade;
}

void imprimirPessoa(Pessoa pessoa){

    printf("\nNome: %s", pessoa.nome);
    printf("\nIdade: %d", pessoa.idade);
    printf("\nAltura: %1.2f", pessoa.altura);
    printf("\nPeso %1.2f", pessoa.peso);

}

