#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <map>

#define pub push_back
using namespace std;

void bfs(void);

queue <int> q;
vector <int> v[5010];
vector <int> adj;
int path[5010];
char color[5010];

int main()
{
    int lines, root, names, test, next, si, j, pre, k;
    char ch;
    map <string, int> strint;
    string temp;
    scanf("%d", &test);
    for(int sc = 1; sc <= test; sc++)
    {
        printf("Scenario %d\n", sc);
        next = 0;
        si = 1;
        scanf("%d %d ", &lines, &names);
        while(lines--)
        {
            root = 0;
            while(scanf(" %c", &ch) == 1)
            {
                if(ch == ',')
                {
                    if(next == 0)
                    {
                        next = 1;
                        temp += ", ";
                    }
                    else
                    {
                        if(strint.find(temp) == strint.end())
                        {
                            strint[temp] = si;
                            if(temp == "Erdos, P.")
                                root = si;
                            else
                                adj.pub(si);
                            si++;
                        }
                        else
                            adj.pub(strint[temp]);
                        next = 0;
                        temp.clear();
                    }
                }
                else if(ch == ':')
                {
                    if(strint.find(temp) == strint.end())
                    {
                        strint[temp] = si;
                        if(temp == "Erdos, P.")
                            root = si;
                        else
                            adj.pub(si);
                        si++;
                    }

                    else
                        adj.pub(strint[temp]);
                    next = 0;
                    while(getchar() != '\n');
                    temp.clear();
                    break;
                }
                else
                    temp += ch;
            }
            if(root)
            {
                for(int i = 0; i < adj.size(); i++)
                {
                    v[root].pub(adj[i]);
                    v[adj[i]].pub(root);
                }
            }
            else
            {
                root = adj[0];
                for(int i = 1; i < adj.size(); i++)
                {
                    v[root].pub(adj[i]);
                    v[adj[i]].pub(root);
                }
            }
            adj.clear();
        }
        q.push(strint["Erdos, P."]);
        path[strint["Erdos, P."]] = 0;
        bfs();
        while(names--)
        {
            getline(cin, temp);
            if(temp == "Erdos, P.")
                cout << temp << " 0" << endl;
            else if(!path[strint[temp]])
                cout << temp << " infinity" << endl;
            else
                cout << temp << " " << path[strint[temp]] << endl;
        }
        for(int i = 0; i <= si; i++)
        {
            path[i] = color[i] = 0;
            v[i].clear();
        }
        while(!q.empty())
            q.pop();
        temp.clear();
        strint.clear();
    }
    return 0;
}

void bfs(void)
{
    int now, p;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for(p = 0; p < v[now].size(); p++)
        {
            if(color[v[now][p]] == 0)
            {
                color[v[now][p]] = 1;
                path[v[now][p]] = path[now] + 1;
                q.push(v[now][p]);
            }
        }
    }
}
