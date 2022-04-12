#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y);
int main()
{
    int recintox=50,recintoy=20;
    int x=recintox/2, y=recintoy/2,i;
    gotoxy(x,y);
    printf("+");
    for(i=0; i<recintox; i++)
    {
        gotoxy(i,0); printf("O");
    }
    for(i=0; i<recintox; i++)
    {
        gotoxy(i,recintoy); printf("O");
    }
    for(i=0; i<recintoy; i++)
    {
        gotoxy(0,i); printf("O");
    }
    for(i=0; i<recintoy+1; i++)
    {
        gotoxy(recintox,i); printf("O");
    }
    while(1)
    {
        Sleep (100);
        if(GetAsyncKeyState(0x27))
        {
            if(x>=0)
            {
            gotoxy(x,y); printf(" ");
            x++;
            gotoxy(x,y); printf("+");
            }

        }
        if(GetAsyncKeyState(0x25))
        {
            if(x>=0)
            {
            gotoxy(x,y); printf(" ");
            x--;
            gotoxy(x,y); printf("+");
            }

        }
        if(GetAsyncKeyState(0x26))
        {
            if(y>=1)
            {
            gotoxy(x,y); printf(" ");
            y--;
            gotoxy(x,y); printf("+");
            }

        }
        if(GetAsyncKeyState(0x28))
        {
            if(y>=1)
            {
            gotoxy(x,y); printf(" ");
            y++;
            gotoxy(x,y); printf("+");
            }
        }
        if((x<=0 || y<=0)||(x>=recintox || y>=recintoy))
        {
            gotoxy(x,y); printf("O");
            x=recintox/2; y=recintoy/2;
        }
    }
    return 0;
}

void gotoxy(int x, int y)
{
    HANDLE ventana;
    ventana=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenadas;
    coordenadas.X=x;
    coordenadas.Y=y;
    SetConsoleCursorPosition(ventana,coordenadas);
}
