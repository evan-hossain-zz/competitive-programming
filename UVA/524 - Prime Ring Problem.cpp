#include <iostream>
#include <cstdio>
#include <vector>

#define pub push_back
#define pob pop_back

using namespace std;

int taken[20], n, cnt;
int primes[35] = {0, 0, 1, 1, 0, 1, 0, 1, 0,
            0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,\
            0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,\
            1, 0, 0, 0};
vector <int> res;

void call(void);

int main()
{
    //freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) == 1)
    {
        if(cnt)
            printf("\n");
        printf("Case %d:\n", ++cnt);
        if(n & 1)
            continue;
        res.pub(1);
        taken[1] = 1;
        call();
        res.clear();
    }
    return 0;
}

void call(void)
{
    if(res.size() == n)
    {
        if(primes[res[0] + res[res.size() - 1]] == 0)
            return;
        printf("%d", res[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", res[i]);
        printf("\n");
        return;
    }
    for(int i = 2; i <= n; i++)
    {
        if(taken[i] == 0 && primes[res[res.size() - 1] + i])
        {
            taken[i] = 1;
            res.pub(i);
            call();
            res.pob(), taken[i] = 0;
        }
    }
}
