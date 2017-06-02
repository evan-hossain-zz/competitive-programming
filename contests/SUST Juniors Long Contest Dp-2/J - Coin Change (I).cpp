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
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

const LL mod = 100000007;

int n, k, cnt, coins[55], freq[55];
LL dp[55][20010];

LL call(int indx, int sum);

int main()
{
    int i, test, kase, j, f;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++)
            scanf("%d", &coins[i]);
        for(i = 0; i < n; i++)
            scanf("%d", &freq[i]);
        cnt = 0;
        printf("Case %d: %lld\n", kase, call(0, 0));
    }
    return 0;
}

LL call(int indx, int sum)
{
    LL &ret = dp[indx][sum];
    if(ret != -1)
        return ret;
    if(indx >= n)
        return ret = sum == k;
    if(sum > k)
        return ret = 0;
    ret = 0;
    for(int i = 0; i <= freq[indx]; i++)
        ret = (call(indx + 1, sum + (coins[indx] * i)) % mod) + ret;
    return ret % mod;
}
