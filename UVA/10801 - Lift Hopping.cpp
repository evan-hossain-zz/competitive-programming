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
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point(){} point(int a, int b){x = a, y = b;}};    // for coordinates;;

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

#define MAX 105
/*************************************************HABIJABI ENDS HERE******************************************************/

int n, t[6];
vector <int> v[6];
vector <point> adj[MAX];
point dist[MAX];

void init(void)
{
    for(int i = 0; i < MAX; i++) dist[i].x = infinity, adj[i].clear();
}

void bfs()
{
    queue <int> q;
    q.push(0);
    dist[0].x = 0;
    dist[0].y = -1;
    int i, u, cur, lim, curdist;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        lim = SZ(adj[u]);
        for(i = 0; i < lim; i++)
        {
            cur = adj[u][i].x;
            curdist = dist[u].x + t[adj[u][i].y] * abs(u - cur);
            if(dist[u].y != -1 && dist[u].y != adj[u][i].y)
                curdist += 60;
            if(curdist < dist[cur].x)
            {
                dist[cur].x = curdist;
                dist[cur].y = adj[u][i].y;
                q.push(cur);
            }
        }
    }
}

int main()
{
    int i, j, num, dest;
    string s;
    char str[400];
    while(scanf("%d %d", &n, &dest) == 2)
    {
        init();
        for(i = 1; i <= n; i++) scanf("%d", &t[i]), v[i].clear();
        for(i = 1; i <= n; i++)
        {
            scanf(" %[^\n]", str);
            s = str;
            stringstream ss(s);
            while(ss >> num)
            {
                for(j = 0; j < SZ(v[i]); j++)
                {
                    adj[num].pb(point(v[i][j], i));
                    adj[v[i][j]].pb(point(num, i));
                }
                v[i].pb(num);
            }
        }
        bfs();
        if(dist[dest].x >= infinity)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", dist[dest].x);
    }
    return 0;
}


