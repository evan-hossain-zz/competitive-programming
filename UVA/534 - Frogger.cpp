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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct point
{
    int a, b;
};

vector <point> v;
double grid[220][220];

int main()
{
    int i, j, n, k, kase = 0, l;
    point p;
    while(scanf("%d", &n) == 1 && n)
        {
            for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                        grid[i][j] = 100000000;
                }
            for(i = 0; i < 2; i++)
            {
                scanf("%d %d", &p.a, &p.b);
                v.pub(p);
            }
            l = n - 2;
            for(i = 0; i < l; i++)
                {
                    scanf("%d %d", &p.a, &p.b);
                    v.pub(p);
                }
            for(i = 0; i < n; i++)
                {
                    for(j = 0; j < n; j++)
                        {
                     if(i != j)
            grid[i][j] = sqrt(((v[i].a - v[j].a) * (v[i].a - v[j].a))
                   + ((v[i].b - v[j].b) * (v[i].b - v[j].b)));
                        }
                }
            for(k = 0; k < n; k++)
                for(i = 0; i < n; i++)
                    for(j = 0; j < n; j++)
          grid[i][j] = min(grid[i][j], max(grid[i][k], grid[k][j]));
            printf("Scenario #%d\n", ++kase);
            printf("Frog Distance = %.3lf\n\n", grid[0][1]);
            v.clear();
        }
    return 0;
}
