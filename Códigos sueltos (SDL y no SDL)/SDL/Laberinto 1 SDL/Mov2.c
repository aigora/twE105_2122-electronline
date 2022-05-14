
#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#define SPEED (300) //Definimos la velocidad(píxeles por segundo)
#include"assets.h"

void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy,int *sal_i,int *sal_j,int *Tk1_i,int *Tk1_j,int *Tk2_i,int *Tk2_j,int *Tk3_i,int *Tk3_j,int *Tk4_i,int *Tk4_j,int *TP1_i,int *TP1_j,int *TP2_i,int *TP2_j);

int main( int argc, char* args[] )
{
    //Declaración de variables
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 640;
    int maze[N][N];
    float x_pos= 1;
    float y_pos = 1;

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

    SDL_Rect dest = {0, 0, 32*80, 32*60}; //Laberinto
    SDL_Rect personaje = {32+46, 32+80, 70, 70}; //Explorador

    _Bool quit = 0;
    _Bool izq=0;
    _Bool dcha=0;
    _Bool arriba=0;
    _Bool abajo=0;


    int inversion=0;
    int *sal_i,*sal_j,*Tk1_i,*Tk1_j,*Tk2_i,*Tk2_j,*Tk3_i,*Tk3_j,*Tk4_i,*Tk4_j,*TP1_i,*TP1_j,*TP2_i,*TP2_j;
    int t1_i,t1_j,t2_i,t2_j,t3_i,t3_j,t4_i,t4_j,tp1_i,tp1_j,tp2_i,tp2_j;
    int coordx=1,coordy=1;
    int teletransportar=1;


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


    screenSurface = SDL_GetWindowSurface( ventana );


    InitMaze(ventana, screenSurface, rend, maze,coordx,coordy,&sal_i,&sal_j,&Tk1_i,&Tk1_j,&Tk2_i,&Tk2_j,&Tk3_i,&Tk3_j,&Tk4_i,&Tk4_j,&TP1_i,&TP1_j,&TP2_i,&TP2_j);
    SDL_Texture* texmaze = SDL_CreateTextureFromSurface(rend, screenSurface);

    t1_i=Tk1_i;
    t1_j=Tk1_j;
    t2_i=Tk2_i;
    t2_j=Tk2_j;
    t3_i=Tk3_i;
    t3_j=Tk3_j;
    t4_i=Tk4_i;
    t4_j=Tk4_j;

    tp1_i=TP1_i;
    tp1_j=TP1_j;
    tp2_i=TP2_i;
    tp2_j=TP2_j;


            while (!quit)
            {
            SDL_Event event;

                if(((t1_i==coordx)&&(t1_j==coordy))||((t2_i==coordx)&&(t2_j==coordy))||((t3_i==coordx)&&(t3_j==coordy)))
                {
                    inversion=1;
                }
                if(((t3_i==coordx)&&(t3_j==coordy))||((t4_i==coordx)&&(t4_j==coordy)))
                {
                    inversion=0;
                }



                while (SDL_PollEvent(&event))
                {
                    if(coordy==20)
                    {
                        printf("El poder de la luna nos ha hecho libres, podemos vagar por el vacío\n");
                    }
                    if (event.type == SDL_QUIT ||salir(coordx,coordy,sal_i,sal_j)==1)
                        quit=1;
                    if(tp1_i==coordx && tp1_j==coordy && teletransportar==1)
                    {
                        coordx=tp2_i;
                        coordy=tp2_j;
                        x_pos=x_pos+76*(tp1_i-tp2_i);
                        y_pos=y_pos+96*(tp1_j-tp2_j);
                        teletransportar=0;
                    }
                    if((coordx!=tp1_i && coordy!=tp1_j)&&(coordx!=tp2_i && coordy!=tp2_j))
                    {
                        teletransportar=1;
                    }
                    if(tp2_i==coordx && tp2_j==coordy && teletransportar==1)
                    {
                        coordx=tp1_i;
                        coordy=tp1_j;
                        x_pos=x_pos+76*(tp2_i-tp1_i);
                        y_pos=y_pos+96*(tp2_j-tp1_j);
                        teletransportar=0;
                    }
                    if((coordx!=tp1_i && coordy!=tp1_j)&&(coordx!=tp2_i && coordy!=tp2_j))
                    {
                        teletransportar=1;
                    }
                    if (event.type == SDL_KEYDOWN) //Cuando estemos pulsando la tecla
                    {

                        if(inversion==0)
                        {
                            salir(coordx,coordy,sal_i,sal_j);

                            if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
                            {
                                if(maze[coordx-1][coordy]==0)
                                {
                                    x_pos=x_pos+76;
                                    coordx--;
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
                                    dcha = 1, izq = 0, arriba = 0, abajo = 0;
                                }
                                if(maze[coordx+1][coordy]==1)
                                {
                                    x_pos=x_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_UP)
                            {
                                if(maze[coordx][coordy-1]==0 )
                                {
                                    y_pos=y_pos+96;
                                    coordy--;
                                    dcha = 0, izq = 0, arriba = 1, abajo = 0;
                                }
                                if(maze[coordx][coordy-1]==1 )
                                {
                                    y_pos=y_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
                            {
                                if(maze[coordx][coordy+1]==0 && coordy+1 !=20)
                                {
                                    y_pos=y_pos-96;
                                    coordy++;
                                    dcha = 0, izq = 0, arriba = 0, abajo = 1;
                                }
                                if(maze[coordx][coordy+1]==1 || coordy+1 ==20)
                                {
                                    y_pos=y_pos;
                                }
                            }
                        }

                        if(inversion==1)
                        {
                            salir(coordx,coordy,sal_i,sal_j);

                            if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)
                            {
                                if(maze[coordx-1][coordy]==0)
                                {
                                    x_pos=x_pos+76;
                                    coordx--;
                                    dcha = 0, izq = 1, arriba = 0, abajo = 0;
                                }
                                if(maze[coordx-1][coordy]==1)
                                {
                                    x_pos=x_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
                            {
                                if(maze[coordx+1][coordy]==0)
                                {
                                    x_pos=x_pos-76;
                                    coordx++;
                                    dcha = 1, izq = 0, arriba = 0, abajo = 0;
                                }
                                if(maze[coordx+1][coordy]==1)
                                {
                                    x_pos=x_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
                            {
                                if(maze[coordx][coordy-1]==0 || coordy+1==20)
                                {
                                    y_pos=y_pos+96;
                                    coordy--;
                                    dcha = 0, izq = 0, arriba = 1, abajo = 0;
                                }
                                if(maze[coordx][coordy-1]==1 && coordy+1!=20 )
                                {
                                    y_pos=y_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_UP)
                            {
                                if(maze[coordx][coordy+1]==0 || coordy+1==20)
                                {
                                    y_pos=y_pos-96;
                                    coordy++;
                                    dcha = 0, izq = 0, arriba = 0, abajo = 1;
                                }
                                if(maze[coordx][coordy+1]==1 && coordy+1!=20)
                                {
                                    y_pos=y_pos;
                                }
                            }
                        }
                    }
                }
                dest.y = y_pos;
                dest.x = x_pos;


                Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
                Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
                SDL_Rect srcrect = {sprite*32, 0, 32, 32};


                if(!quit)
                {
                    SDL_RenderClear(rend);
                    SDL_RenderCopy(rend,texmaze, NULL, &dest);
                    SDL_RenderPresent(rend);
                }


                // SDL_RenderClear(rend);
                SDL_RenderCopy(rend, texid, &srcrect, &personaje);
                SDL_RenderPresent(rend);

                if (dcha && !izq)
                {
                    //SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, texd, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (izq && !dcha)
                {
                    // SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, texi, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (abajo && !arriba)
                {
                    //  SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, texar, &srcrect, &personaje);
                    SDL_RenderPresent(rend);

                }
                if (arriba && !abajo)
                {
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



void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy,int *sal_i,int *sal_j,int *Tk1_i,int *Tk1_j,int *Tk2_i,int *Tk2_j,int *Tk3_i,int *Tk3_j,int *Tk4_i,int *Tk4_j,int *TP1_i,int *TP1_j,int *TP2_i,int *TP2_j)
{
    int alt = 20;
    int anch = 20;
    int i,j,x,y, xo, yo, k = 0;
    int T1,T2,T3,T4,TP1,TP2,T1_i,T1_j,T2_i,T2_j,T3_i,T3_j,T4_i,T4_j,tp1_i,tp1_j,tp2_i,tp2_j;
    int esp=0,salida_i,salida_j;

    srand(time(NULL));

    T1=rand() % 80;
    T2=rand() % 80;
    T3=rand() % 80;
    T4=rand() % 80;

    TP1=rand() % 80;
    TP2=rand() % 80;
    //Llenamos una matriz de 1. Esta matriz se utilizará posteriormente para hacer el laberinto
    for (i = 0; i < alt; i++)
    {
        for(j = 0; j < anch; j++)
            maze[i][j] = 1;
    }
    xo = 9;
    yo = 7;
//Posición inicial
    maze[xo][yo] = 0;
//Hacemos el laberinto
    recursion(xo, yo, anch, alt, maze);

//SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) ); //Ponemos el fondo blanco
    SDL_Surface *camino = SDL_LoadBMP("Path.bmp"); //Cargamos tanto el sprite del camino como el del muro.
    SDL_Surface *muro = SDL_LoadBMP("GenWall.bmp");
    SDL_Surface *Inicio = SDL_LoadBMP("Inicio.bmp");
    SDL_Surface *Salida = SDL_LoadBMP("Salida.bmp");
    SDL_Surface *Token1 = SDL_LoadBMP("TK3.bmp");
    SDL_Surface *Token2 = SDL_LoadBMP("TK3.bmp");
    SDL_Surface *Token3 = SDL_LoadBMP("TK1.bmp");
    SDL_Surface *Token4 = SDL_LoadBMP("TK1.bmp");
    SDL_Surface *Teleportador1 = SDL_LoadBMP("TP.bmp");
    SDL_Surface *Teleportador2 = SDL_LoadBMP("TP.bmp");

//SDL_Texture *texca = SDL_CreateTextureFromSurface(rend, camino);
//SDL_Texture *texmu = SDL_CreateTextureFromSurface(rend, muro);

    SDL_Rect pos;
    for(i = 1; i < 3; i++)
    {
        for(j = 1; j < 3; j++)
        {
            maze[i][j]=0;
        }
    }
    for(i = 1; i < alt; i++)
    {
        for(j = 1; j < anch; j++)
        {
            if(maze[i][j]==0)
            {
              esp++;
              salida_i=i;
              salida_j=j;
            }
            if(esp==T1)
            {
                *Tk1_i=i;
                *Tk1_j=j;
                maze[i][j]=0;
            }
            if(esp==T2)
            {
                *Tk2_i=i;
                *Tk2_j=j;
                maze[i][j]=0;
            }
            if(esp==T3)
            {
                *Tk3_i=i;
                *Tk3_j=j;
                maze[i][j]=0;
            }
            if(esp==T4)
            {
                *Tk4_i=i;
                *Tk4_j=j;
                maze[i][j]=0;
            }
            if(esp==TP1)
            {
                *TP1_i=i;
                *TP1_j=j;
                maze[i][j]=0;
            }
            if(esp==TP2)
            {
                *TP2_i=i;
                *TP2_j=j;
                maze[i][j]=0;
            }
        }
    }
        T1_i=*Tk1_i;
        T1_j=*Tk1_j;

        T2_i=*Tk2_i;
        T2_j=*Tk2_j;

        T3_i=*Tk3_i;
        T3_j=*Tk3_j;

        T4_i=*Tk4_i;
        T4_j=*Tk4_j;

        tp1_i=*TP1_i;
        tp1_j=*TP1_j;

        tp2_i=*TP2_i;
        tp2_j=*TP2_j;
        maze[2][2]=1;
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
                pos.x = 32*tp2_i;
                pos.y = 32*tp2_j;
                SDL_BlitSurface(Teleportador2,0,screenSurface,&pos);
                pos.x = 32*tp1_i;
                pos.y = 32*tp1_j;
                SDL_BlitSurface(Teleportador1,0,screenSurface,&pos);
                pos.x = 32*T4_i;
                pos.y = 32*T4_j;
                SDL_BlitSurface(Token4,0,screenSurface,&pos);
                pos.x = 32*T3_i;
                pos.y = 32*T3_j;
                SDL_BlitSurface(Token3,0,screenSurface,&pos);
                pos.x = 32*T2_i;
                pos.y = 32*T2_j;
                SDL_BlitSurface(Token2,0,screenSurface,&pos);
                pos.x = 32*T1_i;
                pos.y = 32*T1_j;
                SDL_BlitSurface(Token1,0,screenSurface,&pos);
                pos.x = 32;
                pos.y = 32;
                SDL_BlitSurface(Inicio,0,screenSurface,&pos);
                pos.x = 32*salida_i;
                pos.y = 32*salida_j;
                SDL_BlitSurface(Salida,0,screenSurface,&pos);
                *sal_i=salida_i;
                *sal_j=salida_j;

}


