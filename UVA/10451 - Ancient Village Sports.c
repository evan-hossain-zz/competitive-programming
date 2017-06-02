#include<stdio.h>
#include<math.h>
#define PI 2 * acos(0)

int main()
{
    int n, kase = 1;
    double tarea, parea, r1, r2, c;
    while(scanf("%d %lf", &n, &parea) == 2 && n >= 3)
    {
        tarea = parea / n;
        r1 = sqrt(2 * tarea / (sin(2 * PI / n)));
        c = tarea * 2 / (r1 * sin((PI/2) - (PI / n)));
        r2 = .5 * sqrt(4 * r1 * r1 - (c * c));
        printf("Case %d: %.5lf %.5lf\n", kase++, PI
               * r1 * r1 - parea, parea - (r2 * r2 * PI));
    }
    return 0;
}
