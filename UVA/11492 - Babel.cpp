#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int d[2005];
map <string, int> ctoi;
map <int, string> itow;
map <string, int> wtoi;

struct info
{
    int country, wordlen;
    bool operator < (const info &p) const
    {
        return p.wordlen < wordlen;
    }
};

struct edge
{
    int country, word;
};


vector <edge> e[2005];
void initialize(int n);
void dijkstra(int beg, int en);

int main()
{
    int n, i,m = 0, w = 0;
    string beg, en, a, b, media;
    while(scanf("%d", &n) == 1 && n)
    {
        initialize(n);
        cin >> beg >> en;
        for(i = 0; i < n; i++)
        {
            cin >> a >> b >> media;
            if(ctoi.find(a) == ctoi.end())
                ctoi[a] = m++;
            if(ctoi.find(b) == ctoi.end())
                ctoi[b] = m++;
            if(wtoi.find(media) == wtoi.end())
            {
                wtoi[media] = w;
                itow[w] = media;
            }
            e[ctoi[a]].pub((edge) {ctoi[b], wtoi[media]});
            e[ctoi[b]].pub((edge) {ctoi[a], wtoi[media]});
        }
        dijkstra(ctoi[beg], ctoi[en]);
        cout << d[ctoi[en]] << endl;
    }
    return 0;
}

void initialize(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        e[i].clear();
        d[i] = infinity;
    }
    return;
}

void dijkstra(int beg, int en)
{
    info u, v;
    u.country = beg, u.wordlen = 0;
    d[beg] = 0;
    priority_queue <info> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.top(), q.pop();
        if(u.country == en)
            return;
        int ucost = d[u.country];
        for(int i = 0; i < e[u.country].size(); i++)
        {
            v.country = e[u.country][i].country;
            int wd = itow[e[u.country][i].word].size();
            v.wordlen = ucost + wd;
            if(d[v.country] > v.wordlen)
            {
                d[v.country] = v.wordlen;
                q.push(v);
            }
        }
    }
}
