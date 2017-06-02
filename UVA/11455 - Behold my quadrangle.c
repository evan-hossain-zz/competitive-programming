#include<stdio.h>

int comp(const void *a, const void *b)
{
    int *p = (int *) a;
    int *q = (int *) b;
    return *q - *p;
}

int sides[4];
int main()
{
    int tst, i;
    scanf("%d", &tst);
    while(tst--)
    {
        i = 0;
        while(i < 4)
            scanf("%d", &sides[i++]);
        qsort(sides, 4, sizeof(int), comp);
        if(sides[0] == sides[3])
            printf("square");
        else if(sides[0] == sides[1] && sides[2] == sides[3])
            printf("rectangle");
        else if(sides[0] <= (sides[1] + sides[2] + sides[3]))
            printf("quadrangle");

        else
            printf("banana");
            printf("\n");
    }
    return 0;
}
