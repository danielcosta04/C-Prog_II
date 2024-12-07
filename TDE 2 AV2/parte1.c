                                //PARTE 1
//Lista de exercícios structs com base em produtos (id, nome, valor) 
//Contar Produtos Abaixo de um Valor: Crie um programa que conte quantos produtos têm um valor 
//abaixo de um determinado valor fornecido pelo usuário.

#include <stdio.h>
#include <string.h>

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

//fazer o código c: Lista de exercícios structs com base em produtos (id, nome, valor) 
//Buscar Produto pelo ID: Implemente um programa que permita ao usuário buscar um produto pelo ID. 
//Se o produto for encontrado, exiba suas informações; caso contrário, informe que não foi encontrado.

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5

// Definindo a struct para o produto
typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

// Função para buscar um produto pelo ID
void buscarProdutoPorID(Produto produtos[], int quantidade, int id) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            printf("Produto encontrado:\n");
            printf("ID: %d\n", produtos[i].id);
            printf("Nome: %s\n", produtos[i].nome);
            printf("Valor: %.2f\n", produtos[i].valor);
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade, i;
    int idBusca;

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

    // Lendo o ID do produto a ser buscado
    printf("Digite o ID do produto a ser buscado: ");
    scanf("%d", &idBusca);

    // Chamando a função para buscar o produto
    buscarProdutoPorID(produtos, quantidade, idBusca);

    return 0;
}


//programar em c: Lista de exercícios structs com base em produtos (id, nome, valor)
// Atualizar Valor do Produto: Desenvolva um programa que permita ao usuário atualizar 
//o valor de um produto com base no seu ID.

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5

// Definindo a struct para o produto
typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

// Função para atualizar o valor do produto com base no ID
void atualizarValorProduto(Produto produtos[], int quantidade, int id, float novoValor) {
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            produtos[i].valor = novoValor;
            printf("Valor do produto atualizado com sucesso!\n");
            return;
        }
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade, id;
    float novoValor;

    // Lendo a quantidade de produtos e verificando o limite
    printf("Digite a quantidade de produtos (máximo %d): ", MAX_PRODUTOS);
    scanf("%d", &quantidade);

    if (quantidade > MAX_PRODUTOS) {
        printf("A quantidade de produtos excede o limite de %d.\n", MAX_PRODUTOS);
        return 1;
    }

    // Lendo os dados dos produtos
    for (int i = 0; i < quantidade; i++) {
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

    // Lendo o ID do produto a ser atualizado e o novo valor
    printf("Digite o ID do produto a ser atualizado: ");
    scanf("%d", &id);
    printf("Digite o novo valor: ");
    scanf("%f", &novoValor);

    // Chamando a função para atualizar o valor
    atualizarValorProduto(produtos, quantidade, id, novoValor);

    // Exibindo os produtos atualizados
    printf("\nLista de Produtos Atualizada:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
    }

    return 0;
}

//programar em codigo c: Lista de exercícios structs com base em produtos (id, nome, valor) 
//Calcular Média de Preços: Implemente um programa que calcule e retorne a média dos preços dos produtos.

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5

// Definindo a struct para o produto
typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

