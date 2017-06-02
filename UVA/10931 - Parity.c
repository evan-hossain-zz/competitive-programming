#include<stdio.h>

int main()
{
    int i, j, n, c;
    int bin[40];
    while(scanf("%d", &n) == 1 && n != 0)
    {
        i = 1;
        c = 0;
        for(j = 0; i > 0; j++)
        {
            i = n / 2;
            bin[j] = n % 2;
            if(bin[j] == 1)
                c++;
            n = i;
        }
        printf("The parity of ");
        for(i = j - 1; i >= 0; i--)
            printf("%d", bin[i]);
        printf(" is %d (mod 2).\n", c);
    }
    return 0;
}
