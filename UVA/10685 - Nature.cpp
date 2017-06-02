#include <vector>
#include <list>
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

void makeset(int node);
void check_relationship(int a, int b);
int find_predator(int node);

int predator[5010];
int connections[5010];
int maxi;

int main()
{
    int c, r, i;
    string s, s2;
    map <string, int> m;
    while(scanf("%d %d", &c, &r) == 2 && c)
    {
        maxi = 1;
        for(i = 1; i <= c; i++)
        {
            cin >> s;
            m[s] = i;
            makeset(i);
        }
        while(r--)
        {
            cin >> s >> s2;
            check_relationship(m[s], m[s2]);
        }
        cout << maxi << endl;
        m.clear();
    }
    return 0;
}

void makeset(int node)
{
    predator[node] = node;
    connections[node] = 1;
}

void check_relationship(int a, int b)
{
    int u = find_predator(a);
    int v = find_predator(b);
    if(u == v)
        return;
    predator[u] = v;
    connections[v] += connections[u];
    if(connections[v] > maxi)
        maxi = connections[v];
}

int find_predator(int node)
{
    if(predator[node] == node)
        return node;
    return predator[node] = find_predator(predator[node]);
}
