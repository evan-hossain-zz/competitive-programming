#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int n, i, j, l;
    char ch[40];
    while(scanf(" %s", ch) == 1)
    {
        if(strcmp(ch, "0") == 0)
            break;
        n = 0;
        l = strlen(ch);
        for(i = l, j = 0; i > 0; --i)
            n += (ch[j++] - '0') * (pow(2, i) - 1);
        printf("%d\n", n);
    }
    return 0;
}
