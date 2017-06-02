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

#define MAX 20010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[MAX], color[MAX];
vector <int> adj[MAX];

void process()

void bfs(int u)
{
    queue <int> Q;
    Q.push(u);
    if(!adj[u].empty() && arr[u])
        process(u);
    color[u] = 1;
    int i, v;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(i = 0; i < SZ(adj[u]); i++)
        {
            v = adj[u][i];
            if(color[v]) continue;
            if(!adj[v].empty() && arr[v])
                process(v);
            Q.push(v);
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, i, cur, pre;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> arr[i];
            arr[i] %= 2;
            adj[i].clear();
        }
        cin >> pre;
        for(i = 2; i <= n; i++)
        {
            cin >> cur;
            adj[pre].pb(cur);
            pre = cur;
        }
        for(i = 1; i <= n; i++)
            if(adj[i].empty())
                arr[i] = 1;
        bfs(1, -1);
    }
    return 0;
}

