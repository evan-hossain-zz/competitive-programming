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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int indeg[SZ];

int main()
{
    int n, m, i, j, a, b, ones = 0, twos = 0, other = 0;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        indeg[a]++;
        indeg[b]++;
    }
    for(i = 1; i <= n; i++)
    {
        if(indeg[i] == 2)
            twos++;
        else if(indeg[i] == 1)
            ones++;
        else if(indeg[i] == n - 1)
            other++;
    }
    if(ones == 2 && (ones+twos == n))
        cout << "bus topology\n";
    else if(twos == n)
        cout << "ring topology\n";
    else if(ones == (n - 1) && other == 1)
        cout << "star topology\n";
    else
        cout << "unknown topology\n";
    return 0;
}

