#include <stdio.h>

int main() {
    int x, y;
    int *a, *b;

    // Solicita ao usuário que insira dois números
    printf("Digite o valor de x: ");
    scanf("%d", &x);

    printf("Digite o valor de y: ");
    scanf("%d", &y);
    
    //Troca os valores 
    a = &x;
    b = &y;

  	int temp = *a;
   	*a = *b;
  	*b = temp;

    printf("\nApos a troca, x = %d e y = %d\n", x, y);

    return 0;
}