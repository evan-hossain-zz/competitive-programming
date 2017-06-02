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
#define SZ 10000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct info
{
    int a, b, hieght, area;
};

vector <info> v;

bool comp(const info &a, const info &b)
{
    return a.area > b.area;
}

int main()
{
    int n, i, j, x, y, z, H[500], mx, kase = 0;
    info t;
    while(scanf("%d", &n) == 1 && n)
    {
        memset(H, 0, sizeof H);
        v.clear();
        mx = 0;
        while(n--)
        {
            scanf("%d %d %d", &x, &y, &z);
            t.a = x, t.b = y, t.hieght = z, t.area = x * y;
            v.pub(t);
            t.a = y, t.b = x, t.hieght = z, t.area = x * y;
            v.pub(t);
            t.a = x, t.b = z, t.hieght = y, t.area = x * z;
            v.pub(t);
            t.a = z, t.b = x, t.hieght = y, t.area = x * z;
            v.pub(t);
            t.a = z, t.b = y, t.hieght = x, t.area = y * z;
            v.pub(t);
            t.a = y, t.b = z, t.hieght = x, t.area = y * z;
            v.pub(t);
        }
        sort(v.begin(), v.end(), comp);
        for(i = 0; i < v.size(); i++)
            H[i] = v[i].hieght;
        for(i = 0; i < v.size(); i++)
        {
            for(j = i + 1; j < v.size(); j++)
            {
                if(v[i].a > v[j]. a && v[i].b > v[j].b)
                    H[j] = max(H[j], H[i] + v[j].hieght), mx = max(mx, H[j]);
            }
        }
        printf("Case %d: maximum height = %d\n", ++kase, mx);
    }
    return 0;
}
