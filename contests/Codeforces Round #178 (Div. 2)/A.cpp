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
int birds[110];
int tem[110];
int ans[110];

int main()
{
    int n, i, j, m, x, y, flag;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> tem[i];
    cin >> m;
    for(i = 0; i < m; i++)
    {
        cin >> x >> y;
        for(j = 1; j <= tem[x] && tem[x]; j++)
        {
            if(j < y)
                tem[x - 1]++;
            else if(j > y)
                tem[x + 1]++;
        }
        tem[x] = 0;
    }
    for(i = 1; i <= n; i++)
    {
        cout << tem[i] << endl;
    }
    return 0;
}

