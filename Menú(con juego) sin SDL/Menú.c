#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "expliC.h"
#include "juego.h"

void expobj(void);
int main()
{
	system("color f1");
    setlocale(LC_ALL,"spanish");

    int op,dificultad,fondo, colum=17, fila=17,obj;   //Laberinto 13 x 13 predeterminado
    int musica = 0; //música en 0 indica que esta apagada, mientras que uno indica que está encendida.
    int objetos=0;
    char opcion[11],exp[]="explicacion",cont[]="controles";

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
        printf("-Presiona 6 para activar/desactivar los objetos.\n");
        printf("\n");
        printf("-Presiona 7 para acceder a la explicación y los controles.\n");
        printf("\n");
        printf("-Presiona 8 para salir del menú.\n");
        printf("\n");
        scanf("%d",&op);
        printf("\x1b[2J"); //borra toda la información de la ventana.

     }while((op < 1) || (op > 8));


        switch (op)
        {
        case 1:
            juego_lab(colum,fila);
            goto inicio;
            break;

        case 2:
            printf("Introduzca la altura del laberinto. Predeterminado: 17.\n");
            scanf("%i", &colum);
            printf("Introduzca la anchura del laberinto. Predeterminado: 17.\n");
            scanf("%i", &fila);

            printf("\x1b[2J");
            goto inicio;
            break;

        case 3:
            do{
            printf("Presione 1 para dificultad fácil.\n");
            printf("Presione 2 para dificultad media.\n");
            printf("Presione 3 para dificultad difícil.\n");
            scanf("%d",&dificultad);
            } while(dificultad < 1 || dificultad > 3);
            printf("\x1b[2J");
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
             printf("\x1b[2J");
            goto inicio;
            break;
        case 5:
           if (musica == 0) // si la musica está apagada, la enciende.
            musica = 1;
           else if (musica == 1) // si está encendida, la apaga.
            musica = 0;
             printf("\x1b[2J");
            goto inicio;
        break;

        case 6:
            if (objetos==0)
                objetos=1;
            else if (objetos==1)
                objetos=0;
            printf("\x1b[2J");
            goto inicio;
            break;

        case 7:
            printf("Escriba 'controles' para ver los controles del juego o 'explicacion' para la explicación del juego:\n");
            scanf("%20s",opcion);
            if (strcmp(opcion,cont)==0)
                controles();
            else if (strcmp(opcion,exp)==0)
                explicacion();
            scanf("%d",&obj);
            switch (obj)
            {
            case 1:
                expobj();
                sleep(20);
                printf("\x1b[2J");
                goto inicio;
                break;
            case 2:
                printf("\x1b[2J");
                goto inicio;
                break;
            default:
                break;
            }
            break;

         case 8:
             exit(-1);
             break;

        default:
            break;
        }
    return 0;
}
void expobj(void)
{
    printf("Actualmente, el juego dispone de dos tipos de objetos y una salida:\n");
    printf("+: Avatar.\n");
    printf("#: Salida.\n");
    printf("B: Bloqueador. Al pasar sobre este objeto, el bloque en cuestión se convertirá en un muro, no pudiendo volver hacia atrás.\n");
    printf("T: Teletransportador. Al pasar sobre este objeto, el jugador será teletransportado a otro teletransporte repartido por el mapa.\n");
}
