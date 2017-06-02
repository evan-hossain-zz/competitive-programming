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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

const int mod = 1000000007;

int dp[1005][11], n, k;

int call(int pass, int player)
{
    int &ret = dp[pass][player];
    if(pass > n)
        return ret = 0;
    if(ret != -1)
        return ret;
    if(pass == n && player == 0)
        return ret = 1;
    ret = 0;
    for(int i = 0; i <= k; i++)
    {
        if(i != player)
            ret = (call(pass + 1, i) % mod + ret) % mod;
    }
    return ret;
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while(kase--)
    {
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &n, &k);
        printf("%d\n", call(0, 0));
    }
    return 0;
}

