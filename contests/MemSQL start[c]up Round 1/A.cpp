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
#define SZ 20010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct point
{
    int a, b, c, d;
};
bool col[6];

point arr[6];
int X[40000];

int main()
{
    int n, i, j, k, l, m;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
        for(j = arr[i].a; j <= arr[i].c; j++)
        {
        }
    }
    return 0;
}

