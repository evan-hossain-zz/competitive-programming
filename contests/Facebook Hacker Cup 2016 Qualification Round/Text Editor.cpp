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

#define MAX 260010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int trie[MAX][26], last, dp[MAX][300], leaf[MAX], child[MAX], k, cnt[MAX];
vector <int> adj[MAX];

void add(string &s)
{
    int i, id, cur = 0;
    for(i = 0; i < SZ(s); i++)
    {
        id = s[i] - 'a';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            clr(trie[last], -1);
        }
        adj[cur].pb(trie[cur][id]);
        cur = trie[cur][id];
    }
    cnt[cur]++;
}
/// do clr(trie[0], -1) and last = 0 for every case

void call(int u)
{
    clr(dp[u], 63);
    dp[u][0] = 0;
    int &ret = leaf[u];
    ret = 0;
    int i, j;
    for(auto v: adj[u])
    {
        call(v);
        ret += leaf[v];
        for(i = ret; i; i--)
        {
            for(j = 0; j <= i; j++)
            {
                if(cnt[v])
                    dp[u][i] = min(dp[u][i], dp[u][i-j]+dp[v][j-1]+2+1);
                else
                    dp[u][i] = min(dp[u][i], dp[u][i-j]+dp[v][j]+2*(j!=0));
            }
        }
    }
    if(ret == 0)
        ret = 1, dp[u][1] = 1;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, n, i;
    string s;
    cin >> test;
    while(test--)
    {
        cin >> n >> k;
        clr(trie[0], -1);
        last = 0;
        while(n--)
        {
            cin >> s;
            add(s);
        }
        for(i = 0; i <= last; i++)
            clr(dp[i], -1), leaf[i] = 0;
        call(0);
        cout << "Case #" << kase++ << ": " << dp[0][k] << "\n";
    }
    return 0;
}

