#include <bits/stdc++.h>

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
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 500010
#define BLOCK 800
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

multiset <LL> ms[MAX/BLOCK+5];
LL added[MAX/BLOCK+5], arr[MAX], n;

void update(LL l, LL r, LL val)
{
    LL i = l;
    while(i <= r && i/BLOCK == l/BLOCK)
    {
        auto pt = ms[i/BLOCK].find(arr[i]);
        auto en = pt;
        en++;
        ms[i/BLOCK].erase(pt, en);
        arr[i] += val;
        ms[i/BLOCK].insert(arr[i]);
        i++;
    }
    while(i/BLOCK < r/BLOCK)
        added[i/BLOCK] += val, i += BLOCK;
    while(i<=r)
    {
        auto pt = ms[i/BLOCK].find(arr[i]);
        auto en = pt;
        en++;
        ms[i/BLOCK].erase(pt, en);
        arr[i] += val;
        ms[i/BLOCK].insert(arr[i]);
        i++;
    }
}

LL get(LL val)
{
    LL i, mn = -1, mx = -1;
    for(i = 0; i * BLOCK <= n; i++)
    {
        auto pt = ms[i].find(val-added[i]);
        if(pt != ms[i].end())
        {
            mn = i;
            break;
        }
    }
    if(mn == -1)
        return -1;
    for(i = n/BLOCK+1; i >= mn; i--)
    {
        auto pt = ms[i].find(val-added[i]);
        if(pt != ms[i].end())
        {
            mx = i;
            break;
        }
    }
    LL f, s;
    for(i = mn*BLOCK; i / BLOCK == mn; i++)
    {
        if(val - added[mn] == arr[i])
        {
            f = i;
            break;
        }
    }
    for(i = mx*BLOCK; i / BLOCK == mx; i++)
    {
        if(val - added[mx] == arr[i])
            s = i;
    }
    return s - f;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL q, i, m, l, r, x;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
        ms[i/BLOCK].insert(arr[i]);
    }
    while(m--)
    {
        cin >> q;
        if(q == 1)
        {
            cin >> l >> r >> x;
            update(l-1, r-1, x);
            continue;
        }
        cin >> x;
        cout << get(x) << "\n";
    }
    return 0;
}
