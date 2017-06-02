#include<stdio.h>

int main()
{
    int g, l, i, tst;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d %d", &g, &l);
        if(l % g != 0)
            printf("-1\n");
        else
            printf("%d %d\n", g, l);
    }
    return 0;
}
