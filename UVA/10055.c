#include<stdio.h>

int main ()

{
    long long unsigned x, y, z;

    while(scanf("%llu %llu", &x, &y) == 2)
    {

        if (x > y)
            z = x - y;
        else
            z = y - x;

        printf("%llu\n", z);
    }
    return 0;
}
