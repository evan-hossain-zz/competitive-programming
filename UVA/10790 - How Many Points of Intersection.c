#include<stdio.h>

int main()
{
    long long unsigned a, b;
    register int i = 0;
    while(scanf("%llu %llu", &a, &b) == 2 && a != 0 && b != 0)
    {
        printf("Case %d: %llu\n", ++i, (a * (a - 1) * b * (b - 1))/4);
    }
    return 0;
}
