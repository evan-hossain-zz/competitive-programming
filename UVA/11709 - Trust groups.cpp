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
#define SZ 1010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
int low[SZ], tim[SZ], col[SZ], no_of_component, n, timer;
vector <int> adj[SZ];
stack <int> st;
map <string, int> mp;

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
        }
        while(tem != u);
        no_of_component++;
    }
}

void call_for_scc_check(void)
{
    no_of_component = timer = 0;
    clr(col, 0);
    int i;
    while(!st.empty()) st.pop();
    for(i = 0; i < n; i++)
    {
        if(col[i] == 0)
            scc(i);
    }
}

int main()
{
//    out;
    int i, m, map_counter = 0, u, v;
    string from, to;
    char str[SZ];
    while(scanf("%d %d", &n, &m) == 2 && (n | m))
    {
        map_counter = 0;
        mp.clear();
        while(getchar() != '\n');
        for(i = 0; i < n; i++)
        {
            adj[i].clear();
            gets(str);
            from = str;
            mp[from] = i;
        }
        for(i = 0; i < m; i++)
        {
            gets(str);
            from = str;
            gets(str);
            to = str;
            u = mp[from], v = mp[to];
            adj[u].pub(v);
        }
        call_for_scc_check();
        printf("%d\n", no_of_component);
    }
    return 0;
}



