#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#define SPEED (300)
#define N 100

void recursion(int r, int c, int anch, int alt, int maze[N][N]);

int salir(int coordx,int coordy,int sal_i,int sal_j);

void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy,int *sal_i,int *sal_j,int *Tk1_i,int *Tk1_j,int *Tk2_i,int *Tk2_j,int *Tk3_i,int *Tk3_j,int *Tk4_i,int *Tk4_j,int *TP1_i,int *TP1_j,int *TP2_i,int *TP2_j);

void InitGame(int *stage);
