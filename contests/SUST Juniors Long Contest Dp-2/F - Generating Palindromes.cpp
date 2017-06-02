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

char s[200];
int dp[110][110];

int need(int beg, int en);

int main()
{
    int test, kase, i;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        memset(dp, -1, sizeof dp);
        scanf(" %s", &s);
        printf("Case %d: %d\n", kase, need(0, strlen(s) - 1));
    }
    return 0;
}

int need(int beg, int en)
{
    int &ret = dp[beg][en];
    if(ret != -1)
        return ret;
    if(beg >= en)
        return ret = 0;
    if(s[beg] == s[en])
        return ret = need(beg + 1, en - 1);
    return ret = min(need(beg + 1, en), need(beg, en - 1)) + 1;
}
