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
#include <cstring>

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 2147483647

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

struct edge
{
    int u, v;
    double w;
    bool operator < (const edge& p) const
    {
        return p.w > w;
    }
};

struct point
{
    int a, b;
};

vector <edge> e;
point arr[800];
int par[800];
bool given[800][800];

int find_set(int node);
double mst(int n);


int main()
{
    return 0;
}

