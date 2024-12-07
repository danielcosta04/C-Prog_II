#include <stdio.h>

int dobro(int n) {
    return n * 2;
}

int main() {
    int numero;
    
    printf("Digite um número inteiro não negativo: ");
    scanf("%d", &numero);
    
    printf("O dobro de %d é %d\n", numero, dobro(numero));
    
    return 0;
}