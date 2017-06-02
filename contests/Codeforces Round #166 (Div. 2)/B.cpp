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
#define SZ 520

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

bool primes[100010];

void sieve(void)
{
    int i, j;
    primes[1] = 1;
    for(i = 4; i <= 100010; i += 2)
        primes[i] = 1;
    for(i = 2; i < 100010 / i; i++)
    {
        if(primes[i] != 1)
        {
            for(j = 2; j * i < 100010; j++)
                primes[i * j] = 1;
        }
    }
}
int moves[SZ][SZ], rw[SZ], cl[SZ];

int main()
{
    sieve();
    int grid[SZ][SZ], i, j, row, col, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    for(row = 0; row < n; row++)
    {
        for(col = 0; col < m; col++)
        {
            if(grid[row][col] % 2 && primes[grid[row][col]])
            {
                grid[row][col]++;
                moves[row][col]++;
            }
            while(primes[grid[row][col]])
            {
                grid[row][col]++;
                moves[row][col]++;
            }
        }
    }
//    for(i = 0; i < n; i++)
//    {
//        for(j = 0; j < m; j++)
//            cout << moves[i][j] << ' ';
//        cout << endl;
//    }
    int mn = infinity;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            rw[i] += moves[i][j];
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            cl[i] += moves[j][i];
    for(i = 0; i < n; i++)
       mn = min(mn, rw[i]);
    for(j = 0; j < m; j++)
        mn = min(mn, cl[j]);
    cout << mn << endl;
}
