
#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#define SPEED (300) //Definimos la velocidad(píxeles por segundo)
#include"assets.h"

void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend);

int main( int argc, char* args[] )
{
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 640;
int coordx=4,coordy=3,f1=0,f2=0,a=3,b=4;
printf("%d,%d",coordx,coordy);
//Creamos la ventana, definimos el fondo y declaramos el renderer
SDL_Window* ventana = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
SDL_Surface* screenSurface = NULL;
Uint32 render_flags = SDL_RENDERER_ACCELERATED;


SDL_Renderer* rend = SDL_CreateRenderer(ventana, -1, render_flags);


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
_Bool init = 1;

float x_vel=0;
float y_vel=0;



//Inicio de SDL
if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){

    //El SDL comienza verificando que la ventana, el renderer y la textura se han inicializado correctamente
        printf( "SDL no pudo iniciarse. SDL_Error: %s\n", SDL_GetError() );}
    else {
        if( ventana == NULL ) {
            printf( "No se pudo crear la ventana emergente SDL_Error: %s\n", SDL_GetError() ); }

else{
    if (!rend){
        printf("Error al crear el render: %s\n",SDL_GetError());
        SDL_DestroyWindow(ventana);
        SDL_Quit;
        return 1;}
if (!texd || !texi || !texab || !texid || !texar)
{
    printf("Error al crear las textura: %s\n",SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 1;
}


//Empieza el programa verificando la ventana
screenSurface = SDL_GetWindowSurface( ventana );

//Declaramos una para mantener la posición y el tamaño del sprite
SDL_Rect dest = {0, 0, 32*80, 32*60};

SDL_Rect personaje = {9*32+16, 7*32+64, 70, 70};

//Se imprime el laberinto en un Surface
InitMaze(ventana, screenSurface, rend);
//Se crea una textura de ese surface
SDL_Texture* texmaze = SDL_CreateTextureFromSurface(rend, screenSurface);

//Definimos el sprite en el centro de la pantalla
float x_pos= 1;
float y_pos = 1;


while (!quit)
{
    SDL_Event event;


    while (SDL_PollEvent(&event))
    {

        if (event.type == SDL_QUIT)
            quit=1;
        if (event.type == SDL_KEYDOWN) //Cuando estemos pulsando la tecla
        {
            if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
            {
                if(maze[coordx-1][coordy]==0)
                {
                x_pos=x_pos+76;
                coordx--;
                printf("%d,%d\n",coordx,coordy);
                }
                if(maze[coordx-1][coordy]==1)
                {
                x_pos=x_pos;
                }
               }
            if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)
            {
                if(maze[coordx+1][coordy]==0)
                {
                x_pos=x_pos-76;
                coordx++;
                printf("%d,%d\n",coordx,coordy);
                }
                if(maze[coordx-1][coordy]==1)
                {
                x_pos=x_pos;
                }
            }
            if(event.key.keysym.scancode==SDL_SCANCODE_UP)
            {
            if(maze[coordx][coordy-1]==0)
                {
                y_pos=y_pos+96;
                coordy--;
                printf("%d,%d\n",coordx,coordy);
                }
                if(maze[coordx][coordy-1]==1)
                {
                y_pos=y_pos;
                }
            }
            if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
            {
            if(maze[coordx][coordy+1]==0)
                {
                y_pos=y_pos-96;
                coordy++;
                printf("%d,%d\n",coordx,coordy);
                }
                if(maze[coordx][coordy+1]==1)
                {
                y_pos=y_pos;
                }
            }
            }
        }

    x_vel = y_vel = 0;

//Se actualiza la posición y se define cómo de rápido queremos que vaya la imagen
    dest.y= (int) y_pos;
    dest.x = (int) x_pos;


    Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
    Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
    SDL_Rect srcrect = {sprite*32, 0, 32, 32};


if(init){
SDL_RenderClear(rend);
SDL_RenderCopy(rend,texmaze, NULL, &dest);
SDL_RenderPresent(rend);
}


   // SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texid, &srcrect, &personaje);
    SDL_RenderPresent(rend);

if (dcha && !izq){
    //SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texd, &srcrect, &personaje);
    SDL_RenderPresent(rend);
}
if (izq && !dcha){
   // SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texi, &srcrect, &personaje);
    SDL_RenderPresent(rend);
}
if (abajo && !arriba){
  //  SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texar, &srcrect, &personaje);
    SDL_RenderPresent(rend);

}
 if (arriba && !abajo){
   // SDL_RenderClear(rend);
    SDL_RenderCopy(rend, texab, &srcrect, &personaje);
    SDL_RenderPresent(rend);
 }

    SDL_Delay(1000/60);
}

//Se destruye todo y se sale de SDL
SDL_DestroyTexture(texd);
SDL_DestroyRenderer(rend);
SDL_DestroyWindow(ventana);
SDL_Quit();
}
}
return 0;
}


void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend)
{
    int alt = 20;
    int anch = 20;
int i,j,x,y, xo, yo;

   srand(time(NULL));

   //Llenamos una matriz de 1. Esta matriz se utilizará posteriormente para hacer el laberito
 for (i = 0; i < alt; i++){
    for(j = 0; j < anch; j++)
        maze[i][j] = 1;}
xo = 9;
yo = 7;
//Posición inicial
maze[xo][yo] = 0;
//Hacemos el laberinto
      recursion(xo, yo, anch, alt);

//SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) ); //Ponemos el fondo blanco
SDL_Surface *camino = SDL_LoadBMP("GenPath.bmp"); //Cargamos tanto el sprite del camino como el del muro.
SDL_Surface *muro = SDL_LoadBMP("GenWall.bmp");
//SDL_Texture *texca = SDL_CreateTextureFromSurface(rend, camino);
//SDL_Texture *texmu = SDL_CreateTextureFromSurface(rend, muro);

SDL_Rect pos;
  //Recorremos la matriz. Cada vez que encuentra un 1 pomdrá un sprite muro, y en un 0 un sprite camino
for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
   pos.x = 32*i; //Cada vez que tengamos que poner una imagen, tenemos que ponerlo en la posición adecuada
   pos.y = 32*j; //Como cada imagen es 32x32, al multiplicar la posición en la matriz por su tamaño te la posiciona en la ventana
        SDL_BlitSurface(camino,0,screenSurface,&pos);
         //SDL_RenderCopy(rend, texca, NULL, &pos);
         //SDL_RenderPresent(rend);
    }
    if(maze[i][j]==1)
    {
         pos.x = 32*i;
         pos.y = 32*j;
       SDL_BlitSurface(muro,0,screenSurface,&pos);
       // SDL_RenderCopy(rend, texmu, NULL, &pos);
       // SDL_RenderPresent(rend);
    }
}
}
}
