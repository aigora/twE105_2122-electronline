#include<stdio.h>
//Temporizador de tipo 0. Se puede mejorar mucho.
int main()
{
    int minutos=2,segundos=20;
    int lapso=1000,i;
    while(1)
    {
        for(i=1; i<10; i++)
        {
        printf("\n");
        }
        for(i=1; i<7; i++)
        {
        printf("\t");
        }
    printf("  Se acaba el tiempo\n");
            for(i=1; i<8; i++)
        {
        printf("\t");
        }
    printf("%d:%d",minutos,segundos);
            Sleep(lapso);
        system("cls");
        if(segundos==0)
        {
        segundos=60;
        minutos--;
        }
        segundos--;
        if(segundos==0 && minutos==0)
        {
            system("cls");
                    for(i=1; i<10; i++)
        {
        printf("\n");
        }
        for(i=1; i<7; i++)
        {
        printf("\t");
        }
            printf("      Se acabo");
            break;
        }
    }
    getch();
    return 0;
}
