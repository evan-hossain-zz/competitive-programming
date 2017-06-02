#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main()
{
    int tst, n, rlt[510], i, mid, ans;
    scanf("%d", &tst);
    while(tst--)
    {
        i = ans = 0;
        scanf("%d", &n);
        while(i < n)
        scanf("%d", &rlt[i++]);
        sort(rlt, rlt + n);
        if(n % 2 == 0)
            mid = n / 2 - 1;
        else
            mid = n / 2;
        for(i = 0; i < n; i++)
            ans += abs(rlt[mid] - rlt[i]);
        printf("%d\n", ans);
    }
    return 0;
}
