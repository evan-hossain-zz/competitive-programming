#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 20010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

vector <int> adj[SZ];
//vector <int> dag[SZ];
stack <int> st;
int color[SZ], low[SZ], tim[SZ], group_id[SZ], indeg[SZ], outdeg[SZ], component_no, timer, n, m;

void scc(int u)
{
    int i, v, tem, elements = adj[u].size();
    low[u] = tim[u] = timer++;
    color[u] = 1;
    st.push(u);
    for(i = 0; i < elements; i++)
    {
        v = adj[u][i];
        if(color[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(color[v] == 0)
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
            group_id[tem] = component_no;
            color[tem] = 2;
        }while(tem != u);
        component_no++;
    }
}

void call_for_scc_check(void)
{
    int i;
    while(!st.empty()) st.pop();
    component_no = timer = 0;
//    clr(color, 0);
//    clr(indeg, 0);
//    clr(outdeg, 0);
    for(i = 1; i <= n; i++)
        if(color[i] == 0) scc(i);
}

void make_dag(void)
{
    int i, u, v, elements, j;
    for(i = 1; i <= n; i++)
    {
        elements = adj[i].size();
        for(j = 0; j < elements; j++)
        {
            u = group_id[i];
            v = group_id[adj[i][j]]; // check group_id of adjacent nodes to i
            if(u != v)
            {
                outdeg[u]++;
                indeg[v]++;
            }
        }
    }
}
int main()
{
    int kase, test, i, j, u, v;
    scanf("%d", &test);
    for(kase = 1; kase <= test; kase++)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            color[i] = indeg[i] = outdeg[i] = 0;
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].pub(v);
        }
        call_for_scc_check();
        make_dag();
        for(i = 0, u = v = 0; i < component_no && component_no > 1; i++)
        {
            if(indeg[i] == 0)
                u++;
            if(outdeg[i] == 0)
                v++;
        }
//        cout << component_no << endl;
//        printf("Case %d: %d\n", kase, max(u, v));
        printf("%d\n", max(u, v)); // for HDU 2767
    }
    return 0;
}
// for HDU 3836
/*
int main()
{
    int kase, test, i, j, u, v;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            color[i] = indeg[i] = outdeg[i] = 0;
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].pub(v);
        }
        call_for_scc_check();
        make_dag();
        for(i = 0, u = v = 0; i < component_no && component_no > 1; i++)
        {
            if(indeg[i] == 0)
                u++;
            if(outdeg[i] == 0)
                v++;
        }
//        cout << component_no << endl;
        printf("%d\n", max(u, v));
    }
    return 0;
}
*/
