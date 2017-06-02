#include<stdio.h>
#include<string.h>

int main()
{
    char s[500];
    int tst, l;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf(" %s", s);
        l = strlen(s);
        if(strcmp(s, "78") == 0 || strcmp(s, "1") == 0\
            || strcmp(s, "4") == 0)
            printf("+\n");
        else if(s[l - 1] == '5' && s[l - 2] == '3')
            printf("-\n");
        else if(s[0] == '9' && s[l - 1] == '4')
            printf("*\n");
        else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
            printf("?\n");
    }
    return 0;
}
