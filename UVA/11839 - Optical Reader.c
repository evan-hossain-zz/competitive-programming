#include <stdio.h>

int main()
{
    int opt[5], n, flag;
    char res;
    while(scanf("%d", &n) == 1 && n)
    {
        while(n--)
        {
            flag = res = 0;
            scanf("%d %d %d %d %d", &opt[0], &opt[1],\
            &opt[2], &opt[3], &opt[4]);
            if(opt[0] <= 127)
            {
                res = 65;
                flag++;
            }
            if(opt[1] <= 127)
            {
                res = 66;
                flag++;
            }
            if(opt[2] <= 127 && flag < 2)
            {
                res = 67;
                flag++;
            }
            if(opt[3] <= 127 && flag < 2)
            {
                res = 68;
                flag++;
            }
            if(opt[4] <= 127 && flag < 2)
            {
                res = 69;
                flag++;
            }
            if(flag == 1)
                printf("%c\n", res);
            else
                printf("*\n");
        }
    }
}
