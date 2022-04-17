#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 500
int maze[N][N];
char lab[N][N];
void recursion(int r, int c, int anch, int alt);
void construir(int a,int b, int f1, int f2, int anch, int alt, char m, char n, char p,int x,int y);
//Funcion para replicar el laberinto unja vez movida la cruceta.
//Primero crea un patr�n de direcciones aleatorio, luego con esa direcci�n comprueba si se puede.
//Si no puede, pasa a otra direcci�n hasta que una se pueda, y marca esas casillas como camino.
//Una vez creado el camino vuelve a repetirse todo el proceso.

int main()
{

     srand(time(NULL));
       int i, j, anch, alt, rad1, rad2,f1=0,f2=0,esp=0,x,y,a,b,lapso=200;
char m=' '; //caminos
char n=254; //muros
char p='+'; //Personaje
    printf("introduce la altura\n");
    scanf("%i", &alt);
    system("cls");
    printf("introduce la anchura\n");
    scanf("%i", &anch);
    system("cls");

//En la versi�n final el tama�o del laberinto se elegir� a trav�s del men� principal

    for (i = 0; i < alt; i++){ //rellena la matriz laberinto de muros
        for (j = 0; j < anch; j++)
            maze[i][j] = 1;
    }

     do{ //selecciona un punto aleatorio dentro de los l�mites del laberinto
     rad1 = rand() % alt; //Este punto servir� tanto para empezar con nuestro personaje como para que el codigo empiece a generar el laberinto
} while (rad1 % 2 == 0);
     do{
     rad2 = rand() % anch;
} while (rad2 % 2 == 0);

//Posici�n inicial
      maze[rad1][rad2] = 0;
//Modifica la matriz laberinto llena de muros a una con caminos aleatorios
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
    if(lab[i][j]==m)
    {
        //Si detecta un espacio suma uno al contador de espacios
        esp++;
        if(esp==1)
        {
            //Si se detecta el primer espacio se da el valor de las coordenadas iniciales tomaran los valores de las coordenadas del espacio
            lab[i][j]=p;
            x=j;
            y=i;
            //El espaciador toma tambien el valor de las coordenadas del espacio inicial
            a=j;
            b=i;
        }
    }
printf(" %c", lab[i][j]);
}
printf("\n");//Se construye el laberinto inicial
}
printf("x:%d y:%d",x,y);//Coordenadas iniciales
while(1)
{
    //Deteccion de espacios
    if(lab[b+f2][a+1+f1]==m)//Si el siquiente espacio a la derecha es un espacio
    {
         if(GetAsyncKeyState(0x27))//Si la flecha derecha es presionada
{
    Sleep(lapso);
    f1++;
    x++;    //Aumentamos el valor de la coordenada x y de la posicion hacia la derecha
    system("cls");
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}
if(lab[b+f2][f1+a-1]==m) //Si el espacio a la izquierda es un espacio
{
 if(GetAsyncKeyState(0x25)) //Si la flecha izquierda es presionada
{
    Sleep(lapso);
    f1--;
    x--;    //Disminuimos el valor de la coordenada x y desplazamos la cruceta hacia la izquierda
    system("cls");
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}
if((lab[f2][a+f1]==m)) //Si el elemento de abajo es un espacio
{
 if(GetAsyncKeyState(0x26)) //Si se presiona la flecha de abajo
{
    Sleep(lapso);    //Disminuimos el valor de las coordenadas y bajamos la cruceta una unidad
    f2--;
    y--;
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}
if((lab[b+1+f2][a+f1]==m))//Si el espacio superior es un espacio
{
 if(GetAsyncKeyState(0x28))//Si se presiona la flecha superior
{
    Sleep(lapso);
    f2++;
    y++;    //Aumentamos el valor de la coordenada x y subimos un espacio
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}

//Detección de bloques

if(lab[b+f2][a+1+f1]==n)//Si la casilla derecha es un bloque
{
     if(GetAsyncKeyState(0x27))//Si se presiona la flecha superior
{//No se modifica nada
    Sleep(lapso);
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}
if((lab[b+f2][f1+a-1]==n))//Si el elemento de la izquierda es un bloque
{
 if(GetAsyncKeyState(0x25))//Si presionamos la flecha de la izquierda
{
    Sleep(lapso);
    system("cls");//No se cambia nada
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}
if((lab[f2][a+f1]==n))//Si el espacio de abajo es un bloque
{
 if(GetAsyncKeyState(0x26))//Si se presiona la flecha de abajo
{

    //No se cambia nada
    Sleep(lapso);
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}
if((lab[b+1+f2][a+f1]==n))//Si el espacio de arriba es un bloque
{
 if(GetAsyncKeyState(0x28))//Si se presiona la flecha de arriba
{
    Sleep(lapso);
    system("cls");//No se actualiza nada
construir(a,b,f1,f2,anch,alt,m,n,p,x,y);
}
}
    }


return 0;
}

void recursion(int r, int c, int anch, int alt)

{
    int i, num, k, p;
 int direc[4] = {0,0,0,0};

 for (i = 0; i < 4; i++){ //Elige una direcci�n aleatoria
// el bucle terminar� cuando haya buscado entre las 4 direcciones y a�n as� no pueda continuar el laberinto

for(k=0;k<4;k++)
{
    int num = 1 + rand()%4; //genera un numero aleatorio para el vector direcci�n

   if(k>0)
   {

      for(p=0; p < k; p++)  // Verifica si no se ha generado antes
          if(num==direc[p])
          {
             num = 1 + rand()%4;
             p=-1;
          }
    }

   direc[k] =num;
}

    switch(direc[i]){ // crea caminos en el laberinto
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
void construir(int a,int b, int f1, int f2, int anch, int alt, char m, char n, char p,int x,int y)
{
    int i,j;
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
    lab[b+f2][a+f1]=p;
}
printf(" %c", lab[i][j]);
}
printf("\n");
}
printf("x:%d y:%d",x,y);//replicamos el laberinto y cambiamos la posicion de la cruceta y las coordenadas
}


