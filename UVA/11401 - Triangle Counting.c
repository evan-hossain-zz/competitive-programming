#include<stdio.h>

int main()
{
    int n, i, j;
    long long res;
    while(scanf("%d", &n) == 1 && n >= 3)
    {
        res = 0;
        while(n >= 3)
        {
            for(i = 3; n - i >= 0; i += 2)
                res += (n - i);
            n--;
        }
        printf("%lld\n", res);
    }
}
