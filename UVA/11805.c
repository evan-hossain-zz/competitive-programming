#include<stdio.h>

int main()
{
    int test_case, parreira, i, k, p, n;
    scanf("%d", &test_case);
    for(i = 1; i <= test_case; i++)
    {
        scanf("%d %d %d", &n, &k, &p);

        parreira = (k+p)%n;
        if(parreira == 0)
            printf("Case %d: %d\n", i, n);
        else
            printf("Case %d: %d\n", i, parreira);
    }
    return 0;
}
