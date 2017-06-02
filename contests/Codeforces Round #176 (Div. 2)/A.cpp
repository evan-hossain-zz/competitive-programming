
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
#define SZ 1000000

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};

using namespace std;

char grid[5][5];

int main()
{
    int w, b, i, j, k, cnt = 0, p, q;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            cin >> grid[i][j];
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            b = w = 0;
            for(p = i; p < i + 2 && p < 4; p++)
            {
                for(q = j; q < j + 2 && q < 4; q++)
                {
                    if(grid[p][q] == '#')
                        w++;
                    else
                        b++;
                }
            }
            if(b > 2 || w > 2)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
        return 0;
}
