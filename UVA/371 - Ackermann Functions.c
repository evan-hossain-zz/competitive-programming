#include<stdio.h>


int main ()
{
    long long x, y, n, i, p, m, max;

    while(scanf("%lld %lld", &x, &y) == 2)
    {
        max = m = 0;
        if(x == 0 && y == 0)
            break;
        if (x > y)
        {
            max = x;
            x = y;
            y = max;
        }
        for(i = x; i <=y ; i++)
        {
            p = i;

            for(n = 1; ; n++)
            {
                if(p % 2 == 0)
                    p = p / 2;
                else
                    p = 3 * p + 1;
                if(p == 1)
                    break;
            }
            if (n > m)
            {
                max = i;
                m = n;
            }
            else
            {
                max = max;
                m = m;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", x, y, max, m);
    }
    return 0;
}
