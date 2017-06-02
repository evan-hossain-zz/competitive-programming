#include<stdio.h>
#include<string.h>

int check[19];
int main()
{
    register int i;
    int n;
    for(i = 0; i < 19; ++i)
        check[i] = 2 << i;
    for(i = 0; i < 19; ++i)
        printf("%d\n", check[i]);
    while(scanf("%d", &n) == 1 && n != 0)
    {
        for(i = 0; i < 18;)
        {
            if(n > check[i] && n <= check[i + 1])
            {
                n = check[i + 1] - ((check[i + 1] - n) * 2);
                break;
            }
            else
                ++i;
        }
        printf("%d\n", n);
    }
    return 0;
}
