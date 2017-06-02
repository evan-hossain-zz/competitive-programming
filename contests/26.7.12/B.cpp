#include<cstdio>

int main()
{
    int i = 0, n, num, test;
    long long ans;
    scanf("%d", &test);
    while(i < test)
    {
        ans = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &num);
            if(num >= 0)
            ans += num;
        }
        printf("Case %d: %lld\n", ++i, ans);
    }
    return 0;
}
