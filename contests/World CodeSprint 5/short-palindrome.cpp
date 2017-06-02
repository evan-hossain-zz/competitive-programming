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

#define MAX 1000010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL l[MAX], r[MAX], merged[MAX], mod = 1e9+7;

vector <int> adj[26];

LL nc4(LL n)
{
    LL ret = n*(n-1);
    ret %= mod;
    ret *= n-2;
    ret %= mod;
    ret *= n-3;
    ret %= mod;
    ret *= bigmod(24, mod-2, mod);
    return ret%mod;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    string s;
    LL res = 0, i, j, k, x;
    cin >> s;
    for(i = 0; i < SZ(s); i++)
        adj[s[i]-'a'].pb(i);
    for(i = 0; i < 26; i++)
    {
        for(j = 0; j < 26; j++)
        {
            if(adj[i].empty() || adj[j].empty()) continue;
            if(i == j)
            {
                res += nc4(SZ(adj[i]));
                if(res >= mod)
                    res %= mod;
                continue;
            }
            int p = 0, q = 0, lim = 0;
            while(p < SZ(adj[i]) && q < SZ(adj[j]))
            {
                if(adj[i][p] == adj[j][q])
                    merged[lim++] = adj[i][p++], q++;
                else if(adj[i][p] > adj[j][q])
                    merged[lim++] = adj[j][q++];
                else
                    merged[lim++] = adj[i][p++];
            }
            while(p < SZ(adj[i]))
                merged[lim++] = adj[i][p++];
            while(q < SZ(adj[j]))
                merged[lim++] = adj[j][q++];
            LL cnt = 0;
            r[lim] = 0;
            for(x = lim-1; x >= 0; x--)
            {
                k = merged[x];
                r[x] = (s[k]-'a'==j)*cnt + r[x+1];
                cnt += s[k]-'a' == i;
                if(r[x] >= mod)
                    r[x] %= mod;
            }
            cnt = 0;
            for(x = 0; x < lim; x++)
            {
                k = merged[x];
                l[x] = (s[k]-'a'==j)*cnt;
                cnt += s[k]-'a' == i;
                if(l[x] >= mod)
                    l[x] %= mod;
                res += (l[x]*r[x+1])%mod;
                if(res >= mod)
                    res %= mod;
            }
        }
    }
    cout << res;
    return 0;
}
