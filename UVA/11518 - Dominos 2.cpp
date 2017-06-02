#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int cnt;
char visited[10010];
vector <int> v[10010];

void dfs(int start);

int main()
{
    int m, n, l, test, a, b, i;
    scanf("%d", &test);
    while(test--)
    {
        cnt = 0;
        scanf("%d %d %d", &n, &m, &l);
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
        }
        for(i = 0; i < l; i++)
        {
            scanf("%d", &a);
            if(visited[a] == 0)
            {
                visited[a] = 1;
                dfs(a);
            }
        }
        for(b = 0; b <= n; b++)
        {
            if(visited[b] == 1)
                cnt++;
            visited[b] = 0;
        }
        printf("%d\n", cnt);
        for(i = 0; i < 10010; i++)
            v[i].clear();
    }
    return 0;
}

void dfs(int start)
{
    int i;
    for(i = 0; i < v[start].size(); i++)
    {
        if(visited[v[start][i]] == 0)
        {
            visited[v[start][i]] = 1;
            dfs(v[start][i]);
        }
    }
    return;
}
