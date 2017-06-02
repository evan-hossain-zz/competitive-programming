#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    double r1, r2, r3, a, b, c, res, tarea, carea, kon;
    int test;
    cin >> test;
    while(test--)
    {
        cin >> r1 >> r2 >> r3;
        a = r3 + r2;
        b = r1 + r3;
        c = r1 + r2;
        res = (a + b + c) / 2;
        tarea = sqrt(res * (res - a) * (res - b)\
                    * (res - c));
        kon = acos((b * b + c * c - a * a) / ( 2 * b * c));
        carea = kon * r1 * r1 / 2;
        tarea -= carea;
        kon = acos((a * a + c * c - b * b) / ( 2 * a * c));
        carea = kon * r2 * r2 / 2;
        tarea -= carea;
        kon = acos((b * b + a * a - c * c) / ( 2 * b * a));
        carea = kon * r3 * r3 / 2;
        tarea -= carea;
        printf("%lf\n", tarea);
    }
    return 0;
}
