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

char str[1010];
int len, dp[1010];

int part(int beg);
bool palindrome(int beg, int en);

int main()
{
    int test, kase;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        memset(dp, -1, sizeof dp);
        scanf(" %s", &str);
        len = strlen(str);
        part(0);
        printf("Case %d: %d\n", kase, dp[0]);
    }
    return 0;
}

int part(int beg)
{
    int &ret = dp[beg];
    if(beg == len)
        return ret = 0;
    int mx = 2000, ret1;
    if(ret != -1)
        return ret;
    for(int i = beg; i < len; i++)
    {
        if(palindrome(beg, i))
            ret1 = 1 + part(i + 1);
        else
            ret1 = i - beg + 1 + part(i + 1);
        mx = min(ret1, mx);
    }
    return ret = mx;
}

bool palindrome(int beg, int en)
{
    for(;beg <= en; beg++, en--)
    {
        if(str[beg] != str[en])
            return 0;
    }
    return 1;
}
