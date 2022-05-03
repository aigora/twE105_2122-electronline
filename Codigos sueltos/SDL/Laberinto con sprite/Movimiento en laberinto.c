#include <SDL.h>
#include <stdio.h>
#include<stdlib.h>
#define N 100
#define SPEED (300) //Definimos la velocidad(píxeles por segundo)
#include <SDL_timer.h>

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

Uint32 render_flags = SDL_RENDERER_ACCELERATED;
SDL_Renderer* rend = SDL_CreateRenderer(window, -1, render_flags);

//Cargamos todas las imaganes correspondientes a las animaciones
SDL_Surface *Derecha = SDL_LoadBMP("MovRight.bmp");
SDL_Surface *izquierda = SDL_LoadBMP("MovLeft.bmp");
SDL_Surface *arrib = SDL_LoadBMP("MovUp.bmp");
SDL_Surface *abaj = SDL_LoadBMP("MovDown.bmp");
SDL_Surface *idle = SDL_LoadBMP("Idle.bmp");

//Creamos una textura propia de cada animación (Una textura almacena la información de cada pixel)
SDL_Texture*texd = SDL_CreateTextureFromSurface(rend, Derecha);
SDL_Texture*texi = SDL_CreateTextureFromSurface(rend, izquierda);
SDL_Texture*texar = SDL_CreateTextureFromSurface(rend, arrib);
SDL_Texture*texab = SDL_CreateTextureFromSurface(rend, abaj);
SDL_Texture*texid = SDL_CreateTextureFromSurface(rend, idle);

SDL_FreeSurface(Derecha);
SDL_FreeSurface(izquierda);
SDL_FreeSurface(arrib);
SDL_FreeSurface(abaj);
SDL_FreeSurface(idle);

//Se define la salida del programa
_Bool quit = 0;

//Se definen las teclas
SDL_Rect offset;
offset.x= 320;
offset.y=240;

//El movimiento en t=0 no se produce, al igual que la velocidad
_Bool izq=0;
_Bool dcha=0;
_Bool arriba=0;
_Bool abajo=0;
float x_vel=0;
float y_vel=0;



    //Verifica que el renderer y la textura se han inicializado correctamente
    if (!rend){
        printf("Error al crear el render: %s\n",SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit;
        return 1;}
if (!texd || !texi || !texab || !texid || !texar)
{
    printf("Error al crear las textura: %s\n",SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}


//Empieza el programa verificando la ventana
screenSurface = SDL_GetWindowSurface( window );

//Declaramos una para mantener la posición y el tamaño del sprite
SDL_Rect dest = {0, 0, 32, 32};

//Ponemos el fondo azul
SDL_SetRenderDrawColor(rend, 168, 230, 255, 255);
SDL_RenderClear(rend);

//Definimos el sprite en el centro de la pantalla
float x_pos= (SCREEN_WIDTH - dest.w) / 2;
float y_pos = (SCREEN_HEIGHT - dest.h) / 2;

//Una vez inicializada la ventana y sus propiedades, comienza el juego
while (!quit)
{
    SDL_Event event;

//El bucle empieza dando valor a unas variables que controlaremos con el teclado
//Al pulsar las flechas, estaremos dando valor 1 a las variables que dirigen el movimiento y la animación
//Cuando dejemos de pulsarlas, este valor volverá a ser 0

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            quit=1;
        if (event.type == SDL_KEYDOWN) //Cuando estemos pulsando la tecla
        {
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_LEFT:
                izq=1;
                break;
            case SDL_SCANCODE_RIGHT:
                dcha=1;
                break;
            case SDL_SCANCODE_UP:
                arriba=1;
                break;
            case SDL_SCANCODE_DOWN:
                abajo=1;
                break;
            }
        }

        if (event.type == SDL_KEYUP)  //Cuando dejemos de pulsar la tecla
        {
            switch (event.key.keysym.scancode)
            {
            case SDL_SCANCODE_LEFT:
                izq=0;
                break;
            case SDL_SCANCODE_RIGHT:
                dcha=0;
                break;
            case SDL_SCANCODE_UP:
                arriba=0;
                break;
            case SDL_SCANCODE_DOWN:
                abajo=0;
                break;
            }
        }
    }

    //Se determina la velocidad
    //Primero ponemos todo parado en el instante inicial
    x_vel = y_vel = 0;

    //Después veremos el valor de las variables que se modifican con el teclado
    //Cabe destacar que al tratarse de una variable de tipo _Bool, el true se define como 1 y false como 0
    if (arriba && !abajo) y_vel = -SPEED;
    if (abajo && !arriba) y_vel = SPEED;
    if (izq && !dcha) x_vel = -SPEED;
    if (dcha && !izq) x_vel= SPEED;

//Se actualiza la posición y se define cómo de rápido queremos que vaya la imagen
    x_pos+=x_vel/150;
    y_pos+=y_vel/150;

//Poner las posiciones en la estructura
    dest.y= (int) y_pos;
    dest.x = (int) x_pos;

//Se trabaja en la animación
    Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
    Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
    SDL_Rect srcrect = {sprite*32, 0, 32, 32};


//Mostramos la imagen inicial en una zona ya predefinida
//Esta animación será la que saldrá cuando todas las variables de movimiento estén en 0 (false)
//Cada una de estas declaraciones (La principal y las referidas a direcciones), utiliza la textura propia de su sprite

    SDL_RenderClear(rend); //Borra el sprite, para que no se superpongan
    SDL_RenderCopy(rend, texid, &srcrect, &dest); //Copia el nuevo sprite
    SDL_RenderPresent(rend);

if (dcha && !izq){
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texd, &srcrect, &dest);
    SDL_RenderPresent(rend);
}
if (izq && !dcha){
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texi, &srcrect, &dest);
    SDL_RenderPresent(rend);
}
if (abajo && !arriba){
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texar, &srcrect, &dest);
    SDL_RenderPresent(rend);

}
 if (arriba && !abajo){
    SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texab, &srcrect, &dest);
    SDL_RenderPresent(rend);
 }


    SDL_Delay(1000/60);
    //Esperamos 10000 segundos
SDL_Delay( 10000000 );
//Se destruye todo y se sale de SDL

SDL_DestroyTexture(texd);
SDL_DestroyRenderer(rend);
SDL_DestroyWindow( window );
SDL_Quit();
return 0;
}


}
}


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
