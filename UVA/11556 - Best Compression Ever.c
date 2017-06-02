#include<stdio.h>
#include<math.h>

int main()
{
    long long n;
    int b;
    while(scanf("%lld %d", &n, &b) == 2)
    {
        if(n < pow(2, b+1))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
