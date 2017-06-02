#include<cstdio>

int main()
{
    int n, ans;
    while(scanf("%d", &n) == 1)
    {
        ans = n;
        while(n > 2)
        {
            ans += n / 3;
            n = n / 3 + n % 3;
        }
        if(n == 2)
            ans += 1;
        printf("%d\n", ans);
    }
    return 0;
}
