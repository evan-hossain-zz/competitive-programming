#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    char str[1000010], no, flag;
    int i = 0, j, k, l, test, ma, mi, m, n;
    while(scanf(" %[01]", str) == 1)
    {
        l = strlen(str);
        scanf("%d", &test);
        printf("Case %d:\n", ++i);
        while(test--)
        {
            no = 0;
            scanf("%d %d", &m, &n);
            ma = max(m, n);
            mi = min(m, n);
            flag = str[mi];
            for(j = mi++; j <= ma; j++)
            {
                if(str[j] != flag)
                    no = 1;
            }
            if(no == 1)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
}
