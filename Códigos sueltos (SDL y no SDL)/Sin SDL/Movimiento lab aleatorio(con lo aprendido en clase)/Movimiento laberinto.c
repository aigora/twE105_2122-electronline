#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

int maze[N][N];
char lab[N][N];
char m=' ';
char n=254;
int i,j,x,y;
void recursion(int r, int c, int anch, int alt);
void laberinto(int base, int altura, char lab[N][N]);  //Muestra el laberinto


int main()
{
     srand(time(NULL));

       int i, j, anch, alt, rad1, rad2;
    printf("introduce la altura\n");
    scanf("%i", &alt);
    printf("introduce la anchura\n");
    scanf("%i", &anch);


    for (i = 0; i < alt; i++){
        for (j = 0; j < anch; j++)
            maze[i][j] = 1;
    }

     do{
     rad1 = rand() % alt;
} while (rad1 % 2 == 0);
     do{
     rad2 = rand() % anch;
} while (rad2 % 2 == 0);

//Posición inicial
      maze[rad1][rad2] = 50;
//Hacemos el laberinto
      recursion(rad1, rad2, anch, alt);

for(i = 0; i < alt; i++) {
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
}
}

{
    int i,j;                       //Se imprime el laberinto primero por filas y después por columnas.
    for(i = 0; i < alt; i++)
{
    for(j = 0; j < anch; j++)
{
    printf(" %c", lab[i][j]);
}
printf("\n");
}
}

return 0;
}

void recursion(int r, int c, int anch, int alt)

{
    int i, num, k, p;
 int direc[4] = {0,0,0,0};

 for (i = 0; i < 4; i++){ //Elige una dirección aleatoria
// el bucle terminará cuando haya buscado entre las 4 direcciones y aún así no pueda continuar el laberinto

for(k=0;k<4;k++)
{
    int num = 1 + rand()%4; //genera un numero aleatorio para el vector dirección
      for(p=0; p < k; p++)  // Verifica si no se ha generado antes
          if(num==direc[p])
          {
             num = 1 + rand()%4;
             p=-1;
          }
   direc[k] =num;
}

    switch(direc[i]){ // crea caminos en el laberinto
   case 1: //Arriba
       if (r - 2 <= 0) // si dos celdas más arriba está ocupado o no
        continue;
       else if (maze[r - 2][c] != 0){ //ocupa las dos de arriba
        maze[r - 2][c] = 0;
        maze[r - 1][c] = 0;
        recursion(r - 2, c, anch, alt);
       }
       break;

    case 2: //Derecha
       if (c + 2 >= anch - 1)  // si dos celdas a la derecha está ocupado o no
        continue;
       else if (maze[r][c + 2] != 0){ //ocupa las dos de la derecha
        maze[r][c + 2] = 0;
        maze[r][c + 1] = 0;
        recursion(r, c + 2, anch, alt);
       }
       break;

    case 3: //Abajo
       if (r + 2 >= alt - 1)  // si dos celdas más abajo está ocupado o no
        continue;
       else if (maze[r + 2][c] != 0){ //ocupa las dos de abajo
        maze[r + 2][c] = 0;
        maze[r + 1][c] = 0;
        recursion(r + 2, c, anch, alt);
       }
       break;

    case 4: //Izquierda
       if (c - 2 <= 0)  // si dos celdas a la izquierda está ocupado o no
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



