#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL,"spanish");
    int op,tam,dificultad,fondo,musica;
    printf("************************************************************************\n");
    printf("************************************************************************\n");
    printf("**************�BIENVENIDO JUGADOR AL LABERINTO EL�CTRICO!***************\n");
    printf("************  Elige una opci�n para personalizar el juego. *************\n");
    printf("************************************************************************\n");
    printf("************************************************************************\n");
    do
    {
        printf("\n");
        printf("-Presiona 1 para empezar el juego.\n");
        printf("\n");
        printf("-Presiona 2 para elegir el tama�o del laberinto.\n");
        printf("\n");
        printf("-Presiona 3 para elegir la dificultad del laberinto.\n");
        printf("\n");
        printf("-Presiona 4 para elegir un fondo para el laberinto.\n");
        printf("\n");
        printf("-Presione 5 para activar/desactivar m�sica.\n");
        printf("\n");
        printf("-Presione cualquier otra tecla para salir del men�.\n");
        printf("\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            break;
        case 2:
            printf("Presione 1 para un tama�o peque�o.\n");
            printf("Presione 2 para un tama�o mediano.\n");
            printf("Presione 3 para un tama�o grande.\n");
            printf("%d",&tam);
            break;
        case 3:
            printf("Presione 1 para dificultad f�cil.\n");
            printf("Presione 2 para dificultad media.\n");
            printf("Presione 3 para dificultad dif�cil.\n");
            printf("%d",&dificultad);
            break;
        case 4:
            printf("Presione 1 para un fondo negro.\n");
            printf("Presione 2 para un fondo blanco.\n");
            printf("Presione 3 para un fondo rojo.\n");
            printf("Presione 4 para un fondo azul.\n");
            scanf("%d",&fondo);
            break;
        case 5:
            printf("Presione 0 para desactivar m�sica.\n");
            scanf("%d",&musica);
        break;
        default:
            break;
        }
    }
    while((op<1) || (op>6));
    return 0;
}
