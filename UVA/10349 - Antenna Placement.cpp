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
#define fast_input_output ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};
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

#define MAX 42


char grid[MAX][MAX];
vector <int> adj[MAX * MAX];
int n, m, gold;

int getId(int r, int c)
{
    return ((r - 1) * m) + c;
}

void build()
{
    int i, j, nr, nc, k;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if(grid[i][j] == '*')
            {
                for(k = 0; k < 4; k++)
                {
                    nr = i + row[k];
                    nc = j + col[k];
                    if(nr < 1 || nr > n || nc < 1 || nc > m || grid[nr][nc] == 'o')
                        continue;
                    adj[getId(i, j)].pb(getId(nr, nc));
                }
            }
        }
    }
}

int par[MAX * MAX];
bool done[MAX * MAX];

int dfs(int u)
{
    if(done[u])
        return false;
    done[u] = true;
    for(int i = 0; i < SZ(adj[u]); i++)
    {
        int v = adj[u][i];
        if(par[v] == -1 || dfs(par[v]))
        {
            par[v] = u;
            return true;
        }
    }
    return false;
}

int MAX_BMP(int n) // finds maximum possible bipartite matching
{
    int ret = 0, i;
    clr(par, -1);
    for(i = 1; i <= n; i++)
    {
        clr(done, 0);
        if(dfs(i)) ret++;
    }
    return ret;
}

int main()
{
    int i, j, test, kase = 1;
    scanf("%d", &test);
    while(test--)
    {
        gold = 0;
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n * m; i++)
            adj[i].clear();
        for(i = 1; i <= n; i++)
            for(j = 1; j <= m; j++)
                scanf(" %c", &grid[i][j]), gold += (grid[i][j] == '*');
        build();
        printf("%d\n", gold - MAX_BMP(n * m) / 2);
    }
    return 0;
}

