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
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y, s; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;
template <class T> T sqr(T a){return a * a;}    // square
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b

#define MAX 100010

int n;

point arr[55];


double gettime(point a, point b)
{
    return getdist(a, b) / ((double) a.s);
}

double calculate(int x, int y)
{
    point p(x, y);
    double dist = 0;
    for(int i = 0; i < n; i++)
        dist = max(dist, gettime(arr[i], p));
    return dist;
}

double find_y(int x)
{
    double ans;
    int i, midl, midh, low = -1e6, high = 1e6;
    for(i = 0; i < 50; i++)
    {
        midl = ((low * 2) + high) / 3;
        midh = (low + (high * 2)) / 3;
        double l = calculate(x, midl);
        double h = calculate(x, midh);
        if(l < h)
            high = midh;
        else
            low = midl;
        cout << low << ' ' << high << endl;
        ans = min(l, h);
    }
    return ans;
}

int main()
{
    int test, i, j;
    double ans;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> arr[i].x >> arr[i].y >> arr[i].s;
        int low = -1e6, high = 1e6, midl, midh;
        for(i = 0; i < 50; i++)
        {
            midl = ((low * 2) + high) / 3;
            midh = (low + (high * 2)) / 3;
            double l = find_y(midl);
            double h = find_y(midh);
            if(l < h)
                high = midh;
            else
                low = midl;
            ans = min(l, h);
        }
        cout << ans << endl;
    }
    return 0;
}

