#ifndef BANCO_H
#define BANCO_H

typedef struct conta Conta;

Conta* criarConta(int, char nome[], float);

void depositar(Conta*, float);

void sacar(Conta*, float);

float consultarSaldo(Conta*);

void transferir(Conta*, Conta*, float);

void liberarConta(Conta*);

#endif