// Função para calcular a média dos preços dos produtos
float calcularMediaPrecos(Produto produtos[], int quantidade) {
    float soma = 0.0;
    for (int i = 0; i < quantidade; i++) {
        soma += produtos[i].valor;
    }
    return soma / quantidade;
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade;

    // Lendo a quantidade de produtos e verificando o limite
    printf("Digite a quantidade de produtos (máximo %d): ", MAX_PRODUTOS);
    scanf("%d", &quantidade);

    if (quantidade > MAX_PRODUTOS) {
        printf("A quantidade de produtos excede o limite de %d.\n", MAX_PRODUTOS);
        return 1;
    }

    // Lendo os dados dos produtos
    for (int i = 0; i < quantidade; i++) {
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

    // Calculando a média dos preços
    float media = calcularMediaPrecos(produtos, quantidade);

    // Exibindo a média dos preços
    printf("A média dos preços dos produtos é: %.2f\n", media);

    return 0;
}

//programar em c: Lista de exercícios structs com base em produtos (id, nome, valor) 
//Exibir Produtos Acima da Média: Crie um programa que exiba todos os produtos cujo preço é superior à média calculada.

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 5

// Definindo a struct para o produto
typedef struct {
    int id;
    char nome[50];
    float valor;
} Produto;

// Função para calcular a média dos preços dos produtos
float calcularMediaPrecos(Produto produtos[], int quantidade) {
    float soma = 0.0;
    for (int i = 0; i < quantidade; i++) {
        soma += produtos[i].valor;
    }
    return soma / quantidade;
}

// Função para exibir produtos com valor acima da média
void exibirProdutosAcimaDaMedia(Produto produtos[], int quantidade, float media) {
    printf("\nProdutos com valor acima da média:\n");
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].valor > media) {
            printf("ID: %d, Nome: %s, Valor: %.2f\n", produtos[i].id, produtos[i].nome, produtos[i].valor);
        }
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade;

    // Lendo a quantidade de produtos e verificando o limite
    printf("Digite a quantidade de produtos (máximo %d): ", MAX_PRODUTOS);
    scanf("%d", &quantidade);

    if (quantidade > MAX_PRODUTOS) {
        printf("A quantidade de produtos excede o limite de %d.\n", MAX_PRODUTOS);
        return 1;
    }

    // Lendo os dados dos produtos
    for (int i = 0; i < quantidade; i++) {
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

    // Calculando a média dos preços
    float media = calcularMediaPrecos(produtos, quantidade);

    // Exibindo a média dos preços
    printf("A média dos preços dos produtos é: %.2f\n", media);

    // Exibindo os produtos com valor acima da média
    exibirProdutosAcimaDaMedia(produtos, quantidade, media);

    return 0;
}


                                            //PARTE 2

//Lista de exercícios structs com base em Clubes de Futebol (id, nome, vitorias, empates, derrotas, gols_pro, gols_contra)
// Cadastro de Clubes: Crie um programa que permita ao usuário cadastrar um número determinado de clubes 
//(por exemplo, 10). Para cada clube, solicite que o usuário insira o ID, nome, vitórias, empates, derrotas, 
//gols pró e gols contra. O programa deve calcular a pontuação de cada clube com base em suas vitórias, empates e derrotas.
//A pontuação deve ser calculada da seguinte forma: 3 pontos por vitória, 1 ponto por empate, 0 pontos por derrota. 
//Exiba a pontuação total de cada clube.  

#include <stdio.h>
#include <string.h>

#define MAX_CLUBES 10

// Definindo a struct para o clube de futebol
typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
    int pontos;
} Clube;

// Função para calcular a pontuação do clube
void calcularPontos(Clube *clube) {
    clube->pontos = (clube->vitorias * 3) + (clube->empates * 1);
}

int main() {
    Clube clubes[MAX_CLUBES];
    int quantidade, i;

    // Lendo a quantidade de clubes e verificando o limite
    printf("Digite a quantidade de clubes (máximo %d): ", MAX_CLUBES);
    scanf("%d", &quantidade);

    if (quantidade > MAX_CLUBES) {
        printf("A quantidade de clubes excede o limite de %d.\n", MAX_CLUBES);
        return 1;
    }

    // Lendo os dados dos clubes
    for (i = 0; i < quantidade; i++) {
        printf("Clube %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clubes[i].id);

        printf("Nome: ");
        getchar(); // Limpa o buffer para evitar problemas com fgets
        fgets(clubes[i].nome, sizeof(clubes[i].nome), stdin);
        clubes[i].nome[strcspn(clubes[i].nome, "\n")] = '\0'; // Remove o '\n' do final da string

        printf("Vitórias: ");
        scanf("%d", &clubes[i].vitorias);

        printf("Empates: ");
        scanf("%d", &clubes[i].empates);

        printf("Derrotas: ");
        scanf("%d", &clubes[i].derrotas);

        printf("Gols pró: ");
        scanf("%d", &clubes[i].gols_pro);

        printf("Gols contra: ");
        scanf("%d", &clubes[i].gols_contra);

        // Calculando a pontuação do clube
        calcularPontos(&clubes[i]);
    }

    // Exibindo a pontuação de cada clube
    printf("\nPontuação dos Clubes:\n");
    for (i = 0; i < quantidade; i++) {
        printf("ID: %d, Nome: %s, Pontos: %d\n", clubes[i].id, clubes[i].nome, clubes[i].pontos);
    }

    return 0;
}

//Lista de exercícios structs com base em Clubes de Futebol (id, nome, vitorias, empates, derrotas, gols_pro, gols_contra)
// Buscar Clube pelo ID: Desenvolva um programa que permita ao usuário buscar um clube pelo ID. Se o clube for encontrado,
// exiba suas informações; caso contrário, informe que não foi encontrado.

#include <stdio.h>
#include <string.h>

#define MAX_CLUBES 10

// Definindo a struct para o clube de futebol
typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
    int pontos;
} Clube;

