#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>

int main(int argc, char *args[]){

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

_Bool quit = 0;
SDL_Event event;

SDL_Init(SDL_INIT_VIDEO);

SDL_Window *window = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
SDL_Surface *imagen = SDL_LoadBMP("MovRight.bmp"); //Carga la imagen
SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, imagen);


SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
SDL_RenderClear(renderer);
while(!quit){

        Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
        Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
        //Sprite entregará los valores {0, 1, 2, 3, 4, 5, 6} según el tiempo que pase

        SDL_Rect srcrect = {sprite*32, 0, 32, 32}; //Selecciona la porción de imagen que muestra por pantalla, ajustada a cada sprite individual
        //El sprite que se mostrará viene controlado por la variable sprite, multiplicando al tamaño de cada sprite individual
        //De esta manera cada vez que pase el tiempo cambia la posición {0, 32, 64, 96, 128, 160}
        SDL_Rect dstrect = {10, 10, 32, 32};

        SDL_WaitEvent(&event);


while(SDL_PollEvent(&event) != NULL){
        switch(event.type){
case SDL_QUIT:
    quit = 1;
    break;
    }
}

    SDL_RenderClear(renderer); //Borra el sprite, para que no se superpongan
    SDL_RenderCopy(renderer, texture, &srcrect, &dstrect); //Copia el nuevo sprite
    SDL_RenderPresent(renderer);
}


//Se destruye todo y se sale de SDL
SDL_DestroyTexture(texture);
SDL_FreeSurface(imagen);
SDL_DestroyRenderer(renderer);
SDL_DestroyWindow(window);
SDL_Quit();

return 0;
}
