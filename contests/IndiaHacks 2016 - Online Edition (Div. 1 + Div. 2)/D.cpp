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

// Running time: O(|V|^2 |E|)  OUTPUT: - maximum flow value
// To obtain the actual flow values, look at all edges with
// capacity > 0 (zero capacity edges are residual edges).
const LL INF = 2000000000000000000;
struct Edge{
    LL from, to, cap, flow, index;
    Edge(LL from, LL to, LL cap, LL flow, LL index) :
        from(from), to(to), cap(cap), flow(flow), index(index) {}
};
struct Dinic{
    LL N;
    vector <vector<Edge> > G;
    vector <Edge *> dad;
    vector<LL> Q;
    Dinic(LL N) : N(N), G(N), dad(N), Q(N) {}
    void AddEdge(LL from, LL to, LL cap)
    {
        G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    }
    long long BlockingFlow(LL s, LL t)
    {
        fill(dad.begin(), dad.end(), (Edge *) NULL);
        dad[s] = &G[0][0] - 1;
        LL head = 0, tail = 0;
        Q[tail++] = s;
        while (head < tail)
        {
            LL x = Q[head++];
            for (LL i = 0; i < G[x].size(); i++)
            {
                Edge &e = G[x][i];
                if (!dad[e.to] && e.cap - e.flow > 0)
                {
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if (!dad[t]) return 0;
        long long totflow = 0;
        for (LL i = 0; i < G[t].size(); i++)
        {
            Edge *start = &G[G[t][i].to][G[t][i].index];
            LL amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                if (!e){ amt = 0; break; }
                amt = min(amt, e->cap - e->flow);
            }
            if (amt == 0) continue;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from])
            {
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow += amt;
        }
        return totflow;
    }
    long long GetMaxFlow(LL s, LL t) // source, sink
    {
        long long totflow = 0;
        while (long long flow = BlockingFlow(s, t))
            totflow += flow;
        return totflow;
    }
};

vector <LL> flown;

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL n, m, x, i, u, v, c, j;
    cin >> n >> m >> x;
    vector <tuple<LL,LL,LL>> edges;
    while(m--)
    {
        cin >> u >> v >> c;
        edges.pb(make_tuple(u, v, c));
    }
    double low = 0, high = 1e9, mid;
    for(i = 0; i < 200; i++)
    {
        mid = (low+high) / 2;
        Dinic *flow = new Dinic(n+1);
        for(auto e: edges)
        {
            u = get<0> (e);
            v = get<1> (e);
            c = get<2> (e);
            flow->AddEdge(u, v, c/mid);
        }
        if(flow->GetMaxFlow(1, n) >= x)
            low = mid;
        else
            high = mid;
    }
    cout << setprecision(8) << fixed << mid*x;
    return 0;
}
