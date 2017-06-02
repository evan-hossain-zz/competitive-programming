
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

bool comp(const int &a, const int &b)
{
    return a > b;
}

int main()
{
    int n, m, cart[SZ], items[SZ], i, j, mn = infinity, sum, cnt, l;
    cin >> m;
    for(i = 0; i < m; i++)
        cin >> cart[i];
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> items[i];
    sort(items, items+n, comp);
    for(i = 0; i < m; i++)
    {
        sum = cnt = l = 0;
        for(j = 0; j < n - 2;)
        {
            for(int k = 0; k < cart[i]; k++)
                sum += items[j++];
            j += 2;
        }
        if(sum)
        {
            while(j <= n - 1)
                sum += items[j++];
        }
        else
        {
            j = 0;
            while(j <= n - 1)
                sum += items[j++];
        }
        if(j == n)
            mn = min(sum, mn);
    }
    cout << mn << endl;
    return 0;
}
