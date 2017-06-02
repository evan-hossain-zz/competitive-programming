#include<stdio.h>

int age[103];

int main()
{
    int n, i, j, ages, max = 0;
    while(scanf(" %d", &n) == 1 && n != 0)
    {
        max = n;
        while(n--)
        {
            scanf(" %d", &ages);
            age[ages] += 1;
        }
        for(i = 0; i < 102; ++i)
        {
            if(age[i] != 0)
            {
                for(j = 0; j < age[i];)
                {
                    printf("%d", i);
                    j++;
                    if(max == 1)
                        printf("\n");
                    else
                        printf(" ");
                    max--;
                }
                age[i] = 0;
            }
        }
    }
    return 0;
}
