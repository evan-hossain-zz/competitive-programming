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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

char grid[1001][1001];
long long res[1001][1001], r, c;

void dfs(int orow, int ocol, char x, int val);
int countDigits(long long n);

int main()
{
    //out;
    string line;
    int digits[1001], rw, cl;
    while(getline(cin, line))
    {
        char chr;
        if(line == "%")
        {
            int cnt = 0;
            for(rw = 0; rw < r; rw++)
            {
                for(cl = 0; cl < c; cl++)
                {
                    if(grid[rw][cl] != 0)
                    {
                        ++cnt;
                        res[rw][cl] = cnt;
                        char ch = grid[rw][cl];
                        grid[rw][cl] = 0;
                        dfs(rw, cl, ch, cnt);
                    }
                }
            }
            for(int maxcol = 0; maxcol < c; maxcol++)
            {
                digits[maxcol] = 0;
                for(int k = 0; k < r; k++)
                    digits[maxcol] = max(countDigits(res[k][maxcol])
                                         , digits[maxcol]);
            }
            for(rw = 0; rw < r; rw++)
            {
                for(cl = 0; cl < c - 1; cl++)
                    printf("%*d ", digits[cl], res[rw][cl]);
                printf("%*d\n", digits[cl], res[rw][cl]);
            }
            printf("%%\n");
            c = r = 0;
            continue;
        }
        istringstream ss(line);
        c = 0;
        while(ss >> chr)
        {
            res[r][c] = 0;
            grid[r][c++] = chr;
        }
        r++;
    }
    int cnt = 0;
    for(rw = 0; rw < r; rw++)
    {
        for(cl = 0; cl < c; cl++)
        {
            if(grid[rw][cl] != 0)
            {
                ++cnt;
                res[rw][cl] = cnt;
                char ch = grid[rw][cl];
                grid[rw][cl] = 0;
                dfs(rw, cl, ch, cnt);
            }
        }
    }
    for(int maxcol = 0; maxcol < c; maxcol++)
    {
        digits[maxcol] = 0;
        for(int k = 0; k < r; k++)
            digits[maxcol] = max(countDigits(res[k][maxcol])
                                 , digits[maxcol]);
    }
    for(rw = 0; rw < r; rw++)
    {
        for(cl = 0; cl < c - 1; cl++)
            printf("%*d ", digits[cl], res[rw][cl]);
        printf("%*d\n", digits[cl], res[rw][cl]);
    }
    printf("%%\n");
    return 0;
}

void dfs(int orow, int ocol, char x, int val)
{
    int nrow, ncol, p, q;
    for(p = 0; p < 8; p++)
    {
        nrow = orow + row[p];
        ncol = ocol + col[p];
        if(nrow >= 0 && nrow < r && ncol >= 0 && ncol < c)
        {
            if(grid[nrow][ncol] == x)
            {
                grid[nrow][ncol] = 0;
                res[nrow][ncol] = val;
                dfs(nrow, ncol, x, val);
            }
        }
    }
}

int countDigits(long long n)
{
    int ret = 0;
    do
    {
        n /= 10;
        ret++;
    }
    while(n);
    return ret;
}
