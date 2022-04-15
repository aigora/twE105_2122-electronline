#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

int maze[N][N],f1=0,f2=0,lapso=1;
char lab[N][N],bloqueo='B';
char m=' ';
char n=254;
char p='+';
void recursion(int r, int c, int anch, int alt);
void direccion (int x[]); // Genera un vector con números aleatorios del 1 al 4 sin repetición


int main()
{
     srand(time(NULL));

       int i, j, anch, alt, rad1, rad2,reverse=0;
       int reversex,reversey,reversex2,reversey2;
    printf("introduce la altura\n");
    scanf("%i", &alt);
    system("cls");
    printf("introduce la anchura\n");
    scanf("%i", &anch);
    system("cls");
    reversex=rand() % anch+1;
    reversey=rand() % alt+1;
    reversex2=rand() % anch+1;
    reversey2=rand() % alt+1;
    for (i = 0; i < alt; i++){
        for (j = 0; j < anch; j++)
            maze[i][j] = 1;
    }

     do{
     rad1 = rand() % alt;
} while (rad1 % 2 == 0);
     do{
     rad2 = rand() % anch;
} while (rad2 % 2 == 0);

//Posición inicial
      maze[rad1][rad2] = 50;
//Hacemos el laberinto
      recursion(rad1, rad2, anch, alt);
for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1][1]=p;
    if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
    if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
        if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
}
printf(" %c", lab[i][j]);
}
printf("\n");
}
while(1)
{
    if((lab[1+f2][2+f1]==m)||lab[1+f2][2+f1]==bloqueo)
    {
         if(GetAsyncKeyState(0x27))
{
    Sleep(lapso);
    f1++;
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
    if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
    }
if(lab[1+f2][f1]==m||lab[1+f2][f1]==bloqueo)
{
 if(GetAsyncKeyState(0x25))
{
    Sleep(lapso);
    f1--;
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
        if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
}
if((lab[f2][1+f1]==m)||lab[f2][1+f1]==bloqueo)
{
 if(GetAsyncKeyState(0x26))
{
    Sleep(lapso);
    f2--;
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
        if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
}
if((lab[2+f2][1+f1]==m)||lab[2+f2][1+f1]==bloqueo)
{
 if(GetAsyncKeyState(0x28))
{
    Sleep(lapso);
    f2++;
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
        if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
}
if(lab[1+f2][2+f1]==n)
{
     if(GetAsyncKeyState(0x27))
{
    Sleep(lapso);
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
        if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
}
if((lab[1+f2][f1]==n))
{
 if(GetAsyncKeyState(0x25))
{
    Sleep(lapso);
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
        if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
}
if((lab[f2][1+f1]==n))
{
 if(GetAsyncKeyState(0x26))
{
    Sleep(lapso);
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
        if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
}
if((lab[2+f2][1+f1]==n))
{
 if(GetAsyncKeyState(0x28))
{
    Sleep(lapso);
    system("cls");
    for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(maze[i][j]==0)
    {
        lab[i][j]=m;
    }
    if(maze[i][j]==1)
    {
        lab[i][j]=n;
    }
    if(maze[N/2][N/2]==0)
{
    lab[1+f2][1+f1]=p;
}
        if(maze[reversex][reversey]==0)
    {
     lab[reversex][reversey]=bloqueo;
    }
        if(lab[reversex][reversey]==bloqueo)
    {
        maze[reversex][reversey]=2;
    }
            if(maze[reversex2][reversey2]==0)
    {
     lab[reversex2][reversey2]=bloqueo;
    }
    if(lab[reversex2][reversey2]==bloqueo)
    {
        maze[reversex2][reversey2]=2;
    }
printf(" %c", lab[i][j]);
}
printf("\n");
}
}
}
    }
return 0;
}

void recursion(int r, int c, int anch, int alt)
{
    int i;
 int direc[4] = {0,0,0,0};
 direccion(direc);

 for (i = 0; i < 4; i++){

    switch(direc[i]){
   case 1: //Arriba
       if (r - 2 <= 0) // si dos celdas más arriba está ocupado o no
        continue;
       else if (maze[r - 2][c] != 0){ //ocupa las dos de arriba
        maze[r - 2][c] = 0;
        maze[r - 1][c] = 0;
        recursion(r - 2, c, anch, alt);
       }
       break;

    case 2: //Derecha
       if (c + 2 >= anch - 1)  // si dos celdas a la derecha está ocupado o no
        continue;
       else if (maze[r][c + 2] != 0){ //ocupa las dos de la derecha
        maze[r][c + 2] = 0;
        maze[r][c + 1] = 0;
        recursion(r, c + 2, anch, alt);
       }
       break;

    case 3: //Abajo
       if (r + 2 >= alt - 1)  // si dos celdas más abajo está ocupado o no
        continue;
       else if (maze[r + 2][c] != 0){ //ocupa las dos de abajo
        maze[r + 2][c] = 0;
        maze[r + 1][c] = 0;
        recursion(r + 2, c, anch, alt);
       }
       break;

    case 4: //Izquierda
       if (c - 2 <= 0)  // si dos celdas a la izquierda está ocupado o no
        continue;
       else if (maze[r][c - 2] != 0){ //ocupa las dos de la izquierda
        maze[r][c - 2] = 0;
        maze[r][c - 1] = 0;
        recursion(r, c - 2, anch, alt);
       }
       break;

    }
 }

}
void direccion(int x[])
{
srand(time(NULL));
int i, cont, j, rad;

    do{
 rad = rand() % 5;
    } while (rad == 0);

    x[0] = rad;

    inicio:
for (i = 1; i < 4; i++){
    cont = 0;
       do{
 rad = rand() % 5;
    } while (rad == 0);


    for (j = 0; j <= i; j++){
        if (rad == x[j])
            cont = 1;
    }

    if (cont == 0)
        x[i] = rad;
        else
        goto inicio;
}
}



