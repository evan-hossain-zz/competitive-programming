#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

#define pub push_back

using namespace std;


int indeg[110];

int main()
{
    int n, m, i, j, a, b, now;
    queue <int> q;
    vector <int> v[110];
    while(scanf("%d %d", &n, &m) == 2 && n)
    {
        while(m--)
        {
            scanf("%d %d", &a, &b);
            v[a].pub(b);
            indeg[b]++;
        }
        for(i = 1; i <= n; i++)
        {
            if(indeg[i] == 0)
                q.push(i);
        }
        while(true)
        {
            now = q.front();
            q.pop();
            printf("%d", now);
            for(j = 0; j < v[now].size(); j++)
            {
                indeg[v[now][j]]--;
                if(indeg[v[now][j]] == 0)
                    q.push(v[now][j]);
            }
            if(!q.empty())
                printf(" ");
            else
                break;
        }
        printf("\n");
        for(i = 1; i <= n; i++)
            indeg[i] = 0;
        for(i = 0; i < 105; i++)
            v[i].clear();
    }
    return 0;
}
