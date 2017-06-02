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
#define infinity (1 << 20)
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

struct point{double x, y;};    // for coordinates;

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

#define MAX 550
/*************************************************HABIJABI ENDS HERE******************************************************/

struct info
{
    int city, dist, need;
    bool operator < (const info& p) const
    {
        return p.dist < dist;
    }
};

struct edge
{
    int city, cost;
    edge(int a, int b)
    {
        city = a;
        cost = b;
    }
};

vector <edge> e[MAX];
int d[MAX][2], n;

void initialize(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        e[i].clear();
        d[i][0] = d[i][1] = infinity;
    }
    return;
}

void dijkstra(int start, int en)
{
    info u, v;
    u.city = start, u.dist = u.need = 0;
    d[start][0] = 0;
    priority_queue <info> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.top(), q.pop();
        if(u.city == en && u.need == 0)
            return;
        int ucost = d[u.city][u.need];
//        cout << u.city << ' ' << ucost << endl;
        for(int i = 0; i < e[u.city].size(); i++)
        {
            v.city = e[u.city][i].city, v.dist = e[u.city][i].cost + ucost, v.need = !u.need;
            if(d[v.city][v.need] > v.dist)
            {
                d[v.city][v.need] = v.dist;
                q.push(v);
            }
        }
    }
    return;
}

int main()
{
    int i, a, b, c, m, res, kase = 1;
    while(scanf("%d %d", &n, &m) == 2)
    {
        initialize(n);
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            e[a].pb(edge(b, c));
            e[b].pb(edge(a, c));
        }
        dijkstra(0, n - 1);
        res = d[n - 1][0];
        printf("Set #%d\n", kase++);
        if(res >= infinity)
            printf("?\n");
        else
            printf("%d\n", res);
    }
    return 0;
}

