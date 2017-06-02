#include<stdio.h>

typedef struct
{
    char address[110];
    int value;
} info;
info web[10];

int main()
{
    int tst, i, max, j;
    scanf("%d", &tst);
    for(i = 1; i <= tst; i++)
    {
        max = j = 0;
        while(j < 10)
        {
            scanf(" %s %d", web[j].address, &web[j].value);
            if(max < web[j].value)
                max = web[j].value;
            j++;
        }
        printf("Case #%d:\n", i);
        for(j = 0; j < 10; j++)
        {
            if(web[j].value == max)
                printf("%s\n", web[j].address);
        }
    }
    return 0;
}
