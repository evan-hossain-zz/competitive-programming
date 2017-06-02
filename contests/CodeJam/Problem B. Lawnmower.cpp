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
#define in freopen("B-small-attempt0.in", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int row[11], col[11], grid[11][11];

int main()
{
//    in;
//    out;
    int n, m, i, j, key, test, kase, o, t;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        key = 0;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
        {
            o = t = 0;
            for(j = 0; j < m; j++)
            {
                scanf("%d", &grid[i][j]);
//                if(grid[i][j] == 1)
//                    o++;
//                else
//                    t++;
            }
//            if(o == m || t == m)
//                key = 1;
        }
//        if(key)
//        {
//            bool fault = 0;
//            for(i = 0; i < n && !fault; i++)
//            {
//                for(j = 1; j < m; j++)
//                {
//                    if(grid[i][j] != grid[i][j - 1])
//                    {
//                        fault = 1;
//                        break;
//                    }
//                }
//            }
//            if(fault)
//                printf("Case #%d: NO\n", kase);
//            else
//                printf("Case #%d: YES\n", kase);
//            continue;
//        }
        bool fault = 0;
        for(i = 0; i < n && !fault; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    o = t = 0;
                    for(int k = 0; k < n; k++)
                        if(grid[k][j] == 1)
                            o++;
                    for(int k = 0; k < m; k++)
                        if(grid[i][k] == 1)
                            t++;
                    if(o != n && t != m)
                    {
                        printf("Case #%d: NO\n", kase);
                        fault = 1;
                        break;
                    }
                }
            }
        }
        if(!fault)
            printf("Case #%d: YES\n", kase);
    }
    return 0;
}

