#include<stdio.h>
#include<string.h>

int main()
{
    char c[10];
    int i, tst, l;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf(" %[^\n]", c);
        l = strlen(c);
        if(l == 5)
            printf("3\n");
        else
        {
            i = 0;
            if(c[0] == 'o')
                i++;
            if(c[1] == 'n')
                i++;
            if(c[2] == 'e')
                i++;

        if(i >= 2)
            printf("1\n");
        else
            printf("2\n");
        }
    }
    return 0;
}
