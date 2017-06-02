#include<stdio.h>

int main()
{
    int m, n, tst;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", (int) (n / 3) * (int) (m / 3));
    }
    return 0;
}
