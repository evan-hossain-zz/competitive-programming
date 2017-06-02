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
#include <assert.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 502
/*************************************************HABIJABI ENDS HERE******************************************************/

int grid[MAX][MAX], n, m;

pair <int, int> get_row_bounds(int row, int low, int high)
{
    int mid, l = 1, r = m;
    pair <int, int> ret = make_pair(-1, -1);
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(grid[row][mid] >= low)
            r = mid - 1, ret.first = mid;
        else
            l = mid + 1;
    }
    l = 1, r = m;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(grid[row][mid] <= high)
            l = mid + 1, ret.second = mid;
        else
            r = mid - 1;
    }
    return ret;
}

pair <int, int> get_col_bounds(int row, int col, int low, int high)
{
    int l = row, r = n, mid;
    pair <int, int> ret = make_pair(row, -1);
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(grid[mid][col] <= high)
            l = mid + 1, ret.second = mid;
        else
            r = mid - 1;
    }
    return ret;
}

int get_side(int row, int col, int high, int lim)
{
    int low = 0, mid, ret = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(grid[row + mid][col + mid] <= lim)
        {
            low = mid + 1;
            ret = mid;
        }
        else
            high = mid - 1;
    }
    return ret;
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int i, j, q, low, high, side;
    pair <int, int> row_bounds, left_column, right_column;
    while(scanf("%d %d", &n, &m) == 2 && (n | m))
    {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                scanf("%d", &grid[i][j]);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d %d", &low, &high);
            side = 0;
            for(i = 1; i <= n - side; i++)
            {
                row_bounds = get_row_bounds(i, low, high);
                if(row_bounds.first == -1 || row_bounds.second == -1 || row_bounds.second < row_bounds.first)
                    continue;
                left_column = get_col_bounds(i, row_bounds.first, low, high);
                side = max(side, get_side(i, row_bounds.first, min(row_bounds.second -
                            row_bounds.first, left_column.second - left_column.first), high) + 1);
            }
            printf("%d\n", side);
        }
        printf("-\n");
    }
    return 0;
}



