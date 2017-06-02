#include<stdio.h>

int main()
{
    int tst, scr, res[102], i, j, cln;
    scanf("%d", &tst);
    for(i = 1; i <= tst; i++)
    {
        scanf("%d", &scr);
        cln = 0;
        for(j = 0; j < scr; j++)
        {
            scanf("%d", &res[j]);
            if(res[j] > cln)
                cln = res[j];
        }
        printf("Case %d: %d\n", i, cln);
    }
    return 0;
}
