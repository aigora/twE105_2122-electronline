
#include <SDL.h>
#include <stdio.h>
#include<stdlib.h>
#define N 100

int maze[N][N];

int i,j,x,y, rad1, rad2;

void recursion(int r, int c, int anch, int alt);

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 670;

int main( int argc, char* args[] )
{
    int alt = 85;
    int anch = 85;

   srand(time(NULL));
   //Llenamos una matriz de 1. Esta matriz se utilizará posteriormente para hacer el laberito
 for (i = 0; i < alt; i++){
    for(j = 0; j < anch; j++)
        maze[i][j] = 1;
 }
 //Genera una posición aleatoria dentro de los límites para empezar el laberinto
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

//Se define la ventana
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

//Declaramos una variable estructura de rectangulo que controlará la posición de los sprites del laberinto
SDL_Rect pos;

//Iniciamos el SDL
if( SDL_Init( SDL_INIT_VIDEO ) < 0)
{
printf( "SDL no pudo iniciarse. SDL_Error: %s\n", SDL_GetError() );
}
else
{
//Si no hay ningún error, creamos la ventana
window = SDL_CreateWindow( "Laberinto", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
if( window == NULL )
{
printf( "No se pudo crear la ventana emergente SDL_Error: %s\n", SDL_GetError() );
}
else
{
screenSurface = SDL_GetWindowSurface( window );
SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) ); //Ponemos el fondo blanco
SDL_Surface *camino = SDL_LoadBMP("GenPath.bmp"); //Cargamos tanto el sprite del camino como el del muro.
SDL_Surface *muro = SDL_LoadBMP("GenWall.bmp");


//Recorremos la matriz. Cada vez que encuentra un 1 pomdrá un sprite muro, y en un 0 un sprite camino
for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
   pos.x = 32*i; //Cada vez que tengamos que poner una imagen, tenemos que ponerlo en la posición adecuada
   pos.y = 32*j; //Como cada imagen es 32x32, al multiplicar la posición en la matriz por su tamaño te la posiciona en la ventana
        SDL_BlitSurface(camino,0,screenSurface,&pos);
    }
    if(maze[i][j]==1)
    {
         pos.x = 32*i;
         pos.y = 32*j;
        SDL_BlitSurface(muro,0,screenSurface,&pos);
    }
}
}
//Actualizamos la pantalla
SDL_UpdateWindowSurface( window );

//Esperamos 4 segundos
SDL_Delay( 4000 );

}
}

//Se destruye la ventana y se sale de SDL
SDL_DestroyWindow( window );
SDL_Quit();

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
