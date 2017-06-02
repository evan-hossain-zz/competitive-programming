#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL m;

LL func(LL a, LL b)
{
    if(a >= m || b >= m)
        return 0;
    if(a > b)
        return func(a, a + b) + 1;
    return func(a + b, b) + 1;
}

int main()
{
    LL x, y, diff;
    cin >> x >> y >> m;
    if(max(x, y) >= m)
    {
        cout << 0 << endl;
        return 0;
    }
    if(max(x, y) <= 0)
    {
        cout << -1 << endl;
        return 0;
    }
    LL mn = min(x, y), mx = max(x, y), ans = 0;
    if(mn < 0 && m > 0)
    {
        ans =(-mn / mx) + (mn % mx != 0);
        mn += mx * ans;
    }
    ans += func(mn, mx);
    cout << ans << endl;
    return 0;
}

