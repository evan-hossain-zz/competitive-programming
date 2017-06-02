#include <stdio.h>

typedef struct{
    int num;
    int freq;
}data;
int main()
{
    data in[100000];
    int n, i = 0, j;
    while(scanf("%d", &n) == 1)
    {
        for(j = 0; j < i; j++)
        {
            if(in[j].num == n)
            {
                in[j].freq++;
                break;
            }
        }
        if(j == i)
            in[i++].num = n;
    }
    for(j = 0; j < i; j++)
        printf("%d %d\n", in[j].num, in[j].freq + 1);
    return 0;
}
