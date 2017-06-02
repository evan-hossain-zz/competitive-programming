#include<stdio.h>

int main()
{
    int i, tst, n, data[102], temp, j;
    scanf("%d", &tst);
    while(tst--)
    {
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
                }
            }
        }

        printf("%d\n", (data[n - 1] - data[0]) * 2);
    }
    return 0;
}
