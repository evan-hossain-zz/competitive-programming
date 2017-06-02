#include<stdio.h>

int main()

{
    int v, t, s = 0;
    while (scanf("%d %d", &v, &t) == 2)
    {
        s = 2 * v * t;
        printf("%d\n", s);
    }
    return 0;
}
