#include<cstdio>

using namespace std;

int main()
{
    long long m, x, ans, mod;
    while(scanf("%lld %lld", &m, &x) == 2 && (m || x))
    {
        if(x == 100 || x == 0 || m == 1)
        {
            printf("Not found\n");
            continue;
        }
        ans = (100 * m - 100) / (100 - x);
        mod = (100 * m - 100) % (100 - x);
        if(ans < m)
            printf("Not found\n");
        else if(mod == 0)
            printf("%lld\n", ans - 1);
        else
            printf("%lld\n", ans);

    }
    return 0;
}
