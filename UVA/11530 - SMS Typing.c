#include<stdio.h>

int main()
{
    char ch[102];
    int cnt, tst, i, j;
    scanf("%d", &tst);
    for(i = 0; i <= tst; i++)
    {
        cnt = 0;
        getc;
        gets(ch);

        for(j = 0; ch[j] != '\0'; j++)
        {
            if(ch[j] == 'a' || ch[j] == 'd' || ch[j] == 'g' || ch[j] == 'j' || ch[j] == 'm' || ch[j] == 'p' || ch[j] == 't' || ch[j] == 'w' || ch[j] == ' ')
                cnt++;
            else if(ch[j] == 'b' || ch[j] == 'e' || ch[j] == 'h' || ch[j] == 'k' || ch[j] == 'n' || ch[j] == 'q' || ch[j] == 'u' || ch[j] == 'x')
                cnt = cnt + 2;
            else if(ch[j] == 'c' || ch[j] == 'f' || ch[j] == 'i' || ch[j] == 'l' || ch[j] == 'o' || ch[j] == 'r' || ch[j] == 'v' || ch[j] == 'y')
                cnt = cnt + 3;
            else if(ch[j] == 's' || ch[j] == 'z')
                cnt = cnt + 4;
        }
        if(i == 0)
            continue;
        else
            printf("Case #%d: %d\n", i, cnt);
    }
    return 0;

}
