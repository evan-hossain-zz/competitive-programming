#include<stdio.h>
#include<string.h>


int main()
{
    char c[1000000];
    int flag = 0, l, i;
    while(gets(c))
    {
        l = strlen(c);
        for(i = 0; i < l; ++i)
        {
            if(c[i] == '"')
            {
                if(flag % 2 == 0)
                    printf("``");
                else
                    printf("''");
                    flag++;
            }
            else
                printf("%c", c[i]);
        }
        printf("\n");
    }
    return 0;
}
