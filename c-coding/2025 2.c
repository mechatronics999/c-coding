#include <stdio.h>

#define PALMAS 0
#define GURUPI 1
#define GOIANIA 2
#define BRASILIA 3

typedef struct {

    float valor;
    int qtdEntregue;
    int qtdFabricar;
    int qtdDeposito;

} brindeInfo;

// prototipos

int fabricar(brindeInfo [4][3], int, int, int);

void deveSerFabricado(brindeInfo [4][3]);

int main() {
    brindeInfo dados[4][3] = {0};
    float frete[4] = {0};
    char continuar;
    int brinde, cor, quantidade, menu, op, qtdAtual;

    for (int i = 0; i < 4; i++) {
        printf("Insira o valor de frete no ponto de distribuicao %d:\n", i);
        scanf("%f", &frete[i]);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Dados do brinde %d na cor %d [Brindes: 0- Caneta, 1- Chaveiro, 2- Regua. Cores: 0- Branco, 1- Azul, 2- Preto, 3- Vermelho]\n", j, i);
            printf("Valor unitario:\n");
            scanf("%f", &dados[i][j].valor);
            printf("Quantidade ja entregue:\n");
            scanf("%d", &dados[i][j].qtdEntregue);
            printf("Quantidade a fabricar\n");
            scanf("%d", &dados[i][j].qtdFabricar);
            printf("Quantidade em deposito:\n");
            scanf("%d", &dados[i][j].qtdDeposito);
        }
    }

    printf("Qual menu deseja? [0- Fabrica, 1- Pontos de distribuicao]\n");
    scanf("%d", &menu);

    if (menu == 0){

        do {
            printf("--- MENU FABRICA ---\n");
            printf("Qual opcao deseja? [1- Fabricar, 2- Mostrar o que deve ser fabricado, 3- Relatorio por brinde, 4- Relatorio por cor, 5- Relatorio de entregas]\n");
            scanf("%d", &op);

            switch (op) {

                case 1:
                    printf("Insira o brinde a ser fabricado [Brindes: 0- Caneta, 1- Chaveiro, 2- Regua]\n");
                    scanf("%d", &brinde);
                    printf("Insira a cor [Cores: 0- Branco, 1- Azul, 2- Preto, 3- Vermelho]\n");
                    scanf("%d", &cor);
                    printf("Insira a quantidade:\n");
                    scanf("%d", &quantidade);

                    qtdAtual = fabricar(dados, brinde, cor, quantidade);

                    printf("Brinde adicionado no deposito com sucesso\n");
                    printf("Quantidade atual no deposito: %d\n", qtdAtual);

                    break;

                case 2:


                    break;

                case 3:


                    break;

                case 4:


                    break;

                case 5:


                    break;

                default:
                    printf("Opcao invalida!\n");

            }

            printf("Deseja continuar? s ou n\n");
            scanf(" %c", &continuar);
        }while (continuar == 's');
    }

    if (menu == 1){

        do {
            printf("--- MENU PONTOS DE DISTRIBUICAO ---\n");
            printf("Qual opcao deseja? [1- Solicitar entrega, 2- Status da distribuidora, 3- Editar frete]\n");
            scanf("%d", &op);

            switch (op) {

                case 1:

                    break;

                case 2:

                    break;

                case 3:

                    break;


            }

            printf("Deseja continuar? s ou n\n");
            scanf(" %c", &continuar);
        }while (continuar == 's');
    }
}

int fabricar(brindeInfo dados[4][3], int brinde, int cor, int quantidade) {

    dados[cor][brinde].qtdDeposito += quantidade;

    return dados[cor][brinde].qtdDeposito;
}

void deveSerFabricado(brindeInfo dados[4][3]) {

    int brindeMenorQue50 = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Quantidade a fabricar do brinde %d na cor %d:\n", j, i);
            printf("%d\n", dados[i][j].qtdFabricar);
        }
    }

    printf("Brindes com menos de 50 itens no deposito:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (dados[i][j].qtdDeposito < 50) {
                printf("Brinde %d na cor %d tem menos de 50 itens no deposito\n", j, i);
                brindeMenorQue50 = 1;
            }
        }
    }

    if (brindeMenorQue50 == 0) {
        printf("Nao ha nenhum brinde com menos de 50 itens no deposito\n");
    }

}