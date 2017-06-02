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

#define MAX 1<<22
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

bool dp[MAX][22];
int visited[MAX][22], kase;
int n, has[22];
string arr[22];
vector <int> adj[26];

bool call(int mask, int last)
{
    if(mask == (1<<n)-1)
        return 0;
    bool &ret = dp[mask][last];
    int &visit = visited[mask][last], j, k, x;
    if(visit == kase) return ret;
    ret = 0;
    visit = kase;
    for(j = 0; j < 26; j++)
    {
        if(has[last] & (1<<j))
        {
            for(k = 0; k < SZ(adj[j]); k++)
            {
                x = adj[j][k];
                if(mask & (1<<x))
                    continue;
                ret |= !call(mask|(1<<x), x);
                if(ret)
                    return ret;
            }
        }
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, i, j;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 0; i < 26; i++)
            adj[i].clear();
        for(i = 0; i < n; i++)
        {
            cin >> arr[i];
            has[i] = 0;
            for(j = 0; j < SZ(arr[i]); j++)
                has[i] |= 1<<(arr[i][j] - 'a');
            adj[arr[i][0]-'a'].pb(i);
        }
        cout << "Case " << ++kase << ": ";
        int res = 0;
        for(i = 0; i < n; i++)
            res |= !call(1<<i, i);
        if(res)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
