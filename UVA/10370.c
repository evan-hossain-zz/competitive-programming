#include<stdio.h>
#define SZ 1000

int main()
{
    int n, i = 0, j = 0, sum = 0;
    int numbers[SZ];
    double avg = 0.0, res, cnt_nums = 0.0, abv_avg = 0.0;
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        abv_avg = 0.0;
        sum = 0;
        scanf("%lf", &cnt_nums);

        for(j = 0; j < cnt_nums; j++)
        {
            scanf("%d", &numbers[j]);
            sum = sum + numbers[j];
        }

        avg = (sum/cnt_nums);

        for(j = 0; j < cnt_nums; j++)
        {
            if(numbers[j] > avg)
                abv_avg++;
        }
        res = (abv_avg * 100) / cnt_nums;

        printf("%.3lf%%\n", res);

    }

    return 0;
}
