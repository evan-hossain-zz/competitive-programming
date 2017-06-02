
#include<stdio.h>


int main ()
{
    long long x, y, i;
    int cnt, m = 0;

    while(scanf("%lld %lld", &x, &y) == 2)
    {
        m++;
        i = x;
        cnt = 0;
        if(x < 0 && y < 0)
            break;
        while(x <= y)
        {
            cnt++;
            if(x % 2 == 0)
                x = x / 2;
            else
                x = 3 * x + 1;
            if(x == 1)
            {
                cnt++;
                break;
            }
        }
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", m, i, y, cnt);
    }
    return 0;
}
