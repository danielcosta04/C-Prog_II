#include <stdio.h>

int main() {
    float nota1, nota2, media, nota3;

    // Solicita a entrada do usuário para as duas primeiras notas
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    // Calcula a média das duas primeiras notas
    media = (nota1 + nota2) / 2.0;

    // Verifica se o aluno está aprovado ou precisa da terceira nota
    if (media >= 7.0) {
        printf("Aprovado\n");
    } else {
        // Se a média for menor que 7, lê a terceira nota
        printf("Digite a terceira nota: ");
        scanf("%f", &nota3);

        // Verifica se o aluno está aprovado ou reprovado com base na terceira nota
        if (nota3 >= 6.0) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }

    return 0;
}