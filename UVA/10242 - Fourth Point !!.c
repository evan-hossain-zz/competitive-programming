#include<stdio.h>

int main()
{
    double a1, a2, b1, b2, c1, c2, d1, d2;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a1, &a2, &b1, &b2, &c1, &c2, &d1, &d2) == 8)
    {
        if(b1 == d1 && b2 == d2)
            printf("%.3lf %.3lf\n", a1 + c1 - b1, a2 + c2 - b2);
        else if(b1 == c1 && b2 == c2)
            printf("%.3lf %.3lf\n", a1 + d1 - b1, a2 + d2 - b2);
        else if(a1 == d1 && a2 == d2)
            printf("%.3lf %.3lf\n", b1 + c1 - a1, b2 + c2 - a2);
        else if(a1 == c1 && a2 == c2)
            printf("%.3lf %.3lf\n", b1 + d1 - a1, b2 + d2 - a2);
    }
    return 0;
}
