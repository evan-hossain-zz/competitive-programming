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

pair <int, int> pr;

vector < pair<int, int> > jora, ans, fin;

int main()
{
    map < pair<int, int> > mp;
    int n, m, i, j;
    pr a, b;
    double dist;
    cin >> n >> m;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            mk.x = i, mk.y = j;
            jora.pub(mk);
        }
    }
    for(i = 0; i < jora.size(); i++)
    {
        for(j = 0; j < jora.size(); j++)
        {
            if(i != j)
            {
                a = jora[i], b = jora[j];
                dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
//                cout << dist << endl;
                if(dist - (int) dist != 0)
                    ans.pub(a), ans.pub(b);
            }
        }
    }
    for(i = 0; i < ans.size(); i++)
    {
        for(j = 0; j < ans.size(); j++)
        {
            if(i != j)
            {
                if(ans[i].x == ans[j].x && ans[i].y == ans[j].y)
                    continue;
            }
        }
    }
    return 0;
}

