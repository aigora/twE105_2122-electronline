#include "Game.h"
#include "Tokens.h"

void InitGame(int *stage,int pararaudio)//Devuelve el stage del menu y la booleana de parar audio
{
    //Declaración de variables
    const int SCREEN_WIDTH = 1080;
    const int SCREEN_HEIGHT = 720;
 int i, j;
    int alt = 21;
    int anch = 21;
    int xo, yo;


    int maze[N][N];
    Token Teleport[2];
    Token Sol[2];
    Token Luna[2];
    Token Final;
    Token Idolo;

  for (i = 0; i < alt; i++)
    {
        for(j = 0; j < anch; j++)
            maze[i][j] = 1;
    }

do{
    xo = 1 + rand()%19;//Coordenadas aleatorias de 1 a 20 de generacion inicial x
   yo = 1 + rand()%19;//Coordenadas aleatorias de 1 a 20 de generacion inicial y
} while(xo % 2 != 1 || yo % 2 != 1);

 float x_pos  = 405, y_pos = 224 ;//Posiciones iniciales del personaje
 x_pos -= 76*(xo - 1);//Se inicializa la coordendad x del personaje segun la generacion aleatoria dada
 y_pos -= 85*(yo - 1);//Se inicializa la coordendad y del personaje segun la generacion aleatoria dada

    int intento=1;       //Número de veces que se repite el juego (después lo haremos un contador cuando lo enlazemos al menú)
    int minutos=0,segundos=0,puntuacion;
    unsigned int tiempo;

    FILE *tiempoempleado;   //Fichero para las puntuaciones (tiempo que tarda el jugador en completar el laberinto)

    SDL_AudioSpec wavSpec;  //Variable para almacenar un .wav
    Uint32 wavLength;       //Longitud de onda
    Uint8 *wavBuffer;       //Buffer para el audio
    SDL_LoadWAV("Musica2.wav", &wavSpec, &wavBuffer, &wavLength);
    //Ponemos la musica deseada en la funcion y le damos las direcciones de memoria de la variable wav, el bufffer y la longitud de onda


    SDL_Window* ventana = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    SDL_Surface* screenSurface = NULL;
      SDL_Surface* screenSurface2 = NULL;

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
    SDL_Rect personaje = {960/2, 640/2, 70, 70}; //Explorador

    _Bool quit = 0;
    _Bool izq=0;
    _Bool dcha=0;
    _Bool arriba=0;
    _Bool abajo=0;

    int robar = 0;//Booleano de salir desactivado

    int inversion=0;//Cambio de controles desactivado
    int coordx=xo,coordy=yo;//Coordenadas del personaje inicializadas en la generacion del laberinto
    int teletransportar=1;//Variable de teletransportar activada

    recursion(xo, yo, anch, alt, maze);
    InitTokens(maze);
    maze[xo][yo] = 9;

    //Se inicia la música
    SDL_Init(SDL_INIT_AUDIO);//Iniciamos el audio.
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    //Hacemos una variable de tipo DeviceId y la damos los datos que requiere
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
    InitMaze(ventana, screenSurface, rend, maze,coordx,coordy, Luna, Sol, Teleport, &Final, alt, anch, &Idolo);
        SDL_Texture* texmaze = SDL_CreateTextureFromSurface(rend, screenSurface);

        screenSurface2 = SDL_GetWindowSurface( ventana );
  InitMaze2(ventana, screenSurface2, rend, maze,coordx,coordy, Luna, Sol, Teleport, &Final, alt, anch, &Idolo);
        SDL_Texture* texmaze2 = SDL_CreateTextureFromSurface(rend, screenSurface2);




            int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
            //Creamos una variable entera que detecta que el audio funcione

            while (!quit)
            {
                if(pararaudio==0)//Si se para el audio el audio del laberinto se pausa
                    {
                        SDL_PauseAudioDevice(deviceId,1);
                    }
                    else//Si no so se pausa
                    {
                        SDL_PauseAudioDevice(deviceId,0);
                    }
            SDL_Event event;

            //Funcionamiento Luna
            TLuna(coordx, coordy, Luna, &inversion);
            //Funcionamiento Sol
              TSol(coordx, coordy, Sol, &inversion);
//ROBAR
                if(((Idolo.x==coordx)&&(Idolo.y==coordy)))//Si se toca el idolo se activa la opcion de salir
                {
                    robar=1;//booleano de salir activado
                }

                while (SDL_PollEvent(&event))//Cara de evento
                {
                    if (event.type == SDL_QUIT)//Si se pulsa la cruceta se sale del laberinto
                        quit=1;
                    //Funcionamiento de salir
                    if(salir(coordx,coordy, Final, robar))//Si se pasa por la salida y robar esta activada se acaba el laberinto
                    {

                        ////////////////////////////////////////////////////////

                        //Se acaba el juego, resultados:
                        //En el menú pondremos una sección el resultado del intento donde abrimos el fichero y lo mostramos en forma de lectura.

                        tiempo/=1000;         //Pasamos el tiempo a segundos y a minutos
                        minutos=tiempo/60;
                        segundos=abs(minutos*60-tiempo);

                        //Hacemos las puntuaciones
                        puntuacion=puntuaciones(minutos,segundos);

                        //Gestionamos el fichero
                        tiempoempleado=fopen("Puntuacion.txt","w");

                        if (tiempoempleado == NULL)     // Si el resultado es NULL se muestra un mensaje de error
                            {
                                printf("Error al abrir el fichero.\n");
                                return -1;
                            }

                        //Comienza la escritura (minutos, segundos y puntuación equivalente).

                        fprintf(tiempoempleado,"%d,%d,%d\n",minutos,segundos,puntuacion);
                        fclose(tiempoempleado); // Cerramos fichero

                        ///////////////////////////////////////////////////////



                        //Para que no se colapse la música del juego con la del laberinto
                        if(pararaudio==1)//Si se para el audio
                            {
                                *stage = 1;//Se cambia el estado a 1
                                SDL_PauseAudioDevice(deviceId,1);//Se para el audio del laberinto
                                SDL_DestroyWindow(ventana);//Se destruye la ventana
                            }
                            else
                            {
                                *stage = 8;//Se para a estado 8
                                SDL_PauseAudioDevice(deviceId,1);//Se para el audio del laberinto
                                SDL_DestroyWindow(ventana);//Se destruye la ventana
                            }


                            //*stage=15;  //Se muestran las puntuaciones(desde el menú).
                            *stage=14;  //Imagen de fin del laberinto.
                            return;     //Para poder volver a iniciar el laberinto.

                    }
                    //Funcionamiento del TP
                    if(Teleport[0].x==coordx && Teleport[0].y==coordy && teletransportar==1)//Si se pasa por el teletransportador 1
                    {
                        coordx=Teleport[1].x;//cambio de coordenada x a la del otro teleportador
                        coordy=Teleport[1].y;//cambio de coordenada y a la del otro teleportador
                        x_pos=x_pos + 76*(Teleport[0].x-Teleport[1].x);//Movimiento del personaje al teletransportador opuesto(x)
                        y_pos=y_pos + 85*(Teleport[0].y-Teleport[1].y);//Movimiento del personaje al teletransportador opuesto(y)
                        teletransportar=0;//Se desactiva la teletransportacion
                    }
                    if((coordx!=Teleport[0].x && coordy!=Teleport[0].y)&&(coordx!=Teleport[1].x && coordy!=Teleport[1].y))
                    {//Si la coordenada x e y del personaje son distintas de las del teletransportador 1
                        teletransportar=1;//Teletransporte activado
                    }
                    if(Teleport[1].x==coordx && Teleport[1].y==coordy && teletransportar==1)//Si se pasa por el teletransportador 2
                    {
                        coordx=Teleport[0].x;//cambio de coordenada x a la del otro teleportador
                        coordy=Teleport[0].y;//cambio de coordenada y a la del otro teleportador
                        x_pos=x_pos+76*(Teleport[1].x-Teleport[0].x);//Movimiento del personaje al teletransportador opuesto(x)
                        y_pos=y_pos+85*(Teleport[1].y-Teleport[0].y);//Movimiento del personaje al teletransportador opuesto(y)
                        teletransportar=0;//Se desactiva la teletransportacion
                    }
                    if((coordx!=Teleport[0].x && coordy!=Teleport[0].y)&&(coordx!=Teleport[1].x && coordy!=Teleport[1].y))
                    {//Si la coordenada x e y del personaje son distintas de las del teletransportador 2
                        teletransportar=1;//Teletransporte activado
                    }

                    //Movimiento
                    if (event.type == SDL_KEYDOWN) //Cuando estemos pulsando la tecla
                    {

                        if(inversion==0)//Si no se han cambiado los controles
                        {
                            salir(coordx,coordy, Final, robar);//Se llama a la funcion salir

                            if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)//Si se presiona la tecla izquierda
                            {
                                if(maze[coordx -1][coordy]==0 || maze[coordx - 1][coordy] == 2 || maze[coordx -1][coordy]==3 || maze[coordx - 1][coordy] == 4|| maze[coordx - 1][coordy] == 9|| maze[coordx - 1][coordy] == 5)
                                {//Si la casilla adyacente a la izquierda es un camino o token
                                    x_pos=x_pos+76;//Se cambia la posicion del personaje
                                    coordx--;//Disminuye la coordenada x
                                    dcha = 0, izq = 1, arriba = 0, abajo = 0;//variable izquierda activada
                                }
                                if(maze[coordx-1][coordy]==1)
                                {//Si la casilla adyacente es un muro
                                    x_pos=x_pos;//Posicion fija
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)//Si se presiona la tecla derecha
                            {
                                if(maze[coordx + 1][coordy]==0 || maze[coordx + 1][coordy] == 2 || maze[coordx + 1][coordy]==3 || maze[coordx + 1][coordy] == 4 || maze[coordx + 1][coordy] == 9 || maze[coordx + 1][coordy] == 5)
                                {//Si la casilla adyacente a la derecha es un camino o token
                                    x_pos=x_pos-76;//Se cambia la posicion del personaje
                                    coordx++;//Disminuye la coordenada x
                                    dcha = 1, izq = 0, arriba = 0, abajo = 0;//variable derecha activada
                                }
                                if(maze[coordx+1][coordy]==1)
                                {//Si la casilla adyacente es un muro
                                    x_pos=x_pos;//posicion fija
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_UP)//Si se presiona la tecla arriba
                            {
                                if(maze[coordx][coordy-1]==0 || maze[coordx][coordy-1] == 2 || maze[coordx][coordy-1]==3 || maze[coordx][coordy-1] == 4 || maze[coordx][coordy - 1] == 9 || maze[coordx][coordy - 1] == 5 )
                                {//Si la casilla adyacente hacia arriba es un camino o token
                                    y_pos=y_pos+85;//Se cambia la posicion del personaje
                                    coordy--;//Aumenta la coordenada y
                                    dcha = 0, izq = 0, arriba = 1, abajo = 0;//variable arriba activada
                                }
                                if(maze[coordx][coordy-1]==1 )
                                {//Si la casilla adyacente es un muro
                                    y_pos=y_pos;//Posicion fija
                                }
                            }

                            if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)//Si se presiona la tecla abajo
                            {//Si la casilla adyacente hacia abajo es un camino o token
                                if(maze[coordx][coordy+1]==0 || maze[coordx][coordy+1] == 2 || maze[coordx][coordy+1]==3 || maze[coordx][coordy+1] == 4 || maze[coordx][coordy + 1] == 9 || maze[coordx][coordy + 1] == 5 && coordy+1 !=21)
                                {//Si la casilla adyacente hacia abajo es un camino o token
                                    y_pos=y_pos-85;//Se cambia la posicion del personaje
                                    coordy++;//Aumenta la coordenada y
                                    dcha = 0, izq = 0, arriba = 0, abajo = 1;//variable abajo activada
                                }
                                if(maze[coordx][coordy+1]==1 || coordy+1 ==20)
                                {//Si la casilla adyacente es un muro
                                    y_pos=y_pos;//Posicion fija
                                }
                            }
                        }
                        //Movimiento invertido
                        if(inversion==1)//Si se cambian los controles
                        {//Llamamos a la funcion salida
                            salir(coordx,coordy, Final, robar);
//Si de presiona la tecla derecha
                            if(event.key.keysym.scancode==SDL_SCANCODE_RIGHT)
                            {//Hacia abajo
                                if(maze[coordx][coordy+1]==0 || maze[coordx][coordy+1] == 2 || maze[coordx][coordy+1]==3 || maze[coordx][coordy+1] == 4 || maze[coordx][coordy + 1] == 9 || maze[coordx][coordy + 1] == 5|| coordy+1==21)
                                {//Si la casilla adyacente hacia abajo es un token o camino
                                    y_pos=y_pos-85;//varia la posicion
                                    coordy++;//Cambian las coordenadas
                                    dcha = 0, izq = 0, arriba = 0, abajo = 1;//Se activa la variable abajo
                                }
                                if(maze[coordx][coordy+1]==1 && coordy+1!=20)
                                {//Si la casilla adyacente es un muro
                                    y_pos=y_pos;//Posicion fija
                                }
                            }
//Si de presiona la tecla izquierda
                            if(event.key.keysym.scancode==SDL_SCANCODE_LEFT)
                            {
                                 if(maze[coordx][coordy-1]==0 || maze[coordx][coordy-1] == 2 || maze[coordx][coordy-1]==3 || maze[coordx][coordy-1] == 4 || maze[coordx][coordy - 1] == 9 || maze[coordx][coordy - 1] == 5|| coordy+1==21)
                                {//Si la casilla adyacente hacia arriba es un token o camino
                                    y_pos=y_pos+85;//Varia la posicion
                                    coordy--;//Varian las coordenadas
                                    dcha = 0, izq = 0, arriba = 1, abajo = 0;//variable arrriva activada
                                }
                                if(maze[coordx][coordy-1]==1 && coordy+1!=20 )
                                {//Si la casilla adyacente es un muro
                                    y_pos=y_pos;//Coordenadas fijas
                                }
                            }
//Si se presiona la tecla abajo
                            if(event.key.keysym.scancode==SDL_SCANCODE_DOWN)
                            {//Si la casilla adyacente hacia la derecha es un token o camino
                                 if(maze[coordx + 1][coordy]==0 || maze[coordx + 1][coordy] == 2 || maze[coordx + 1][coordy]==3 || maze[coordx + 1][coordy] == 4 || maze[coordx + 1][coordy] == 9 || maze[coordx + 1][coordy] == 5)
                                {//Si la casilla adyacente es un token o camino
                                    x_pos=x_pos-76;//Varia la posicion del personaje
                                    coordx++;//Varian las coordenadas
                                    dcha = 1, izq = 0, arriba = 0, abajo = 0;//Variable derecha activada
                                }
                                if(maze[coordx+1][coordy]==1)
                                {//Si la casilla adyacente es un muro
                                    x_pos=x_pos;//Posicion fija
                                }
                            }
//Si se presiona la tecla arriba
                            if(event.key.keysym.scancode==SDL_SCANCODE_UP)
                            {
                               if(maze[coordx -1][coordy]==0 || maze[coordx - 1][coordy] == 2 || maze[coordx -1][coordy]==3 || maze[coordx - 1][coordy] == 4 || maze[coordx - 1][coordy] == 9 || maze[coordx - 1][coordy] == 5)
                                {//Si la casilla adyacente hacia la izquierda es un token o camino
                                    x_pos=x_pos+76;//Varia la posicion
                                    coordx--;//Varian las coordenadas
                                    dcha = 0, izq = 1, arriba = 0, abajo = 0;//Variable izquierda activada
                                }
                                if(maze[coordx-1][coordy]==1)
                                {//Si la casilla adyacente es un muro
                                    x_pos=x_pos;//Posicion fija
                                }
                            }
                        }
                    }
                }
                dest.y = y_pos;
                dest.x = x_pos;

                //Animación
                Uint32 ticks = SDL_GetTicks(); //GetTicks nos da el numero de milisegundos desde que el programa ha empezado
                Uint32 sprite = (ticks/50) % 6; //Los dividimos por el numero de sprites de nuestra animación
                SDL_Rect srcrect = {sprite*32, 0, 32, 32};

                //Laberinto pot pantalla

                if (robar == 0){
                     SDL_RenderClear(rend);
                    SDL_RenderCopy(rend,texmaze, NULL, &dest);
                    SDL_RenderPresent(rend);

                }
                    if (robar == 1){
                     SDL_RenderClear(rend);
                    SDL_RenderCopy(rend,texmaze2, NULL, &dest);
                    SDL_RenderPresent(rend);

                    }

                SDL_RenderCopy(rend, texid, &srcrect, &personaje);
                SDL_RenderPresent(rend);

                if (dcha && !izq)
                {
                    SDL_RenderCopy(rend, texd, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (izq && !dcha)
                {
                    SDL_RenderCopy(rend, texi, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }
                if (abajo && !arriba)
                {
                    SDL_RenderCopy(rend, texar, &srcrect, &personaje);
                    SDL_RenderPresent(rend);

                }
                if (arriba && !abajo)
                {
                    SDL_RenderCopy(rend, texab, &srcrect, &personaje);
                    SDL_RenderPresent(rend);
                }


                 tiempo = SDL_GetTicks();   //Cuenta el tiempo desde que se inicia el juego (devuelve el valor en milisegundos) (para las puntuaciones)


                SDL_Delay(1000/60);
            }


            //Se destruye todo y se sale de SDL
            SDL_DestroyTexture(texd);
            SDL_DestroyRenderer(rend);
            SDL_DestroyWindow(ventana);
            SDL_Quit();
        }
    }
    return 0;
}






//Función para la salida
int salir(int coordx,int coordy, Token Final, int robar)//Se reciben las coordenadas del personaje y el booleano robar
{
if((coordx==Final.x)&&(coordy==Final.y)&&(robar == 1))
{//En caso de coincidir con las coordenadas de la salida y que robar sea verdadero se permite la salida
    return 1;
}
else
{//En caso de que falte algun requisito el laberinto continua
    return 0;
}
}



int puntuaciones(int minutos, int segundos)
{
    int puntuacion;
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
    return puntuacion;
}

