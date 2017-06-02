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

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

pair<LL,LL> arr[MAX];

set <pair<LL,LL>> adj[MAX], inset[MAX];
LL m, k;

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL n, i, j, res = 0;
    cin >> n >> m >> k;
    for(i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second, adj[arr[i].second].insert(mp(arr[i].first, i));
    set <pair<LL,LL>> ss;
    for(i = 0; i < m; i++)
    {
        ss.insert(mp(arr[i].first*arr[i].second, i));
        adj[arr[i].second].erase(mp(arr[i].first, i));
        inset[arr[i].second].insert(mp(arr[i].first, i));
    }
    while(k--)
    {
        pair<LL,LL> forIn[2] = mp(0, 0), forOut[2] = mp(0, 0);
        LL curMin = (*ss.begin()).first, tem, mx = 0;
        for(i = 0; i <= 100; i++)
        {
            if(adj[i].empty())
                continue;
            auto it = adj[i].begin();
            auto val = *it;
            tem = val.first*100 - curMin;
            mx = max(tem, mx);
            if(tem > forOut[0].first)
                forOut[0] = mp(tem, i);
            it = adj[i].end();
            it--;
            val = *it;
            tem = val.first*100 - curMin;
            mx = max(tem, mx);
            if(tem > forOut[1].first)
                forOut[1] = mp(tem, i);
        }
        if(mx == 0)
            break;
        if(mx == forOut[0].first)
        {
            auto it = ss.begin();
            auto val = *it;
            ss.erase(ss.begin());
            adj[forOut[0].second].erase(mp(arr[val.second].first, val.second));
            inset[forOut[0].second].insert(mp(arr[val.second].first, val.second));
            it = adj[forOut[0].second].begin();
            val = *it;
            ss.insert(mp(val.first*100, val.second));
        }
        else if(mx == forOut[1].first)
        {
            auto it = ss.begin();
            auto val = *it;
            ss.erase(ss.begin());
            adj[forOut[1].second].erase(mp(arr[val.second].first, val.second));
            inset[forOut[1].second].insert(mp(arr[val.second].first, val.second));
            it = adj[forOut[1].second].end();
            it--;
            val = *it;
            ss.insert(mp(val.first*100, val.second));
        }
    }
    for(auto x: ss)
        res += x.first;
    cout << res;
    return 0;
}
