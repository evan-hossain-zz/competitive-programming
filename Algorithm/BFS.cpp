#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

vector <int> adj[MAX];
bool color[MAX];

void bfs(int beg)
{
    queue <int> Q;
    memset(color, 0, sizeof color);
    color[beg] = 1;
    Q.push(beg);
    while(!Q.empty())
    {
        int from = Q.front();
        Q.pop();
        for(int i = 0; i < adj[from].size(); i++)
        {
            int to = adj[from][i];
            if(!color[to])
            {
                color[to] = 1;
                Q.push(to);
            }
        }
    }
}

void dfs(int node)
{
    color[node] = 1;
    for(int i = 0; i < adj[node].size(); i++)
    {
        if(!color[adj[node][i]])
            dfs(adj[node][i]);
    }
}

int main()
{
    int n, a, b, i, q;
    while(cin >> n && n)
    {
        for(i = 1; i <= n; i++)
            adj[i].clear();
        cout << "how many connection? ";
        cin >> q;
        cout << "enter connections among the " << n << " nodes" << endl;
        while(q--)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(a);
        for(i = 1; i <= n; i++)
        {
            if(color[i] == 0)
                break;
        }
        if(i > n)
            cout << "The graph is connected" << endl;
        else
            cout << "The graph is not connected" << endl;
    }
}
