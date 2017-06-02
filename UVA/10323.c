#include<stdio.h>

int main()
{
    long long unsigned res;
    int n, i;
    while(scanf("%d", &n)== 1)
    {
        res = 1;
        if(n < 0)
        {
            if(-n % 2 == 0)
                printf("Underflow!\n");
            else
                printf("Overflow!\n");
        }

        else if(n <= 7)
            printf("Underflow!\n");

        else if(n >= 14)
            printf("Overflow!\n");

        else
        {
            for(i = n; i >= 1; i--)
                res *= i;
            printf("%llu\n", res);
        }
    }
    return 0;
}
