#include<stdio.h>
#include<string.h>

int main()
{
    int a, b, cnt = 0, num;
    char ch, res[4];
    while(scanf("%d %c %d = %s", &a, &ch, &b, res) == 4)
    {
        if(strcmp(res, "?") == 0)
            continue;
        else
            num = atoi(res);
        if(ch == '+')
        {
            if(a + b == num)
                cnt++;
        }
        else if(ch == '-')
        {
            if(a - b == num)
                cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

