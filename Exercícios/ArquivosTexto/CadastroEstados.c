#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar dados do estado
typedef struct {
    int codigo;
    char nome[50];
    char uf[3];
    int populacao;
} Estado;

// Funções
void incluirEstado();
void excluirEstado();
void alterarEstado();
void consultarEstado();
void listarEstados();
void exibirMenu();

const char *ARQUIVO_ESTADOS = "estados.txt";

int main() {
    int opcao;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch (opcao) {
            case 1:
                incluirEstado();
                break;
            case 2:
                excluirEstado();
                break;
            case 3:
                alterarEstado();
                break;
            case 4:
                consultarEstado();
                break;
            case 5:
                listarEstados();
                break;
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

void exibirMenu() {
    printf("\n--- Sistema de Cadastro de Estados Brasileiros ---\n");
    printf("1. Incluir estado\n");
    printf("2. Excluir estado\n");
    printf("3. Alterar estado\n");
    printf("4. Consultar estado\n");
    printf("5. Listar estados\n");
    printf("6. Sair\n");
}

void incluirEstado() {
    Estado e;
    FILE *arquivo = fopen(ARQUIVO_ESTADOS, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o codigo do estado: ");
    scanf("%d", &e.codigo);
    getchar();

    printf("Digite o nome do estado: ");
    fgets(e.nome, sizeof(e.nome), stdin);
    e.nome[strcspn(e.nome, "\n")] = 0; // Remove o '\n'

    printf("Digite a sigla da UF (2 caracteres): ");
    fgets(e.uf, sizeof(e.uf), stdin);
    e.uf[strcspn(e.uf, "\n")] = 0;

    printf("Digite a populacao do estado: ");
    scanf("%d", &e.populacao);

    // Grava os dados no arquivo separados por vírgulas
    fprintf(arquivo, "%d,%s,%s,%d\n", e.codigo, e.nome, e.uf, e.populacao);
    fclose(arquivo);

    printf("Estado incluido com sucesso!\n");
}

void excluirEstado() {
    Estado e;
    int codigo, encontrado = 0;
    FILE *arquivo = fopen(ARQUIVO_ESTADOS, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o codigo do estado a ser excluido: ");
    scanf("%d", &codigo);

    while (fgets(e.nome, sizeof(e.nome), arquivo)) {
        sscanf(e.nome, "%d,%49[^,],%2[^,],%d", &e.codigo, e.nome, e.uf, &e.populacao);
        if (e.codigo == codigo) {
            encontrado = 1;
        } else {
            fprintf(temp, "%d,%s,%s,%d\n", e.codigo, e.nome, e.uf, e.populacao);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO_ESTADOS);
    rename("temp.txt", ARQUIVO_ESTADOS);

    if (encontrado) {
        printf("Estado excluido com sucesso!\n");
    } else {
        printf("Estado nao encontrado.\n");
    }
}

void alterarEstado() {
    Estado e;
    int codigo, encontrado = 0;
    FILE *arquivo = fopen(ARQUIVO_ESTADOS, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o codigo do estado a ser alterado: ");
    scanf("%d", &codigo);
    getchar();

    while (fgets(e.nome, sizeof(e.nome), arquivo)) {
        sscanf(e.nome, "%d,%49[^,],%2[^,],%d", &e.codigo, e.nome, e.uf, &e.populacao);
        if (e.codigo == codigo) {
            encontrado = 1;

            printf("Digite o novo nome do estado: ");
            fgets(e.nome, sizeof(e.nome), stdin);
            e.nome[strcspn(e.nome, "\n")] = 0;

            printf("Digite a nova sigla da UF: ");
            fgets(e.uf, sizeof(e.uf), stdin);
            e.uf[strcspn(e.uf, "\n")] = 0;

            printf("Digite a nova populacao: ");
            scanf("%d", &e.populacao);
            getchar();
        }
        fprintf(temp, "%d,%s,%s,%d\n", e.codigo, e.nome, e.uf, e.populacao);
    }

    fclose(arquivo);
    fclose(temp);

    remove(ARQUIVO_ESTADOS);
    rename("temp.txt", ARQUIVO_ESTADOS);

    if (encontrado) {
        printf("Estado alterado com sucesso!\n");
    } else {
        printf("Estado nao encontrado.\n");
    }
}

void consultarEstado() {
    Estado e;
    int codigo, encontrado = 0;
    FILE *arquivo = fopen(ARQUIVO_ESTADOS, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("Digite o codigo do estado para consulta: ");
    scanf("%d", &codigo);

    while (fgets(e.nome, sizeof(e.nome), arquivo)) {
        sscanf(e.nome, "%d,%49[^,],%2[^,],%d", &e.codigo, e.nome, e.uf, &e.populacao);
        if (e.codigo == codigo) {
            printf("\nEstado encontrado:\n");
            printf("Codigo: %d\n", e.codigo);
            printf("Nome: %s\n", e.nome);
            printf("UF: %s\n", e.uf);
            printf("Populacao: %d\n", e.populacao);
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Estado nao encontrado.\n");
    }
}

void listarEstados() {
    Estado e;
    FILE *arquivo = fopen(ARQUIVO_ESTADOS, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\n--- Lista de Estados ---\n");

    while (fgets(e.nome, sizeof(e.nome), arquivo)) {
        sscanf(e.nome, "%d,%49[^,],%2[^,],%d", &e.codigo, e.nome, e.uf, &e.populacao);
        printf("Codigo: %d | Nome: %s | UF: %s | Populacao: %d\n",
               e.codigo, e.nome, e.uf, e.populacao);
    }

    fclose(arquivo);
}