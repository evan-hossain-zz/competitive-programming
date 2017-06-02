#include<stdio.h>

int main()
{
    int s, a, e, f, tst, res;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d", &f);
        res = 0;
        while(f--)
        {
            scanf("%d %d %d", &s, &a, &e);
            res += s * e;
        }
        printf("%d\n", res);
    }
    return 0;
}
