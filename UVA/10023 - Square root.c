#include<stdio.h>
#include<math.h>

int main()
{
    long double n;
    int tst;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%Lf", &n);
        n = sqrt(n);
        printf("%.0Lf\n\n", n);
    }
    return 0;
}
