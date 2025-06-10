#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    float preco;
    int quantidade;
} Produto;

Produto produto[10];

void cadastrarProduto();
void visualizarProduto();
void realizarCompra();
void finalizaFuncao();

int numProdutos = 0;


int main() {
    int opcao;
    
    do{
        printf("---== Supermercado SuperMais ==---\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Visualizar Produtos\n ");
        printf("3 - Realizar uma Compra\n");
        printf("0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d",&opcao);
        
        switch(opcao){
            case 1:
            cadastrarProduto();
            break;
            
            case 2:
            visualizarProduto();
            break;
            
            case 3:
            realizarCompra();
            break;
            
            
            case 0:
                printf("\nObrigado!\n");
            break;
            
            default:
                printf("Opção Inválida!\n");
                break;
        }
    }while(opcao !=0);
    
    return 0;
    
}

void cadastrarProduto(){
    system("clear");
    printf("--== Cadastro de Produto ==--\n");
    printf("Nome do Produto: ");
    scanf("%s", produto[numProdutos].nome);
    printf("Preço: R$ ");
    scanf("%f", &produto[numProdutos].preco);
    printf("Quantidade: ");
    scanf("%d", &produto[numProdutos].quantidade);
    numProdutos++;
   finalizaFuncao();
}

void visualizarProduto(){
    system("clear");
    printf("--== Meus Produtos ==--\n");
    if(numProdutos == 0){
    printf("Nenhum produto foi cadastrado ainda");
    finalizaFuncao();
    }else{
    for (int i = 0; i < numProdutos; i++) {
    printf("Produto: %s\n",produto[i].nome);
    printf("Preço:R$ %.2f\n",produto[i].preco);
    printf("Quantidade: %d\n", produto[i].quantidade);
    printf("-------------------------\n");
        }

    }
    
    finalizaFuncao();
}

void realizarCompra() {
    system("clear");
    int quantidadeCompra;

    if (produto[numProdutos].quantidade == 0) {
        printf("\nNenhum produto disponível para compra.\n");
    } else {
        printf("\n--== Realizar Compra ==--\n");
        printf("Produto: %s\n", produto[numProdutos].nome);
        printf("Preço unitário: R$ %.2f\n", produto[numProdutos].preco);
        printf("Quantidade disponível: %d\n", produto[numProdutos].quantidade);
        printf("Quantidade desejada: ");
        scanf("%d", &quantidadeCompra);
        getchar();

        if (quantidadeCompra > produto[numProdutos].quantidade) {
            printf("\nErro: Quantidade insuficiente em estoque!\n");
        } else {
            produto[numProdutos].quantidade -= quantidadeCompra;
            printf("\nCompra realizada com sucesso!\n");
        }
    }

    finalizaFuncao();
}



 
 void finalizaFuncao(){
    printf("\nEnter para continuar...");
    getchar();
    getchar();
    system("clear");
 }
 






