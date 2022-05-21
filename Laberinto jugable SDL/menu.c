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
SDL_Event ev;

//Se define la ventana
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

SDL_Surface*menu1=SDL_LoadBMP("MENU2.0.bmp");
SDL_Surface*menu2=SDL_LoadBMP("MENU2.1.bmp");
SDL_Surface*menu3=SDL_LoadBMP("MENU2.2.bmp");
SDL_Surface*menu4=SDL_LoadBMP("MENU2.3.bmp");

SDL_Surface*dificultad1=SDL_LoadBMP("DIFICULTAD2.0.bmp");
SDL_Surface*dificultad5=SDL_LoadBMP("DIFICULTAD2.4.bmp");

SDL_Surface*comojugar1=SDL_LoadBMP("comojugar3.0.bmp");
SDL_Surface*comojugar2=SDL_LoadBMP("comojugar3.1.bmp");
SDL_Surface*comojugar3=SDL_LoadBMP("comojugar3.2.bmp");
SDL_Surface*comojugar4=SDL_LoadBMP("comojugar3.3.bmp");

SDL_Surface*integrantes1=SDL_LoadBMP("integrantes3.0.bmp");
SDL_Surface*integrantes2=SDL_LoadBMP("integrantes3.1.bmp");

SDL_Surface*tutorial1=SDL_LoadBMP("tutorial3.0.bmp");
SDL_Surface*tutorial2=SDL_LoadBMP("tutorial3.1.bmp");


SDL_Surface*currentimage=NULL;



 SDL_Init( SDL_INIT_VIDEO);

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


#include <SDL2/SDL.h>
#include <stdio.h>
#include<stdbool.h>
#include <string.h>
#include <math.h>


int main( int argc, char* args[] )
{

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 675;
int mouse_x, mouse_y;
int buttons;
int stage=1;
SDL_Event ev;


//Se define la ventana
SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface*menu1=SDL_LoadBMP("MENU2.0.bmp");
SDL_Surface*menu2=SDL_LoadBMP("MENU2.1.bmp");
SDL_Surface*menu3=SDL_LoadBMP("MENU2.2.bmp");
SDL_Surface*menu4=SDL_LoadBMP("MENU2.3.bmp");
SDL_Surface*dificultad1=SDL_LoadBMP("DIFICULTAD2.0.bmp");
SDL_Surface*dificultad5=SDL_LoadBMP("DIFICULTAD2.4.bmp");
SDL_Surface*comojugar1=SDL_LoadBMP("comojugar3.0.bmp");
SDL_Surface*comojugar2=SDL_LoadBMP("comojugar3.1.bmp");
SDL_Surface*comojugar3=SDL_LoadBMP("comojugar3.2.bmp");
SDL_Surface*comojugar4=SDL_LoadBMP("comojugar3.3.bmp");
SDL_Surface*integrantes1=SDL_LoadBMP("integrantes3.0.bmp");
SDL_Surface*integrantes2=SDL_LoadBMP("integrantes3.1.bmp");
SDL_Surface*lol=SDL_LoadBMP("TrollFace2.bmp");
SDL_Surface*tutorial1=SDL_LoadBMP("tutorial3.0.bmp");
SDL_Surface*tutorial2=SDL_LoadBMP("tutorial3.1.bmp");
SDL_Surface*controles1=SDL_LoadBMP("controles1.bmp");
SDL_Surface*controles2=SDL_LoadBMP("controles2.bmp");


SDL_Surface*currentimage=NULL;



 SDL_Init( SDL_INIT_VIDEO);

 window = SDL_CreateWindow( "Movimiento", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
switch(stage)
{
case 1:
    {
    while(stage==1)
    {
        currentimage=menu1;
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
                    currentimage=menu2;
                }
                else if(mouse_x < 800 && mouse_y >390 && mouse_x > 400&& mouse_y < 460)
                {
                    currentimage=menu3;
                }
                else if(mouse_x < 800 && mouse_y >510  && mouse_x > 400&& mouse_y < 580)
                {
                    currentimage=menu4;
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
            buttons = SDL_GetMouseState(&mouse_x, &mouse_y);
            while(SDL_PollEvent( &ev ) != 0)
            {
               if(ev.type==SDL_QUIT)
               {
                return 0;
               }
            InitGame(&stage);
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
}
}


return 0;
}
}
    } while(!quit);

}



return 0;
}

