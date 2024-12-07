#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_PRODUTOS 5

//Definindo a struct para o produto

struct Produto{
    int id;
    char nome[50];
    float valor;
};

//função para buscar um produto pelo ID
    struct Produto* buscarProduto(struct Produto produtos[], int total, int id){
        for(int i=0;i < total;i++){
            if(produtos[i].id == id){
                return &produtos[i];//retorna o endereço do produto encontrado
            }
        }
        return NULL;//retorna NULL se o produto não for encontrado
    }

int main(){
    setlocale(LC_ALL, "portuguese");

    int totalProdutos = 3;
    int idBuscado;

        struct Produto produtos[MAX_PRODUTOS] = {
            {1,"Produto A", 10.50},
            {2, "Produto B", 20.75},
            {3, "Produto C", 15.00}
        };

        printf("Digite o ID do produto que deseja buscar: ");
        scanf("%d", &idBuscado);

        struct Produto* produtoEncontrado = buscarProduto(produtos, totalProdutos, idBuscado);

        if(produtoEncontrado != NULL){
            printf("Produto encontrado:\n");
            printf("ID:\t %d\n", produtoEncontrado->id);
            printf("Nome:\t %s\n", produtoEncontrado->nome);
            printf("Valor:\t %.2f", produtoEncontrado->valor);
        }else{
            printf("Produto não encontrado.\n");
        }

    return 0;
}