#include<stdio.h>

int main()
{
    int a, b, c, ans, strt;
    while(scanf("%d %d %d %d", &strt, &a, &b, &c) == 4)
    {
        if(a == 0 && b == 0 && c == 0 && strt == 0) break;
        ans = 1080;
        if(a < strt)
            ans += ((strt - a) * 9);
        else
            ans += ((strt + (40 - a)) * 9);
        if(a < b)
            ans += ((b - a) * 9);
        else
            ans += ((b + (40 - a)) * 9);
        if(c < b)
            ans += ((b - c) * 9);
        else
            ans += ((b + (40 - c)) * 9);
        printf("%d\n", ans);
    }
    return 0;
}
