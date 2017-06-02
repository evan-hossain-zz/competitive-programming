#include<stdio.h>

int main()
{
    char ch;
    int i = 0, j;

    while(scanf("%c", &ch) == 1)
    {
        if(ch >= '0' && ch <= '9')
        {
            i += ch - '0';
        }
        else if(ch == '\n' || ch == '!')
        {
            printf("\n");
        }
        else
        {
            if(ch == 'b')
                for(j = 0; j < i; j++)
                    printf(" ");
            else
                for(j = 0; j < i; j++)
                    printf("%c", ch);
            i = 0;
        }
    }
    return 0;
}
