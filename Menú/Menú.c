#include <stdio.h>
#include <locale.h>

int main()
{
	system("color f1");
    setlocale(LC_ALL,"spanish");

    int op,dificultad,fondo, colum, fila;
    int musica = 0; //música en 0 indica que esta apagada, mientras que uno que está encendida.

    printf("************************************************************************\n");
    printf("************************************************************************\n");
    printf("**************¡BIENVENIDO JUGADOR AL LABERINTO ELÉCTRICO!***************\n");
    printf("************  Elige una opción para personalizar el juego. *************\n");
    printf("************************************************************************\n");
    printf("************************************************************************\n");

    inicio:
do{
    printf("\n");
        printf("-Presiona 1 para empezar el juego.\n");
        printf("\n");
        printf("-Presiona 2 para elegir el tamaño del laberinto.\n");
        printf("\n");
        printf("-Presiona 3 para elegir la dificultad del laberinto.\n");
        printf("\n");
        printf("-Presiona 4 para elegir un fondo para el laberinto y el menú.\n");
        printf("\n");
        printf("-Presiona 5 para activar/desactivar música.\n");
        printf("\n");
        printf("-Presiona 6 para salir del menú.\n");
        printf("\n");
        scanf("%d",&op);
        system("cls"); //borra toda la información de la ventana

     }while((op < 1) || (op > 6));


        switch (op)
        {
        case 1:
            //empieza el juego
            break;

        case 2:
            printf("Introduzca la altura del laberinto.\n");
            scanf("%i", &colum);
            printf("Introduzca la anchura del laberinto.\n");
           scanf("%i", &fila);

            system("cls");
            goto inicio;
            break;

        case 3:
            do{
            printf("Presione 1 para dificultad fácil.\n");
            printf("Presione 2 para dificultad media.\n");
            printf("Presione 3 para dificultad difícil.\n");
            scanf("%d",&dificultad);
            } while(dificultad < 1 || dificultad > 3);
            system("cls");
            goto inicio;
            break;

        case 4:
            do{
            printf("Presione 1 para un fondo negro.\n");
            printf("Presione 2 para un fondo blanco.\n");
            printf("Presione 3 para un fondo rojo.\n");
            printf("Presione 4 para un fondo azul.\n");
            scanf("%d",&fondo);
            } while(fondo < 1 || fondo > 4);

            switch(fondo){
        case 1:
            system("color 0f");
            break;

        case 2:
            system("color f0");
            break;

        case 3:
            system("color 40");
            break;

        case 4:
            system("color b0");
            break;
        default:
            break;
            }
             system("cls");
            goto inicio;

            break;
        case 5:
           if (musica == 0) // si la musica está apagada la enciende
            musica = 1;
           else if (musica == 1) // si esta encendida la apaga
            musica = 0;
             system("cls");
            goto inicio;

        break;
         case 6:
             exit(-1);
             break;

        default:
            break;
        }
    return 0;
}
