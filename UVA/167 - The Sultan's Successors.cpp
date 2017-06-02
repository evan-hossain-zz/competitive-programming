#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define pub push_back
#define pob pop_back

using namespace std;

void input(void);
void call(void);
int check_corner(int rw, int cl);

int col[9], ss, grid[9][9], r, color[9][9];
vector <int> res;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        ss = 0;
        input();
        printf("%5d\n", ss);
        res.clear();
    }
    return 0;
}

void input(void)
{
    int i, j;
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            scanf("%d", &grid[i][j]);
    for(int ic = 0; ic < 8; ic++)
    {
        res.pub(grid[0][ic]);
        color[0][ic] = col[ic] = 1;
        r = 1;
        call();
        col[ic] = 0, color[0][ic] = 0;
        res.clear();
    }
}

void call(void)
{
    if(res.size() == 8)
    {
        int sum = 0;
        for(int p = 0; p < 8; p++)
            sum += res[p];
        ss = max(ss, sum);
        return;
    }
    for(int j = 0; j < 8; j++)
    {
        if(col[j] == 0 && check_corner(r, j))
        {
            col[j] = color[r][j] = 1;
            res.pub(grid[r][j]);
            r++;
            call();
            r--, res.pob(), col[j] = color[r][j] = 0;
        }
    }
}

int check_corner(int rw, int cl)
{
    int m, n;
    for(m = rw + 1, n = cl + 1; m < 8 && n < 8; m++, n++)
    {
        if(color[m][n])
            return 0;
    }
    for(m = rw - 1, n = cl - 1; m >= 0 && n >= 0; m--, n--)
    {
        if(color[m][n])
            return 0;
    }
    for(m = rw - 1, n = cl + 1; m >= 0 && n < 8; m--, n++)
    {
        if(color[m][n])
            return 0;
    }
    for(m = rw + 1, n = cl - 1; m < 8 && n >= 0; m++, n--)
    {
        if(color[m][n])
            return 0;
    }
    return 1;
}
