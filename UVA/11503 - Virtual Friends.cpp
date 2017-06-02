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
int check_relationship(int a, int b);
int find_predator(int node);

int predator[100005];
int connections[100005];
int maxi;

int main()
{
    int c, r, i, test;
    scanf("%d", &test);
    string s, s2;
    map <string, int> m;
    while(test--)
    {
        scanf("%d", &r);
        maxi = i = 0;
        while(r--)
        {
            cin >> s >> s2;
            if(m.find(s) == m.end())
            {
                m[s] = ++i;
                makeset(i);
            }
            if(m.find(s2) == m.end())
            {
                m[s2] = ++i;
                makeset(i);
            }
            cout << check_relationship(m[s], m[s2]) << endl;
        }
        m.clear();
    }
    return 0;
}

void makeset(int node)
{
    predator[node] = node;
    connections[node] = 1;
}

int check_relationship(int a, int b)
{
    int u = find_predator(a);
    int v = find_predator(b);
    if(u == v)
        return connections[v];
    predator[u] = v;
    connections[v] += connections[u];
    return connections[v];
}

int find_predator(int node)
{
    if(predator[node] == node)
        return node;
    return predator[node] = find_predator(predator[node]);
}

