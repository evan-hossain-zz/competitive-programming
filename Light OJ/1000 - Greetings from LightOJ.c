#include<stdio.h>

int main()
{
    int a, b, tst;
    register int i = 0;
    scanf("%d", &tst);
    while(i < tst)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", ++i, a + b);
    }
    return 0;
}
