#include<cstdio>
#include<cmath>

int main()
{
    int i, n, tst;
    double ans;
    scanf("%d", &tst);
    while(tst--)
    {
        ans = 0;
        scanf("%d", &n);
        for(i = 2; i <= n; i++)
            ans += log10(i);
        printf("%d\n", (int)ans + 1);
    }
    return 0;
}
