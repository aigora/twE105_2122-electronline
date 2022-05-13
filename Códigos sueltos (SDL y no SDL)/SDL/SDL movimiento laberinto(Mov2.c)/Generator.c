
#include "assets.h"


void recursion(int r, int c, int anch, int alt, int maze[N][N])
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
        recursion(r - 2, c, anch, alt, maze);
       }
       break;

    case 2: //Derecha
       if (c + 2 >= anch - 1)  // si dos celdas a la derecha está ocupado o no
        continue;
       else if (maze[r][c + 2] != 0){ //ocupa las dos de la derecha
        maze[r][c + 2] = 0;
        maze[r][c + 1] = 0;
        recursion(r, c + 2, anch, alt, maze);
       }
       break;

    case 3: //Abajo
       if (r + 2 >= alt - 1)  // si dos celdas más abajo está ocupado o no
        continue;
       else if (maze[r + 2][c] != 0){ //ocupa las dos de abajo
        maze[r + 2][c] = 0;
        maze[r + 1][c] = 0;
        recursion(r + 2, c, anch, alt, maze);
       }
       break;

    case 4: //Izquierda
       if (c - 2 <= 0)  // si dos celdas a la izquierda está ocupado o no
        continue;
       else if (maze[r][c - 2] != 0){ //ocupa las dos de la izquierda
        maze[r][c - 2] = 0;
        maze[r][c - 1] = 0;
        recursion(r, c - 2, anch, alt, maze);
       }
       break;

    }
 }

}
