#include<stdio.h>

int main()
{
    int n, data[52], temp, i, swap, j, tst, p;
    scanf("%d", &tst);

    while(tst--)
    {
        swap = 0;
        scanf("%d", &n);
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
                    swap++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swap);
    }

    return 0;
}

