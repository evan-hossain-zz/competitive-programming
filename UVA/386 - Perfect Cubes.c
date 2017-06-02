#include<stdio.h>

int main()
{
    register int a, b, c, d, sum = 0;
    for(a = 6; a <= 200; a++)
    {
        for(b = 2; b <= a; ++b)
            for(c = 2; c <= a; ++c)
                for(d = 2; d <= a; ++d)
                {
                    if((a*a*a == b*b*b+c*c*c+d*d*d) && b < c && c < d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
    }
    return 0;
}
