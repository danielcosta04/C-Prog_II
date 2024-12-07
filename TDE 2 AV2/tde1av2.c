  //1.Contar Produtos Abaixo de um Valor: Crie um programa que conte quantos produtos tem 
//um valor abaixo de um determinado valor fornecido pelo usuario.
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX_PRODUTOS 5
// Definindo a struct para o produto
typedef struct {
 int id;
 char nome[50];
 float valor;
} Produto;
int main() {
 Produto produtos[MAX_PRODUTOS];
 int quantidade, i;
 float valorLimite;
 int contador = 0;
 // Lendo a quantidade de produtos e verificando o limite
 printf("Digite a quantidade de produtos (máximo %d): ", MAX_PRODUTOS);
 scanf("%d", &quantidade);
 if (quantidade > MAX_PRODUTOS) {
 printf("A quantidade de produtos excede o limite de %d.\n", MAX_PRODUTOS);
 return 1;
 }
 // Lendo os dados dos produtos
 for (i = 0; i < quantidade; i++) {
 printf("Produto %d:\n", i + 1);
 printf("ID: ");
 scanf("%d", &produtos[i].id);
 printf("Nome: ");
 getchar(); // Limpa o buffer para evitar problemas com fgets
 fgets(produtos[i].nome, sizeof(produtos[i].nome), stdin);
 produtos[i].nome[strcspn(produtos[i].nome, "\n")] = '\0'; // Remove o '\n' do final da string
 printf("Valor: ");
 scanf("%f", &produtos[i].valor);
 }
 // Lendo o valor limite
 printf("Digite o valor limite: ");
 scanf("%f", &valorLimite);
 // Contando produtos abaixo do valor limite
 for (i = 0; i < quantidade; i++) {
 if (produtos[i].valor < valorLimite) {
 contador++;
 }
 }
 // Exibindo o resultado
 printf("Quantidade de produtos abaixo de R$ %.2f: %d\n", valorLimite, contador);
 return 0;
}
