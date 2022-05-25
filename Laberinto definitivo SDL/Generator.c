#include "Game.h"
#include "Tokens.h"



void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy,Token Luna[2], Token Sol[2], Token Teleport[2], Token *Final, int alt, int anch, Token *Idolo)
{

    int t = 0;
     int l = 0;
      int s = 0;

    int finx, finy;

    int i,j;
    int randw;
    int srandx, srandy, numwalls = 0;

    srand(time(NULL));

    //Llenamos una matriz de 1. Esta matriz se utilizará posteriormente para hacer el laberinto

//Hacemos el laberinto


    SDL_Surface *camino = SDL_LoadBMP("Path.bmp"); //Cargamos tanto el sprite del camino como el del muro.

    SDL_Surface *muroG = SDL_LoadBMP("GenWall.bmp");
    SDL_Surface *muroB = SDL_LoadBMP("BasicWall.bmp");
    SDL_Surface *muroD = SDL_LoadBMP("DogWall.bmp");
    SDL_Surface *muroX = SDL_LoadBMP("XatuWall.bmp");
    SDL_Surface *muroF = SDL_LoadBMP("FWall.bmp");

    SDL_Surface *Inicio = SDL_LoadBMP("Inicio.bmp");
    SDL_Surface *Salida = SDL_LoadBMP("End.bmp");

    SDL_Surface *Idol = SDL_LoadBMP("Treasure.bmp");

    SDL_Surface *Token1 = SDL_LoadBMP("TK3.bmp"); //luna
    SDL_Surface *Token3 = SDL_LoadBMP("TK1.bmp"); //sol
    SDL_Surface *Teleportador1 = SDL_LoadBMP("TP.bmp");

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
            }
            if(maze[i][j]==1)
            {
              pos.x = 32*i;
              pos.y = 32*j;

                  randw= 1 + rand()%10;
             switch(randw){
         case 1:
         case 2:
         case 3:
         case 4:
              SDL_BlitSurface(muroB,0,screenSurface,&pos);
            break;
         case 5:
         case 6:
         case 7:
             SDL_BlitSurface(muroG,0,screenSurface,&pos);
            break;
         case 8:
             SDL_BlitSurface(muroF,0,screenSurface,&pos);
             break;
         case 9:
             SDL_BlitSurface(muroX,0,screenSurface,&pos);
             break;
         case 10:
               SDL_BlitSurface(muroD,0,screenSurface,&pos);
             break;
             }

            }
            if(maze[i][j]==2)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Luna[l].x = i;
                Luna[l].y = j;

                SDL_BlitSurface(Token1,0,screenSurface,&pos);
                l++;
            }
             if(maze[i][j]==3)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Sol[s].x = i;
                Sol[s].y = j;
                SDL_BlitSurface(Token3,0,screenSurface,&pos);
                s++;
            }

            if(maze[i][j]==4)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Teleport[t].x = i;
                Teleport[t].y = j;
                SDL_BlitSurface(Teleportador1,0,screenSurface,&pos);
                t++;
            }
                if(maze[i][j]==5)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Idolo->x = i;
                Idolo->y = j;
                SDL_BlitSurface(Idol,0,screenSurface,&pos);
            }
            if (maze[i][j] == 9)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                SDL_BlitSurface(Inicio,0,screenSurface,&pos);
            }
        }
    }




                do{
                srandx = 1 + rand()%20;
                srandy = 1 + rand()%20;
                    numwalls = 0;
                if(maze[srandx - 1][srandy] == 1)
                    numwalls ++;
                      if(maze[srandx + 1][srandy] == 1)
                    numwalls ++;
                            if(maze[srandx][srandy - 1] == 1)
                        numwalls ++;
                            if(maze[srandx][srandy + 1] == 1)
                        numwalls ++;
                } while (numwalls != 3 || maze[srandx][srandy] == 1);


//printf("%i %i", srandx, srandy);

                            Final->x = srandx;
                            Final->y = srandy;
                pos.x = 32*Final->x;
                pos.y = 32*Final->y;
                SDL_BlitSurface(Salida,0,screenSurface,&pos);
}


