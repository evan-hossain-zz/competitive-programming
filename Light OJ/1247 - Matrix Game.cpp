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
#define SZ 60

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL piles[SZ];

int main()
{
    int n, m, i, j, t, ans;
    LL cur;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
        {
            piles[i] = 0;
            for(j = 0; j < m; j++)
            {
                scanf("%d", &cur);
                piles[i] += cur;
            }
        }
        ans = piles[0];
        for(i = 1; i < n; i++)
            ans = (ans | piles[i]);
        if(ans)
            printf("Case %d: Alice\n", kase);
        else
            printf("Case %d: Bob\n", kase);
    }
    return 0;
}
