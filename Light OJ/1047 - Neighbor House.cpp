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
#define infinity 21474836
#define LL long long
#define Pi acos(-1)
#define SZ 21

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int dp[SZ][3], info[SZ][3], houses;

int color(int bari, int cur, int agerta);

int main()
{
    int test, i, j, r, b, g;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
    {
        scanf("%d", &houses);
        for(i = 0; i < houses; i++)
            for(j = 0; j < 3; j++)
                scanf("%d", &info[i][j]);
        memset(dp, -1, sizeof(dp));
        r = color(0, 0, -1);
        b = color(0, 1, -1);
        g = color(0, 2, -1);
        printf("Case %d: %d\n", kase, min(r, min(b, g)));
    }
    return 0;
}

int color(int bari, int cur, int agerta)
{
    if(bari == houses)
        return 0;
    if(dp[bari][cur] != -1)
        return dp[bari][cur];
    int a, b;
    a = color(bari + 1, (cur + 1) % 3, cur);
    b = color(bari + 1, (cur + 2) % 3, cur);
    return dp[bari][cur] = min(a, b) + info[bari][cur];
}

