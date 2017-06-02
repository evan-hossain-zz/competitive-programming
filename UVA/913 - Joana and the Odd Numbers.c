#include<stdio.h>

int main()
{
    long long n;
    while(scanf("%lld", &n) == 1)
    {
        n = ((n + 1) >> 1);
        n = (1 << (n * n)) - 1;
        n += (n - 2) + (n - 4);
        printf("%lld\n", n);
    }
    return 0;
}
