#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    typedef struct{
        int n1;
        char sign;
        int n2;
    } data;
    data equ;
    char ch[5];
    int i, j, l, cnt = 0, sum, n1, n2;
    while(scanf("%d %c %d", &equ.n1, &equ.sign, &equ.n2) == 3)
    {
        sum = 0;
        if(equ.sign == '+')
            sum = equ.n1 + equ.n2;
        else
            sum = equ.n1 - equ.n2;
        scanf(" %s", ch);
        l = strlen(ch);
        j = 0;
        for(i = l - 1; i > 0; i--)
        {
            if(ch[i] >= '0' && ch[i] <= '9')
            {
                sum -= (ch[i] - '0') * pow(10, j++);
            }
        }
        if(sum == 0)
            cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
