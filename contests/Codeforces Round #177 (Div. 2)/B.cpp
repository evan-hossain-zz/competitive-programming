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

int mat[110][110];

int main()
{
    int n, m, d, i, j, k, l, mn = infinity, flag = 0;
    cin >> n >> m >> d;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> mat[i][j];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            int val = mat[i][j];
            int moves = 0;
            flag = 1;
            for(k = 0; k < n && flag; k++)
                for(l = 0; l < m; l++)
                {
                    if(abs(val - mat[k][l]) % d == 0)
                        moves += (abs(val - mat[k][l]) / d);
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            if(flag)
                mn = min(mn, moves);
        }
    }
    if(mn == infinity)
        cout << -1;
    else
        cout << mn;
    return 0;
}

