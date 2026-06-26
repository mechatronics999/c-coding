#include <stdio.h>

typedef struct {
    int estoque[4][2];
    float valorUnitario[4][2];
    float frete[3];
} distribuidora;

typedef struct {
    int sabor;
    int tamanho;
    int quantidade;
    int localidade;
    int atendido;
} atacado;

void receberCarga(distribuidora *dist, int sabor, int tamanho, int quantidade);

void pedidoVarejo(distribuidora *dist);

void pedidoAtacado(distribuidora *dist, int sabor, int tamanho, int quantidade, int localidade, atacado pedidos[], int *qtdPedidos);

int main() {
    distribuidora dist = {0};
    atacado pedidos[100];
    char continuar;
    int sabor, tamanho, quantidade, localidade, op, op2, op3, op4, qtdPedidos = 0, totalGeral = 0, totalSabor = 0, atendidos = 0, naoAtendidos = 0;
    float porcentagem = 0.0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Insira o valor unitario do refrigerante %d no tamanho %d [Refrigerantes: 0- Guarana, 1- Laranja, 2- Limao, 3- Cola; Tamanhos: 0- Lata, 1- Garrafa]:\n", j, i);
            scanf("%f", &dist.valorUnitario[j][i]);
        }
    }

    printf("Insira o valor do frete em Luzimangues:\n");
    scanf("%f", &dist.frete[0]);
    printf("Insira o valor do frete na regiao Sul de Palmas:\n");
    scanf("%f", &dist.frete[1]);
    printf("Insira o valor do frete na regiao Norte de Palmas:\n");
    scanf("%f", &dist.frete[2]);

    do {
        printf("Escolha uma opcao: [1- Receber carga, 2- Receber pedido, 3- Editar valores, 4- Relatorio por sabor, 5- Relatorio geral]\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Insira sabor [0- Guarana, 1- Laranja, 2- Limao, 3- Cola]:\n");
                scanf("%d", &sabor);
                printf("Insira tamanho [0- Lata, 1- Garrafa]:\n");
                scanf("%d", &tamanho);
                printf("Insira quantidade:\n");
                scanf("%d", &quantidade);

                receberCarga(&dist, sabor, tamanho, quantidade);

                break;

            case 2:
                printf("Deseja realizar o pedido no Varejo ou no Atacado? [0- Varejo, 1- Atacado]:\n");
                scanf("%d", &op2);

                if (op2 == 0) {
                    pedidoVarejo(&dist);
                }
                if (op2 == 1) {
                    printf("Insira sabor [0- Guarana, 1- Laranja, 2- Limao, 3- Cola]:\n");
                    scanf("%d", &sabor);
                    printf("Insira tamanho [0- Lata, 1- Garrafa]:\n");
                    scanf("%d", &tamanho);
                    printf("Insira quantidade:\n");
                    scanf("%d", &quantidade);
                    printf("Insira localidade [0 - Luzimangues, 1- Palmas Sul, 2- Palmas Norte]:\n");
                    scanf("%d", &localidade);

                    pedidoAtacado(&dist, sabor, tamanho, quantidade, localidade, pedidos, &qtdPedidos);
                }

                break;

            case 3:
                printf("Deseja consultar ou editar valores? [1- Consultar, 0- Editar]\n");
                scanf("%d", &op3);

                if (op3 == 1) {
                    printf("O que deseja consultar? [1- Valor unitario, 2- Frete]\n");
                    scanf("%d", &op4);

                    if (op4 == 1) {
                        printf("Insira sabor [0- Guarana, 1- Laranja, 2- Limao, 3- Cola]:\n");
                        scanf("%d", &sabor);
                        printf("Insira tamanho [0- Lata, 1- Garrafa]:\n");
                        scanf("%d", &tamanho);

                        printf("Valor unitario atual: %.2f\n", dist.valorUnitario[sabor][tamanho]);
                    }
                    else if (op4 == 2) {
                        printf("De qual cidade deseja consultar o frete? [0- Luzimangues, 1- Palmas Sul, 2- Palmas Norte]:\n");
                        scanf("%d", &localidade);

                        printf("Valor do frete atual: %.2f\n", dist.frete[localidade]);
                    }
                }
                else if (op3 == 0) {
                    printf("O que deseja editar? [1- Valor Unitario, 2- Valor do Frete]:\n");
                    scanf("%d", &op4);

                    if (op4 == 1) {
                        printf("Insira sabor [0- Guarana, 1- Laranja, 2- Limao, 3- Cola]:\n");
                        scanf("%d", &sabor);
                        printf("Insira tamanho [0- Lata, 1- Garrafa]:\n");
                        scanf("%d", &tamanho);

                        printf("Insira o NOVO valor unitario:\n");
                        scanf("%f", &dist.valorUnitario[sabor][tamanho]);
                        printf("Valor atualizado com sucesso!\n");
                    }
                    else if (op4 == 2) {
                        printf("Insira de qual local deseja editar o frete [0- Luzimangues, 1- Palmas Sul, 2- Palmas Norte]:\n");
                        scanf("%d", &localidade);

                        printf("Insira o NOVO valor do frete:\n");
                        scanf("%f", &dist.frete[localidade]);
                        printf("Frete atualizado com sucesso!\n");
                    }
                }

                break;

            case 4:
                printf("Insira o sabor do refrigerante [0- Guarana, 1- Laranja, 2- Limao, 3- Cola]:\n");
                scanf("%d", &sabor);

                printf("Quantidade em estoque de latinhas desse sabor: %d\n", dist.estoque[sabor][0]);
                printf("Quantidade em estoque de garrafas desse sabor: %d\n", dist.estoque[sabor][1]);

                break;

            case 5:
                printf("--- Quantidade de latinhas e de garrafas, e a porcentagem de itens de cada sabor---\n");

                totalGeral = 0, atendidos = 0, naoAtendidos = 0;

                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 2; j++) {
                        totalGeral += dist.estoque[i][j];
                    }
                }

                for (int i = 0; i < 4; i++) {
                    printf("Quantidade de latinhas do sabor %d: %d\n", i, dist.estoque[i][0]);
                    printf("Quantidade de garrafas do sabor %d: %d\n", i, dist.estoque[i][1]);

                    totalSabor = dist.estoque[i][0] + dist.estoque[i][1];

                    if (totalGeral != 0) {
                        porcentagem = ((float)totalSabor / totalGeral) * 100;
                    }

                    printf("Porcentagem do sabor %d no estoque: %.2f%%\n", i, porcentagem);
                    printf("--------------------------------------------------\n");
                }

                printf("---Quantidade de latinhas e garrafas ao todo---\n");
                printf("Total de itens em estoque: %d\n", totalGeral);
                printf("--------------------------------------------------\n");


                printf("---Numero de pedidos atendidos e nao atendidos---\n");
                for (int k = 0; k < qtdPedidos; k++) {
                    if (pedidos[k].atendido == 1) {
                        atendidos++;
                    } else {
                        naoAtendidos++;
                    }
                }
                printf("Pedidos atendidos: %d\n", atendidos);
                printf("Pedidos nao atendidos: %d\n", naoAtendidos);
                printf("--------------------------------------------------\n");

                break;

            default:
                printf("Opcao invalida\n");

        }

        printf("Deseja retornar ao menu inicial? s ou n\n");
        scanf(" %c", &continuar);
    }while (continuar == 's');

    return 0;
}

