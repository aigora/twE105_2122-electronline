#include <stdio.h>
#define N 100
void laberinto(int base,int altura,char lab[][N]);  //Función para mostrar el laberinto.
int main()
{
    char lab[N][N];
    char avatar='$',avance;
    int i,j,base,altura;
    printf("Introduzca la base y la altura:\n");
    scanf("%d %d",&base,&altura);
    for (i=0;i<=base;i++)
    {
        for (j=0;j<=altura;j++)
        {
        lab[i][j]=' ';
        if(i==0 || j==0 || j==altura || i==base)
            lab[i][j]='#';
        }
    }
    lab[1][1]=avatar;
    laberinto(base,altura,lab);
    i=1;
    j=1;
    do
    {
        scanf("%c",&avance);
        switch (avance)
        {
        case 'w':
            system("cls");
            if (lab[i-1][j]!='#')
            {
                lab[i-1][j]=avatar;
                lab[i][j]=' ';
            }
            i--;
            laberinto(base,altura,lab);
            break;
        case 'a':
            system("cls");
            if (lab[i][j-1]!='#')
            {
                lab[i][j-1]=avatar;
                lab[i][j]=' ';
            }
            j--;
            laberinto(base,altura,lab);
            break;
        case 's':
            system("cls");
            if (lab[i+1][j]!='#')
            {
                lab[i+1][j]=avatar;
                lab[i][j]=' ';
            }
            i++;
            laberinto(base,altura,lab);
            break;
        case 'd':
            system("cls");
            if (lab[i][j+1]!='#')
            {
                lab[i][j+1]=avatar;
                lab[i][j]=' ';
            }
            j++;
            laberinto(base,altura,lab);
            break;
        default:
            break;
        }
    }while(lab[i][j]!='#');
}
void laberinto(int base,int altura,char lab[][N])
{
    int i,j;
    for (i=0;i<=base;i++)
    {
        for (j=0;j<=altura;j++)
        {
        printf("%c",lab[i][j]);
        }
        printf("\n");
    }
}

