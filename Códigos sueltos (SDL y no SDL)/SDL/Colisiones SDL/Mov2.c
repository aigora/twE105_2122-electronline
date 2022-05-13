
#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#define SPEED (300) //Definimos la velocidad(píxeles por segundo)
#include "assets.h"

void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N]);

int main( int argc, char* args[] )
{

//Declaramos las variables a utilizar
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 640;
int maze[N][N];
int coordx=4,coordy=3;
float x_pos;
float y_pos;


    SDL_Rect dest = {0, 0, 32*80, 32*60}; //Laberinto
    SDL_Rect personaje = {9*32+16, 7*32+76, 70, 70}; //Alberto el explorador

    SDL_Window* ventana = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    SDL_Surface* screenSurface = NULL;
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(ventana, -1, render_flags);
    SDL_Surface *Pers;

Pers = SDL_LoadBMP("MovRight.bmp");
SDL_Texture*texd = SDL_CreateTextureFromSurface(rend, Pers);
SDL_FreeSurface(Pers);

Pers = SDL_LoadBMP("MovLeft.bmp");
SDL_Texture*texi = SDL_CreateTextureFromSurface(rend, Pers);
SDL_FreeSurface(Pers);

Pers = SDL_LoadBMP("MovUp.bmp");
SDL_Texture*texar = SDL_CreateTextureFromSurface(rend, Pers);
SDL_FreeSurface(Pers);

Pers = SDL_LoadBMP("MovDown.bmp");
SDL_Texture*texab = SDL_CreateTextureFromSurface(rend, Pers);
SDL_FreeSurface(Pers);

Pers = SDL_LoadBMP("Idle.bmp");
SDL_Texture*texid = SDL_CreateTextureFromSurface(rend, Pers);
SDL_FreeSurface(Pers);


//Inicializamos los booleanos
    _Bool quit = 0;

    _Bool izq=0;
    _Bool dcha=0;
    _Bool arriba=0;
    _Bool abajo=0;

    float x_vel=0;
    float y_vel=0;


printf("%d,%d\n",coordx,coordy);

//Inicio de SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {

        //El SDL comienza verificando que la ventana, el renderer y la textura se han inicializado correctamente
        printf( "SDL no pudo iniciarse. SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        if( ventana == NULL )
        {
            printf( "No se pudo crear la ventana emergente SDL_Error: %s\n", SDL_GetError() );
        }

        else
        {
            if (!rend)
            {
                printf("Error al crear el render: %s\n",SDL_GetError());
                SDL_DestroyWindow(ventana);
                SDL_Quit;
                return 1;
            }
            if (!texd || !texi || !texab || !texid || !texar)
            {
                printf("Error al crear las textura: %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(ventana);
                SDL_Quit();
                return 1;
            }
//Una vez comprobado que se ha iniciado correctamente, empieza el juego
            screenSurface = SDL_GetWindowSurface( ventana );

//Carga el laberinto en una textura
            InitMaze(ventana, screenSurface, rend, maze);
            SDL_Texture* texmaze = SDL_CreateTextureFromSurface(rend, screenSurface);

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
                            dcha = 0, izq = 1, arriba = 0, abajo = 0;
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
                        dcha = 1, izq = 0, arriba = 0, abajo = 0;
                    }
                    if(maze[coordx+1][coordy]==1)
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
                        dcha = 0, izq = 0, arriba = 1, abajo = 0;
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
                        dcha = 0, izq = 0, arriba = 0, abajo = 1;
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

             dest.y = y_pos;
             dest.x = x_pos;

                //Controla el frame de la animación
                Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
                Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
                SDL_Rect srcrect = {sprite*32, 0, 32, 32};

                if(!quit) //Imprime el laberinto en pantalla
                {
                    SDL_RenderClear(rend);
                    SDL_RenderCopy(rend,texmaze, NULL, &dest);
                    SDL_RenderPresent(rend);
                }

                //Controla las animaciones según el movimiento
                SDL_RenderCopy(rend, texid, &srcrect, &personaje);
                SDL_RenderPresent(rend);

                if (dcha && !izq)
                {
                    SDL_RenderCopy(rend, texd, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (izq && !dcha)
                {
                    SDL_RenderCopy(rend, texi, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (abajo && !arriba)
                {
                    SDL_RenderCopy(rend, texar, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (arriba && !abajo)
                {
                    SDL_RenderCopy(rend, texab, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }

                SDL_Delay(1000/60);
            }

//Sale de SDL
            SDL_DestroyTexture(texd);
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(ventana);
            SDL_Quit();
        }
    }
    return 0;
}



void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N])
{
    int alt = 20;
    int anch = 20;
    int i,j,x,y, xo, yo, k = 0;

    srand(time(NULL));

    //Llenamos una matriz de 1. Esta matriz se utilizará posteriormente para hacer el laberinto
    for (i = 0; i < alt; i++)
    {
        for(j = 0; j < anch; j++)
            maze[i][j] = 1;
    }
    xo = 4;
    yo = 3;
//Posición inicial
    maze[xo][yo] = 0;
//Hacemos el laberinto
    recursion(xo, yo, anch, alt, maze);

//SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) ); //Ponemos el fondo blanco
    SDL_Surface *camino = SDL_LoadBMP("GenPath.bmp"); //Cargamos tanto el sprite del camino como el del muro.
    SDL_Surface *muro = SDL_LoadBMP("GenWall.bmp");
//SDL_Texture *texca = SDL_CreateTextureFromSurface(rend, camino);
//SDL_Texture *texmu = SDL_CreateTextureFromSurface(rend, muro);

    SDL_Rect pos;
    //Recorremos la matriz. Cada vez que encuentra un 1 pomdrá un sprite muro, y en un 0 un sprite camino
    for(i = 0; i < alt; i++)
    {
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


