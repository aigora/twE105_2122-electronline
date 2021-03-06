#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#define SPEED (300)
#define N 100

typedef struct{
    int x;
    int y;
} Token;

void recursion(int r, int c, int anch, int alt, int maze[N][N]);

int salir(int coordx,int coordy, Token Final, int robar);//Funcion para la salida

void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy, Token Luna[2], Token Sol[2], Token Teleport[2], Token *Final, int xo, int yo, Token *Idolo);
void InitMaze2(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy, Token Luna[2], Token Sol[2], Token Teleport[2], Token *Final, int xo, int yo, Token *Idolo);

void InitGame(int *stage,int pararaudio);

int puntuaciones(int minutos, int segundos);
