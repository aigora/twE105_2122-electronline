#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100

int maze[N][N];
char lab[N][N];
char m=' ';
char n=254;
char avatar='$',avance;
int i,j;
void recursion(int r, int c, int anch, int alt);
void direccion (int x[]); // Genera un vector con n�meros aleatorios del 1 al 4 sin repetici�n
void laberinto(int base, int altura, char lab[N][N]);  //Muestra el laberinto


int main()
{
     srand(time(NULL));

       int i, j, anch, alt, rad1, rad2;
    printf("introduce la altura\n");
    scanf("%i", &alt);
    printf("introduce la anchura\n");
    scanf("%i", &anch);


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

//Posici�n inicial
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
}
}
lab[1][1]=avatar;    //Ponemos el avatar al principio del laberinto(esquina superior izquierda).
laberinto(anch,alt,lab);
i=1,j=1;
do
    {
    scanf("%c",&avance);
    switch (avance)
    {
        case 'w':        //Avance superior.
            system("cls");
            if (lab[i-1][j]!=n)          //Si el bloque de arriba no es un l�mite, avanza, y el bloque anterior vuelve a ser un espacio.
            {
                lab[i-1][j]=avatar;
                lab[i][j]=' ';
                i--;
            }
            else
                lab[i-1][j]=n;            //Si el bloque de arriba es un l�mite, permanece siendo un l�mite.
            laberinto(anch,alt,lab);
            break;
        case 'a':       //Avance izquierda.
            system("cls");
            if (lab[i][j-1]!=n)
            {
                lab[i][j-1]=avatar;
                lab[i][j]=' ';
                j--;
            }
            else
                lab[i][j-1]=n;
            laberinto(anch,alt,lab);
            break;
        case 's':           //Avance inferior.
            system("cls");
            if (lab[i+1][j]!=n)
            {
                lab[i+1][j]=avatar;
                lab[i][j]=' ';
                i++;
            }
            else
                lab[i+1][j]=n;
            laberinto(anch,alt,lab);
            break;
        case 'd':            //Avance derecha.
            system("cls");
            if (lab[i][j+1]!=n)
            {
                lab[i][j+1]=avatar;
                lab[i][j]=' ';
                j++;
            }
            else
                lab[i][j+1]=n;
            laberinto(anch,alt,lab);
            break;
        default:
            break;
    }
}while(lab[i][j]!=400);  //Bucle "infinito", que permite mover el avatar indefinidamente.(Pr�ximamente se puede incluir alg�n objeto
                         //que perjudique al jugador poniendo movimientos limitados).
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
       if (r - 2 <= 0) // si dos celdas m�s arriba est� ocupado o no
        continue;
       else if (maze[r - 2][c] != 0){ //ocupa las dos de arriba
        maze[r - 2][c] = 0;
        maze[r - 1][c] = 0;
        recursion(r - 2, c, anch, alt);
       }
       break;

    case 2: //Derecha
       if (c + 2 >= anch - 1)  // si dos celdas a la derecha est� ocupado o no
        continue;
       else if (maze[r][c + 2] != 0){ //ocupa las dos de la derecha
        maze[r][c + 2] = 0;
        maze[r][c + 1] = 0;
        recursion(r, c + 2, anch, alt);
       }
       break;

    case 3: //Abajo
       if (r + 2 >= alt - 1)  // si dos celdas m�s abajo est� ocupado o no
        continue;
       else if (maze[r + 2][c] != 0){ //ocupa las dos de abajo
        maze[r + 2][c] = 0;
        maze[r + 1][c] = 0;
        recursion(r + 2, c, anch, alt);
       }
       break;

    case 4: //Izquierda
       if (c - 2 <= 0)  // si dos celdas a la izquierda est� ocupado o no
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

void laberinto(int base, int altura, char lab[N][N])
{
    int i,j;                       //Se imprime el laberinto primero por filas y despu�s por columnas.
    for(i = 0; i < altura; i++)
{
    for(j = 0; j < base; j++)
{
    printf(" %c", lab[i][j]);
}
printf("\n");
}
}

