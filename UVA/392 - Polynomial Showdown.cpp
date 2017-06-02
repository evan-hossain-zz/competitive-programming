#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("out.txt", "w", stdout);
    int pwr, co[9], i, flag;
    while(scanf("%d", &co[0]) == 1)
    {
        pwr = 9;
        flag = 0;
        for(i = 1; i < 9; i++)
            scanf("%d", &co[i]);
        for(i = 0; pwr > 2; i++)
        {
            pwr--;
            if(!co[i])
                continue;
            if(co[i] > 0 && flag)
                printf(" + ");
            else if(co[i] < 0 && flag)
                printf(" - ");
            else if(co[i] < 0)
                printf("-");
            flag = 1;
            if(abs(co[i]) == 1)
                printf("x^%d", pwr);
            else
                printf("%dx^%d", abs(co[i]), pwr);
        }
        if(co[i] != 0)
        {
            if(co[i] > 0 && flag)
            {
                printf(" + ");
                flag = 1;
            }
            else if(co[i] < 0 && flag)
            {
                printf(" - ");
                flag = 1;
            }
            if(co[i] == 1 && flag == 0)
                printf("x");
            else if(co[i] == -1 && flag == 0)
                printf("-x");
            else if(abs(co[i]) == 1)
                printf("x");
            else
            {
                if(flag)
                    printf("%dx", abs(co[i]));
                else
                    printf("%dx", co[i]);
            }
            flag = 1;
        }
        i++;
        if(co[i] > 0 && flag)
            printf(" + ");
        else if(co[i] < 0 && flag)
            printf(" - ");
        if(flag && co[i])
            printf("%d", abs(co[i]));
        else if(!flag)
            printf("%d", co[i]);
        printf("\n");
    }
    return 0;
}
