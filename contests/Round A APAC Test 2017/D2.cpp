#include <bits/stdc++.h>

//#define in freopen("D-small-attempt0.in", "r", stdin);
#define in freopen("input.txt", "r", stdin);
#define out freopen("output2.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1LL << 58)
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

LL L[MAX], C[MAX][MAX], A[MAX][MAX], K[MAX];


typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef pair<LL, LL> PII;
typedef vector<PII> VPII;

const LL INF = (1LL << 60);

struct MinCostMaxFlow
{
    LL N;
    VVL cap, flow, cost;
    VI found;
    VL dist, pi, width;
    VPII dad;

    MinCostMaxFlow(LL N) :
        N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
        found(N), dist(N), pi(N), width(N), dad(N) {}

    void AddEdge(LL from, LL to, LL cap, LL cost)
    {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
    }

    void Relax(LL s, LL k, LL cap, LL cost, LL dir)
    {
        LL val = dist[s] + pi[s] - pi[k] + cost;
        if (cap && val < dist[k])
        {
            dist[k] = val;
            dad[k] = make_pair(s, dir);
            width[k] = min(cap, width[s]);
        }
    }

    LL Dijkstra(LL s, LL t)
    {
        fill(found.begin(), found.end(), false);
        fill(dist.begin(), dist.end(), INF);
        fill(width.begin(), width.end(), 0);
        dist[s] = 0;
        width[s] = INF;

        while (s != -1)
        {
            LL best = -1;
            found[s] = true;
            for (LL k = 0; k < N; k++)
            {
                if (found[k]) continue;
                Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
                Relax(s, k, flow[k][s], -cost[k][s], -1);
                if (best == -1 || dist[k] < dist[best]) best = k;
            }
            s = best;
        }

        for (LL k = 0; k < N; k++)
            pi[k] = min(pi[k] + dist[k], INF);
        return width[t];
    }

    pair<LL, LL> GetMaxFlow(LL s, LL t)
    {
        LL totflow = 0, totcost = 0;
        while (LL amt = Dijkstra(s, t))
        {
            totflow += amt;
            for (LL x = t; x != s; x = dad[x].first)
            {
                if (dad[x].second == 1)
                {
                    flow[dad[x].first][x] += amt;
                    totcost += amt * cost[dad[x].first][x];
                }
                else
                {
                    flow[x][dad[x].first] -= amt;
                    totcost -= amt * cost[x][dad[x].first];
                }
            }
        }
        return make_pair(totflow, totcost);
    }
};

LL get(int mask, int n, LL f)
{
    MinCostMaxFlow *mcmf = new MinCostMaxFlow(100);
    int node = n+1, source = 98, sink = 99;
    for(int i = 0; i < n; i++)
    {
        if(!(mask & (1<<i))) continue;
        mcmf->AddEdge(source, i+1, infinity, 0);
        mcmf->AddEdge(i+1, node, A[i+1][L[i+1]], 0);
        mcmf->AddEdge(node++, sink, INF, 0);
        LL sum = 0;
        for(int j = max(1LL, L[i+1]); j < K[i+1]; j++)
        {
            mcmf->AddEdge(i+1, node, A[i+1][j+1], C[i+1][j]+sum);
            mcmf->AddEdge(node++, sink, INF, 0);
            sum += C[i+1][j];
        }
    }
    mcmf->AddEdge(0, source, f, 0);
    auto res = mcmf->GetMaxFlow(0, sink);
    cout << f << ' ' << res.first << ' ' << res.second << endl;
    if(res.first == f)
        return res.second;
    return infinity;
}

int main()
{
    #ifdef Evan
        in;
//        out;
    #endif
    LL test, kase = 1, n, m, i, j;
    cin >> test;
    while(test--)
    {
        cin >> m >> n;
        for(i = 1; i <= n; i++)
        {
            cin >> K[i] >> L[i];
            for(j = 1; j <= K[i]; j++)
                cin >> A[i][j];
            for(j = 1; j < K[i]; j++)
                cin >> C[i][j];
        }
        LL res = 0;
        for(i = 0; i < (1<<n); i++)
        {
            if(no_of_ones(i) != 8) continue;
            cout << i << ' ' << kase << ' ' << "here " << endl;
            LL low = 0, high = 1e14, mid, cur = 0;
            while(low <= high)
            {
                mid = (low+high) / 2;
                LL tem = get(i, n, mid);
//                cout << tem << endl;
                if(tem <= m)
                {
                    low = mid+1;
                    cur = mid;
                }
                else
                    high = mid-1;
            }
            res = max(res, cur);
        }
        cout << get(255, n, 17) << endl;
        cout << "Case #" << kase++ << ": " << res << "\n";
        cerr << "Case #" << kase-1 << ": " << res << "\n";
    }
    return 0;
}
