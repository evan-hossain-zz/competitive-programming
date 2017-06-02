#include<stdio.h>
#include<string.h>

int fibo[46] = {1, 1, 2, 3, 5, 8, 13, 21,\
                34, 55, 89, 144,233, 377, 610,\
                987, 1597, 2584, 4181, 6765,\
                10946, 17711, 28657, 46368, 75025,\
                121393, 196418, 317811, 514229,\
                832040, 1346269, 2178309, 3524578,\
                5702887, 9227465, 14930352, 24157817,\
                39088169, 63245986, 102334155, 165580141,\
                267914296, 433494437, 701408733,\
                1134903170,1836311903
               };

int main()
{
    int n, nums[101], tst, i, num, max, j, k;
    char cipher[101], message[101], ch;
    scanf("%d", &tst);
    while(tst--)
    {
        max = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        for(i = 0; i < 101; i++)
        {
            message[i] = ' ';
            cipher[i] = '\0';
        }
        i = 0;
        ch = getchar();
        while((ch = getchar()) != '\n')
        {
            if(ch >= 'A' && ch <= 'Z')
                cipher[i++] = ch;
        }
        cipher[i] = '\0';
        for(i = 0, k = 0; i < n; i++)
        {
            for(j = 1; j < 46; j++)
            {
                if(nums[i] == fibo[j] && cipher[k] != '\0')
                {
                    message[j-1] = cipher[k];
                    if(j > max)
                        max = j;
                    k++;
                }
            }
        }
        message[max] = '\0';
        printf("%s\n", message);
    }
    return 0;
}
