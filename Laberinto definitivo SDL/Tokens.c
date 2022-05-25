#include "Tokens.h"

//Función para los objetos
void InitTokens(int maze[N][N])
{
    int numwalls;
    int i, r1, r2;
      for (i = 0; i < 2; i ++){
            do{
        r1 =  1 + rand() % 20; //numeros aleatorios del 1 al 20
        r2 =  1 + rand() % 20;
              } while(maze[r1][r2] == 1 || (r1 == 1 && r2 == 1));
        maze[r1][r1] = 2; //2 para las lunas
    }


    for (i = 0; i < 2; i ++){
            do{
        r1 =  1 + rand() % 20;
        r2 = 1 + rand() % 20;
              } while(maze[r1][r2] == 1 || maze[r1][r2] == 2 || (r1 == 1 && r2 == 1));

        maze[r1][r2] = 3; //3 para los soles
    }

//Cada TP se generará en una zona de la pantalla
            do{
        r1 =  1 + rand() % 10;
        r2 = 10 + rand() % 10;
              }while(maze[r1][r2] == 1 || maze[r1][r2] == 2 || maze[r1][r2] == 3 || (r1 == 1 && r2 == 1));
        maze[r1][r2] = 4; //4 para los tps

       do{
        r1 =  10 + rand() % 10;
        r2 = 1 + rand() % 10;
              }while(maze[r1][r2] == 1 || maze[r1][r2] == 2 || maze[r1][r2] == 3 || (r1 == 1 && r2 == 1));
        maze[r1][r2] = 4; //4 para los tps

          do{
               r1 = 1 + rand()%18;
               r2 = 1 + rand()%18;
                    numwalls = 0;
                if(maze[r1- 1][2] == 1)
                    numwalls ++;
                      if(maze[r1+ 1][r2] == 1)
                    numwalls ++;
                            if(maze[r1][r2 - 1] == 1)
                        numwalls ++;
                            if(maze[r1][r2 + 1] == 1)
                        numwalls ++;
                } while (numwalls != 3 || maze[r1][r2] == 1|| maze[r1][r2] == 2 || maze[r1][r2] == 3 || maze[r1][r2] == 4);
    maze[r1][r2] = 5;
}



void TLuna(int coordx, int coordy, Tokenn Luna[2], int *inversion)
{
    if(((Luna[0].x==coordx)&&(Luna[0].y==coordy))||((Luna[1].x==coordx)&&(Luna[1].y==coordy)))
                    *inversion=1;
}


void TSol(int coordx, int coordy, Tokenn Sol[2], int *inversion)
{
      if(((Sol[0].x==coordx)&&(Sol[0].y==coordy))||((Sol[1].x==coordx)&&(Sol[1].y==coordy)))
                    *inversion=0;

}
