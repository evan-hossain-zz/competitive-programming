#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#define infinity 20000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

int grid[105][105];

void initialize(int n);
void floyed(int n);

int main()
{
    int m, i, j, a, b, kase = 0, cnt;
    string s;
    double ans;
    map <int, int> mp;
    initialize(104);
    while(getline(cin, s))
        {
            istringstream ss(s);
            m = ans = 0;
            cnt = 0;
            while(ss >> a >> b && (a | b))
                {
                    grid[a][b] = 1;
                    m = max(max(a, b), m);
                    if(mp.find(a) == mp.end())
                        mp[a] = ++cnt;
                    if(mp.find(b) == mp.end())
                        mp[b] = ++cnt;
                }
            if(m)
                {
                    floyed(m);
                    for(i = 1; i <= m; i++)
                        for(j = 1; j <= m; j++)
                            if(grid[i][j] < infinity && grid[i][j])
                                ans += grid[i][j];
                    cnt = cnt * (cnt - 1);
                    printf("Case %d: average length\
 between pages = %.3lf clicks\n", ++kase, ans / cnt);
                    initialize(m);
                    mp.clear();
                }
            else
                break;
        }
    return 0;
}

void initialize(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
                grid[i][j] = infinity;
            grid[i][i] = 0;
        }
    return;
}

void floyed(int n)
{
    int i, j, k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
    return;
}


