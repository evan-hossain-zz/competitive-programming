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

using namespace std;

#define MAX 500010
#define infinity 60000000
#define LL long long
#define clr(arr, key) memset(arr, key, sizeof arr)

int full, more_bit[10], n, beton[110], dp[110][20000];
vector <int> can_teach[110];

int get_bit(int mask , int pos)
{
    return (mask / more_bit[pos]) % 3;
}
int set_bit(int mask, int pos , int bit)
{
    int tmp = (mask / more_bit[pos]) % 3;
    mask -= tmp * more_bit[pos];
    mask += bit * more_bit[pos];
    return mask;
}

int call(int indx, int mask)
{
    if(indx == n)
        return mask == full? 0 : infinity;
    if(mask == full)
        return 0;
    int &ret = dp[indx][mask], i, lim;
    if(ret != -1)
        return ret;
    ret = call(indx + 1, mask);
    lim = can_teach[indx].size();
    for(i = 0; i < lim; i++)
    {
        if(get_bit(mask, can_teach[indx][i]) < 2)
            mask = set_bit(mask, can_teach[indx][i], get_bit(mask, can_teach[indx][i]) + 1);
    }
    return ret = min(ret, call(indx + 1, mask) + beton[indx]);
}

int main()
{
    int i, s, m, res, mask, tem;
    char c;
    more_bit[1] = 3;
    for(i = 2; i < 10; i++) more_bit[i] = 3 * more_bit[i - 1];
    while(scanf("%d %d %d", &s, &m, &n) == 3 && (s || m || n))
    {
        mask = res = 0;
        full = more_bit[s + 1] - 3;
        for(i = 0; i < m; i++)
        {
            scanf("%d", &tem);
            res += tem;
            while((c = getchar()) != '\n')
            {
                if(isdigit(c))
                {
                    if(get_bit(mask, c - '0') < 2)
                        mask = set_bit(mask, c - '0', get_bit(mask, c - '0') + 1);
                }
            }
        }
        for(i = 0; i < n; i++)
        {
            can_teach[i].clear();
            scanf("%d", &beton[i]);
            while((c = getchar()) != '\n')
            {
                if(isdigit(c))
                    can_teach[i].push_back(c - '0');
            }
        }
        clr(dp, -1);
        res += call(0, mask);
        printf("%d\n", res);
    }
    return 0;
}

