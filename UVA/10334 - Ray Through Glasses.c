#include<stdio.h>
//string lagbe
int main()
{
    long long unsigned sum,f0,f1;
    int count, n;
    while(scanf("%d",&n) == 1)
    {
        sum=0;
        f0=0;
        f1=1;
        count=1;
        while (count <= n + 2)
        {
            f0 = f1;
            f1 = sum;
            sum = f0 + f1;
            count++;
        }
        printf("%llu\n", sum);
    }
}
