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

int salir(int coordx,int coordy, Token Final);

void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy, Token Luna[2], Token Sol[2], Token Teleport[2], Token *Final);

void InitTokens(int maze[N][N]);

void TLuna(int coordx, int coordy, Token Luna[2],int *inversion);

void TSol(int coordx, int coordy, Token Sol[2], int *inversion);

void TP(int coordx, int coordy, Token Teleport[2], int *teletransportar, int *x_pos, int *y_pos);

void InitGame();

