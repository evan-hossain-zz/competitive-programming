#include<stdio.h>

int main()
{
    long int test_case, i, j, k, x, y;
    scanf("%ld", &test_case);

    for(x = 1; x <= test_case; x++)
    {
        scanf("%ld %ld %ld", &i, &j, &k);

        if(i + j <= k || i + k <= j || j + k <= i)
            printf("Case %ld: Invalid\n", x);
        else if (i == j && j == k)
            printf("Case %ld: Equilateral\n", x);
        else if(i == j || i == k || j == k)
            printf("Case %ld: Isosceles\n", x);
        else
            printf("Case %ld: Scalene\n", x);
    }
    return 0;

}
