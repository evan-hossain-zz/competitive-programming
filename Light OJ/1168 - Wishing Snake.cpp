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

#define MAX 1002
/*************************************************HABIJABI ENDS HERE******************************************************/


int low[MAX], tim[MAX], mpp[MAX], indeg[MAX], outdeg[MAX], col[MAX], no_of_component, n, timer, group_id[MAX];
vector <int> adj[MAX];
stack <int> st;

void scc(int u)
{
    low[u] = tim[u] = timer++;
    col[u] = 1;
    st.push(u);
    int i, elements = adj[u].size(), v, tem;
    for(i = 0; i < elements; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == tim[u])
    {
        do
        {
            tem = st.top();
            st.pop();
            group_id[tem]=no_of_component;
            col[tem] = 2;
        }
        while(tem != u);
        no_of_component++;
    }
}

void call_for_scc_check()
{
    no_of_component = timer = 0;
    clr(col, 0);
    int i;
    while(!st.empty()) st.pop();
    scc(mpp[0]);
}

void make_new_DAG()
{
    int i,j,u,v;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < SZ(adj[i]); j++)
        {
            u=group_id[i];
            v=group_id[adj[i][j]];
            if(u!=v)
                indeg[v]++, outdeg[u]++;
        }
    }
}

int main()
{
    int kase = 1, test, i, u, v, wish, k, zero;
    scanf("%d", &test);
    while(test--)
    {
        clr(indeg, 0);
        clr(outdeg, 0);
        clr(mpp, 0);
        for(i = 0; i < MAX; i++) adj[i].clear();
        scanf("%d", &wish);
        if(!wish)
        {
            printf("Case %d: YES\n", kase++);
            continue;
        }
        n = 1;
        zero = 0;
        while(wish--)
        {
            scanf("%d", &k);
            while(k--)
            {
                scanf("%d %d", &u, &v);
                if(!mpp[u]) mpp[u] = n++;
                if(!mpp[v]) mpp[v] = n++;
                adj[mpp[u]].pb(mpp[v]);
                zero |= u == 0;
            }
        }
        if(!zero)
        {
            printf("Case %d: NO\n", kase++);
            continue;
        }
        call_for_scc_check();
        for(i = 1; i < n; i++)
            if(!col[i]) break;
        if(i != n)
        {
            printf("Case %d: NO\n", kase++);
            continue;
        }
        make_new_DAG();
        u = v = k = 0;
        for(i = 0; i < no_of_component; i++)
        {
            if(indeg[i] == 0 && outdeg[i] == 1)
                u++;
            else if(indeg[i] == 1 && outdeg[i] == 0)
                v++;
            else if(indeg[i] == 1 && outdeg[i] == 1)
                k++;
        }
        if((u + v + k == no_of_component && u == 1 && v == 1) || no_of_component == 1)
            printf("Case %d: YES\n", kase++);
        else
            printf("Case %d: NO\n", kase++);
    }
}
