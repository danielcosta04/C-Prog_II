#include <stdio.h>
#include <string.h>

struct Estudante {
    int id;
    char nome[50];
    float nota;
};

int main() {
    struct Estudante estudante1;

    estudante1.id = 1;
    strcpy(estudante1.nome, "Ana Maria");
    estudante1.nota = 9.5;

    printf("ID: %d\n", estudante1.id);
    printf("Nome: %s\n", estudante1.nome);
    printf("Nota: %.2f\n", estudante1.nota);

    return 0;
}

//---------------------------------------
/*
#include <stdio.h>
#include <string.h>

struct Livro {
    int id;
    char titulo[100];
    char autor[50];
    float preco;
};

void mostrarLivro(struct Livro livro) {
    printf("ID: %d\n", livro.id);
    printf("Título: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Preço: %.2f\n", livro.preco);
}

int main() {
    struct Livro livro1;

    livro1.id = 101;
    strcpy(livro1.titulo, "Estruturas de Dados em C");
    strcpy(livro1.autor, "José Silva");
    livro1.preco = 59.90;

    mostrarLivro(livro1);

    return 0;
}
*/

//---------------------------------------

/*#include <stdio.h>
#include <string.h>

struct Funcionario {
    int id;
    char nome[50];
    float salario;
};

int main() {
    struct Funcionario funcionarios[2];

    // Funcionario 1
    funcionarios[0].id = 1;
    strcpy(funcionarios[0].nome, "João Pereira");
    funcionarios[0].salario = 3000.0;

    // Funcionario 2
    funcionarios[1].id = 2;
    strcpy(funcionarios[1].nome, "Maria Souza");
    funcionarios[1].salario = 3500.0;

    // Exibindo os funcionários
    for (int i = 0; i < 2; i++) {
        printf("ID: %d\n", funcionarios[i].id);
        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Salário: %.2f\n", funcionarios[i].salario);
        printf("\n");
    }

    return 0;
}
*/
