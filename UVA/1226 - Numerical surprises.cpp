#include<cstdio>
#include<cstring>

int main()
{
    char p[2002];
    int tst, n, i, l, ans;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d  %s", &n, p);
        l = strlen(p);
        ans = 0;
        for(i = 0; i < l; i++)
            ans = (ans * 10 + p[i] - '0') % n;
        printf("%d\n", ans % n);
    }
    return 0;
}
