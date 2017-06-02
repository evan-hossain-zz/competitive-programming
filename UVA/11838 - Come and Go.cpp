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
#define SZ 2010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
int low[SZ], tim[SZ], col[SZ], no_of_component, n, timer;
vector <int> adj[SZ];
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
            col[tem] = 2;
        }while(tem != u);
        no_of_component++;
    }
}

void call_for_scc_check(void)
{
    no_of_component = timer = 0;
    int i;
    while(!st.empty()) st.pop();
    for(i = 1; i <= n; i++)
    {
        if(col[i] == 0)
            scc(i);
    }
}

int main()
{
    int i, u, v, direction, m;
    while(scanf("%d %d", &n, &m) == 2 && (m && n))
    {
        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            col[i] = 0;
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &direction);
            if(direction == 1)
                adj[u].pub(v);
            else
            {
                adj[u].pub(v);
                adj[v].pub(u);
            }
        }
        call_for_scc_check();
        if(no_of_component == 1)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}

