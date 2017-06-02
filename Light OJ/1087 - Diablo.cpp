#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 150010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

struct info
{
    int army;
    LL already_called_army;
};

int BEG, END, arr[SZ];
info segtree[SZ];

void build(int L, int R, int cur)
{
    if(L == R)
    {
        segtree[cur].army = arr[L];
        segtree[cur].already_called_army = 0;
        return;
    }
    build(L, (L + R) >> 1, cur >> 1);
    build(((L + R) >> 1) + 1, R, (cur >> 1) + 1);
    segtree[cur].already_called_army = 0;
}

int update(int L, int R, int cur);


int main()
{
    return 0;
}
