#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct point{
    int x, y;
    };
void bfs(point start);
vector <int> path;
queue <point> q;

int main()
{
    vector <int> v[1000000];
    point p;
    int x0, y0, x1, y1, r, a, b, n;
    cin >> x0 >> y0 >> x1 >> y1;
    p.x = x0;
    p.y = y0;
//    v[x0].push_back(y0);
//    v[x1].push_back(y1);
    cin >> n;
    while(n--)
    {
        cin >> r >> a >> b;
        for(int i = a; i <= b; i++)
        {
            v[r].push_back(i);
        }
    }
    bfs(p);
    p.x = x1, p.y = y1;
    if(path[p] == 0)
        printf("-1");
    else
        printf("%d", path[p]);
}

void bfs(point start)
{
    point d, next;
    q.push(start);
    while(!q.empty())
    {
        next = q.front();
        int c = next.x;
        q.pop();
        for(int i = 0; i < v[c].size(); i++)
        {
            d.x = c;
            d.y = v[c][i];
            path[d] = path[next] + 1;
            q.push(d);
        }
    }
}
