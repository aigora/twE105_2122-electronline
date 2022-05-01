/**
#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#define SPEED (300) //Definimos la velocidad(píxeles por segundo)

int main( int argc, char* args[] )
{
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
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

//Se define la ventana
SDL_Window* ventana;
SDL_Surface* screenSurface = NULL;

//Cargamos la imagen que vamos a mover
SDL_Surface *Derecha = SDL_LoadBMP("MovRight.bmp"); //esto carga la imagen.

//Anim

//

//Inicio de SDL
if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
{
printf( "SDL no pudo iniciarse. SDL_Error: %s\n", SDL_GetError() );
}
else
{
//Creación ventana
ventana = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
if( ventana == NULL )
{
printf( "No se pudo crear la ventana emergente SDL_Error: %s\n", SDL_GetError() );
}
else
{

Uint32 render_flags = SDL_RENDERER_ACCELERATED;
SDL_Renderer* rend = SDL_CreateRenderer(ventana, -1, render_flags);
if (!rend)
{
    printf("Error al crear el render: %s\n",SDL_GetError());
    SDL_DestroyWindow(ventana);
    SDL_Quit;
    return 1;
}
//Carga la ventana
screenSurface = SDL_GetWindowSurface( ventana );



//SDL_BlitSurface(camino,0,screenSurface,&offset);//El 0,0 es esquina superior izquierda
//SDL_BlitSurface(imagen,&SDL_Rect,PANTALLA,&SDL_Rect);  //Hay que poner & y la variable SDL_Rect para la posición

//Se guardan los datos de la imagen en la memoria del software de los gráficos
SDL_Texture*tex = SDL_CreateTextureFromSurface(rend, Derecha);
//SDL_Texture*texi = SDL_CreateTextureFromSurface(rend, izqda);
//SDL_Texture*texar = SDL_CreateTextureFromSurface(rend, arriba);
//SDL_Texture*texab = SDL_CreateTextureFromSurface(rend, abajo);

SDL_FreeSurface(Derecha);

if (!tex)
{
    printf("Error al crear la textura: %s\n",SDL_GetError());
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(ventana);
    SDL_Quit();
    return 1;
}

//Estructura para mantener la posición y el tamaño del sprite

SDL_Rect dest = {0, 0, 32, 32};

SDL_SetRenderDrawColor(rend, 168, 230, 255, 255);
SDL_RenderClear(rend);

//Definimos el sprite en el centro de la pantalla
float x_pos= (SCREEN_WIDTH - dest.w) / 2;
float y_pos = (SCREEN_HEIGHT - dest.h) / 2;

while (!quit)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            quit=1;
        if (event.type == SDL_KEYDOWN)
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

        if (event.type == SDL_KEYUP)  //Keyup es cuando dejamos de presionar la tecla
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
        Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
        Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
        SDL_Rect srcrect = {sprite*32, 0, 32, 32};

    //Se determina la velocidad
    x_vel = y_vel = 0;
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

//En esta parte se muestra la imagen
    SDL_RenderClear(rend); //Borra el sprite, para que no se superpongan
    SDL_RenderCopy(rend, tex, &srcrect, &dest); //Copia el nuevo sprite
    SDL_RenderPresent(rend);

    SDL_Delay(1000/60);
}

//Se destruye todo y se sale de SDL
SDL_DestroyTexture(tex);
SDL_DestroyRenderer(rend);
SDL_DestroyWindow(ventana);
SDL_Quit();
}
}
return 0;
}

*/
