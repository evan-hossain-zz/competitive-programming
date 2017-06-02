#include<stdio.h>

int digit[10];
int main()
{
    int i, div, test, n;
    scanf("%d", &test);
    while(test--)
    {
        i = div = 1;
        scanf("%d", &n);
        for(i = n; i > 0; i--)
        {
            div = i;
            do
            {
                digit[div % 10]++;
                div = div / 10;
            }
            while(div);
        }
        for(i = 0; i < 10; i++)
        {
            printf("%d",digit[i]);
            if(i != 9)
                printf(" ");
            else
                printf("\n");
            digit[i] = 0;
        }
    }
    return 0;
}
