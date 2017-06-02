#include<stdio.h>

int main()
{
    long long n, res;
    while(scanf("%lld", &n) == 1 && n >= 0)
    {
        res = ((n * (n + 1) / 2) + 1);
        printf("%lld\n", res);
    }
    return 0;
}
