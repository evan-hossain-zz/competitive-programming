#include<cstdio>
#include<cstdlib>
#include<math.h>

int main()
{
    int i, j, total, test, kase = 0;
    double tax, taka;
    scanf("%d", &test);
    while(test--)
    {
        tax = taka = 0.0;
        scanf("%d", &total);
        if(total > 180000)
            taka = total - 180000;
        if(taka > 0 && taka <= 300000)
        {
            tax += ceil(taka * 10 / 100);
            taka = 0;
        }
        else if(taka > 300000)
        {
            taka = taka - 300000;
            tax += 30000;
        }
        if(taka > 0 && taka <= 400000)
        {
            tax += ceil(taka * 15 / 100);
            taka = 0;
        }
        else if(taka > 400000)
        {
            taka = taka - 400000;
            tax += 60000;
        }
        if(taka > 0 && taka <= 300000)
            tax += ceil(taka * 20 / 100);
        else if(taka > 300000)
        {
            taka = taka - 300000;
            tax += 60000 + ceil(taka * 25 / 100);
        }
        if(tax > 0 && tax < 2000)
            printf("Case %d: 2000\n", ++kase);
        else
        printf("Case %d: %.lf\n", ++kase, ceil(tax));
    }
    return 0;
}
