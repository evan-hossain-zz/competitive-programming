#include<cstdio>


int main()
{
    int test;
    long long n;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld", &n);
        n = n * 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        n /= 10;
        if(n > 0)
            printf("%lld\n", n % 10);
        else
            printf("%lld\n", -(n % 10));
    }
    return 0;
}
