#include<stdio.h>

int main()
{
    float a, b, x1, y1;
    typedef struct{
        float x;
        float y;
    }plot;
    plot cordnt;
    int tst;
    while(scanf("%d", &tst) == 1 && tst != 0)
    {
        scanf("%f %f", &x1, &y1);
        while(tst--)
        {
            a = x1;
            b = y1;
            scanf("%f %f", &cordnt.x, &cordnt.y);
            a = cordnt.x - a;
            b = cordnt.y - b;
            if(a > 0 && b > 0)
                printf("NE\n");
            else if(a > 0 && b < 0)
                printf("SE\n");
            else if(a < 0 && b > 0)
                printf("NO\n");
            else if(a < 0 && b < 0)
                printf("SO\n");
            else
                printf("divisa\n");
        }
    }
    return 0;
}
