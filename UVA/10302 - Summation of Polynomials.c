#include<stdio.h>

int main()
{
    long long x;
    while(scanf("%lld", &x) == 1)
    {
        printf("%lld\n", (x * (x + 1) / 2) * (x * (x + 1) / 2));
    }
    return 0;
}
