#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

LL arr[SZ], incrs[SZ];

int main()
{
    int n, i, m, q, o, nw;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> arr[i];
    for(i = 0; i < m; i++)
    {
        cin >> o;
        if(o == 1)
        {
            cin >>  q >> nw;
            arr[q] = nw;
            incrs[q] = incrs[0];
        }
        else if(o == 2)
        {
            cin >> nw;
            incrs[0] += nw;
        }
        else if(o == 3)
        {
            cin >> nw;
            cout << arr[nw] + incrs[0] - incrs[nw] << endl;
        }
    }
    return 0;
}

