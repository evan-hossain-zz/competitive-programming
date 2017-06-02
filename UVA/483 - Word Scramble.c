#include<stdio.h>
#include<string.h>

int main()
{
    char str[500];
    int i, j, l;
    while(scanf(" %[^\n]", str) == 1)
    {
        l = strlen(str);
        for(i = 1; i <= l+1; i++)
        {
            if(str[i] == ' ' || i == l)
            {
                if(str[i - 1] != ' ')
                    for(j = i - 1; str[j] != ' ' && str[j] != '\0'; j--)
                    putchar(str[j]);
                if(i < l)
                    printf(" ");
            }

        }
        printf("\n");
    }
    return 0;
}
