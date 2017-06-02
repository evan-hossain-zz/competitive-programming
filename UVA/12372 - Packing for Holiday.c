#include<stdio.h>
int main()
{
    int h, w, l, i = 0, tst;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d %d %d", &l, &w, &h);
        if(l > 20 || w > 20 || h > 20)
            printf("Case %d: bad\n", ++i);
        else
            printf("Case %d: good\n", ++i);
    }
    return 0;
}