// Função para buscar um clube pelo ID
void buscarClubePorID(Clube clubes[], int quantidade, int id) {
    for (int i = 0; i < quantidade; i++) {
        if (clubes[i].id == id) {
            printf("Clube encontrado:\n");
            printf("ID: %d\n", clubes[i].id);
            printf("Nome: %s\n", clubes[i].nome);
            printf("Vitórias: %d\n", clubes[i].vitorias);
            printf("Empates: %d\n", clubes[i].empates);
            printf("Derrotas: %d\n", clubes[i].derrotas);
            printf("Gols Pró: %d\n", clubes[i].gols_pro);
            printf("Gols Contra: %d\n", clubes[i].gols_contra);
            printf("Pontos: %d\n", clubes[i].pontos);
            return;
        }
    }
    printf("Clube com ID %d não encontrado.\n", id);
}

int main() {
    Clube clubes[MAX_CLUBES];
    int quantidade, idBusca;

    // Lendo a quantidade de clubes e verificando o limite
    printf("Digite a quantidade de clubes (máximo %d): ", MAX_CLUBES);
    scanf("%d", &quantidade);

    if (quantidade > MAX_CLUBES) {
        printf("A quantidade de clubes excede o limite de %d.\n", MAX_CLUBES);
        return 1;
    }

    // Lendo os dados dos clubes
    for (int i = 0; i < quantidade; i++) {
        printf("Clube %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clubes[i].id);

        printf("Nome: ");
        getchar(); // Limpa o buffer para evitar problemas com fgets
        fgets(clubes[i].nome, sizeof(clubes[i].nome), stdin);
        clubes[i].nome[strcspn(clubes[i].nome, "\n")] = '\0'; // Remove o '\n' do final da string

        printf("Vitórias: ");
        scanf("%d", &clubes[i].vitorias);

        printf("Empates: ");
        scanf("%d", &clubes[i].empates);

        printf("Derrotas: ");
        scanf("%d", &clubes[i].derrotas);

        printf("Gols pró: ");
        scanf("%d", &clubes[i].gols_pro);

        printf("Gols contra: ");
        scanf("%d", &clubes[i].gols_contra);

        // Calculando a pontuação do clube
        clubes[i].pontos = (clubes[i].vitorias * 3) + (clubes[i].empates * 1);
    }

    // Lendo o ID do clube a ser buscado
    printf("Digite o ID do clube a ser buscado: ");
    scanf("%d", &idBusca);

    // Chamando a função para buscar o clube
    buscarClubePorID(clubes, quantidade, idBusca);

    return 0;
}


//Lista de exercícios structs com base em Clubes de Futebol (id, nome, vitorias, empates, derrotas, gols_pro, gols_contra)
// Exibir Clubes com Gols Pró Acima da Média: Crie um programa que calcule a média de gols pró de todos os clubes e 
//exiba apenas os clubes que têm um número de gols pró superior a essa média.

#include <stdio.h>
#include <string.h>

#define MAX_CLUBES 10

// Definindo a struct para o clube de futebol
typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
    int pontos;
} Clube;

// Função para calcular a média de gols pró
float calcularMediaGolsPro(Clube clubes[], int quantidade) {
    int somaGolsPro = 0;
    for (int i = 0; i < quantidade; i++) {
        somaGolsPro += clubes[i].gols_pro;
    }
    return (float)somaGolsPro / quantidade;
}

