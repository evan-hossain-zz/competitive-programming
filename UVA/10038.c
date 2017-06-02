#include<stdio.h>

#define SIZE 3010

int main()
{
    int array[SIZE];
    int i, j, k, cnt, n, one, temp;
    while(scanf("%d", &n) == 1)
    {
        cnt = 0;
        one = 0;

        for(i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }
        for(i = 0; i < n - 1; i++)
        {
            array[i] = array[i] - array[i + 1];
            if(array[i] < 0)
                array[i] = -1 * array[i];
            cnt++;
        }
        for(i = 0; i < n - 1; i++)
        {
            for(j = i; j < n - 1; j++)
            {
                if(array[i] < array[j])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }

        for(j = 0; j < i - 1; j++)
        {
            array[j] = array[j] - array[j + 1];
            if(array[j] == 1)
                one++;
        }

        if(cnt == (n - 1) && one == (cnt - 1) || n == 1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
