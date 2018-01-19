#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("input.in", "r", stdin);
#define out freopen("output.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 505
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[MAX][MAX], n, m, k, q;
struct node{
    int x, y, t;
}query[MAX*MAX];

bool comp(const node &a, const node &b)
{
    return a.t < b.t;
}

void break_pixels(int mid)
{
    clr(arr, 0);
    for(int i = 1; i <= mid; i++)
        arr[query[i].x][query[i].y]++;
}

bool done(int mid)
{
    int i, j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            arr[i][j] += arr[i][j-1];

    for(j = 1; j <= m; j++)
        for(i = 1; i <= n; i++)
            arr[i][j] += arr[i-1][j];

    for(i = k; i <= n; i++)
        for(j= k; j <= m; j++)
        {
            LL sum = arr[i][j] - arr[i-k][j] - arr[i][j-k] + arr[i-k][j-k];
            if(sum == k*k)
                return true;
        }
    return false;
}

int main()
{
    // in;
    cin >> n >> m >> k >> q;
    for(int i = 1; i <= q; i++)
        cin >> query[i].x >> query[i].y >> query[i].t;
    sort(query+1, query+q+1, comp);
    // for(int i = 0; i < q; i++)
    //     cout << query[i].x << ' ' << query[i].y << ' ' << query[i].t << endl;
    int low = 1, high = q, mid, res = -1;
    while(low <= high)
    {
        mid = (low+high)/2;
        break_pixels(mid);
        if(done(mid))
        {
            res = query[mid].t;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    cout << res << "\n";
    return 0;
}
