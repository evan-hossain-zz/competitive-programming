/*12
10
5
0
Sample Output


Case 1: 7
Case 2: 7
Case 3: 6
*/
#include<stdio.h>

int main()
{
    int temp[80];
    long long n, res;
    int i, j, k;
    while(scanf("%lld", &n) == 1 && n != 0)
    {
        j = 0;
        res = 0;
        int temp[] = {0};
        for(i = 1; i <= n / 2; i++)
        {
            if(n % i == 0)
                n = n / i;
            {
                for(k = 0; k <= i; k++)
                {
                    if(temp[k] != n)
                    {
                        temp[j] = n;
                        j++;
                    }
                }
            }
        }
        for(k = 0; k < j; k++)
            res +=temp[k];
        printf("%lld", res - n);
    }
}
