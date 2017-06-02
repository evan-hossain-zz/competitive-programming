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
#define infinity 214748
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};

using namespace std;

int grid[20][20], color[20][20];
int n, m, test, i, ar, ac, br, bc, cr, cc, hr, hc;

void initialize(void);
void bfs(int r, int c);
void colr(void)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            color[i][j] = 0;
}


int main()
{
    int i, j, ad, bd, cd;
    cin >> test;
    char x;
    for(int kase = 1; kase <= test; kase++)
    {
        cin >> n >> m;
        initialize();
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                scanf(" %c", &x);
                if(x != '#' && x != 'm')
                    grid[i][j] = 1;
                if(x == 'a')
                    ar = i, ac = j;
                else if(x == 'b')
                    br = i, bc = j;
                else if(x == 'c')
                    cr = i, cc = j;
                else if(x == 'h')
                    hr = i, hc = j;
            }
        }
        bfs(ar, ac);
        ad = color[hr][hc];
        colr();
        bfs(br, bc);
        bd = color[hr][hc];
        colr();
        bfs(cr, cc);
        cd = color[hr][hc];
        colr();
        printf("Case %d: %d\n", kase, max(ad, max(bd, cd)) - 1);
    }
    return 0;
}

void initialize(void)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            grid[i][j] = -1;
    return;
}

void bfs(int r, int c)
{
    queue <int> q;
    q.push(r), q.push(c);
    color[r][c] = 1;
    int i, nc, nr, rw, cl;
    while(!q.empty())
    {
        rw = q.front();
        q.pop();
        cl = q.front();
        q.pop();
        for(int p = 0; p < 4; p++)
        {
            nr = rw + row[p];
            nc = cl + col[p];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != -1 && color[nr][nc] == 0)
            {
//                cout << nr << ' ' << nc << endl;
                color[nr][nc] = color[rw][cl] + 1;
                if(nr == hr && nc == hc)
                {
//                    cout << hr << ' ' << hc << ' ' << color[hr][hc] << endl;
                    return;
                }
                q.push(nr), q.push(nc);
            }
        }
    }
}
