#include <stdio.h>
#include <string.h>
#include <locale.h>

// Definindo a estrutura do produto
struct Produto {
    int id;
    char nome[50];
    float valor;
};

// Função para atualizar o valor do produto com base no ID
void atualizarValor(struct Produto produtos[], int n, int id, float novoValor){
    for(int i=0;i<n;i++){
        if(produtos[i].id == id){
            produtos[i].valor = novoValor;
            printf("Valor atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

int main() {

    setlocale(LC_ALL, "portuguese");

    // Criando uma lista de produtos
    struct Produto produtos[3] = {
        {1, "Produto A", 10.00},
        {2, "Produto B", 20.00},
        {3, "Produto C", 30.00}
    };
    
    // Exibindo os produtos
    for(int i=0;i<3;i++){
        printf("ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
    }
    
    // Atualizando o valor de um produto
    int id;
    float novoValor;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);
    printf("Digite o novo valor: ");
    scanf("%f", &novoValor);

    // Chamando a função para atualizar o valor
    atualizarValor(produtos, 3, id, novoValor);    

    // Exibindo os produtos atualizados
    printf("\nLista de produtos atualizada:\n");
    for(int i=0;i<3;i++){
        printf("ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
    }    

    return 0;
}
