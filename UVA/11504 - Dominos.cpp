#include <iostream>
#include <vector>
#include <cstring>
#define pb push_back

using namespace std;

vector <int> v[100005];
vector <int> f;
char color[100005];
int flag;

void dfs(int start);

int main()
{
    int n, r, i, e, test, cnt;
    cin >> test;
    while(test--)
    {
        cin >> n >> r;
        while(r--)
        {
            cin >> i >> e;
            v[i].pb(e);
        }
        flag = 1;
        for(i = 1; i <= n; i++)
        {
            if(color[i] != flag)
            {
                color[i] = flag;
                dfs(i);
                f.pb(i);
            }
        }
        i = f.size();
        cnt = 0;
        flag = 2;
        while(i--)
        {
            if(color[f[i]] != flag)
            {
                color[f[i]] = flag;
                dfs(f[i]);
                cnt++;
            }
        }
        cout << cnt << endl;
        for(i = 0; i <= n; i++)
            v[i].clear();
        memset(color, 0, sizeof(char) * (n + 1));
        f.clear();
    }
    return 0;
}

void dfs(int start)
{
    int s = v[start].size(), p;
    for(p = 0; p < s; p++)
    {
        if(color[v[start][p]] != flag)
        {
            color[v[start][p]] = flag;
            if(!v[v[start][p]].empty())
                dfs(v[start][p]);
        }
    }
    return;
}
