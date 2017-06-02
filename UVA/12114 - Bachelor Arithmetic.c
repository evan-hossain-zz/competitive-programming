#include<stdio.h>

int main()
{
    int s, b, i = 0;
    while(scanf("%d %d", &s, &b) == 2 && (s | b))
    {
        if(s <= 1) printf("Case %d: :-\\\n", ++i);
        else if(s < b || s == b) printf("Case %d: :-|\n", ++i);
        else if(s > b) printf("Case %d: :-(\n", ++i);
    }
    return 0;
}
