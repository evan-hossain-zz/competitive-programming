#include<stdio.h>

int main()
{
    long long n, tst;
    scanf("%lld", &tst);
    while(scanf("%lld,", &n) == 1)
    {
        if(n == 2 || n == 3 || n == 5 || n == 7 || n == 13 || n == 17)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
