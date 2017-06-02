#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, sum, n;


    while(scanf("%d", &n) == 1)
    {
        sum = 0;
        while(n)
        {
            n = n % 10;
            sum += n;
        }
        printf("%d\n", sum);
    }

}
