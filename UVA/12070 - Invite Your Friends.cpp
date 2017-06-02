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

#define MAX 26
/*************************************************HABIJABI ENDS HERE******************************************************/

int n, cost[MAX][MAX], cnt, t, final_cost[MAX][MAX][MAX];
pair <int, int> friends[6];

struct info
{
    int r, c, cost, shomoy;
    info(){}
    info(int R, int C, int COST, int T)
    {
        r = R;
        c = C;
        cost = COST;
        shomoy = T;
    }
    bool operator < (const info &p) const
    {
        return p.cost < cost;
    }
};

void initialize()
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k <= t; k++)
                final_cost[i][j][k] = infinity;
}

void dijkstra(int r, int c)
{
    priority_queue <info> Q;
    Q.push(info(r, c, 0, 0));
    final_cost[r][c][0] = 0;
    int nr, nc, i, ucost;
    info u, v;
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();
        ucost = final_cost[u.r][u.c][u.shomoy];
        for(i = 0; i < 4; i++)
        {
            nr = row[i] + u.r;
            nc = col[i] + u.c;
            if(nr < 0 || nr == n || nc < 0 || nc == n)
                continue;
            v = info(nr, nc, ucost + cost[nr][nc], u.shomoy + 1);
            if(v.shomoy > t) continue;
            if(final_cost[nr][nc][v.shomoy] > v.cost)
            {
                Q.push(v);
                final_cost[nr][nc][v.shomoy] = v.cost;
            }
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, j, f, u, v, mn, sum, kase = 1, k, tem;
    while(scanf("%d %d %d", &n, &f, &t) == 3 && (n || f || t))
    {
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &cost[i][j]);
        for(u = 0; u < f; u++)
            scanf("%d %d", &friends[u].first, &friends[u].second);
        mn = infinity;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                initialize();
                dijkstra(i, j);
                sum = 0;
                for(k = 0; k < f; k++)
                {
                    tem = infinity;
                    for(int l = 0; l <= t; l++)
                        tem = min(tem, final_cost[friends[k].first][friends[k].second][l]);
                    if(tem >= infinity)
                        break;
                    sum += tem;
                    if(sum > mn)
                        break;
                }
                if(k == f && mn > sum)
                {
                    mn = sum;
                    u = i;
                    v = j;
                }
            }
        if(mn == infinity)
            printf("Case #%d: Impossible.\n", kase++);
        else
            printf("Case #%d: Selected city (%d,%d) with minimum cost %d.\n", kase++, u, v, mn);
    }
    return 0;
}


