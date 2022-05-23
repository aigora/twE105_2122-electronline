#include "Tokens.h"

//Función para los objetos
void InitTokens(int maze[N][N])
{
    int i, r1, r2;
      for (i = 0; i < 2; i ++){
            do{
        r1 =  2 + rand() % 19;
        r2 =  2 + rand() % 19;
              } while(maze[r1][r2] == 1 || (r1 == 1 && r2 == 1));
        maze[r1][r1] = 2; //2 para las lunas
    }


    for (i = 0; i < 2; i ++){
            do{
        r1 =  2 + rand() % 19;
        r2 = 2 + rand() % 19;
              } while(maze[r1][r2] == 1 || maze[r1][r2] == 2 || (r1 == 1 && r2 == 1));

        maze[r1][r2] = 3; //3 para los soles
    }


    for (i = 0; i < 2; i ++){
            do{
        r1 =  2 + rand() % 19;
        r2 = 2 + rand() % 19;
              }while(maze[r1][r2] == 1 || maze[r1][r2] == 2 || maze[r1][r2] == 3 || (r1 == 1 && r2 == 1));
        maze[r1][r2] = 4; //4 para los tps
    }

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
