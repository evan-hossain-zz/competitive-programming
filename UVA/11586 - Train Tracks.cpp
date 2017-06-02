#include<cstdio>

int main()
{
    char ch;
    int tst, m, f;
    scanf("%d\n", &tst);
    while(tst--)
    {
        m = f = 0;
        while((ch = getchar()) != '\n')
        {
            if(ch == 'M') m++;
            else if(ch == 'F') f++;
        }
        if(m == f && m != 1)
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }
    return 0;
}
