#include <SDL.h>
#include <stdio.h>
#include<stdbool.h>
#include <string.h>
#include"Game.h"

int main( int argc, char* args[] )
{

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;
int mouse_x, mouse_y;
int buttons;
int stage=1;
int pararaudio=1;
int pararaudio_menu=1;
SDL_Event ev;


//Para las puntuaciones
FILE *pf;
int mins,seg,puntuacion;


//Se define la ventana
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

SDL_Surface*menu1=SDL_LoadBMP("MENU2.0.1.bmp");
SDL_Surface*menu2=SDL_LoadBMP("MENU2.0.2.bmp");
SDL_Surface*menu3=SDL_LoadBMP("MENU2.0.3.bmp");
SDL_Surface*menu4=SDL_LoadBMP("MENU2.0.4.bmp");
SDL_Surface*menu5=SDL_LoadBMP("MENU2.0.5.bmp");
SDL_Surface*menu6=SDL_LoadBMP("MENU2.0.6.bmp");
SDL_Surface*menu7=SDL_LoadBMP("MENU2.0.7.bmp");
SDL_Surface*menu8=SDL_LoadBMP("MENU2.0.8.bmp");
SDL_Surface*imfinal = SDL_LoadBMP("FinalTemplo.bmp");


SDL_Surface*comojugar1=SDL_LoadBMP("comojugar3.0.bmp");
SDL_Surface*comojugar2=SDL_LoadBMP("comojugar3.1.bmp");
SDL_Surface*comojugar3=SDL_LoadBMP("comojugar3.2.bmp");
SDL_Surface*comojugar4=SDL_LoadBMP("comojugar3.3.bmp");

SDL_Surface*integrantes1=SDL_LoadBMP("integrantes3.0.bmp");
SDL_Surface*integrantes2=SDL_LoadBMP("integrantes3.1.bmp");

SDL_Surface*tutorial1=SDL_LoadBMP("tutorial3.0.bmp");
SDL_Surface*tutorial2=SDL_LoadBMP("tutorial3.1.bmp");

SDL_Surface*controles1=SDL_LoadBMP("controles1.bmp");
SDL_Surface*controles2=SDL_LoadBMP("controles2.bmp");


SDL_Surface*currentimage=NULL;

    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8 *wavBuffer;
    SDL_LoadWAV("Musica_menu.wav", &wavSpec, &wavBuffer, &wavLength);

    SDL_AudioSpec wavSpec2;
    Uint32 wavLength2;
    Uint8 *wavBuffer2;
    SDL_LoadWAV("Musica_final.wav", &wavSpec2, &wavBuffer2, &wavLength2);

SDL_Init( SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId,0);
    SDL_AudioDeviceID deviceId2 = SDL_OpenAudioDevice(NULL, 0, &wavSpec2, NULL, 0);
    int success2 = SDL_QueueAudio(deviceId2, wavBuffer2, wavLength2);
    SDL_PauseAudioDevice(deviceId2,1);


 window = SDL_CreateWindow( "Menu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
 screenSurface = SDL_GetWindowSurface( window );


 bool quit = false;
SDL_Event e;

  if( SDL_PollEvent( &e ) != 0 )
{

   switch( e.type )
{
    case SDL_QUIT:
    quit = true;
    break;

    default:
        break;
}
}
while(1)
{
    do{

switch(stage)
{

case 1:
    {
    while(stage==1)
    {
        pararaudio=1;
        currentimage=menu1;
        buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        SDL_PauseAudioDevice(deviceId,0);
        SDL_PauseAudioDevice(deviceId2,1);
        while(SDL_PollEvent( &ev ) != 0)
        {

            if(ev.type==SDL_QUIT)
            {
                return 0;
            }
            else if(ev.type==SDL_MOUSEMOTION)
                {
                if(mouse_x < 700 && mouse_y >270  && mouse_x > 500&& mouse_y < 350)
                {
                    currentimage=menu3;
                }
                else if(mouse_x < 800 && mouse_y >390 && mouse_x > 400&& mouse_y < 460)
                {
                    currentimage=menu5;
                }
                else if(mouse_x < 800 && mouse_y >510  && mouse_x > 400&& mouse_y < 580)
                {
                    currentimage=menu7;
                }
                else
                {
                    currentimage=menu1;
                }
                }
            else if (ev.type==SDL_MOUSEBUTTONDOWN)
            {
               if(mouse_x < 700 && mouse_y >270  && mouse_x > 500&& mouse_y < 350)//Jugar
               {
                   stage=2;
               }
               else if(mouse_x < 800 && mouse_y >390 && mouse_x > 400&& mouse_y < 460)//Como jugar
               {
                   stage=3;
               }
               else if(mouse_x < 800 && mouse_y >510  && mouse_x > 400&& mouse_y < 580)//Integrantes
               {
                   stage=4;
               }
               else if(mouse_x < 917 && mouse_y >565  && mouse_x > 848 && mouse_y < 635)//Volumen
               {
                   stage=8;
                   SDL_PauseAudioDevice(deviceId,1);
                   pararaudio=0;
                   pararaudio_menu=0;
               }
            }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
    }
    }
    }

case 2:
    {

               while(stage==2)
        {
            SDL_PauseAudioDevice(deviceId,1);
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
            while(SDL_PollEvent( &ev ) != 0)
            {
               if(ev.type==SDL_QUIT)
               {
                return 0;
               }
            InitGame(&stage,pararaudio);
            }
        }
    }

case 3:
    {

     while(stage==3)
     {
         currentimage=comojugar1;
        buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
            if(ev.type==SDL_QUIT)
            {
                return 0;
            }
           else if(ev.type==SDL_MOUSEMOTION)
           {
               if(mouse_x < 1003 && mouse_y >567  && mouse_x >938 && mouse_y < 602)
               {
                   currentimage=comojugar4;
               }
               else if(mouse_x < 713 && mouse_y >193  && mouse_x > 457&& mouse_y < 260)
               {
                   currentimage=comojugar2;
               }
               else if(mouse_x < 735 && mouse_y >363  && mouse_x > 441&& mouse_y < 426)
               {
                   currentimage=comojugar3;
               }
               else
               {
                   currentimage=comojugar1;
               }
           }
           else if(ev.type==SDL_MOUSEBUTTONDOWN)
            {
               if(mouse_x < 1003 && mouse_y >567  && mouse_x >938 && mouse_y < 602)
               {
                   currentimage=menu1;
                   stage=1;
               }
               else if(mouse_x < 713 && mouse_y >193  && mouse_x > 457&& mouse_y < 260)
               {
                   stage=5;
               }
               else if(mouse_x < 735 && mouse_y >363  && mouse_x > 441&& mouse_y < 426)
               {
                   stage=6;
               }
            }
            SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        }
     }
    }

case 4:
    {
 currentimage=integrantes1;
       while(stage==4)
       {
        buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
          if(ev.type==SDL_QUIT)
          {
                return 0;
          }
          else if(ev.type==SDL_MOUSEMOTION)
          {
               if(mouse_x < 1004 && mouse_y >571  && mouse_x > 940&& mouse_y < 605)
               {
                   currentimage=integrantes2;
               }
               else
               {
                   currentimage=integrantes1;
               }
          }
          else if(ev.type==SDL_MOUSEBUTTONDOWN)
          {
              if(mouse_x < 1004 && mouse_y >571  && mouse_x > 940&& mouse_y < 605)
               {
                   currentimage=menu1;
                   stage=1;
               }
          }

        }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
       }

    }

case 5:
    {
         currentimage=tutorial1;
        while(stage==5)
        {
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
           if(ev.type==SDL_QUIT)
          {
                return 0;
          }
          else if(ev.type==SDL_MOUSEMOTION)
          {
              if(mouse_x < 1005 && mouse_y >568  && mouse_x > 945&& mouse_y < 605)
               {
                   currentimage=tutorial2;
               }
               else
               {
                   currentimage=tutorial1;
               }
          }
          else if(ev.type==SDL_MOUSEBUTTONDOWN)
          {
              if(mouse_x < 1005 && mouse_y >568  && mouse_x > 945&& mouse_y < 605)
               {
                   stage=3;
               }
          }
        }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        }
    }

case 6:
    {
        currentimage=controles1;
        while(stage==6)
        {
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
           if(ev.type==SDL_QUIT)
          {
                return 0;
          }
          else if(ev.type==SDL_MOUSEMOTION)
          {
              if(mouse_x < 1007 && mouse_y >564  && mouse_x > 941&& mouse_y < 600)
               {
                   currentimage=controles2;
               }
               else
               {
                   currentimage=controles1;
               }
          }
          else if(ev.type==SDL_MOUSEBUTTONDOWN)
          {
              if(mouse_x < 1007 && mouse_y >564  && mouse_x > 941&& mouse_y < 600)
               {
                   stage=3;
               }
          }
        }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        }
    }

case 7:
    {
        currentimage=menu2;
        while(stage==7)
        {
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
           if(ev.type==SDL_QUIT)
          {
                return 0;
          }
          else if(ev.type==SDL_MOUSEMOTION)
          {
              if(mouse_x < 700 && mouse_y >270  && mouse_x > 500&& mouse_y < 350)
               {
                   currentimage=menu4;
               }
               else if(mouse_x < 800 && mouse_y >390 && mouse_x > 400&& mouse_y < 460)
               {
                   currentimage=menu6;
               }
               else if(mouse_x < 800 && mouse_y >510  && mouse_x > 400&& mouse_y < 580)
               {
                   currentimage=menu8;
               }
               else
               {
                   currentimage=menu2;
               }
          }
          else if(ev.type==SDL_MOUSEBUTTONDOWN)
          {
              if(mouse_x < 917 && mouse_y >565  && mouse_x > 848 && mouse_y < 635)
               {
                   stage=8;
               }
               else if(mouse_x < 700 && mouse_y >270  && mouse_x > 500&& mouse_y < 350)
               {
                   stage=2;
               }
               else if(mouse_x < 800 && mouse_y >390 && mouse_x > 400&& mouse_y < 460)
               {
                   stage=3;
               }
               else if(mouse_x < 800 && mouse_y >510  && mouse_x > 400&& mouse_y < 580)
               {
                   stage=4;
               }
          }
        }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        }
    }

