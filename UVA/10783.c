#include<stdio.h>

int main()
{
    int test_case, i, a, b, j, sum;
    scanf("%d", &test_case);

    for(i = 1; i <= test_case; i++)
    {
        sum = 0;
        scanf("%d", &a);

        scanf("%d", &b);

        for(j = a; j <= b; j++)
        {
            if(j % 2 == 0)
                continue;
            else
                sum = j + sum;
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}
