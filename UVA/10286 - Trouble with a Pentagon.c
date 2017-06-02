#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979/180

int main()
{
    double n;
    while(scanf("%lf", &n) == 1)
    {
        printf("%.10lf\n", (n / sin(63 * PI)) * sin(108 * PI));
    }
    return 0;
}
