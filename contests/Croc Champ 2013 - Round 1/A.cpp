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

int main()
{
    int q = 0, a = 0, b = 0, t, c, n, mxq = 0, i, j, lst = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> t >> c;
        if(i == 0)
            a = t, q = c;
        mxq = max(mxq, q);
        for(j = a; j < t; j++)
            q--;
        q = max(0, q);
        if(i != 0)
        {
            q += c;
            a = t;
        }
        mxq = max(mxq, q);
    }
    cout << q+t << ' ' << mxq << endl;
    return 0;
}

