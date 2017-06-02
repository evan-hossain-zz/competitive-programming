#include<stdio.h>
#include<string.h>

long long c[1000][1000], n, m;
long long ncm(long long n, long long m);
int main()
{
    memset(c, -1, sizeof(long long) * 1000000);
    while(scanf("%lld %lld", &n, &m) == 2 && (n || m))
        printf("%lld\n", ncm(n, m));
    return 0;
}

long long ncm(long long n, long long m)
{
    if(n == m || m == 0 || n == 0) return 1;
    else if(m == 1) return n;
    else if(c[n][m] != -1) return c[n][m];
    else
    {
        c[n][m] = ncm(n - 1, m) + ncm(n - 1, m - 1);
        return c[n][m];
    }
}
