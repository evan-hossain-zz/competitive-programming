#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("input.in", "r", stdin);
#define out freopen("output.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
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

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

vector <pair<int,int>> adj[MAX];
bool valid;
int visited[MAX], dist[MAX], visit_time, target, A[MAX];
map <pair<int,int>, int> edges;

void dfs(int u, int parent)
{
    if(visited[u])
        return;
    visited[u] = 1;
    // cout << u << ' ' << A[u] << endl;
    for(auto v: adj[u])
    {
        if(v.first == parent)
            continue;
        int expected = (A[u] + v.second)%2;
        if(A[v.first] == expected || A[v.first] == -1)
        {
            A[v.first] = expected;
            dfs(v.first, u);
        }
        else
            valid = false;
    }
}

int main()
{
    // in;
    int test, n, q, u, v, has_connection, i;
    cin >> test;
    while(test--)
    {
        cin >> n >> q;
        for(i = 0; i <= n; i++)
        {
            A[i] = -1;
            visited[i] = 0;
            adj[i].clear();
        }
        edges.clear();
        valid = true;
        visit_time = 0;
        while(q--)
        {
            cin >> u >> v >> has_connection;
            if(u > v)
                swap(u, v);
            if(edges.find({u,v}) != edges.end())
            {
                if(edges[{u, v}] != has_connection)
                    valid = false;
            }
            else
            {
                edges[{u, v}] = has_connection;
                if(u == v)
                {
                    if(has_connection)
                        valid = false;
                }
                else
                {
                    adj[u].pb({v, has_connection});
                    adj[v].pb({u, has_connection});
                }
            }
        }
        for(i = 1; i <= n; i++)
        {
            if(visited[i])
                continue;
            A[i] = 0;
            dfs(i, -1);
        }

        for(auto edge: edges)
        {
            assert(A[edge.first.first] != -1);
            assert(A[edge.first.second] != -1);
            if(abs(A[edge.first.first]-A[edge.first.second]) != edge.second)
                valid = false;
        }
        if(valid)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
