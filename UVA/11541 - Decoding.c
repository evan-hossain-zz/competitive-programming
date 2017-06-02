#include<stdio.h>
#include<string.h>

int main()
{
    int tst, i, j, num, l, flag;
    char ch;
    scanf("%d\n", &tst);
    for(i = 1; i <= tst; ++i)
    {
        flag = 0;
        printf("Case %d: ", i);
        while(1)
        {
            if(flag == 0)
            {
                ch = getchar();
                if(ch == '\n')
                    break;
                flag = 1;
                continue;
            }
            else if(flag == 1)
            {
                scanf("%d", &num);
                flag = 0;
            }
            for(j = 0; j < num; j ++)
                printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