void receberCarga(distribuidora *dist, int sabor, int tamanho, int quantidade) {

    dist->estoque[sabor][tamanho] += quantidade;
}

void pedidoAtacado(distribuidora *dist, int sabor, int tamanho, int quantidade, int localidade, atacado pedidos[], int *qtdPedidos) {

    float valorPedido;
    if (quantidade <= 500) {
        valorPedido = (float) (dist->valorUnitario[sabor][tamanho] * quantidade) + dist->frete[localidade];
    }
    else if (quantidade > 500) {
        valorPedido = (float) (dist->valorUnitario[sabor][tamanho] * quantidade);
    }

    if (dist->estoque[sabor][tamanho] >= quantidade) {
        dist->estoque[sabor][tamanho] -= quantidade;

        pedidos[*qtdPedidos].sabor = sabor;
        pedidos[*qtdPedidos].tamanho = tamanho;
        pedidos[*qtdPedidos].quantidade = quantidade;
        pedidos[*qtdPedidos].localidade = localidade;

        printf("Valor do pedido: %.2f\n", valorPedido);
        printf("Pedido atendido com sucesso\n");

        pedidos[*qtdPedidos].atendido = 1;
        (*qtdPedidos)++;
    }
    else if (dist->estoque[sabor][tamanho] < quantidade) {
        printf("Valor do pedido: %.2f\n", valorPedido);
        printf("Estoque insuficiente para o pedido ser atendido no momento\n");

        pedidos[*qtdPedidos].sabor = sabor;
        pedidos[*qtdPedidos].tamanho = tamanho;
        pedidos[*qtdPedidos].quantidade = quantidade;
        pedidos[*qtdPedidos].localidade = localidade;

        pedidos[*qtdPedidos].atendido = 0;
        (*qtdPedidos)++;
    }
}

void pedidoVarejo(distribuidora *dist) {

    int sabor, tamanho, quantidade, op;
    int carrinho[4][2] = {0};
    char continuar;
    float valorTotal = 0;

    do {
        printf("Insira sabor [0- Guarana, 1- Laranja, 2- Limao, 3- Cola]:\n");
        scanf("%d", &sabor);
        printf("Insira tamanho [0- Lata, 1- Garrafa]:\n");
        scanf("%d", &tamanho);
        printf("Insira quantidade:\n");
        scanf("%d", &quantidade);

        if (dist->estoque[sabor][tamanho] >= (carrinho[sabor][tamanho] + quantidade)) {
            valorTotal += (float) (dist->valorUnitario[sabor][tamanho] * quantidade);
            carrinho[sabor][tamanho] += quantidade;
        }
        else if (dist->estoque[sabor][tamanho] < (carrinho[sabor][tamanho] + quantidade)) {
            printf("Estoque insuficiente para esse pedido\n");
        }
        printf("Deseja adicionar mais itens ao seu pedido? s ou n\n");
        scanf(" %c", &continuar);
    }while (continuar == 's');

    printf("Valor total do seu pedido: %.2f\n", valorTotal);
    printf("Efetivar ou cancelar pedido? [1- Efetivar, 0- Cancelar]:\n");
    scanf("%d", &op);

    if (op == 1) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                dist->estoque[i][j] -= carrinho[i][j];
            }
        }
    }
    else if (op == 0) {
        printf("Pedido cancelado\n");
    }
}