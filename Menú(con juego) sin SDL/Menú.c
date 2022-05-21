#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "expliC.h"
#include "juego.h"
#define ANSI_COLOR_BLUE "\x1b[34m"   //Definimos el color azul


//Definici�n de funciones
void expobj(void);
void creadores(void);


int main()
{

    setlocale(LC_ALL,"spanish");  //Definimos como idioma el espa�ol.

    //Declaraci�n de variables
    int op,dificultad,fondo, colum=17, fila=17,obj;   //Laberinto 13 x 13 predeterminado
    int objetos=0,n;
    char opcion[11],exp[]="explicacion",cont[]="controles";
    FILE *pf;
    int puntuacion,mins,seg;

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
        printf("-Presiona 3 para ver las puntuaciones.\n");
        printf("\n");
        printf("-Presiona 4 para acceder a la explicaci�n y los controles.\n");
        printf("\n");
        printf("-Presiona 5 para ver los creadores del juego.\n");
        printf("\n");
        printf("-Presiona 6 para salir del men�.\n");
        printf("\n");
        scanf("%d",&op);
        printf("\x1b[2J"); //borra toda la informaci�n de la ventana.




        switch (op)
        {

        case 1:

            juego_lab(colum,fila);
            printf("\x1b[2J");
            break;


        case 2:

            printf("Introduzca la altura del laberinto (n�mero impar y mayor que 9). Predeterminado: 17.\n");
            scanf("%i", &colum);
            if (colum<=9 || colum%2==0)
            {
                printf("Introduzca un n�mero mayor o impar:\n");
                do
                {
                    scanf("%i", &colum);
                }
                while(colum<=9 || colum%2==0);
            }
            printf("Introduzca la anchura del laberinto (n�mero impar y mayor que 9). Predeterminado: 17.\n");
            scanf("%i", &fila);
            if (fila<=9 || fila%2==0)
            {
                printf("Introduzca un n�mero mayor o impar:\n");
                do
                {
                    scanf("%i", &fila);
                }
                while(fila<=9 || fila%2==0);
            }

            printf("\x1b[2J");
            break;


        case 3:

            // Abrimos fichero para lectura

            pf = fopen("Puntuacion.txt", "r");
            if (pf == NULL)
            {
                // Si el resultado es NULL mensaje de error
                printf("Error al abrir el fichero.\n");
                return -1;
            }
            else
            {
                // Leemos los datos
                n = fscanf(pf,"%d,%d,%d",&mins,&seg,&puntuacion);
                fclose(pf);
                // Mostramos en pantalla lo le�do
                printf("***Resultados del �ltimo intento realizado***\n");
                printf("%d minuto(s) y %d segundos --------> %d puntos\n",mins,seg,puntuacion);
                sleep(5);
            }

            break;



        case 4:

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
                sleep(10);   //Espera 10 segundos
                printf("\x1b[2J");
                break;
            case 2:
                printf("\x1b[2J");
                break;
            default:
                break;
            }
            break;

        case 5:
            creadores();
            sleep(7);
            printf("\x1b[2J");
            break;


        case 6:
            exit(-1);
            break;

        default:
            break;
        }

    }
    while((op >= 1) || (op <= 6));


    return 0;
}


void expobj(void)
{
    printf("Actualmente, el juego dispone de dos tipos de objetos y una salida:\n");
    printf("+: Avatar.\n");
    printf("#: Salida.\n");
    printf("B: Bloqueador. Al pasar sobre este objeto, el bloque en cuesti�n se convertir� en un muro, no pudiendo volver hacia atr�s.\n");
    printf("T: Teletransportador. Al pasar sobre este objeto, el jugador ser� teletransportado a otro teletransporte repartido por el mapa.\n");
}

void creadores(void)
{
    printf(ANSI_COLOR_BLUE "-Juan Mu�oz de Bustillo (https://github.com/Juanmdemiguel)\n");
    printf(ANSI_COLOR_BLUE "-Diego Rodr�guez Gonz�lez (https://github.com/DiegoRodriguezGonzalez)\n");
    printf(ANSI_COLOR_BLUE "-Mario Luna L�pez (https://github.com/Mariuser24)\n");
    printf(ANSI_COLOR_BLUE "-Daniel Frenzel Zarza (https://github.com/Mariuser24)\n");
}
