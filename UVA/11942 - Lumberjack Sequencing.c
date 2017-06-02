#include<stdio.h>
#include<string.h>

int main()
{
    int lamb[11];
    int i, j, n, o, d;
    scanf("%d", &n);
    printf("Lumberjacks:\n");
    while(n--)
    {
        o = d = 0;
        for(i = 0; i < 10; i++)
        {
            scanf("%d", &lamb[i]);
        }
        for(i = 0; i < 9; i++)
        {
            if(lamb[i] > lamb[i + 1])
                o++;
            else if(lamb[i] < lamb[i + 1])
                d++;
        }
        if(o == 9 || d == 9)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
