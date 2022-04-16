#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 500

int maze[N][N];
char lab[N][N];
char m=' '; //caminos
char n=254; //muros

void recursion(int r, int c, int anch, int alt);
//Primero crea un patr�n de direcciones aleatorio, luego con esa direcci�n comprueba si se puede.
//Si no puede, pasa a otra direcci�n hasta que una se pueda, y marca esas casillas como camino.
//Una vez creado el camino vuelve a repetirse todo el proceso.

int main()
{

     srand(time(NULL));

       int i, j, anch, alt, rad1, rad2;
    printf("introduce la altura\n");
    scanf("%i", &alt);
    printf("introduce la anchura\n");
    scanf("%i", &anch);

//En la versi�n final el tama�o del laberinto se elegir� a trav�s del men� principal 

    for (i = 0; i < alt; i++){ //rellena la matriz laberinto de muros 
        for (j = 0; j < anch; j++)
            maze[i][j] = 1;
    }

     do{ //selecciona un punto aleatorio dentro de los l�mites del laberinto 
     rad1 = rand() % alt; //Este punto servir� tanto para empezar con nuestro personaje como para que el codigo empiece a generar el laberinto
} while (rad1 % 2 == 0);
     do{
     rad2 = rand() % anch;
} while (rad2 % 2 == 0);

//Posici�n inicial
      maze[rad1][rad2] = 0;
//Modifica la matriz laberinto llena de muros a una con caminos aleatorios
      recursion(rad1, rad2, anch, alt);

for(i = 0; i < alt; i++) { // Una vez generado cambiamos los 0 y 1 por espacios y muros
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
printf(" %c", lab[i][j]); // Se representa el laberinto
}
printf("\n");
}



return 0;
}

void recursion(int r, int c, int anch, int alt)

{
    int i, num, k, p;
 int direc[4] = {0,0,0,0};

 for (i = 0; i < 4; i++){ //Elige una direcci�n aleatoria
// el bucle terminar� cuando haya buscado entre las 4 direcciones y a�n as� no pueda continuar el laberinto

for(k=0;k<4;k++)
{
    int num = 1 + rand()%4; //genera un numero aleatorio para el vector direcci�n

   if(k>0)
   {
     
      for(p=0; p < k; p++)  // Verifica si no se ha generado antes
          if(num==direc[p])
          {
             num = 1 + rand()%5;
             p=-1;
          }
    }

   direc[k] =num;
}

    switch(direc[i]){ // crea caminos en el laberinto
   case 1: //Arriba
       if (r - 2 <= 0) // si dos celdas m�s arriba est� ocupado o no
        continue;
       else if (maze[r - 2][c] != 0){ //ocupa las dos de arriba
        maze[r - 2][c] = 0;
        maze[r - 1][c] = 0;
        recursion(r - 2, c, anch, alt);
       }
       break;

    case 2: //Derecha
       if (c + 2 >= anch - 1)  // si dos celdas a la derecha est� ocupado o no
        continue;
       else if (maze[r][c + 2] != 0){ //ocupa las dos de la derecha
        maze[r][c + 2] = 0;
        maze[r][c + 1] = 0;
        recursion(r, c + 2, anch, alt);
       }
       break;

    case 3: //Abajo
       if (r + 2 >= alt - 1)  // si dos celdas m�s abajo est� ocupado o no
        continue;
       else if (maze[r + 2][c] != 0){ //ocupa las dos de abajo
        maze[r + 2][c] = 0;
        maze[r + 1][c] = 0;
        recursion(r + 2, c, anch, alt);
       }
       break;

    case 4: //Izquierda
       if (c - 2 <= 0)  // si dos celdas a la izquierda est� ocupado o no
        continue;
       else if (maze[r][c - 2] != 0){ //ocupa las dos de la izquierda
        maze[r][c - 2] = 0;
        maze[r][c - 1] = 0;
        recursion(r, c - 2, anch, alt);
       }
       break;

    }
 }

}

