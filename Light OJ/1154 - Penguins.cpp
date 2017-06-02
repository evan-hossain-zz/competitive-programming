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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 202
/*************************************************HABIJABI ENDS HERE******************************************************/

int source, sink, from[MAX], visited[MAX], capacity[MAX][MAX], prime_capacity[MAX][MAX];
vector <int> adj[MAX], ans;
point arr[101];

void add_edge(int u, int v, int cost)
{
    adj[u].pb(v);
    adj[v].pb(u);
    capacity[u][v] = cost;
    capacity[v][u] = 0;
}

int find_path()
{
    //find augmenting path
    queue <int> Q;
    Q.push(source);
    clr(visited, 0);
    clr(from, -1);
    visited[source] = 1;
    int v, lim, i, cur;
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        lim = SZ(adj[cur]);
        for(i = 0; i < lim; i++)
        {
            v = adj[cur][i];
            if(visited[v] || v == from[cur] || !capacity[cur][v])
                continue;
            Q.push(v);
            visited[v] = 1;
            from[v] = cur;
            if(v == sink)
                break;
        }
        if(i < lim)
            break;
    }
    //compute path capacity
    int path_capacity = infinity, prev;
    cur = sink;
    while(from[cur] > -1)
    {
        prev = from[cur];
        path_capacity = min(path_capacity, capacity[prev][cur]);
        cur = prev;
    }
    //update residual graph
    cur = sink;
    while(from[cur] > -1)
    {
        prev = from[cur];
        capacity[prev][cur] -= path_capacity;
        capacity[cur][prev] += path_capacity;
        cur = prev;
    }
    if(path_capacity == infinity)
        return 0;
    return path_capacity;
}

int max_flow()
{
    int result = 0, path_capacity;
    while(true)
    {
        path_capacity = find_path(); //finds augmenting path
        if(path_capacity == 0) //no augmenting path found
            break;
        else
            result += path_capacity;
    }
    return result;
}

int main()
{
    #ifdef Evan
        in;
    #endif
    double dist;
    int test, n, kase = 1, total_penguins, i, j, ni, mi, flow;
    source = 0;
    scanf("%d", &test);
    while(test--)
    {
        ans.clear();
        total_penguins = 0;
        scanf("%d %lf", &n, &dist);
        for(i = 0; i <= 2 * n; i++) adj[i].clear();
        dist *= dist;
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d %d %d", &arr[i].x, &arr[i].y, &ni, &mi);
            total_penguins += ni;
            add_edge(i, n + i, mi);
            capacity[source][i] = ni;
            adj[source].pb(i);
            for(j = 1; j < i; j++)
            {
                if(getdist(arr[i], arr[j]) <= dist)
                    add_edge(i + n, j, infinity), add_edge(j + n, i, infinity);
            }
        }
        memcpy(prime_capacity, capacity, sizeof capacity);
        for(i = 1; i <= n; i++)
        {
            sink = i;
            memcpy(capacity, prime_capacity, sizeof prime_capacity);
            flow = max_flow();
            if(flow == total_penguins)
                ans.pb(i);
        }
        if(ans.empty())
            printf("Case %d: -1\n", kase++);
        else
        {
            printf("Case %d:", kase++);
            for(i = 0; i < SZ(ans); i++)
                printf(" %d", ans[i] - 1);
            printf("\n");
        }
    }
    return 0;
}

