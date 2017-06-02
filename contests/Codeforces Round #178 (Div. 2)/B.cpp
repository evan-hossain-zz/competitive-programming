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
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int dp[110][300][300];

int t[110], w[110], n, ans = infinity;

void call(int indx, int niche, int upore)
{
    if(niche < upore)
        return;
    ans = min(ans, niche);
    if(dp[indx][niche][upore] != -1)
        return;
    dp[indx][niche][upore] = 1;
//    cout << indx << ' ' << niche << ' ' << upore << endl;
    if(indx >= n)
        return;
    call(indx + 1, niche - t[indx], upore + w[indx]);
    call(indx + 1, niche, upore);
}

int main()
{
    int i, totn = 0;
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> t[i] >> w[i];
        totn += t[i];
    }
    call(0, totn, 0);
    cout << ans << endl;
    return 0;
}

