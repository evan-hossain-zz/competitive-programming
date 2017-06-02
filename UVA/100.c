#include<stdio.h>


int main ()

{
    long long unsigned x, y, n, i, p, m;

    while(scanf("%llu %llu", &x, &y) == 2)
    {
        m = 0;
        if (x < y)
        {
            for(i = x; i <=y ; i++)
            {
                p = i;

                for(n = 1; p != 1; n++)
                {
                    if(p % 2 == 0)
                        p = p / 2;

                    else
                        p = 3 * p + 1;
                }
                if (n > m)
                    m = n;
                else
                    m = m;
            }
        }
        else
        {
            for(i = y; i <=x ; i++)
            {
                p = i;
                for(n = 1; p != 1; n++)
                {
                    if(p % 2 == 0)
                        p = p / 2;

                    else
                        p = 3 * p + 1;
                }
                if (n > m)
                    m = n;
                else
                    m = m;
            }
        }
        printf("%llu %llu %llu\n", x, y, i);
    }
    return 0;
}
