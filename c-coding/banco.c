#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

struct conta{
    int numeroConta;
    char nomeTitular[40];
    float saldo;
};

Conta* criarConta(int numero, char nome[40], float saldo){
    Conta* conta = (Conta *) malloc(sizeof(Conta));

    if(conta != NULL){
        conta->numeroConta = numero;
        strcpy(conta->nomeTitular, nome);
        conta->saldo = saldo;
    }

    return conta;
}

void depositar(Conta* conta, float valor){
    if(conta != NULL){
        conta->saldo += valor;
    }
}

void sacar(Conta* conta, float valor){
    if(conta != NULL && conta->saldo >= valor){
        conta->saldo -= valor;
    }
}

float consultarSaldo(Conta* conta){
    if(conta != NULL){
        return conta->saldo;
    }

    return 0;
}

void transferir(Conta* conta1, Conta* conta2, float valor){
    if(conta1 != NULL && conta2 != NULL && conta1->saldo >= valor){
        conta1->saldo -= valor;
        conta2->saldo += valor;
    }
}

void liberarConta(Conta* conta){
    free(conta);
}
