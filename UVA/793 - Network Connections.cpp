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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

void makeset(int node);
void check_relationship(int a, int b);
void creat_relationship(int a, int b);
int find_parent(int node);

int computers[1000000];
int success, unsuccess;

char str[20], ch;
int main()
{
    int test, pcs, A, B, i;
    scanf("%d", &test);
    while(test--)
    {
        success = unsuccess = 0;
        scanf("%d", &pcs);
        getchar();
        for(i = 1; i <= pcs; i++)
            makeset(i);
        while(gets(str) && strlen(str))
        {
            sscanf(str, "%c %d %d", &ch, &A, &B);
            if(ch == 'c')
                creat_relationship(A, B);
            else
                check_relationship(A, B);
        }
        printf("%d,%d\n", success, unsuccess);
        if(test)
            printf("\n");
    }
    return 0;
}

void makeset(int node)
{
    computers[node] = node;
}

void creat_relationship(int a, int b)
{
    int u = find_parent(a);
    int v = find_parent(b);
    if(u == v)
        return;
    computers[u] = v;
}

void check_relationship(int a, int b)
{
    int u = find_parent(a);
    int v = find_parent(b);
    if(u == v)
        success++;
    else
        unsuccess++;
}

int find_parent(int node)
{
    if(computers[node] == node)
        return node;
    return computers[node] = find_parent(computers[node]);
}
