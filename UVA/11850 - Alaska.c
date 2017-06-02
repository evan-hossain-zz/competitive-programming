#include<stdio.h>

int main()
{
    int kase, strt, statn,flag;
    while(scanf("%d", &kase) == 1 && kase)
    {
        flag = 0;
        strt = 1422;
        while(kase--)
        {
            scanf("%d", &statn);
            if(statn - strt > 200)
                flag = 1;
            strt = statn;
        }
        if(flag == 1)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    }
    return 0;
}
