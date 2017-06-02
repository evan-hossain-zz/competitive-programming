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

int h[110], g[110];

int main()
{
    int team, host, guest, i, cnt = 0, j;
    cin >> team;
    for(i = 0; i < team; i++)
    {
        cin >> h[i] >> g[i];
    }
    for(i = 0; i < 105; i++)
    {
        for(j = 0; j < 105; j++)
        {
            if(g[i] > 0 && h[i] == g[j])
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}