case 8:
    {
    while(stage==8)
    {
        currentimage=menu2;
           buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {

            if(ev.type==SDL_QUIT)
            {
                return 0;
            }
            else if(ev.type==SDL_MOUSEMOTION)
                {
                if(mouse_x < 700 && mouse_y >270  && mouse_x > 500&& mouse_y < 350)
                {
                    currentimage=menu4;
                }
                else if(mouse_x < 800 && mouse_y >390 && mouse_x > 400&& mouse_y < 460)
                {
                    currentimage=menu6;
                }
                else if(mouse_x < 800 && mouse_y >510  && mouse_x > 400&& mouse_y < 580)
                {
                    currentimage=menu8;
                }
                else
                {
                    currentimage=menu2;
                }
                }
            else if (ev.type==SDL_MOUSEBUTTONDOWN)
            {
               if(mouse_x < 700 && mouse_y >270  && mouse_x > 500&& mouse_y < 350)//Jugar
               {
                   stage=9;
               }
               else if(mouse_x < 800 && mouse_y >390 && mouse_x > 400&& mouse_y < 460)//Como jugar
               {
                   stage=10;
               }
               else if(mouse_x < 800 && mouse_y >510  && mouse_x > 400&& mouse_y < 580)//Integrantes
               {
                   stage=11;
               }
               else if(mouse_x < 917 && mouse_y >565  && mouse_x > 848 && mouse_y < 635)//Volumen
               {
                   stage=1;
               }
            }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
    }
    }
    }
    break;

