#include <stdio.h>
#include "banco.h"

int main(){

    Conta* contaChad = criarConta(50, "Chad", 1500);
    printf("Saldo atual Chad: %.2f\n", consultarSaldo(contaChad));
    
    Conta* contaFoda = criarConta(100, "Foda", 1000);
    printf("Saldo atual Foda: %.2f\n", consultarSaldo(contaFoda));

    depositar(contaChad, 500);
    printf("Saldo atual Chad: %.2f\n", consultarSaldo(contaChad));
    
    sacar(contaChad, 500);
    printf("Saldo atual Chad: %.2f\n", consultarSaldo(contaChad));

    depositar(contaFoda, 1000);
    printf("Saldo atual Foda: %.2f\n", consultarSaldo(contaFoda));
    
    sacar(contaFoda, 1000);
    printf("Saldo atual Foda: %.2f\n", consultarSaldo(contaFoda));

    transferir(contaChad, contaFoda, 1000);

    printf("Saldo atual Chad: %.2f\n", consultarSaldo(contaChad));
    printf("Saldo atual Foda: %.2f\n", consultarSaldo(contaFoda));

    liberarConta(contaChad);
    liberarConta(contaFoda);

    return 0;
}



