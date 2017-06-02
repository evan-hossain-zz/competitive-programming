#include<stdio.h>
#include<string.h>

int main()
{
    typedef struct{
        char words[20];
        int salary;
    }des;
    des dic[1010];
    int n, m, i = 0, j;
    long long ans;
    char temp[80];
    scanf("%d %d", &m, &n);
    while(i < m)
        scanf(" %s %d", dic[i++].words, &dic[i].salary);
    i = 0;
    ans = 0;
    while(i < n)
    {
        scanf(" %s", temp);
        if(strcmp(temp, ".") == 0)
        {
            printf("%lld\n",ans);
            ans = 0;
            i++;
            continue;
        }
        for(j = 0; j < m; j++)
        {
            if(strcmp(temp, dic[j].words) == 0)
                ans += dic[j].salary;
        }
    }
    return 0;
}
