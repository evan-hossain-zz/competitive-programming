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

struct point{LL x, y; point () {} point(LL a, LL b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> LL getdist(T a, T b){return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 10010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL n, k, s, d;

point arr[MAX];
bool color[MAX];

LL ok(LL y)
{
    set <int> ss;
    vector <int> dlt;
    LL i = 0, j = 0;
    for(i = 0; i < n; i++)
        ss.insert(i);
    while(!ss.empty())
    {
        i = *ss.begin();
        j++;
        LL low = arr[i].x, high = arr[n-1].x, mid, res, ok = 0;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(getdist(arr[i], point(mid, y)) > d)
                high = mid-1;
            else
                low = mid+1, res = mid, ok = 1;
        }
        if(ok == 0)
            return 0;
        dlt.clear();
        for(auto x: ss)
        {
            if(getdist(arr[x], point(res, y)) <= d)
                dlt.pb(x);
            else
                break;
        }
        for(auto d: dlt)
            ss.erase(d);
    }
    return j <= s;
}

bool comp(const point &a, const point &b)
{
    return a.x < b.x;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL test, kase = 1, i;
    cin >> test;
    while(test--)
    {
        cin >> k >> n >> s >> d;
        d = sqr(d);
        for(i = 0; i < n; i++)
            cin >> arr[i].x >> arr[i].y;
        sort(arr, arr+n, comp);
        LL low = -1e9, high = k-1, mid, res, found = 0;
        while(low <= high)
        {
            mid = (low+high) / 2;
            if(ok(mid))
                high = mid-1, res=mid, found = 1;
            else
                low = mid+1;
        }
        cout << "Case " << kase++ << ": ";
        if(found)
            cout << abs(k-res) << "\n";
        else
            cout << "IMPOSSIBLE\n";
    }
    return 0;
}
