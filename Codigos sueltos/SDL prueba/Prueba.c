/**

#include <SDL.h>
#include <stdio.h>


int main( int argc, char* args[] )
{

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int i,j,matriz[4][4];
//Se define la ventana
SDL_Window* window = NULL;


SDL_Surface* screenSurface = NULL;
SDL_Surface* camino;     //Definimos la imagen

//Inicio de SDL
if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
{
printf( "SDL no pudo iniciarse. SDL_Error: %s\n", SDL_GetError() );
}
else
{
//Creación ventana
window = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
if( window == NULL )
{
printf( "No se pudo crear la ventana emergente SDL_Error: %s\n", SDL_GetError() );
}
else
{
//Carga la ventana
screenSurface = SDL_GetWindowSurface( window );

//Cubrimos la pantalla de blanco
SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );


//Cargamos la imagen
SDL_Surface *camino = SDL_LoadBMP("CaminoGenerico.bmp"); //esto carga la imagen.

SDL_BlitSurface(camino,0,screenSurface,0);//El 0,0 es esquina superior izquierda
//SDL_BlitSurface(imagen,&SDL_Rect,PANTALLA,&SDL_Rect);  //Hay que poner & y la variable SDL_Rect para la posición


//Actualizamos la pantalla
SDL_UpdateWindowSurface( window );

//Esperamos 10 segundos
SDL_Delay( 10000 );

}
}

//Se destruye la ventana y se sale de SDL
SDL_DestroyWindow( window );
SDL_Quit();

return 0;
}
*/
