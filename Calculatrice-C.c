#include <stdio.h>
#include <stdlib.h>

void estnombre(float* nombre)
{
    while (scanf(" %f", nombre) != 1)
    {
        printf("Ce n'est pas un nombre\n");
        while (getchar() != '\n');
        printf("Veuillez entrer un nombre : ");
    }
}

void input(float* x, float* y, char* operation)
{
    do
    {
        printf("Entrez l'operation (+ - * /) : ");
        scanf(" %c", operation);
    }
    while (*operation != '+' && *operation != '-' &&
           *operation != '*' && *operation != '/');

    printf("Entrez le premier nombre  : ");
    estnombre(x);

    printf("Entrez le deuxieme nombre : ");
    estnombre(y);
}

float calcul(float x, float y, char operation)
{
    switch (operation)
    {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/':
            if (y == 0)
            {
                printf("Erreur : division par zero\n");
                exit(EXIT_FAILURE);
            }
            return x / y;
        default:
            return 0;
    }
}

void result(float x, float y, char operation)
{
    float res = calcul(x, y, operation);

    switch (operation)
    {
        case '+': printf("Somme    : "); break;
        case '-': printf("Reste    : "); break;
        case '*': printf("Produit  : "); break;
        case '/': printf("Quotient : "); break;
    }

    printf("%g\n", res);
}

void calculatrice(void)
{
    float x, y;
    char operation;

    input(&x, &y, &operation);
    result(x, y, operation);
}

int main(void)
{
    calculatrice();
    return 0;
}
