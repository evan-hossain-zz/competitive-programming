#include<stdio.h>

int main()
{
    int tst_cs, walls, i, hj, lj, j, jmps, isp;
    scanf("%d", &tst_cs);
    for(i = 1; i <= tst_cs; i++)
    {
        hj = 0;
        lj = 0;
        scanf("%d", &walls);
        scanf("%d", &isp);
        for(j = 1; j < walls; j++)
        {
            scanf("%d", &jmps);
            if(jmps > isp)
                hj++;
            else if(jmps < isp)
                lj++;
            else
                continue;
            isp = jmps;
        }
        printf("Case %d: %d %d\n", i, hj, lj);
    }
    return 0;
}
