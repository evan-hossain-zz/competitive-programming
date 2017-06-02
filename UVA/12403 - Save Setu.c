#include<stdio.h>

int main()
{
    int i, tst, setu = 0;
    char s[20];
    scanf("%d", &tst);
    while(tst--)
    {
        scanf(" %s", &s);
        if(s[0] == 'd')
        {
            scanf("%d", &i);
            setu += i;
        }
        else if(s[0] == 'r')
            printf("%d\n", setu);
    }
    return 0;
}
