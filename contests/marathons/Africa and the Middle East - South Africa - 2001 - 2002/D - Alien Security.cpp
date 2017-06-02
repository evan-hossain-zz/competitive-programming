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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 1010
/*************************************************HABIJABI ENDS HERE******************************************************/

char str[10];
int target;
bool color[MAX], dfs_color[MAX];

vector <int> adj[MAX], ulta[MAX];

bool dfs(int node)
{
    if(node == target) return true;
    int i, v;
    for(i = 0; i < SZ(adj[node]); i++)
    {
        v = adj[node][i];
        if(!dfs_color[v])
        {
            dfs_color[v] = 1;
            if(dfs(v)) return true;
            dfs_color[v] = 0;
        }
    }
    return false;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, u, v = -2, n, i;
    scanf("%d", &test);
    while(test--)
    {
        if(v != -2)
            puts("");
        scanf("%d %d ", &n, &target);
        for(i = 0; i <= n; i++) adj[i].clear(), ulta[i].clear();
        while(gets(str) && strlen(str) != 0)
        {
            sscanf(str, "%d %d", &u, &v);
            adj[u].pb(v);
            ulta[v].pb(u);
        }
        queue <int> q;
        clr(color, 0);
        color[target] = 1;
        q.push(target);
        n = 0;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            for(i = 0; i < SZ(ulta[u]); i++)
            {
                v = ulta[u][i];
                if(color[v]) continue;
                color[v] = 1;
                clr(dfs_color, 0);
                dfs_color[v] = 1;
                if(!dfs(0))
                {
                    n = v;
                    v = -1;
                    break;
                }
                q.push(v);
            }
            if(v == -1)
                break;
        }
        printf("Put guards in room %d.\n", n);
    }
    return 0;
}

/*
2

6 4
0 1
0 2
1 5
5 4
3 4
1 3
2 3
2 4

6 3
0 1
0 2
1 5
5 4
3 4
1 3
2 3
2 4
*/
