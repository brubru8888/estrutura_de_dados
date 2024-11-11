#ifndef PESSOA_H
#define PESSOA_H

typedef struct{
    char nome[50];
    float peso;
    float altura;
    int idade;
} Pessoa;

Pessoa criarPessoa(const char* nome, int idade, float peso, float altura);

void atualizarIdade(Pessoa* pessoa, int idade);

void imprimirPessoa(Pessoa pessoa);

#endif // PESSOA_H
