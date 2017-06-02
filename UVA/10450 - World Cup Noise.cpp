#include<cstdio>


long long ffibo(long long n);

long long fibo[53];

int main()
{
    long long n;
    int test, i = 0;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld", &n);
        printf("Scenario #%d:\n%lld\n\n", ++i, ffibo(n + 2));
    }
    return 0;
}
long long ffibo(long long n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(fibo[n] != 0)
        return fibo[n];
    else
    {
        fibo[n] = ffibo(n - 1) + ffibo(n - 2);
        return fibo[n];
    }
}
