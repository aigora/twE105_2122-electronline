#include <stdio.h>
#include <locale.h>
#include "expliC.h"
#include <string.h>
void expobj(void);
int main()
{
	system("color f1");
    setlocale(LC_ALL,"spanish");

    int op,dificultad,fondo, colum, fila,obj;
    int musica = 0; //m�sica en 0 indica que esta apagada, mientras que uno indica que est� encendida.
    int objetos=0;
    char opcion[11],exp[]="explicacion",cont[]="controles";

    printf("************************************************************************\n");
    printf("************************************************************************\n");
    printf("**************�BIENVENIDO JUGADOR AL LABERINTO EL�CTRICO!***************\n");
    printf("************  Elige una opci�n para personalizar el juego. *************\n");
    printf("************************************************************************\n");
    printf("************************************************************************\n");

    inicio:
do{
    printf("\n");
        printf("-Presiona 1 para empezar el juego.\n");
        printf("\n");
        printf("-Presiona 2 para elegir el tama�o del laberinto.\n");
        printf("\n");
        printf("-Presiona 3 para elegir la dificultad del laberinto.\n");
        printf("\n");
        printf("-Presiona 4 para elegir un fondo para el laberinto y el men�.\n");
        printf("\n");
        printf("-Presiona 5 para activar/desactivar m�sica.\n");
        printf("\n");
        printf("-Presiona 6 para activar/desactivar los objetos.\n");
        printf("\n");
        printf("-Presiona 7 para acceder a la explicaci�n y los controles.\n");
        printf("\n");
        printf("-Presiona 8 para salir del men�.\n");
        printf("\n");
        scanf("%d",&op);
        system("cls"); //borra toda la informaci�n de la ventana.

     }while((op < 1) || (op > 8));


        switch (op)
        {
        case 1:
            //empieza el juego.
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
            printf("Presione 1 para dificultad f�cil.\n");
            printf("Presione 2 para dificultad media.\n");
            printf("Presione 3 para dificultad dif�cil.\n");
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
           if (musica == 0) // si la musica est� apagada, la enciende.
            musica = 1;
           else if (musica == 1) // si est� encendida, la apaga.
            musica = 0;
             system("cls");
            goto inicio;
        break;

        case 6:
            if (objetos==0)
                objetos=1;
            else if (objetos==1)
                objetos=0;
            system("cls");
            goto inicio;
            break;

        case 7:
            printf("Escriba 'controles' para ver los controles del juego o 'explicacion' para la explicaci�n del juego:\n");
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
                system("cls");
                goto inicio;
                break;
            case 2:
                system("cls");
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
    printf("Actualmente, el juego tiene 3 objetos disponibles:\n");
    printf("\n");
    printf("Teletransportador. Al coger este objeto, el personaje es transportado a cualquier parte del laberinto.\n");
    printf("\n");
    printf("Bloqueos. Al coger este objeto, cuando se pasan ciertas zonas del laberinto, el jugador no podr� volver hacia atr�s.\n");
    printf("\n");
    printf("Acelerador de tiempo. Al coger este objeto, el tiempo puede ir m�s r�pido o m�s lento.\n");
}
