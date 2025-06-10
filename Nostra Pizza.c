#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[30];
    float valor;
} Pizza;

typedef struct {
    char nome[25];
    int idade;
    char endereco[100];
} Cliente;

Pizza pizzas[50];
Cliente clientes[50];
int totalpizza = 0;
int totalcliente = 0;


void CadastrarPizza();
void CadastrarCliente();
void ListarPizza();
void ListarClente();
void ComprarPizza();
void FinalizarFuncao();

int main() {
    int opcao;
    do {
        printf("---- Pizzaria Nostra Pizza ----\n");
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar pizza\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Listar pizza\n");
        printf("4 - Listar cliente\n");
        printf("5 - Comprar pizza\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
            CadastrarPizza();
            break;
                
            case 2:
            CadastrarCliente();
            break;
                
            case 3:
            ListarPizza();
            FinalizarFuncao();
            break;
                
            case 4:
            ListarClente();
            break;
                
            case 5:
            ComprarPizza();
            break;
                
            case 0:
            printf("Obrigado pela preferencia!\n");
            printf("Saindo...\n");
            break;
                
            default:
            printf("Opção invalida! Tente novamente!\n");
            FinalizarFuncao();
            break;
            
        }
        
    } while (opcao != 6);
    
    return 0;
}

void CadastrarPizza() {
    printf("Digite o nome da pizza:\n");
    scanf(" %s", pizzas[totalpizza].nome);
    
    printf("Digite o valor da pizza:\n");
    scanf("%f", &pizzas[totalpizza].valor);
    
    totalpizza++;
}

void CadastrarCliente() {
    printf("Digite o nome do cliente:\n");
    scanf(" %s", clientes[totalcliente].nome);
    
    printf("Digite sua idade:\n");
    scanf("%d", &clientes[totalcliente].idade);
    
    printf("Informe seu endereço (Rua, Bairro e Número): \n");
    scanf(" %s", clientes[totalcliente].endereco);
    
    totalcliente++;
}

void ListarPizza() {
    for (int i = 0; i < totalpizza; i++) {
        
        printf("\nPizza %d: %s \nR$ %.2f\n", i + 1, pizzas[i].nome, pizzas[i].valor);
    }
}

void ListarClente() {
    for (int i = 0; i < totalcliente; i++) {
        
        printf("\nCliente %d: %s\n", i + 1, clientes[i].nome);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Endereço: %s\n", clientes[i].endereco);
    }
}

void ComprarPizza() {
    int cliente;
    float total = 0;
    int quantidadepizza;
    int pizza;
    
    printf("Digite o número do cliente:\n");
    scanf("%d", &cliente);
    
    if (cliente > 0 && cliente <= totalcliente) {
        
        printf("\nPizzas disponíveis:\n");
        ListarPizza();
        
        printf("\nQuantas pizzas você deseja comprar?\n");
        scanf("%d", &quantidadepizza);
        
        printf("\nComprar:\n");
        
        for (int i = 0; i < quantidadepizza; i++) {
            
            printf("Digite o número da pizza %d: \n", i + 1);
            scanf("%d", &pizza);
            
            if (pizza > 0 && pizza <= totalpizza) {
                printf("\n%s \nR$ %.2f\n", pizzas[pizza - 1].nome, pizzas[pizza - 1].valor);
                total += pizzas[pizza - 1].valor;
            } else {
                printf("Pizza inválida!\n");
            }
        }
        
        printf ("\n---- Nota Fiscal -----\n");
        printf("\nTotal: R$ %.2f\n", total);
    } else {
        printf("Cliente inválido!\n");
    }
}

void FinalizarFuncao() {
    
    printf("\nEnter para Continuar....\n");
    getchar();
    getchar();
    system("clear");
}