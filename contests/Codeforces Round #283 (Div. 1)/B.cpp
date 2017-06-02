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
#define mp(a, b) make_pair(a, b)
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
template <class T> void show(T a){cout << a << endl;}
template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int one[MAX], two[MAX], arr[MAX], n;

pair <int, int> get(int indx, int val)
{
    int mid, low = indx, high = n, o = infinity, t = infinity;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(one[mid] - one[indx - 1] >= val)
        {
            o = min(o, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    low = indx, high = n;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(two[mid] - two[indx - 1] >= val)
        {
            t = min(t, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if(min(o, t) == infinity)
        return mp(-1, 0);
    if(o < t)
        return mp(o, 1);
    return mp(t, 2);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int i, j;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(i = 1; i <= n; i++)
    {
        one[i] = one[i - 1] + (arr[i] == 1);
        two[i] = two[i - 1] + (arr[i] == 2);
    }
    vector <pair <int, int> > res;
    for(i = 1; i <= n; i++)
    {
        int lwin = 0, owin = 0, twin = 0;
        for(j = 1; j <= n;)
        {
            auto g = get(j, i);
            if(g.first == -1)
                break;
            j = g.first + 1;
            if(g.second == 1)
                owin++, lwin = 1;
            else
                twin++, lwin = 2;
        }
        if(j <= n || owin == twin)
            continue;
        if(owin > twin && lwin == 1)
            res.pb(mp(owin, i));
        else if(twin > owin && lwin == 2)
            res.pb(mp(twin, i));
    }
    sort(all(res));
    cout << SZ(res) << "\n";
    for(i = 0; i < SZ(res); i++)
        cout << res[i].first << ' ' << res[i].second << "\n";
    return 0;
}