case 9:
    {
               while(stage==9)
        {
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
            while(SDL_PollEvent( &ev ) != 0)
            {
               if(ev.type==SDL_QUIT)
               {
                return 0;
               }
            InitGame(&stage,pararaudio);
            }
        }
    }
    break;

case 10:
    {

     while(stage==10)
     {
         currentimage=comojugar1;
        buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
            if(ev.type==SDL_QUIT)
            {
                return 0;
            }
           else if(ev.type==SDL_MOUSEMOTION)
           {
               if(mouse_x < 1003 && mouse_y >567  && mouse_x >938 && mouse_y < 602)
               {
                   currentimage=comojugar4;
               }
               else if(mouse_x < 713 && mouse_y >193  && mouse_x > 457&& mouse_y < 260)
               {
                   currentimage=comojugar2;
               }
               else if(mouse_x < 735 && mouse_y >363  && mouse_x > 441&& mouse_y < 426)
               {
                   currentimage=comojugar3;
               }
               else
               {
                   currentimage=comojugar1;
               }
           }
           else if(ev.type==SDL_MOUSEBUTTONDOWN)
            {
               if(mouse_x < 1003 && mouse_y >567  && mouse_x >938 && mouse_y < 602)
               {
                   stage=8;
               }
               else if(mouse_x < 713 && mouse_y >193  && mouse_x > 457&& mouse_y < 260)
               {
                   stage=12;
               }
               else if(mouse_x < 735 && mouse_y >363  && mouse_x > 441&& mouse_y < 426)
               {
                   stage=13;
               }
            }
            SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        }
     }
    }
    break;

