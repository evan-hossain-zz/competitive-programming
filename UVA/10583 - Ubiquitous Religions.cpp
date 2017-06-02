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
int find_parent(int node);

int citizens[50005];
int people;

int main()
{
    int A, B, i, r, kase = 1;
    while(scanf("%d %d", &people, &r) == 2 && people)
    {
        for(i = 1; i <= people; i++)
            makeset(i);
        while(r--)
        {
            scanf("%d %d", &A, &B);
            check_relationship(A, B);
        }
        printf("Case %d: %d\n", kase++, people);
    }
    return 0;
}

void makeset(int node)
{
    citizens[node] = node;
}

void check_relationship(int a, int b)
{
    int u = find_parent(a);
    int v = find_parent(b);
    if(u == v)
        return;
    citizens[u] = v;
    people--;
}

int find_parent(int node)
{
    if(citizens[node] == node)
        return node;
    return citizens[node] = find_parent(citizens[node]);
}

