#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

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

#define MAX 1010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int dist[2][MAX], last[2][MAX];

vector <pair<int, int> > adj[MAX];

void dijkstra(int source, int no)
{
    priority_queue <pair<int, int>, vector <pair<int, int> >, greater< pair<int, int> > > Q;
    Q.push(mp(0, source));
    dist[no][source] = 0;
    int i;
    pair <int, int> u, v;
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();
        for(i = 0; i < SZ(adj[u.second]); i++)
        {
            v = adj[u.second][i];
            if(dist[no][v.second] > dist[no][u.second] + v.first)
            {
                dist[no][v.second] = dist[no][u.second] + v.first;
                last[no][v.second] = v.first;
                v.first = dist[no][v.second];
                Q.push(v);
            }

        }
    }
}

vector <tuple<int, int, int> > edges;
int q[MAX], res[MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, m, s, t, u, v, c, i, j = -1;
    while(scanf("%d %d %d %d", &n, &m, &s, &t) == 4)
    {
        if(j != -1) puts("");
        edges.clear();
        clr(res, 0);
        for(i = 1; i <= n; i++)
            adj[i].clear(), dist[0][i] = dist[1][i] = infinity;
        while(m--)
        {
            scanf("%d %d %d", &u, &v, &c);
            adj[u].pb(mp(c, v));
            adj[v].pb(mp(c, u));
            edges.pb(make_tuple(u, v, c));
        }
        dijkstra(s, 0);
        dijkstra(t, 1);
        scanf("%d", &m);
        int mn = dist[0][t];
        for(i = 0; i < m; i++)
            scanf("%d", &q[i]);
        for(i = 0; i < SZ(edges); i++)
        {
            u = get<0>(edges[i]);
            v = get<1>(edges[i]);
            c = get<2>(edges[i]);
            for(j = 0; j < m; j++)
            {
                if(dist[0][u] < q[j] && dist[0][v] > q[j] && dist[0][u] + c + dist[1][v] == mn)
                    res[j]++;
            }
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(dist[0][i] == q[j] && dist[0][i] + dist[1][i] == mn)
                    res[j]++;
            }
        }
        for(i = 0; i < m; i++)
            printf("%d\n", max(1, res[i]));
    }
    return 0;
}
/*
5 6 1 5
1 2 2
1 3 2
1 4 2
2 5 3
3 5 3
4 5 3
6
1
2
3
4
5
6
*/