// Função para exibir clubes com gols pró acima da média
void exibirClubesAcimaDaMedia(Clube clubes[], int quantidade, float media) {
    printf("\nClubes com gols pró acima da média:\n");
    for (int i = 0; i < quantidade; i++) {
        if (clubes[i].gols_pro > media) {
            printf("ID: %d, Nome: %s, Gols Pró: %d\n", clubes[i].id, clubes[i].nome, clubes[i].gols_pro);
        }
    }
}

int main() {
    Clube clubes[MAX_CLUBES];
    int quantidade;

    // Lendo a quantidade de clubes e verificando o limite
    printf("Digite a quantidade de clubes (máximo %d): ", MAX_CLUBES);
    scanf("%d", &quantidade);

    if (quantidade > MAX_CLUBES) {
        printf("A quantidade de clubes excede o limite de %d.\n", MAX_CLUBES);
        return 1;
    }

    // Lendo os dados dos clubes
    for (int i = 0; i < quantidade; i++) {
        printf("Clube %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clubes[i].id);

        printf("Nome: ");
        getchar(); // Limpa o buffer para evitar problemas com fgets
        fgets(clubes[i].nome, sizeof(clubes[i].nome), stdin);
        clubes[i].nome[strcspn(clubes[i].nome, "\n")] = '\0'; // Remove o '\n' do final da string

        printf("Vitórias: ");
        scanf("%d", &clubes[i].vitorias);

        printf("Empates: ");
        scanf("%d", &clubes[i].empates);

        printf("Derrotas: ");
        scanf("%d", &clubes[i].derrotas);

        printf("Gols pró: ");
        scanf("%d", &clubes[i].gols_pro);

        printf("Gols contra: ");
        scanf("%d", &clubes[i].gols_contra);

        // Calculando a pontuação do clube
        clubes[i].pontos = (clubes[i].vitorias * 3) + (clubes[i].empates * 1);
    }

    // Calculando a média de gols pró
    float mediaGolsPro = calcularMediaGolsPro(clubes, quantidade);

    // Exibindo a média de gols pró
    printf("A média de gols pró dos clubes é: %.2f\n", mediaGolsPro);

    // Exibindo os clubes com gols pró acima da média
    exibirClubesAcimaDaMedia(clubes, quantidade, mediaGolsPro);

    return 0;
}


//Lista de exercícios structs com base em Clubes de Futebol (id, nome, vitorias, empates, derrotas, gols_pro, gols_contra)
// Exibir saldo de gols: Crie um programa que calcule o saldo de gols de todos os clubes e exiba o nome e o saldo de cada clube.

#include <stdio.h>
#include <string.h>

#define MAX_CLUBES 10

// Definindo a struct para o clube de futebol
typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
    int saldo_gols;
    int pontos;
} Clube;

// Função para calcular o saldo de gols do clube
void calcularSaldoGols(Clube *clube) {
    clube->saldo_gols = clube->gols_pro - clube->gols_contra;
}

int main() {
    Clube clubes[MAX_CLUBES];
    int quantidade;

    // Lendo a quantidade de clubes e verificando o limite
    printf("Digite a quantidade de clubes (máximo %d): ", MAX_CLUBES);
    scanf("%d", &quantidade);

    if (quantidade > MAX_CLUBES) {
        printf("A quantidade de clubes excede o limite de %d.\n", MAX_CLUBES);
        return 1;
    }

    // Lendo os dados dos clubes
    for (int i = 0; i < quantidade; i++) {
        printf("Clube %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clubes[i].id);

        printf("Nome: ");
        getchar(); // Limpa o buffer para evitar problemas com fgets
        fgets(clubes[i].nome, sizeof(clubes[i].nome), stdin);
        clubes[i].nome[strcspn(clubes[i].nome, "\n")] = '\0'; // Remove o '\n' do final da string

        printf("Vitórias: ");
        scanf("%d", &clubes[i].vitorias);

        printf("Empates: ");
        scanf("%d", &clubes[i].empates);

        printf("Derrotas: ");
        scanf("%d", &clubes[i].derrotas);

        printf("Gols pró: ");
        scanf("%d", &clubes[i].gols_pro);

        printf("Gols contra: ");
        scanf("%d", &clubes[i].gols_contra);

        // Calculando a pontuação do clube
        clubes[i].pontos = (clubes[i].vitorias * 3) + (clubes[i].empates * 1);
        // Calculando o saldo de gols do clube
        calcularSaldoGols(&clubes[i]);
    }

    // Exibindo o saldo de gols de cada clube
    printf("\nSaldo de Gols dos Clubes:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s, Saldo de Gols: %d\n", clubes[i].nome, clubes[i].saldo_gols);
    }

    return 0;
}


