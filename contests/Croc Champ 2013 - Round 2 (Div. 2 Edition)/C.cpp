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
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int a[100];

int main()
{
    int n, x, i, y;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i == 1) x = a[1];
        else
        {
            y = a[i];
            while(x > 0 && y > 0)
            {
                if(x > y)
                    x %= y;
                else
                    y %= x;
            }
            x += y;
        }
    }
    for(i = 1; i <= n; i++)
    {
        if(x == a[i])
        {
            cout << x << endl;
            return 0;
        }
    }
    cout << "-1";
return 0;
}

