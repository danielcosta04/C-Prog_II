#include <stdio.h>

int main() {
    int numero, pares = 0;

    for (int i = 1; i <= 10; i++) {
        printf("Digite o %do número: ", i);
        scanf("%d", &numero);

        if (numero % 2 == 0) {
            pares++;
        }
    }

    printf("Quantidade de números pares: %d\n", pares);
    return 0;
}