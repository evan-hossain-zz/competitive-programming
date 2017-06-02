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

#define out freopen("output.out", "w", stdout);
#define in freopen("C-large-1.in", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 10000003

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> pal;
int ans[SZ];

void precalculate(void)
{
    int i, j, k;
    LL cur;
    string s;
    for(i = 1; i < SZ; i++)
    {
        stringstream ss;
        ss << i;
        s = ss.str();
        for(j = 0, k = s.size() - 1; j <= k; j++, k--)
        {
            if(s[j] != s[k])
                break;
        }
        if(j > k)
            pal.pub(i);
    }
    for(i = 0; i < pal.size(); i++)
    {
        cur = (LL) pal[i] * (LL) pal[i];
        stringstream ss;
        ss << cur;
        s = ss.str();
        for(j = 0, k = s.size() - 1; j <= k; j++, k--)
        {
            if(s[j] != s[k])
                break;
        }
        if(j > k)
            ans[pal[i]]++;
    }
    for(i = 2; i < SZ; i++)
        ans[i] += ans[i - 1];
}

int main()
{
//    in;
//    out;
    int test, kase, i, c, d;
    LL a, b;
    precalculate();
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%lld %lld", &a, &b);
        c = ceil(sqrt(a));
        d = sqrt(b);
        printf("Case #%d: %d\n", kase, ans[d] - ans[c - 1]);
    }
    return 0;
}
