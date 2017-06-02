#include<cstdio>
#include<cmath>

int main()
{
    double n, x, i;
    double d;
    int test, kase = 0;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%lf", &n);
        printf("Case %d:", ++kase);
        for(i = 1; i < n; i++)
        {
            x = i / sqrt(n - i);
            if(x - (int)x == 0.0)
                printf(" %.lf", i);
        }
        printf("\n");
    }
    return 0;
}
