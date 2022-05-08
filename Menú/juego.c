#include "juego.h"     //Código fuente del laberinto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void juego_lab(void){


     int maze[N][N];
     char lab[N][N];



     srand(time(NULL));//Se milla aleatoria para el teleportador y los bloqueos
     teleporter t1,t2;//declaramos el teletransportador;
     bloqueo b1[4]; // declaramos el vector de bloqueos;
       int i, j, anch, alt, rad1, rad2,f1=0,f2=0,esp=0,x,y,a,b,lapso=200,T1,T2,B1[bloc],espacios=0;
       int activ=0,laberinto=1;
       int si,sj;
       t1.identificador='T';//Simbolo del inicio del teletransportador;
       t2.identificador='T';
       b1[0].identificador='B';//Simbolo del bloqueo;
       b1[1].identificador='B';
       b1[2].identificador='B';
       b1[3].identificador='B';
       int paso=1;
char m=' '; //caminos
char n=254; //muros
char p='+'; //Personaje
    printf("introduce la altura\n");
    scanf("%i", &alt);
    system("cls");
    printf("introduce la anchura\n");
    scanf("%i", &anch);
    system("cls");
T1=rand() % (3*(alt+anch)); //Espacio aleatorio para T1
T2=rand() % (3*(anch+anch)); //Espacio aleatorio para T2
for(i=0; i<bloc; i++)
{
 B1[i]=rand() % (3*(alt+anch));
}
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
      recursion(rad1, rad2, anch, alt, maze, n);
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
        if(esp==T1)//Si se alcanza el espacio aleatorio 1 se pone el inicio del teletransportador;
        {
         lab[i][j]=t1.identificador;
         t1.y=i;
         t1.x=j;
        }
        if(esp==T2)//Si se alcanza el espacio aleatorio 2 se pone el final del teletransportador;
        {
         lab[i][j]=t2.identificador;
         t2.y=i;
         t2.x=j;
        }
        if(esp==B1[0])//Generar B1 en espacio;
        {
         lab[i][j]=b1[0].identificador;
         b1[0].y=i;
         b1[0].x=j;
        }
        if(esp==B1[1])//Generar B2 en espacio;
        {
         lab[i][j]=b1[1].identificador;
         b1[1].y=i;
         b1[1].x=j;
        }
        if(esp==B1[2])//Generar B3 en espacio;
        {
         lab[i][j]=b1[2].identificador;
         b1[2].y=i;
         b1[2].x=j;
        }
        if(esp==B1[3])//Generar B4 en espacio;
        {
         lab[i][j]=b1[3].identificador;
         b1[3].y=i;
         b1[3].x=j;
        }
    }
}
}
for(i = 0; i < alt; i++) {
for(j = 0; j < anch; j++)
{
    if(lab[i][j]==' '||lab[i][j]=='T'||lab[i][j]=='B'||lab[i][j]=='+')
    {
        espacios++;
    }
    if(espacios==esp)
    {
        activ=1;
        lab[i][j]='#';
    }
    if(maze[i][j]==1)
    {
        activ=0;
        lab[i][j]=n;
    }
    if(activ==1)
    {
        si=i;
        sj=j;
    }
 printf(" %c", lab[i][j]);
}
printf("\n");//Se construye el laberinto inicial
    }
