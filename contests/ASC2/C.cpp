#include <bits/stdc++.h>

#define in freopen("huffman.in", "r", stdin);
#define out freopen("huffman.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
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

struct node{
    LL p;
    int x;
    node(){}
    node(LL P, int X)
    {
        p = P;
        x = X;
    }
    bool operator < (const node &a)const
    {
        return p > a.p;
    }
};

int adj[MAX][2];
LL res, freq[MAX];

LL dfs(int u, int d)
{
    if(freq[u])
        return freq[u] * d;
    return dfs(adj[u][0], d+1) + dfs(adj[u][1], d+1);
}

int main()
{
        in;
        out;
    priority_queue <node> Q;
    int n, i, p, cur;
    scanf("%d", &n);
    cur = n;
    node a, b;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &p),Q.push(node(p, i)), freq[i] = p;
        while(Q.top().p < p)
        {
            a = Q.top();
            Q.pop();
            if(Q.top().p < p)
                b = Q.top(), Q.pop();
            else
            {
                Q.push(a);
                break;
            }
            Q.push(node(a.p+b.p, cur));
            adj[cur][0] = a.x;
            adj[cur++][1] = b.x;
        }
    }
    while(SZ(Q) > 1)
    {
        a = Q.top();
        Q.pop();
        b = Q.top();
        Q.pop();
        Q.push(node(a.p+b.p, cur));
        adj[cur][0] = a.x;
        adj[cur++][1] = b.x;
    }
    cout << dfs(cur-1, 0);
    return 0;
}
