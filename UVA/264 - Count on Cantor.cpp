#include <stdio.h>

typedef struct
{
    int a, b;
} in;
in cantors[10000050];
int main()
{
    int i, k = 3, n, u;
    cantors[1].a = 1, cantors[1].b = 1,
    cantors[2].a = u = 1, cantors[2].b = n = 2;
    while(n > 1)
        {
            cantors[k].a = ++u;
            cantors[k++].b = --n;
        }
    while(k <= 10000003)
    {
        cantors[k].a = ++u;
        cantors[k++].b = 1;
        while(u > 1 && k <= 10000003)
        {
            cantors[k].a = --u;
            cantors[k++].b = ++n;
        }
        cantors[k].b = ++n;
        cantors[k++].a = 1;
        while(n > 1 && k <= 10000003)
        {
            cantors[k].a = ++u;
            cantors[k++].b = --n;
        }

    }
    while(scanf("%d", &i) == 1)
    {
        printf("TERM %d IS %d/%d\n", i, cantors[i].a,\
        cantors[i].b);
    }
    return 0;
}
