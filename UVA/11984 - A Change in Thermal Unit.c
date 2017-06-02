#include<stdio.h>

int main()
{
    int i, n, c, d;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d", &c, &d);
        printf("Case %d: %.2f\n", i, c + (.5555556 * d));
    }
    return 0;
}
