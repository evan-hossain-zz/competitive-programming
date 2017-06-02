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

int dp[12][12], m, n, digits[12];

int call(int indx, int sz);

int main()
{
    int i, test, kase;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; i++)
            scanf("%d", &digits[i]);
        int tot = 0;
        for(i = 0; i < m; i++)
            tot += call(i, 1);
        printf("Case %d: %d\n", kase, tot);
    }
    return 0;
}

int call(int indx, int sz)
{
    int &ret = dp[indx][sz];
    if(ret != -1)
        return ret;
    if(sz == n)
        return 1;
    ret = 0;
    for(int j = 0; j < m; j++)
    {
        if(abs(digits[indx] - digits[j]) < 3)
        {
//            cout << indx << ' ' << j << endl;
            ret += call(j, sz + 1);
        }
    }
    return ret;
}
