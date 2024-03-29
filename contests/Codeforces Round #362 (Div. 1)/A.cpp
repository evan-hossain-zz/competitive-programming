#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcountll // __builtin_popcountll for LL
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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int len(LL n)
{
    if(n == 0)
        return 1;
    int ret = 0;
    while(n)
        ret++, n>>=1;
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    map <pair<LL,LL>, LL> mpp;
    int q, t, u, v, w;
    cin >> q;
    LL res, nu, nv;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> u >> v >> w;
            while(u != v)
            {
                int lu = len(u);
                int lv = len(v);
                if(lu > lv)
                {
                    nu = u >> 1;
                    mpp[mp(u, nu)] += w;
                    mpp[mp(nu, u)] += w;
                    u = nu;
                }
                else if(lu < lv)
                {
                    nv = v >> 1;
                    mpp[mp(v, nv)] += w;
                    mpp[mp(nv, v)] += w;
                    v = nv;
                }
                else
                {
                    nu = u >> 1;
                    mpp[mp(u, nu)] += w;
                    mpp[mp(nu, u)] += w;
                    nv = v >> 1;
                    mpp[mp(v, nv)] += w;
                    mpp[mp(nv, v)] += w;
                    u = nu;
                    v = nv;
                }
            }
        }
        else
        {
            cin >> u >> v;
            res = 0;
            while(u != v)
            {
                int lu = len(u);
                int lv = len(v);
                if(lu > lv)
                {
                    nu = u >> 1;
                    res += mpp[mp(u, nu)];
                    u = nu;
                }
                else if(lu < lv)
                {
                    nv = v >> 1;
                    res += mpp[mp(v, nv)];
                    v = nv;
                }
                else
                {
                    nu = u >> 1;
                    nv = v >> 1;
                    res += mpp[mp(v, nv)];
                    res += mpp[mp(u, nu)];
                    u = nu;
                    v = nv;
                }
//                cout << u << ' ' << v << ' ' << res << endl;
            }
            cout << res << "\n";
        }
    }
    return 0;
}
