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

using namespace std;

int res[93][9][9], taken[10], cnt, grid[9][9], atta, row[9], cur;

void generate(void);
void backtrack(void);
int check_corner(int r, int c);

int main()
{
    //freopen("out.txt", "w", stdout);
    generate();
    int test, rw, cl, soln;
    scanf("%d", &test);
    while(test--)
    {
        soln = 1;
        scanf("%d %d", &cl, &rw);
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        for(int check = 0; check < 93; check++)
        {
            if(res[check][rw][cl] == 1)
            {
                printf("%2d     ", soln++);
                for(int r = 1; r < 9; r++)
                    for(int cool = 1; cool < 9; cool++)
                    {
                        if(res[check][r][cool] == 1)
                            printf(" %d", cool);
                    }
                printf("\n");
            }
        }
        if(test)
            printf("\n");
    }
    return 0;
}

void generate(void)
{
    for(int COL = 1; COL < 9; COL++)
    {
        for(int i = 1; i < 9; i++)
        {
            for(int j = 1; j < 9; j++)
                grid[i][j] = 0;
            taken[i] = row[i] = 0;
        }
        taken[COL] = 1;
        row[1] = 1;
        grid[1][COL] = 1;
        cur = 2;
        atta = 1;
        backtrack();
    }
}

void backtrack(void)
{
    if(atta == 8)
    {
        for(int m = 1; m < 9; m++)
            for(int n = 1; n < 9; n++)
                res[cnt][m][n] = grid[m][n];
        cnt++;
        return;
    }
    for(int p = 1; p < 9; p++)
    {
        if(taken[p] == 0 && check_corner(cur, p))
        {
            taken[p] = 1;
            grid[cur][p] = 1;
            cur++, atta++;
            backtrack();
            cur--;
            grid[cur][p] = taken[p] = 0, atta--;
        }
    }
}

int check_corner(int r, int c)
{
    int y, z;
    for(y = r - 1, z = c - 1; y > 0 && z > 0; y--, z--)
    {
        if(grid[y][z] == 1)
            return 0;
    }
    for(y = r - 1, z = c + 1; y > 0 && z < 9; y--, z++)
    {
        if(grid[y][z] == 1)
            return 0;
    }
    for(y = r + 1, z = c - 1; y < 9 && z > 0; y++, z--)
    {
        if(grid[y][z] == 1)
            return 0;
    }
    for(y = r + 1, z = c + 1; y < 9 && z < 9; y++, z++)
    {
        if(grid[y][z] == 1)
            return 0;
    }
    return 1;
}
