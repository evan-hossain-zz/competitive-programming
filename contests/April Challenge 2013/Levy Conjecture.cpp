#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 10010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

bool flag[SZ];
int ans[SZ];
vector <int> primes;
int sieve()
{
    int i, j, cnt = 0;
    flag[1] = flag[0] = 1;
    for(i = 4; i <= SZ; i += 2)
        flag[i] = 1;
    for(i = 2; i < SZ / i; i++)
    {
        if(flag[i] != 1)
        {
            for(j = 2; j * i < SZ; j++)
                flag[i * j] = 1;
        }
    }
    for(i = 0; i < SZ; i++)
    {
        if(!flag[i])
        {
            primes.pub(i);
            cnt++;
        }
    }
}

void precalculate(void)
{
    int i, n, cnt, j;
    for(i = 0; i < primes.size(); i++)
    {
        for(j = 0; primes[i] + primes[j] * 2 < SZ; j++)
            ans[primes[i] + primes[j] * 2]++;
    }
}

int main()
{
    sieve();
    precalculate();
    int kase, n, i, j;
    scanf("%d", &kase);
    while(kase--)
    {
        int cnt = 0;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}

