#include "Game.h"

void InitGame()
{
    //Declaración de variables
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 640;

    int maze[N][N];
    Token Teleport[2];
       Token Sol[2];
         Token Luna[2];
            Token Final;

    float x_pos= 1;
    float y_pos = 1;

    int intento=1;       //Número de veces que se repite el juego (después lo haremos un contador cuando lo enlazemos al menú)
    int minutos=0,segundos=0,puntuacion;
    unsigned int tiempo;

    FILE *tiempoempleado;   //Fichero para las puntuaciones (tiempo que tarda el jugador en completar el laberinto)


    SDL_Window* ventana = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    SDL_Surface* screenSurface = NULL;
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(ventana, -1, render_flags);
    SDL_Surface *Pers;

    Pers = SDL_LoadBMP("MovRight.bmp");
    SDL_Texture*texd = SDL_CreateTextureFromSurface(rend, Pers);
    SDL_FreeSurface(Pers);

    Pers = SDL_LoadBMP("MovLeft.bmp");
    SDL_Texture*texi = SDL_CreateTextureFromSurface(rend, Pers);
    SDL_FreeSurface(Pers);

    Pers = SDL_LoadBMP("MovUp.bmp");
    SDL_Texture*texar = SDL_CreateTextureFromSurface(rend, Pers);
    SDL_FreeSurface(Pers);

    Pers = SDL_LoadBMP("MovDown.bmp");
    SDL_Texture*texab = SDL_CreateTextureFromSurface(rend, Pers);
    SDL_FreeSurface(Pers);

    Pers = SDL_LoadBMP("Idle.bmp");
    SDL_Texture*texid = SDL_CreateTextureFromSurface(rend, Pers);
    SDL_FreeSurface(Pers);

    SDL_Rect dest = {0, 0, 32*80, 32*60}; //Laberinto
    SDL_Rect personaje = {32+46, 32+80, 70, 70}; //Explorador

    _Bool quit = 0;
    _Bool izq=0;
    _Bool dcha=0;
    _Bool arriba=0;
    _Bool abajo=0;

    int inversion=0;
    int coordx=1,coordy=1;
    int teletransportar=1;


    //Inicio de SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {

        //El SDL comienza verificando que la ventana, el renderer y la textura se han inicializado correctamente
        printf( "SDL no pudo iniciarse. SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        if( ventana == NULL )
        {
            printf( "No se pudo crear la ventana emergente SDL_Error: %s\n", SDL_GetError() );
        }
        else
        {
            if (!rend)
            {
                printf("Error al crear el render: %s\n",SDL_GetError());
                SDL_DestroyWindow(ventana);
                SDL_Quit;
                return;
            }
            if (!texd || !texi || !texab || !texid || !texar)
            {
                printf("Error al crear las textura: %s\n",SDL_GetError());
                SDL_DestroyRenderer(rend);
                SDL_DestroyWindow(ventana);
                SDL_Quit();
                return;
            }

    screenSurface = SDL_GetWindowSurface( ventana );

    InitMaze(ventana, screenSurface, rend, maze,coordx,coordy, Luna, Sol, Teleport, &Final);
    SDL_Texture* texmaze = SDL_CreateTextureFromSurface(rend, screenSurface);


            while (!quit)
            {
            SDL_Event event;

//Funcionamiento Luna
              TLuna(coordx, coordy, Luna, &inversion);
//Funcionamiento Sol
              TSol(coordx, coordy, Sol, &inversion);

                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                        quit=1;
//Funcionamiento de salir
                    if(salir(coordx,coordy, Final)==1){
                        SDL_DestroyWindow(ventana);
                    }
//Funcionamiento del TP
                    if(Teleport[0].x==coordx && Teleport[0].y==coordy && teletransportar==1)
                    {
                        coordx=Teleport[1].x;
                        coordy=Teleport[1].y;
                        x_pos=x_pos + 76*(Teleport[0].x-Teleport[1].x);
                        y_pos=y_pos + 96*(Teleport[0].y-Teleport[1].y);
                        teletransportar=0;
                    }
                    if((coordx!=Teleport[0].x && coordy!=Teleport[0].y)&&(coordx!=Teleport[1].x && coordy!=Teleport[1].y))
                    {
                        teletransportar=1;
                    }
                    if(Teleport[1].x==coordx && Teleport[1].y==coordy && teletransportar==1)
                    {
                        coordx=Teleport[0].x;
                        coordy=Teleport[0].y;
                        x_pos=x_pos+76*(Teleport[1].x-Teleport[0].x);
                        y_pos=y_pos+96*(Teleport[1].y-Teleport[0].y);
                        teletransportar=0;
                    }
                    if((coordx!=Teleport[0].x && coordy!=Teleport[0].y)&&(coordx!=Teleport[1].x && coordy!=Teleport[1].y))
                    {
                        teletransportar=1;
                    }
//Movimiento
                    if (event.type == SDL_KEYDOWN) //Cuando estemos pulsando la tecla
                    {

                        if(inversion==0)
                        {
                            salir(coordx,coordy, Final);

                            if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
                            {
                                if(maze[coordx -1][coordy]==0 || maze[coordx - 1][coordy] == 2 || maze[coordx -1][coordy]==3 || maze[coordx - 1][coordy] == 4)
                                {
                                    x_pos=x_pos+76;
                                    coordx--;
                                    dcha = 0, izq = 1, arriba = 0, abajo = 0;
                                }
                                if(maze[coordx-1][coordy]==1)
                                {
                                    x_pos=x_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)
                            {
                                if(maze[coordx + 1][coordy]==0 || maze[coordx + 1][coordy] == 2 || maze[coordx + 1][coordy]==3 || maze[coordx + 1][coordy] == 4 )
                                {
                                    x_pos=x_pos-76;
                                    coordx++;
                                    dcha = 1, izq = 0, arriba = 0, abajo = 0;
                                }
                                if(maze[coordx+1][coordy]==1)
                                {
                                    x_pos=x_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_UP)
                            {
                                if(maze[coordx][coordy-1]==0 || maze[coordx][coordy-1] == 2 || maze[coordx][coordy-1]==3 || maze[coordx][coordy-1] == 4 )
                                {
                                    y_pos=y_pos+96;
                                    coordy--;
                                    dcha = 0, izq = 0, arriba = 1, abajo = 0;
                                }
                                if(maze[coordx][coordy-1]==1 )
                                {
                                    y_pos=y_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
                            {
                                if(maze[coordx][coordy+1]==0 || maze[coordx][coordy+1] == 2 || maze[coordx][coordy+1]==3 || maze[coordx][coordy+1] == 4  && coordy+1 !=20)
                                {
                                    y_pos=y_pos-96;
                                    coordy++;
                                    dcha = 0, izq = 0, arriba = 0, abajo = 1;
                                }
                                if(maze[coordx][coordy+1]==1 || coordy+1 ==20)
                                {
                                    y_pos=y_pos;
                                }
                            }
                        }
//Movimiento invertido
                        if(inversion==1)
                        {
                            salir(coordx,coordy, Final);

                            if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)
                            {
                                if(maze[coordx][coordy+1]==0 || maze[coordx][coordy+1] == 2 || maze[coordx][coordy+1]==3 || maze[coordx][coordy+1] == 4 || coordy+1==20)
                                {
                                    y_pos=y_pos-96;
                                    coordy++;
                                    dcha = 0, izq = 0, arriba = 0, abajo = 1;
                                }
                                if(maze[coordx][coordy+1]==1 && coordy+1!=20)
                                {
                                    y_pos=y_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
                            {
                                 if(maze[coordx][coordy-1]==0 || maze[coordx][coordy-1] == 2 || maze[coordx][coordy-1]==3 || maze[coordx][coordy-1] == 4 || coordy+1==20)
                                {
                                    y_pos=y_pos+96;
                                    coordy--;
                                    dcha = 0, izq = 0, arriba = 1, abajo = 0;
                                }
                                if(maze[coordx][coordy-1]==1 && coordy+1!=20 )
                                {
                                    y_pos=y_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
                            {
                                 if(maze[coordx + 1][coordy]==0 || maze[coordx + 1][coordy] == 2 || maze[coordx + 1][coordy]==3 || maze[coordx + 1][coordy] == 4)
                                {
                                    x_pos=x_pos-76;
                                    coordx++;
                                    dcha = 1, izq = 0, arriba = 0, abajo = 0;
                                }
                                if(maze[coordx+1][coordy]==1)
                                {
                                    x_pos=x_pos;
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_UP)
                            {
                               if(maze[coordx -1][coordy]==0 || maze[coordx - 1][coordy] == 2 || maze[coordx -1][coordy]==3 || maze[coordx - 1][coordy] == 4)
                                {
                                    x_pos=x_pos+76;
                                    coordx--;
                                    dcha = 0, izq = 1, arriba = 0, abajo = 0;
                                }
                                if(maze[coordx-1][coordy]==1)
                                {
                                    x_pos=x_pos;
                                }
                            }
                        }
                    }
                }
                dest.y = y_pos;
                dest.x = x_pos;

//animación
                Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
                Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
                SDL_Rect srcrect = {sprite*32, 0, 32, 32};

//Laberinto pot pantalla
                if(!quit)
                {
                    SDL_RenderClear(rend);
                    SDL_RenderCopy(rend,texmaze, NULL, &dest);
                    SDL_RenderPresent(rend);
                }


                // SDL_RenderClear(rend);
                SDL_RenderCopy(rend, texid, &srcrect, &personaje);
                SDL_RenderPresent(rend);

                if (dcha && !izq)
                {
                    //SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, texd, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (izq && !dcha)
                {
                    // SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, texi, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (abajo && !arriba)
                {
                    //  SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, texar, &srcrect, &personaje);
                    SDL_RenderPresent(rend);

                }
                if (arriba && !abajo)
                {
                    // SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, texab, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }


                 tiempo = SDL_GetTicks();   //Cuenta el tiempo desde que se inicia el juego (devuelve el valor en milisegundos)


                SDL_Delay(1000/60);
            }
            //Se acaba el juego, resultados:
            //En el menú pondremos una sección con todos los resultados donde abrimos el fichero y lo mostramos en forma de lectura.


            tiempo/=1000;         //Pasamos el tiempo a segundos y a minutos
            minutos=tiempo/60;
            segundos=abs(minutos*60-tiempo);


            //Hacemos las puntuaciones
            if (minutos==0 && segundos>0 && segundos<20)
                puntuacion=30;
            else if (minutos==0 && segundos>=20 && segundos<40)
                puntuacion=25;
            else if (minutos==0 && segundos>=40 && segundos<60)
                puntuacion=20;
            else if (minutos==1 && segundos>=0 && segundos<20)
                puntuacion=15;
            else if (minutos==1 && segundos>=20 && segundos<40)
                puntuacion=10;
            else if (minutos==1 && segundos>=40 && segundos<60)
                puntuacion=5;
            else
                puntuacion=0;


            //Gestionamos el fichero
            tiempoempleado = fopen("Puntuación.txt", "w");

                if (tiempoempleado == NULL)     // Si el resultado es NULL se muestra un mensaje de error
                    {
                    printf("Error al abrir el fichero.\n");
                    return;
                    }

                else    // Si ha funcionado, comienza la escritura
                    {
                        fprintf(tiempoempleado,"*****Resultados del intento número %i*****\n",intento);
                        fprintf(tiempoempleado,"%d minuto(s) y %d segundos --------> %d puntos\n",minutos,segundos,puntuacion);
                    }
                fclose(tiempoempleado); // Cerramos fichero



            //Se destruye todo y se sale de SDL
            SDL_DestroyTexture(texd);
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(ventana);
            SDL_Quit();
        }
    }
    return 0;
}




void InitMaze(SDL_Window* window, SDL_Surface* screenSurface, SDL_Renderer* rend, int maze[N][N],int coordx,int coordy,Token Luna[2], Token Sol[2], Token Teleport[2], Token *Final)
{

    int t = 0;
     int l = 0;
      int s = 0;

    int alt = 20;
    int anch = 20;
    int i,j, xo, yo;
    int randw;

    //srand(time(NULL));

    //Llenamos una matriz de 1. Esta matriz se utilizará posteriormente para hacer el laberinto
    for (i = 0; i < alt; i++)
    {
        for(j = 0; j < anch; j++)
            maze[i][j] = 1;
    }
    xo = 1;
    yo = 1;
//Posición inicial
    maze[xo][yo] = 0;
//Hacemos el laberinto
    recursion(xo, yo, anch, alt, maze);
    InitTokens(maze);
    SDL_Surface *camino = SDL_LoadBMP("Path.bmp"); //Cargamos tanto el sprite del camino como el del muro.

    SDL_Surface *muroG = SDL_LoadBMP("GenWall.bmp");
    SDL_Surface *muroB = SDL_LoadBMP("BasicWall.bmp");
    SDL_Surface *muroD = SDL_LoadBMP("DogWall.bmp");
    SDL_Surface *muroX = SDL_LoadBMP("XatuWall.bmp");
    SDL_Surface *muroF = SDL_LoadBMP("FWall.bmp");

    SDL_Surface *Inicio = SDL_LoadBMP("Inicio.bmp");
    SDL_Surface *Salida = SDL_LoadBMP("End.bmp");

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
        }
    }

    //La entrada siempre va a estar en la casilla 1,1
                pos.x = 32;
                pos.y = 32;
                SDL_BlitSurface(Inicio,0,screenSurface,&pos);

//La Salida estará en la última casilla
                for (i = 0; i < alt; i++){
                    for (j = 0; j < anch; j++){
                        if(maze[i][j] == 0){
                            Final->x = i;
                            Final->y = j;
                        }
                    }
                }


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


int salir(int coordx,int coordy, Token Final)
{
if((coordx==Final.x)&&(coordy==Final.y))
{
    return 1;
}
else
{
    return 0;
}
}

void TLuna(int coordx, int coordy, Token Luna[2], int *inversion)
{
    if(((Luna[0].x==coordx)&&(Luna[0].y==coordy))||((Luna[1].x==coordx)&&(Luna[1].y==coordy)))
                    *inversion=1;
}

void TSol(int coordx, int coordy, Token Sol[2], int *inversion)
{
      if(((Sol[0].x==coordx)&&(Sol[0].y==coordy))||((Sol[1].x==coordx)&&(Sol[1].y==coordy)))
                    *inversion=0;

}
