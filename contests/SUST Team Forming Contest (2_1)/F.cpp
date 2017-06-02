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

char grid[110][10010];
int value[110][10010], cost[110][10010], r, c;

int srch(int val, int low, int high, int row)
{
    int mid, ans = -1;
    while(low <= high)
    {
        mid = low + high >> 1;
        if(value[row][mid] >= val)
        {
            high = mid - 1;
            if(grid[row][mid] == '1')
                ans = mid;
        }
        else
            low = mid + 1;
    }
    if(value[row][ans] == val)
        return ans;
    return -1;
}

int main()
{
    int i, j, rpos, lpos;
    while(cin >> r >> c)
    {
        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
            {
                cin >> grid[i][j];
                value[i][j] = grid[i][j] - '0';
                cost[i][j] = 0;
            }
        for(i = 0; i < r; i++)
            for(j = 1; j < c; j++)
                value[i][j] += value[i][j - 1];
        for(i = 0; i < r; i++)
            if(value[i][c - 1] == 0)
            {
                printf("-1\n");
                break;
            }
        if(i < r)
            continue;
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                if(grid[i][j] == '0')
                {
                    rpos = srch(value[i][j] + 1, j + 1, c-1, i);
                    lpos = srch(value[i][j], 0, j - 1, i);
                    if(rpos != -1)
                        rpos = min(rpos - j, c - 1 - rpos + j + 1);
                    if(lpos != -1)
                        lpos = min(j - lpos, c - 1 - j + lpos + 1);
                    if(lpos == -1)
                        cost[i][j] = rpos;
                    else if(rpos == -1)
                        cost[i][j] = lpos;
                    else
                        cost[i][j] = min(lpos, rpos);
                }
            }
        }
        for(i = 0; i < c; i++)
        {
            for(j = 1; j < r; j++)
                cost[j][i] += cost[j - 1][i];
        }
        int ans = infinity;
        for(i = 0; i < c; i++)
            ans = min(ans, cost[r - 1][i]);
        cout << ans << endl;
    }
    return 0;
}

