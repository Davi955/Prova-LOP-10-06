#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char banda[50];
    int quant, ano, generoID;
    float preco;
} CD;

CD vendacd[500];
int numVenda = 0;

void cadastrarCD();
void venderCD();
void generoporCD();
void consultarCD(); 
void finalizaFuncao(); 
int main() {
    int opcao;

    do {
        system("clear");
        printf("--- Som & Arte ---\n");
        printf("1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - CD por Genero\n");
        printf("4 - Consultar CD\n"); 
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                venderCD();
                break;
            case 3:
                generoporCD();
                break;
            case 4: 
                consultarCD();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while(opcao != 0);

    return 0;
}

void cadastrarCD() {
    system("clear");
    if (numVenda >= 500) {
        printf("Limite de CDs atingido.\n");
        finalizaFuncao();
        return;
    }

    printf("-- Cadastro de CD --\n");
    printf("Nome da Banda: ");
    scanf("%s", vendacd[numVenda].banda);
    printf("Ano: ");
    scanf("%d", &vendacd[numVenda].ano);
    printf("ID do genero: ");
    scanf("%d", &vendacd[numVenda].generoID);
    printf("Quantidade no estoque: ");
    scanf("%d", &vendacd[numVenda].quant);
    printf("Preco do produto: R$ ");
    scanf("%f", &vendacd[numVenda].preco);
    
    printf("\nProduto cadastrado com sucesso!\n");
    
    numVenda++;
    finalizaFuncao();
}

void venderCD() {
    system("clear");
    if (numVenda == 0) {
        printf("Nenhum produto cadastrado.\n");
        finalizaFuncao();
        return;
    }
    int quantComprada;
    printf("--- Realizar Compra ---\n");
    printf("Quantidade de produtos: ");
    scanf("%d", &quantComprada);

    if (quantComprada <= 0) {
        printf("Quantidade invalida.\n");
    } else if (quantComprada > vendacd[0].quant) {
        printf("Estoque insuficiente. Estoque atual: %d\n", vendacd[0].quant);
    } else {
        vendacd[0].quant -= quantComprada;
        float total = quantComprada * vendacd[0].preco;
        printf("Compra realizada com sucesso! Total: R$ %.2f\n", total);
        printf("Estoque restante: %d\n", vendacd[0].quant);
    }
    
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
    system("clear");
}

void generoporCD() {
    system("clear");
    int id;
    int encontrado = 0;
    printf("Digite o ID do genero: ");
    scanf("%d", &id);
    
    for (int i = 0; i < numVenda; i++) {
        if (vendacd[i].generoID == id) {
            encontrado = 1;
            printf("Nome da Banda: %s\n", vendacd[i].banda);
            printf("Ano: %d\n", vendacd[i].ano);
            printf("ID do genero: %d\n", vendacd[i].generoID);
            printf("Quantidade no estoque: %d\n", vendacd[i].quant);
            printf("Preco do produto: R$ %.2f\n", vendacd[i].preco);
            printf("-----------------------------\n");
        }
    }
    if (!encontrado) {
        printf("Nenhum CD encontrado para o ID de genero %d.\n", id);
    }
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
    system("clear");
}

void consultarCD() {
    system("clear");
    char bandaBusca[50];
    printf("Digite o nome da banda: \n");
    scanf("%s", bandaBusca);
    
    for (int i = 0; i < numVenda; i++) { 
        if (vendacd[i].banda[0] == bandaBusca[0]) { 
            if (vendacd[i].quant > 0) { 
                printf("CD disponivel!\n");
            } else {
                printf("CD nao esta disponivel!\n");
            }
            finalizaFuncao();
            return;
        }
    }
    printf("CD nao encontrado!\n");
    finalizaFuncao();
}



void finalizaFuncao() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
    system("clear");
}