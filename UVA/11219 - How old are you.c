#include<stdio.h>

int main()
{
    int d, m, y, i, tst, dp, mp, yp, temp;
    scanf("%d", &tst);
    for(i = 0; i < tst; ++i)
    {
        temp = 0;
        scanf("%d/%d/%d", &dp, &mp, &yp);
        scanf("%d/%d/%d", &d, &m, &y);
        if((y - yp) < 0)
        {
            if((mp - m) <= 0)
                printf("Case %d: Invalid birth date\n");
                continue;
        }
        if(d > dp)
            d = d - dp;
        else
            d = dp - d;
        if(y % 4 == 0)
        {
            if(d >= 29)
            temp = d / 29;
        }
        else
        {
            if(d >= 30)
            temp = d / 30;
        }
        if(m > mp)
            m = temp + (m - mp);
        else
            m = temp + (mp - m);
        if(m >= 12)
            temp = m / 12;
        if(y > yp)
            y = (y - yp) + temp;
        else
            y = (yp - y) + temp;
        if(y < 0)
            printf("Case %d: Invalid birth date\n", i);
        else if(y > 130)
            printf("Case %d: Check birth date\n", i);
        else
            printf("Case %d: %d\n", i, y);
    }
    return 0;
}
