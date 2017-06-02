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

int par[95], cnt;

void makeset(int node);
void check_friendship(int a, int b);
int find_rep(int node);

int main()
{
    int test, i;
    char x, str[3];
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %c", &x);
        getchar();
        for(i = 'A'; i <= x; i++)
            makeset(i);
        cnt = x - 'A' + 1;
        while(gets(str) && strlen(str))
        {
            check_friendship(str[0], str[1]);
        }
        printf("%d\n", cnt);
        if(test)
            printf("\n");
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
