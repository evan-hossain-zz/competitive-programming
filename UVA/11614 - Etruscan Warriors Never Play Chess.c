#include<stdio.h>
#include<math.h>

int main()
{
    long long n=999999999999999999;
    int tst;
    //scanf("%d", &tst);
    //while(tst--)
    {
        //scanf("%lld", &n);
        n = (sqrt(1 + 8 * n) - 1) / 2;
        printf("%lld\n", n);
    }
    return 0;
}