case 11:
    {
 currentimage=integrantes1;
       while(stage==11)
       {
        buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
          if(ev.type==SDL_QUIT)
          {
                return 0;
          }
          else if(ev.type==SDL_MOUSEMOTION)
          {
               if(mouse_x < 1004 && mouse_y >571  && mouse_x > 940&& mouse_y < 605)
               {
                   currentimage=integrantes2;
               }
               else
               {
                   currentimage=integrantes1;
               }
          }
          else if(ev.type==SDL_MOUSEBUTTONDOWN)
          {
              if(mouse_x < 1004 && mouse_y >571  && mouse_x > 940&& mouse_y < 605)
               {
                   stage=8;
               }
          }

        }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
       }

    }
    break;

case 12:
    {
         currentimage=tutorial1;
        while(stage==12)
        {
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
           if(ev.type==SDL_QUIT)
          {
                return 0;
          }
          else if(ev.type==SDL_MOUSEMOTION)
          {
              if(mouse_x < 1005 && mouse_y >568  && mouse_x > 945&& mouse_y < 605)
               {
                   currentimage=tutorial2;
               }
               else
               {
                   currentimage=tutorial1;
               }
          }
          else if(ev.type==SDL_MOUSEBUTTONDOWN)
          {
              if(mouse_x < 1005 && mouse_y >568  && mouse_x > 945&& mouse_y < 605)
               {
                   stage=10;
               }
          }
        }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        }
    }
    break;

case 13:
    {
        currentimage=controles1;
        while(stage==13)
        {
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
        while(SDL_PollEvent( &ev ) != 0)
        {
           if(ev.type==SDL_QUIT)
          {
                return 0;
          }
          else if(ev.type==SDL_MOUSEMOTION)
          {
              if(mouse_x < 1007 && mouse_y >564  && mouse_x > 941&& mouse_y < 600)
               {
                   currentimage=controles2;
               }
               else
               {
                   currentimage=controles1;
               }
          }
          else if(ev.type==SDL_MOUSEBUTTONDOWN)
          {
              if(mouse_x < 1007 && mouse_y >564  && mouse_x > 941&& mouse_y < 600)
               {
                   stage=10;
               }
          }
        }
        SDL_BlitSurface( currentimage, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        }
    }
    break;

case 14:
    {
        currentimage=imfinal;
        SDL_Rect posicion={63,0,0,0};  //Ponemos la imagen de la salida en mitad de la pantalla.
        SDL_BlitSurface( currentimage, NULL, screenSurface, &posicion );   //Se muestra la imagen de la salida durante 7 segundos.
        SDL_UpdateWindowSurface( window );
        while(SDL_PollEvent( &ev ) != 0)
        {
        if(pararaudio==1)
        {
        SDL_PauseAudioDevice(deviceId2,0);
        SDL_PauseAudioDevice(deviceId,1);
        if(ev.type== SDL_MOUSEBUTTONDOWN)
        {
        if(mouse_x < 1200 && mouse_y >1  && mouse_x > 1&& mouse_y < 675)
        {
                 stage=1;   //Se vuelve al menú.
        }
        }
        }
        if(pararaudio==0)
        {
        SDL_PauseAudioDevice(deviceId2,1);
        SDL_PauseAudioDevice(deviceId,1);
                if(ev.type== SDL_MOUSEBUTTONDOWN)
        {
        if(mouse_x < 1200 && mouse_y >1  && mouse_x > 1&& mouse_y < 675)
        {
                  stage=8;   //Se vuelve al menú con el audio pausado.
        }
        }
        }
        }
    }
    break;

    /**     //Mostrar puntuaciones
case 15:
    {
            pf = fopen("Puntuacion.txt", "r");
            if (pf == NULL)
            {
                // Si el resultado es NULL mensaje de error
                printf("Error al abrir el fichero.\n");
                return -1;
            }
            else
            {
                // Leemos los datos
                fscanf(pf,"%d,%d,%d",&mins,&seg,&puntuacion);
                fclose(pf);
                // Mostramos en pantalla lo leído
                printf("***Resultados del último intento realizado***\n");
                printf("%d minuto(s) y %d segundos --------> %d puntos\n",mins,seg,puntuacion);
            }
    }
    break;
*/

}

    } while(!quit);
}

return 0;
}


