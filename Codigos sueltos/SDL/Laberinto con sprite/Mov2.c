
/**


#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#define SPEED (300) //Definimos la velocidad(píxeles por segundo)


int main( int argc, char* args[] )
{

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Creamos la ventana, definimos el fondo y declaramos el renderer
SDL_Window* ventana = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );;
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


*/