printf("x:%d y:%d\n",x,y);//Coordenadas iniciale
printf("Presione el tabulador para reiniciar");
printf("%d,%d",si,sj);
while(laberinto==1)
{
    //Deteccion de espacios
    if((lab[b+f2][a+1+f1]==m)||(lab[b+f2][a+1+f1]==t1.identificador)||(lab[b+f2][a+1+f1]==t2.identificador)||(lab[b+f2][a+1+f1]=='B')||(lab[b+f2][a+1+f1]=='#'))//Si el siquiente espacio a la derecha es un espacio
    {//Si detecta un inicio o fin de teleportador pasa;
         if(GetAsyncKeyState(0x27))//Si la flecha derecha es presionada
{
    Sleep(lapso);
    f1++;
    x++;    //Aumentamos el valor de la coordenada x y de la posicion hacia la derecha
    system("cls");
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}
if((lab[b+f2][f1+a-1]==m)||(lab[b+f2][f1+a-1]==t1.identificador)||(lab[b+f2][f1+a-1]==t2.identificador)||(lab[b+f2][f1+a-1]=='B')||(lab[b+f2][f1+a-1]=='#')) //Si el espacio a la izquierda es un espacio
{//Si detecta un inicio o fin de teleportador pasa;
 if(GetAsyncKeyState(0x25)) //Si la flecha izquierda es presionada
{
    Sleep(lapso);
    f1--;
    x--;    //Disminuimos el valor de la coordenada x y desplazamos la cruceta hacia la izquierda
    system("cls");
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}
if((lab[f2][a+f1]==m)||(lab[f2][a+f1]==t1.identificador)||(lab[f2][a+f1]==t2.identificador)||(lab[f2][a+f1]=='B')||(lab[f2][a+f1]=='#')) //Si el elemento de abajo es un espacio
{//Si detecta un inicio o fin de teleportador pasa;
 if(GetAsyncKeyState(0x26)) //Si se presiona la flecha de abajo
{
    Sleep(lapso);    //Disminuimos el valor de las coordenadas y bajamos la cruceta una unidad
    f2--;
    y--;
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}
if((lab[b+1+f2][a+f1]==m)||(lab[b+1+f2][a+f1]==t1.identificador)||(lab[b+1+f2][a+f1]==t2.identificador)||(lab[b+1+f2][a+f1]=='B')||(lab[b+1+f2][a+f1]=='#'))//Si el espacio superior es un espacio
{//Si detecta un inicio o fin de teleportador pasa;
 if(GetAsyncKeyState(0x28))//Si se presiona la flecha superior
{
    Sleep(lapso);
    f2++;
    y++;    //Aumentamos el valor de la coordenada x y subimos un espacio
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}

//Detección de bloques

if(lab[b+f2][a+1+f1]==n)//Si la casilla derecha es un bloque
{
     if(GetAsyncKeyState(0x27))//Si se presiona la flecha superior
{//No se modifica nada
    Sleep(lapso);
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}
if((lab[b+f2][f1+a-1]==n))//Si el elemento de la izquierda es un bloque
{
 if(GetAsyncKeyState(0x25))//Si presionamos la flecha de la izquierda
{
    Sleep(lapso);
    system("cls");//No se cambia nada
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}
if((lab[f2][a+f1]==n))//Si el espacio de abajo es un bloque
{
 if(GetAsyncKeyState(0x26))//Si se presiona la flecha de abajo
{

    //No se cambia nada
    Sleep(lapso);
    system("cls");
construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}
if((lab[b+1+f2][a+f1]==n))//Si el espacio de arriba es un bloque
{
 if(GetAsyncKeyState(0x28))//Si se presiona la flecha de arriba
{
    Sleep(lapso);
    system("cls");//No se actualiza nada
construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
}
if(GetAsyncKeyState(0x09))//Si se presiona el tabulador;
{
    f2=0;//Al reiniciar recreamos la semilla inicial con generación en el primer espacio.
    f1=0;
    x=b;
    y=a;//Queremos los bloqueos renovados para evitar futuros colapsos:
    b1[0].identificador='B';//Volvemos a cambiar los muros por bloqueos;
    b1[1].identificador='B';
    b1[2].identificador='B';
    b1[3].identificador='B';
reiniciar(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,T1,T2,B1,si,sj,maze,lab);//Iniciar reinicio;
}
if((x==t1.x) && (y==t1.y) && (paso==1))
{
    paso=0;
    x=t2.x; // Si alcanza la posicion del teletransportador 1 se va al teletransportador 2.
    y=t2.y;
    f1=t2.x-a;
    f2=t2.y-b;
    Sleep(1000);
    system("cls");//Cambiamos al punto T;
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
if((x==t2.x) && (y==t2.y) && (paso==1))
{
    paso=0;
    x=t1.x; // Si alcanza la posicion del teletransportador 2 se va al teletransportador 1.
    y=t1.y;
    f1=t1.x-a;
    f2=t1.y-b;
    Sleep(1000);
    system("cls");//Cambiamos al punto T;
    construir(a,b,f1,f2,anch,alt,m,n,p,x,y,t1,t2,b1,si,sj,maze,lab);
}
if(((x!=t1.x) && (y!=t1.y)) || ((x!=t2.x) && (y!=t2.y)))
{
    paso=1; //Permitir el paso si se está fuera de los teleportadores.
}
if((x==b1[0].x) && (y==b1[0].y))
{
    b1[0].identificador=n; //Crear muro al pasar por el bloqueo. B1
}
if((x==b1[1].x) && (y==b1[1].y))
{
    b1[1].identificador=n;
}//B2
if((x==b1[2].x) && (y==b1[2].y))
{
    b1[2].identificador=n;
}//B3
if((x==b1[3].x) && (y==b1[3].y))
{
    b1[3].identificador=n;
}//B4
if(si==x && sj==y)
{
    printf("\x1b[2J");
    printf("Felicidades, has ganado!");
    Sleep(500);
    system("cls");
    printf(" ");
    Sleep(500);
}
    }
return 0;
}

void recursion(int r, int c, int anch, int alt, int maze[N][N], char n)
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
        recursion(r - 2, c, anch, alt, maze, n);
       }
       break;

    case 2: //Derecha
       if (c + 2 >= anch - 1)  // si dos celdas a la derecha est� ocupado o no
        continue;
       else if (maze[r][c + 2] != 0){ //ocupa las dos de la derecha
        maze[r][c + 2] = 0;
        maze[r][c + 1] = 0;
        recursion(r, c + 2, anch, alt, maze, n);
       }
       break;

    case 3: //Abajo
       if (r + 2 >= alt - 1)  // si dos celdas m�s abajo est� ocupado o no
        continue;
       else if (maze[r + 2][c] != 0){ //ocupa las dos de abajo
        maze[r + 2][c] = 0;
        maze[r + 1][c] = 0;
        recursion(r + 2, c, anch, alt, maze, n);
       }
       break;

    case 4: //Izquierda
       if (c - 2 <= 0)  // si dos celdas a la izquierda est� ocupado o no
        continue;
       else if (maze[r][c - 2] != 0){ //ocupa las dos de la izquierda
        maze[r][c - 2] = 0;
        maze[r][c - 1] = 0;
        recursion(r, c - 2, anch, alt, maze, n);
       }
       break;

    }
 }

}
void construir(int a,int b, int f1, int f2, int anch, int alt, char m, char n, char p,int x,int y,teleporter t1,teleporter t2,bloqueo b1[],int si,int sj, int maze[N][N], char lab[N][N])
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
lab[t1.y][t1.x]=t1.identificador;//Se construye el laberinto con el inicio del teletransportador;
lab[t2.y][t2.x]=t2.identificador;//Se construye el laberinto con el final del teletransportador;
lab[b1[0].y][b1[0].x]=b1[0].identificador;//Construir laberinto con vector de bloqueos;
lab[b1[1].y][b1[1].x]=b1[1].identificador;
lab[b1[2].y][b1[2].x]=b1[2].identificador;
lab[b1[3].y][b1[3].x]=b1[3].identificador;
lab[si][sj]='#';
}
}
        for(i = y-2; i < y+11; i++) {
for(j = x-2; j < x+11; j++)
{
printf(" %c", lab[i][j]);
}
printf("\n");
}
printf("x:%d y:%d\n",x,y);//replicamos el laberinto y cambiamos la posicion de la cruceta y las coordenadas
printf("Presione el tabulador para reiniciar.\n");
printf("%d,%d",si,sj);
}

void reiniciar(int a,int b, int f1, int f2, int anch, int alt, char m, char n, char p,int x,int y,teleporter t1,teleporter t2,bloqueo b1[],int T1,int T2,int B1[],int si,int sj, int maze[N][N], char lab[N][N])
{
    int i,j,esp=0;
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
        if(esp==T1)//Si se alcanza el espacio aleatorio 1 se pone el inicio del teletransportador;
        {
         lab[i][j]=t1.identificador;
         t1.y=i;
         t1.x=j;
        }
        if(esp==T2)//Si se alcanza el espacio aleatorio 2 se pone el final del teletransportador;
        {
         lab[i][j]=t2.identificador;
         t2.y=i;
         t2.x=j;
        }
        if(esp==B1[0])//Generar B1 en espacio;
        {
         lab[i][j]=b1[0].identificador;
         b1[0].y=i;
         b1[0].x=j;
        }
        if(esp==B1[1])//Generar B2 en espacio;
        {
         lab[i][j]=b1[1].identificador;
         b1[1].y=i;
         b1[1].x=j;
        }
        if(esp==B1[2])//Generar B3 en espacio;
        {
         lab[i][j]=b1[2].identificador;
         b1[2].y=i;
         b1[2].x=j;
        }
        if(esp==B1[3])//Generar B4 en espacio;
        {
         lab[i][j]=b1[3].identificador;
         b1[3].y=i;
         b1[3].x=j;
        }
        lab[si][sj]='#';
    }
printf(" %c", lab[i][j]);
}
printf("\n");//Regeneramos el laberinto
}
printf("x:%d y:%d\n",x,y);//Coordenadas
printf("Presione el tabulador para reiniciar");//Mensaje de reinicio

}

