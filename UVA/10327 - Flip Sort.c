#include<stdio.h>

int main()
{
    int n, data[1002], temp, i, flip, j;

    while(scanf("%d", &n) == 1 && n != 0)
    {
        flip = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &data[i]);
        for(i = 0; i < n; i++)
        {
            for(j = 1; j < n; j++)
            {
                if(data[j - 1] > data[j])
                {
                    temp = data[j];
                    data[j] = data[j - 1];
                    data[j - 1] = temp;
                    flip++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", flip);
    }
    return 0;
}
