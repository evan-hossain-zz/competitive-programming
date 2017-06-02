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

enum res{GOOD, BAD, MIXED};

int dp[55][55][55], len;
char str[55];

int call(int pos, int vwl, int con);
bool isvowel(char a)
{
    if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U')
        return true;
    return false;
}

int main()
{
    int test, kase;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        memset(dp, -1, sizeof dp);
        scanf(" %s", &str);
        len = strlen(str);
        int ans = call(0, 0, 0);
        if(ans == GOOD)
            printf("Case %d: GOOD\n", kase);
        else if(ans == MIXED)
            printf("Case %d: MIXED\n", kase);
        else
            printf("Case %d: BAD\n", kase);
    }
    return 0;
}

int call(int pos, int vwl, int con)
{
    int &ret = dp[pos][vwl][con];
    if(ret != -1)
        return ret;
    if(vwl >= 3 || con >= 5)
        return ret = BAD;
    if(pos >= len)
        return ret = GOOD;
    if(str[pos] == '?')
    {
        if(call(pos + 1, vwl + 1, 0) == BAD && call(pos + 1, 0, con + 1) == BAD)
            return ret = BAD;
        if(call(pos + 1, vwl + 1, 0) == GOOD && call(pos + 1, 0, con + 1) == GOOD)
            return ret = GOOD;
        return ret = MIXED;
    }
    if(isvowel(str[pos]))
        return ret = call(pos + 1, vwl + 1, 0);
    return ret = call(pos + 1, 0, con + 1);
}

