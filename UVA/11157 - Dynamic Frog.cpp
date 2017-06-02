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
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 220
/*************************************************HABIJABI ENDS HERE******************************************************/

int source, sink, from[MAX], visited[MAX], capacity[MAX][MAX], prime_capacity[MAX][MAX], tol;
struct info
{
    int node, dist;
    info(int n, int d)
    {
        node = n;
        dist = d;
    }
};
vector <info> adj[MAX];

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
            v = adj[cur][i].node;
            if(visited[v] || v == from[cur] || !capacity[cur][v] || adj[cur][i].dist > tol)
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

bool max_flow()
{
    int result = 0, path_capacity;
    while(true)
    {
        if(result > 1)
            return true;
        path_capacity = find_path(); //finds augmenting path
        if(path_capacity == 0) //no augmenting path found
            break;
        else
            result += path_capacity;
    }
    return result > 1;
}

int main()
{
    #ifdef Evan
//        in;
    #endif
    int test, kase = 1, i, j, d, n, low, high, res;
    source = 0;
    pair<char, int> arr[102];
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &d);
        sink = 2 * n + 1;
        for(i = 0; i <= sink; i++)
            adj[i].clear();
        for(i = 1; i <= n; i++)
        {
            scanf(" %c-%d", &arr[i].first, &arr[i].second);
            adj[source].pb(info(i, arr[i].second));
            adj[i].pb(info(i + n, 0));
            adj[n + i].pb(info(sink, d - arr[i].second));
            prime_capacity[source][i] = 100;
            prime_capacity[n + i][sink] = 100;
            if(arr[i].first == 'B')
                prime_capacity[i][i + n] = 100;
            else
                prime_capacity[i][n + i] = 1;
            prime_capacity[n + i][i] = 0;
            for(j = 1; j < i; j++)
            {
                adj[n + j].pb(info(i, arr[i].second - arr[j].second));
                adj[n + i].pb(info(j, arr[i].second - arr[j].second));
                prime_capacity[n + j][i] = 100;
                prime_capacity[n + i][j] = 0;
            }
        }
        low = 0, high = res = d;
        while(low <= high)
        {
            memcpy(capacity, prime_capacity, sizeof prime_capacity);
            tol = (low + high) / 2;
            if(max_flow())
                high = tol - 1, res = min(tol, res);
            else
                low = tol + 1;
        }
        printf("Case %d: %d\n", kase++, res);
    }
    return 0;
}

