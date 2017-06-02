#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
#define A


int main()
{
    double r, res, a, n;
    while(scanf("%lf %lf", &r, &n) == 2)
    {
        res = n * (.5 * r * r * sin(2*PI/n));
        printf("%.3lf\n", res);
    }
    return 0;
}
