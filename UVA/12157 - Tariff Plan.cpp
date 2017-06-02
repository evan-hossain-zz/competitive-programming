#include<cstdio>

int main()
{
    int test, mile, juice, n, tk, kase = 0;
    scanf("%d", &test);
    while(kase < test)
    {
        mile = juice = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &tk);
            mile += tk / 30 * 10 + 10;
            juice += tk / 60 * 15 + 15;
        }
        if(mile == juice)
            printf("Case %d: Mile Juice %d\n", ++kase, mile);
        else if(mile < juice)
            printf("Case %d: Mile %d\n", ++kase, mile);
        else
            printf("Case %d: Juice %d\n", ++kase, juice);
    }
    return 0;
}