void InitMaze2(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy,Token Luna[2], Token Sol[2], Token Teleport[2], Token *Final, int alt, int anch, Token *Idolo)
{

    int t = 0;
     int l = 0;
      int s = 0;

    int finx, finy;

    int i,j;
    int randw;
    int srandx, srandy, numwalls = 0;

    srand(time(NULL));

    //Llenamos una matriz de 1. Esta matriz se utilizará posteriormente para hacer el laberinto

//Hacemos el laberinto


    SDL_Surface *camino = SDL_LoadBMP("Path.bmp"); //Cargamos tanto el sprite del camino como el del muro.

    SDL_Surface *muroG = SDL_LoadBMP("GenWall.bmp");
    SDL_Surface *muroB = SDL_LoadBMP("BasicWall.bmp");
    SDL_Surface *muroD = SDL_LoadBMP("DogWall.bmp");
    SDL_Surface *muroX = SDL_LoadBMP("XatuWall.bmp");
    SDL_Surface *muroF = SDL_LoadBMP("FWall.bmp");

    SDL_Surface *Inicio = SDL_LoadBMP("Inicio.bmp");
    SDL_Surface *Salida = SDL_LoadBMP("End.bmp");

    SDL_Surface *Idol = SDL_LoadBMP("Stolen.bmp");

    SDL_Surface *Token1 = SDL_LoadBMP("TK3.bmp"); //luna
    SDL_Surface *Token3 = SDL_LoadBMP("TK1.bmp"); //sol
    SDL_Surface *Teleportador1 = SDL_LoadBMP("TP.bmp");

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
            }
            if(maze[i][j]==1)
            {
              pos.x = 32*i;
              pos.y = 32*j;

                  randw= 1 + rand()%10;
             switch(randw){
         case 1:
         case 2:
         case 3:
         case 4:
              SDL_BlitSurface(muroB,0,screenSurface,&pos);
            break;
         case 5:
         case 6:
         case 7:
             SDL_BlitSurface(muroG,0,screenSurface,&pos);
            break;
         case 8:
             SDL_BlitSurface(muroF,0,screenSurface,&pos);
             break;
         case 9:
             SDL_BlitSurface(muroX,0,screenSurface,&pos);
             break;
         case 10:
               SDL_BlitSurface(muroD,0,screenSurface,&pos);
             break;
             }

            }
            if(maze[i][j]==2)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Luna[l].x = i;
                Luna[l].y = j;

                SDL_BlitSurface(Token1,0,screenSurface,&pos);
                l++;
            }
             if(maze[i][j]==3)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Sol[s].x = i;
                Sol[s].y = j;
                SDL_BlitSurface(Token3,0,screenSurface,&pos);
                s++;
            }

            if(maze[i][j]==4)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Teleport[t].x = i;
                Teleport[t].y = j;
                SDL_BlitSurface(Teleportador1,0,screenSurface,&pos);
                t++;
            }
                if(maze[i][j]==5)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                Idolo->x = i;
                Idolo->y = j;
                SDL_BlitSurface(Idol,0,screenSurface,&pos);
            }
            if (maze[i][j] == 9)
            {
                pos.x = 32*i;
                pos.y = 32*j;
                SDL_BlitSurface(Inicio,0,screenSurface,&pos);
            }
        }
    }




                do{
                srandx = 1 + rand()%20;
                srandy = 1 + rand()%20;
                    numwalls = 0;
                if(maze[srandx - 1][srandy] == 1)
                    numwalls ++;
                      if(maze[srandx + 1][srandy] == 1)
                    numwalls ++;
                            if(maze[srandx][srandy - 1] == 1)
                        numwalls ++;
                            if(maze[srandx][srandy + 1] == 1)
                        numwalls ++;
                } while (numwalls != 3 || maze[srandx][srandy] == 1);


//printf("%i %i", srandx, srandy);

                            Final->x = srandx;
                            Final->y = srandy;
                pos.x = 32*Final->x;
                pos.y = 32*Final->y;
                SDL_BlitSurface(Salida,0,screenSurface,&pos);
}



void recursion(int r, int c, int anch, int alt, int maze[N][N])
{
    int i, k, p;
 int direc[4] = {0,0,0,0};

 for (i = 0; i < 4; i++){ //Elige una dirección aleatoria
// el bucle terminará cuando haya buscado entre las 4 direcciones y aún así no pueda continuar el laberinto

for(k=0;k<4;k++)
{
    int num = 1 + rand()%4; //genera un numero aleatorio para el vector dirección
      for(p=0; p < k; p++)  // Verifica si no se ha generado antes
          if(num==direc[p])
          {
             num = 1 + rand()%4;
             p=-1;
          }
   direc[k] =num;
}

    switch(direc[i]){ // crea caminos en el laberinto
   case 1: //Arriba
       if (r - 2 <= 0) // si dos celdas más arriba está ocupado o no
        continue;
       else if (maze[r - 2][c] != 0){ //ocupa las dos de arriba
        maze[r - 2][c] = 0;
        maze[r - 1][c] = 0;
        recursion(r - 2, c, anch, alt, maze);
       }
       break;

    case 2: //Derecha
       if (c + 2 >= anch - 1)  // si dos celdas a la derecha está ocupado o no
        continue;
       else if (maze[r][c + 2] != 0){ //ocupa las dos de la derecha
        maze[r][c + 2] = 0;
        maze[r][c + 1] = 0;
        recursion(r, c + 2, anch, alt, maze);
       }
       break;

    case 3: //Abajo
       if (r + 2 >= alt - 1)  // si dos celdas más abajo está ocupado o no
        continue;
       else if (maze[r + 2][c] != 0){ //ocupa las dos de abajo
        maze[r + 2][c] = 0;
        maze[r + 1][c] = 0;
        recursion(r + 2, c, anch, alt, maze);
       }
       break;

    case 4: //Izquierda
       if (c - 2 <= 0)  // si dos celdas a la izquierda está ocupado o no
        continue;
       else if (maze[r][c - 2] != 0){ //ocupa las dos de la izquierda
        maze[r][c - 2] = 0;
        maze[r][c - 1] = 0;
        recursion(r, c - 2, anch, alt, maze);
       }
       break;

    }
 }
}
