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
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 35

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int n, k;

LL position(int row, int rook, LL way);
LL dp[SZ][SZ], ans;

int main()
{
    int test, i, j;
    scanf("%d", &test);
    for(int kase = 1; kase <= test; kase++)
        {
            memset(dp, -1, sizeof(dp));
            scanf("%d %d", &n, &k);
            ans = position(1, 1, 1);;
//            position(1, 1, 1);
            printf("Case %d: %lld\n", kase, ans);
        }
    return 0;
}

LL position(int row, int rook, LL way)
{
    if(row > n && rook <= k)
        return 0;
    if(rook > k)
    {
        return way;
    }
    if(dp[row][rook] != -1)
        return dp[row][rook];
    return dp[row][rook] = position(row + 1, rook + 1, way * (n - (rook - 1))) + position(row + 1, rook, way);
//    position(row + 1, rook + 1, way * (n - (rook - 1)));
//    position(row + 1, rook, way);
}

