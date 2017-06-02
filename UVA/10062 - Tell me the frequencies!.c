#include<stdio.h>
#include<string.h>

int input[96];

int main()
{
    freopen("out.txt", "w", stdout);
    int i, j, l = 0, m = 0, max = 0;
    char ch, paisi = 0;
    while(scanf("%c", &ch) == 1)
    {
        if(ch == '\n')
            paisi = 1;
        else
        {
            m = ++input[ch - 32];
            if(m > max) max = m;
        }
        if(paisi == 1)
        {
            if(l != 0)
            {
                printf("\n");
                l++;
            }
            j = 1;
            while(1)
            {
                i = 96;
                if(j > max) break;
                while(i)
                {
                    if(j == input[--i])
                    {
                        printf("%d %d\n", i + 32, j);
                        input[i] = 0;
                    }
                }
                j++;
            }
            max = paisi = 0;
            l++;
        }
    }
    return 0;
}
