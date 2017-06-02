#include<stdio.h>
#include<math.h>

int main()
{
    long long unsigned n;
    double res;
    while(scanf("%llu", &n) == 1 && n != 0)
    {
        res = sqrt(n);
        if(res - (int) res == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
