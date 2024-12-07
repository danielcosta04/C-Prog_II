#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100 // Número máximo de produtos

// Definindo a estrutura para o produto
typedef struct {
    int numero;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

// Declaração do array de produtos e contador
Produto produtos[MAX_PRODUTOS];
int contador_produtos = 0;

// Função para adicionar um novo produto
void adicionar_produto() {
    if (contador_produtos >= MAX_PRODUTOS) {
        printf("Limite máximo de produtos atingido.\n");
        return;
    }

    Produto p;
    
    printf("Digite o numero do produto: ");
    scanf("%d", &p.numero);
    
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", p.nome);  // Leitura de string com espaços
    
    printf("Digite a quantidade do produto: ");
    scanf("%d", &p.quantidade);
    
    printf("Digite o preco do produto: ");
    scanf("%f", &p.preco);
    
    // Armazenando no array de produtos
    produtos[contador_produtos] = p;
    contador_produtos++;

    printf("Produto adicionado com sucesso!\n");
}

// Função para exibir todos os produtos cadastrados
void exibir_produtos() {
    if (contador_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    
    printf("Lista de Produtos Cadastrados:\n");
    for (int i = 0; i < contador_produtos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Numero: %d\n", produtos[i].numero);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preco: %.2f\n", produtos[i].preco);
        printf("---------------------------\n");
    }
}

// Função para salvar os produtos em um arquivo de texto
void salvar_produtos() {
    FILE *arquivo = fopen("produtos.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < contador_produtos; i++) {
        fprintf(arquivo, "%d %s %d %.2f\n", 
                produtos[i].numero, 
                produtos[i].nome, 
                produtos[i].quantidade, 
                produtos[i].preco);
    }

    fclose(arquivo);
    printf("Produtos salvos com sucesso no arquivo.\n");
}

// Função para carregar os produtos de um arquivo de texto
void carregar_produtos() {
    FILE *arquivo = fopen("produtos.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    contador_produtos = 0;
    while (fscanf(arquivo, "%d %s %d %f", 
                  &produtos[contador_produtos].numero, 
                  produtos[contador_produtos].nome, 
                  &produtos[contador_produtos].quantidade, 
                  &produtos[contador_produtos].preco) != EOF) {
        contador_produtos++;
    }

    fclose(arquivo);
    printf("Produtos carregados com sucesso do arquivo.\n");
}

// Função para exibir o menu do sistema
void menu() {
    int opcao;
    do {
        printf("\n==== Sistema de Cadastro de Produtos ====\n");
        printf("1. Adicionar Produto\n");
        printf("2. Exibir Produtos\n");
        printf("3. Salvar Produtos\n");
        printf("4. Carregar Produtos\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionar_produto();
                break;
            case 2:
                exibir_produtos();
                break;
            case 3:
                salvar_produtos();
                break;
            case 4:
                carregar_produtos();
                break;
            case 5:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida, tente novamente.\n");
        }
    } while (opcao != 5);
}

int main() {
    // Iniciar o sistema
    menu();
    return 0;
}