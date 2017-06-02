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

#define out freopen("out.out", "w", stdout);
#define in freopen("A-large.in", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int grid[8][8];

int row[4] = {2, 3, 4, 5};
int col[4] = {5, 4, 3, 2};

int main()
{
//    in;
//    out;
    int i, j, k, faka, kase, test, com, x, o;
    scanf(" %d ", &test);
    char c;
    for(kase = 1; kase <= test; kase++)
    {
        faka = com = x = o = 0;
        memset(grid, 0, sizeof grid);
        for(i = 2; i < 6; i++)
        {
            for(j = 2; j < 6; j++)
            {
                scanf(" %c", &c);
                if(!com)
                {
                    if(c == 'O')
                    {
                        grid[i][6]++;
                        grid[6][j]++;
                    }
                    else if(c == 'X')
                    {
                        grid[i][7]++;
                        grid[7][j]++;
                    }
                    else if(c == 'T')
                    {
                        grid[i][6]++;
                        grid[6][j]++;
                        grid[i][7]++;
                        grid[7][j]++;
                    }
                    else
                        faka = 1;
                    for(k = 0; k < 6; k++)
                    {
                        if(i == row[k] && j == col[k])
                        {
                            if(c == 'O')
                                grid[6][1]++;
                            else if(c == 'X')
                                grid[7][0]++;
                            else if(c == 'T')
                            {
                                grid[6][1]++;
                                grid[7][0]++;
                            }
                        }
                    }
                    if(i == j)
                    {
                        if(c == 'O')
                            grid[6][6]++;
                        else if(c == 'X')
                            grid[7][7]++;
                        else if(c == 'T')
                        {
                            grid[6][6]++;
                            grid[7][7]++;
                        }
                    }
                    for(k = 0; k < 8; k++)
                    {
                        if(grid[k][6] == 4 || grid[6][k] == 4)
                        {
                            o = 1;
                            com = 1;
                            break;
                        }
                        if(grid[k][7] == 4 || grid[7][k] == 4)
                        {
                            x = 1;
                            com = 1;
                            break;
                        }
                    }
                }
            }
        }
        if(o)
            printf("Case #%d: O won\n", kase);
        else if(x)
            printf("Case #%d: X won\n", kase);
        else if(!com && !faka)
            printf("Case #%d: Draw\n", kase);
        else if(!com && faka)
            printf("Case #%d: Game has not completed\n", kase);
    }
    return 0;
}

