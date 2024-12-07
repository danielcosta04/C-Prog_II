#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    
    printf("Digite uma string: ");
    gets(str);
    
    printf("A string tem %d caracteres.\n", strlen(str));
    return 0;
}