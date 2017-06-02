#include <stdio.h>
#include <math.h>

int main()
{
    int test, i, kase = 0;
    double ans, n;
    scanf("%d", &test);
    while(kase < test)
    {
        ans = 0;
        i = 12;
        while(i--)
        {
            scanf("%lf", &n);
            ans += n;
        }
        ans /= 12.0;
        if(ans > 999.00)
            printf("%d $%d,%.2lf\n", ++kase,\
        int(ans / 1000), fmod(ans, 1000));
        else
            printf("%d $%.2lf\n", ++kase, ans);
    }
    return 0;
}
