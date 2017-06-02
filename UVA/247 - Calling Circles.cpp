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
#define SZ 27

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;
int low[SZ], tim[SZ], col[SZ], group_id[SZ], no_of_component, n, timer;
vector <int> adj[SZ];
stack <int> st;
map <string, int> mp;
map<int, string> itos;

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
            group_id[tem] = no_of_component;
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
    int i, m, map_counter = 0, u, v, kase = 0;
    string from, to;
    while(scanf("%d %d", &n, &m) == 2 && (n | m))
    {
        if(kase)
            printf("\n");
        map_counter = 0;
        for(i = 0; i < n; i++)
            adj[i].clear();
        mp.clear();
        itos.clear();
        for(i = 0; i < m; i++)
        {
            cin >> from >> to;
            if(mp.find(from) == mp.end())
            {
                mp[from] = map_counter;
                itos[map_counter] = from;
                map_counter++;
            }
            if(mp.find(to) == mp.end())
            {
                mp[to] = map_counter;
                itos[map_counter] = to;
                map_counter++;
            }
            u = mp[from], v = mp[to];
            adj[u].pub(v);
        }
        call_for_scc_check();
        printf("Calling circles for data set %d:\n", ++kase);
        for(i = 0; i < no_of_component; i++)
        {
            from.clear();
            for(u = 0; u < n; u++)
            {
                if(group_id[u] == i)
                    from += itos[u] + ", ";
            }
            from.resize(from.size() - 2);
            printf("%s\n", from.c_str());
        }
    }
    return 0;
}


