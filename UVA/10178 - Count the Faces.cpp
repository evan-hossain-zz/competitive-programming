#include <vector>
#include <list>
#include <cstring>
#include <map>
#include <set>
#include <deque>
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

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

int par[130], cnt, taken[130];

void makeset(int node);
void check_friendship(int a, int b);
int find_rep(int node);

int main()
{
    int i, v, e;
    char x, ch1, ch2;
    while(scanf("%d %d", &v, &e) == 2)
    {
        cnt = v;
        for(i = 0; i < e; i++)
        {
            scanf(" %c %c", &ch1, &ch2);
            if(taken[ch1] == 0)
            {
                makeset(ch1);
                taken[ch1] = 1;
            }
            if(taken[ch2] == 0)
            {
                makeset(ch2);
                taken[ch2] = 1;
            }
            check_friendship(ch1, ch2);
        }
        printf("%d\n", cnt + e - v + 1);
        for(i = 64; i <= 130; i++)
            taken[i] = par[i] = 0;
    }
    return 0;
}

void makeset(int node)
{
    par[node] = node;
}

void check_friendship(int a, int b)
{
    int u = find_rep(a);
    int v = find_rep(b);
    if(u == v) return;
    par[u] = v;
    cnt--;
}

int find_rep(int node)
{
    if(par[node] == node)
        return node;
    return par[node] = find_rep(par[node]);
}
