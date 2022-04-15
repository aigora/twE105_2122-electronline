#include <stdio.h>
int main()
{
    char lab[25][40];
    char i,j;
    for (i=0;i<25;i++)
    {
        for (j=0;j<40;j++)
        {
                lab[i][j]='|';
            printf("%c",lab[i][j]);
        }
        printf("\n");
    }
    return 0;
}
