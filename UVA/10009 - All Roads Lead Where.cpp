#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>

#define pb push_back
#define max 'Z'+5

using namespace std;

struct name
{
    char c;
    string s;
} path[max];
queue <char> Q;
vector <char> v[max];
char color[max];
string e, l;

void bfs(char start);

int main()
{
    int m, n, test, j;
    cin >> test;
    while(test--)
    {
        cin >> m >> n;
        while(m--)
        {
            cin >> l >> e;
            v[l[0]].pb(e[0]);
            v[e[0]].pb(l[0]);
            path[l[0]].c = l[0];
            path[e[0]].c = e[0];
        }
        while(n--)
        {
            cin >> l >> e;
            bfs(l[0]);
            for(j = 'A'; j <= 'Z'; j++)
            {
                color[j] = 0;
                path[j].s.clear();
            }
        }
        if(test)
            cout << endl;
        for(j = 'A'; j <= 'Z'; j++)
            v[j].clear();
    }
}

void bfs(char start)
{
    color[start] = 1;
    Q.push(start);
    path[start].s += start;
    char t, ch;
    while(!Q.empty())
    {
        t = Q.front();
        Q.pop();

        for(int i = 0; i < v[t].size(); i++)
        {
            if(color[v[t][i]] != 1)
            {
                color[v[t][i]] = 1;
                Q.push(v[t][i]);
                path[v[t][i]].s = path[t].s + path[v[t][i]].c;
                if(v[t][i] == e[0])
                {
                    cout << path[v[t][i]].s << endl;
                    while(!Q.empty())
                        Q.pop();
                    return;
                }
            }
        }
    }
}
