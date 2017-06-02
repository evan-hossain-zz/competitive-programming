#include<stdio.h>

int main()
{
    int prbs[12], cntsts[12], i, tst = 0, prblms;
    while(1)
    {
        scanf("%d", &prblms);
        if(prblms < 0) break;
        printf("Case %d:\n", ++tst);
        i = 0;
        while(i < 12)
            scanf("%d", &prbs[i++]);
        for(i = 0; i < 12; i++)
        {
            scanf("%d", &cntsts[i]);
            if(cntsts[i] <= prblms)
            {
                printf("No problem! :D\n");
                prblms -= cntsts[i];
            }
            else
                printf("No problem. :(\n");
                prblms += prbs[i];
        }
    }
    return 0;
}
