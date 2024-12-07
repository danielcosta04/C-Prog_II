// Faca um programa que leia uma matriz de tamanho 4x4.
// Imprima na tela o maior valor contido nessa matriz
// e a sua localização (linha e coluna)
#include <stdio.h>
#define LINHA 4
#define COLUNA 4
int main()
{
    int matriz[LINHA][COLUNA], i, j, maior = 0;
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            printf("Digite a matriz[%d][%d]:", i, j);
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
            }
        }
    }
    for (i = 0; i < LINHA; i++)
    {
        for (j = 0; j < COLUNA; j++)
        {
            if (matriz[i][j] == maior)
            {
                printf("\nMAIOR : [%d][%d]= %d", i, j, matriz[i][j]);
            }
        }
    }
}