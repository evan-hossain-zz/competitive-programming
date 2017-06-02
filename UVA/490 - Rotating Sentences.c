#include<stdio.h>
#include<string.h>

char array[103][103];
int main()
{
    register int i = 0, j, l = 0, c = 0;
    while(gets(array[i]))
    {
     if(strlen(array[i]) > l)
            l = strlen(array[i]);
        i++;
    }
    for(j = 0; j < l; j++)
    {
        for(c = i - 1; c >= 0; c--)
        {
            if(array[c][j] != '\0')
                printf("%c", array[c][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
