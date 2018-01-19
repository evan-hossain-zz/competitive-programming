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
#define SZ(v) (LL)(v.size())
#define eps 1e-7

LL col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
LL row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
LL col4[4] = {1, 0, -1, 0};
LL row4[4] = {0, 1, 0, -1};
//LL months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct poLL{LL x, y; poLL () {} poLL(LL a, LL b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(LL i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 2000010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL bringing_cost[MAX], sending_cost[MAX];

struct flight{
    LL d, f, t;
    LL c;
}arr[MAX];

bool comp(const flight &a, const flight &b)
{
    if(a.d != b.d)
        return a.d < b.d;
    return a.t < b.t;
}

int main()
{
    in;
    LL n, m, k, i, j;
    cin >> n >> m >> k;
    for(i = 0; i < m; i++)
        cin >> arr[i].d >> arr[i].f >> arr[i].t >> arr[i].c;
    sort(arr, arr+m, comp);
    // for(i = 0; i < m; i++)
    //     cout << arr[i].d << ' ' << arr[i].f << ' ' << arr[i].t << endl;
    map <LL,LL> mpp;
    LL cur_cost = 0;
    clr(bringing_cost, -1);
    clr(sending_cost, -1);
    for(i = 0; i < m; i++)
    {
        if(arr[i].t)
            continue;
        if(mpp.find(arr[i].f) == mpp.end())
        {
            mpp[arr[i].f] = arr[i].c;
            cur_cost += arr[i].c;
        }
        else if(mpp[arr[i].f] > arr[i].c)
        {
            cur_cost -= mpp[arr[i].f];
            cur_cost += arr[i].c;
            mpp[arr[i].f] = arr[i].c;
        }
        if(SZ(mpp) == n)
        {
            if(bringing_cost[arr[i].d] == -1 || bringing_cost[arr[i].d] > cur_cost)
                bringing_cost[arr[i].d] = cur_cost;
        }
    }
    mpp.clear();
    cur_cost = 0;

    for(i = m-1; i >= 0; i--)
    {
        if(arr[i].f)
            continue;
        if(mpp.find(arr[i].t) == mpp.end())
        {
            mpp[arr[i].t] = arr[i].c;
            cur_cost += arr[i].c;
        }
        else if(mpp[arr[i].t] > arr[i].c)
        {
            cur_cost -= mpp[arr[i].t];
            cur_cost += arr[i].c;
            mpp[arr[i].t] = arr[i].c;
        }
        if(SZ(mpp) == n)
        {
            if(sending_cost[arr[i].d] == -1 || sending_cost[arr[i].d] > cur_cost)
            sending_cost[arr[i].d] = cur_cost;
        }
    }
    LL res = LONG_MAX;
    for(i = 1, j = 1; i < MAX; i++)
    {
        if(bringing_cost[i] == -1)
            continue;
        while(j < MAX && (j-i <= k || sending_cost[j] == -1))
            j++;
        if(j < MAX)
        {
            cout << i << ' ' << j << ' ' << bringing_cost[i] << ' ' << sending_cost[j] << endl;
            res = min(res, bringing_cost[i] + sending_cost[j]);
        }
    }
    if(res == LONG_MAX)
        res = -1;
    cout << res;
    return 0;
}
