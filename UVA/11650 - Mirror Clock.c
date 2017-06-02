#include<stdio.h>

int main()
{
    int h, m, i, tst;
    scanf("%d", &tst);
    while(tst--)
    {
        scanf("%d : %d", &h, &m);
        m = 60 - m;
        if(m == 60)
            h = 12 - h % 12;
        else
            h = 11 - h % 12;
        if(m == 0 || m == 60)
            m = 0;
        if(h == 0)
            h = 12;
        printf("%02d:%02d\n", h, m);
    }
    return 0;
}
