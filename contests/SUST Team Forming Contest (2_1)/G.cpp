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
#define SZ 110

int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

char grid[SZ][SZ];
int ans[SZ][SZ], r, c;

void check(void);

int main()
{
    int i, j, field = 1;
    while(cin >> r >> c && (r | c))
    {
        if(field > 1)
            printf("\n");
        printf("Field #%d:\n", field++);
        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
            {
                scanf(" %c", &grid[i][j]);
                if(grid[i][j] == '*')
                    ans[i][j] = -1;
                else
                    ans[i][j] = 0;
            }
        check();
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                if(ans[i][j] == -1)
                    printf("*");
                else
                    printf("%d", ans[i][j]);
            }
            cout << endl;
        }
    }
    return 0;
}

void check(void)
{
    int p, nr, nc;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(grid[i][j] == '.')
            {
                for(p = 0; p < 8; p++)
                {
                    nr = i + row[p];
                    nc = j + col[p];
                    if(nr >= 0 && nr < r && nc >= 0 && nc < c)
                    {
                        if(grid[nr][nc] == '*')
                        ans[i][j]++;
                    }
                }
            }
        }
    }
}
