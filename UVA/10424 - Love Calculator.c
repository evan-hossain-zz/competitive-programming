#include<stdio.h>
#include<string.h>


int main()
{
    char a[27], b[27];
    int cnt1, cnt2, i, div, l;
    while(scanf(" %[^\n] %[^\n]", a, b) == 2)
    {
        cnt1 = cnt2 = 0;
        l = strlen(a);
        for(i = 0; i < l; i++)
        {
            if(a[i] >= 'A' && a[i] <= 'Z')
                cnt1 += a[i] - 64;
            else if(a[i] >= 'a' && a[i] <= 'z')
                cnt1 += a[i] - 96;
        }
        l = strlen(b);
        for(i = 0; i < l; i++)
        {

            if(b[i] >= 'A' && b[i] <= 'Z')
                cnt2 += b[i] - 64;
            else if(b[i] >= 'a' && b[i] <= 'z')
                cnt2 += b[i] - 96;
        }
        printf("%d %d", cnt1, cnt2);
        div = cnt1;
        while(div)
        {
            div = cnt1 / 10;
            cnt1 = div + cnt1 % 10;
        }
        div = cnt2;
        while(div)
        {
            div = cnt2 / 10;
            cnt2 = div + cnt2 % 10;
        }
        if(cnt1 < cnt2)
            printf("%.2f %%\n", (float)(cnt1 * 100) / cnt2);
        else
            printf("%.2f %%\n", (float)(cnt2 *100) / cnt1);
    }
    return 0;
}