//Lista de exercícios structs com base em Clubes de Futebol (id, nome, vitorias, empates, derrotas, gols_pro, gols_contra) 
//Exibir dados do melhor e do pior clube: Crie um programa que exiba os dados do clube campeão e do último colocado.

#include <stdio.h>
#include <string.h>

#define MAX_CLUBES 10

// Definindo a struct para o clube de futebol
typedef struct {
    int id;
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int gols_pro;
    int gols_contra;
    int saldo_gols;
    int pontos;
} Clube;

// Função para calcular o saldo de gols do clube
void calcularSaldoGols(Clube *clube) {
    clube->saldo_gols = clube->gols_pro - clube->gols_contra;
}

// Função para calcular os pontos do clube
void calcularPontos(Clube *clube) {
    clube->pontos = (clube->vitorias * 3) + (clube->empates * 1);
}

int main() {
    Clube clubes[MAX_CLUBES];
    int quantidade;

    // Lendo a quantidade de clubes e verificando o limite
    printf("Digite a quantidade de clubes (máximo %d): ", MAX_CLUBES);
    scanf("%d", &quantidade);

    if (quantidade > MAX_CLUBES) {
        printf("A quantidade de clubes excede o limite de %d.\n", MAX_CLUBES);
        return 1;
    }

    // Lendo os dados dos clubes
    for (int i = 0; i < quantidade; i++) {
        printf("Clube %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &clubes[i].id);

        printf("Nome: ");
        getchar(); // Limpa o buffer para evitar problemas com fgets
        fgets(clubes[i].nome, sizeof(clubes[i].nome), stdin);
        clubes[i].nome[strcspn(clubes[i].nome, "\n")] = '\0'; // Remove o '\n' do final da string

        printf("Vitórias: ");
        scanf("%d", &clubes[i].vitorias);

        printf("Empates: ");
        scanf("%d", &clubes[i].empates);

        printf("Derrotas: ");
        scanf("%d", &clubes[i].derrotas);

        printf("Gols pró: ");
        scanf("%d", &clubes[i].gols_pro);

        printf("Gols contra: ");
        scanf("%d", &clubes[i].gols_contra);

        // Calculando a pontuação e o saldo de gols do clube
        calcularPontos(&clubes[i]);
        calcularSaldoGols(&clubes[i]);
    }

    // Encontrando o melhor e o pior clube
    Clube *melhorClube = &clubes[0];
    Clube *piorClube = &clubes[0];

    for (int i = 1; i < quantidade; i++) {
        if (clubes[i].pontos > melhorClube->pontos) {
            melhorClube = &clubes[i];
        }
        if (clubes[i].pontos < piorClube->pontos) {
            piorClube = &clubes[i];
        }
    }

    // Exibindo os dados do melhor e do pior clube
    printf("\nMelhor Clube:\n");
    printf("ID: %d, Nome: %s, Vitórias: %d, Empates: %d, Derrotas: %d, Gols Pró: %d, Gols Contra: %d, Saldo de Gols: %d, Pontos: %d\n",
           melhorClube->id, melhorClube->nome, melhorClube->vitorias, melhorClube->empates,
           melhorClube->derrotas, melhorClube->gols_pro, melhorClube->gols_contra,
           melhorClube->saldo_gols, melhorClube->pontos);

    printf("\nPior Clube:\n");
    printf("ID: %d, Nome: %s, Vitórias: %d, Empates: %d, Derrotas: %d, Gols Pró: %d, Gols Contra: %d, Saldo de Gols: %d, Pontos: %d\n",
           piorClube->id, piorClube->nome, piorClube->vitorias, piorClube->empates,
           piorClube->derrotas, piorClube->gols_pro, piorClube->gols_contra,
           piorClube->saldo_gols, piorClube->pontos);

    return 0;
}

