#include<cstdio>

int main()
{
    unsigned long long a, b, c;
    while(scanf("%llu %llu", &a, &b) == 2)
        printf("%llu\n", a ^ b);
    return 0;
}
