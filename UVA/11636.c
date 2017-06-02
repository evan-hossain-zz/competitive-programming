#include<stdio.h>

int main()
{
    int m, n, cnt = 0, res;
    while(scanf("%d", &n) == 1 && n >= 0)
    {
        res = 0;
        m = 1;
        while(m)
        {
            m = n / 2;
            n = m + n % 2;
            res++;
        }
        cnt++;
        printf("Case %d: %d\n", cnt, res - 1);
    }
    return 0;
}
