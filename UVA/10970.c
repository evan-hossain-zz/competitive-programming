#include<stdio.h>

int main()
{
    int m, n, i;

    while(scanf("%d %d", &m, &n) == 2)
        printf("%d\n", m*n-1);

    return 0;
}
