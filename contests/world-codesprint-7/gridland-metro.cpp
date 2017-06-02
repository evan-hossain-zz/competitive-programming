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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

map <int,int> mpp;
vector <pair<int,int>> adj[MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL n, m, k, i, r, c1, c2, mc = 0;
    cin >> n >> m >> k;
    LL res = n*m;
    for(i = 0; i < k; i++)
    {
        cin >> r >> c1 >> c2;
        if(mpp.find(r) == mpp.end())
            mpp[r] = ++mc;
        adj[mpp[r]].pb(mp(c1, c2));
    }
    for(auto x: mpp)
    {
        r = x.second;
        sort(all(adj[r]));
        bool color[MAX] = {0};
        for(int i = 0; i < SZ(adj[r]); i++)
        {
            if(color[i]) continue;
            for(int j = i+1; j < SZ(adj[r]); j++)
            {
                if(adj[r][i].first <= adj[r][j].first && adj[r][i].second >= adj[r][j].second)
                    color[j] = 1;
            }
        }
        vector <pair<int,int>> tem;
        for(i = 0; i < SZ(adj[r]); i++)
            if(color[i] == 0)
                tem.pb(adj[r][i]);
        adj[r] = tem;
        sort(all(adj[r]));
        n = SZ(adj[r]);
        for(i = 0; i < n; i++)
        {
            if(i+1 < n && adj[r][i].second >= adj[r][i+1].first)
                res -= adj[r][i+1].first-adj[r][i].first;
            else
                res -= adj[r][i].second-adj[r][i].first+1;
        }
    }
    cout << res;
    return 0;
}
