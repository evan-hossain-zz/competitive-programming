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
#define LL long long

///LL col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///LL row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

LL data[1000005], moves;

void merge_sort(LL *data, LL lef, LL rig);
void merg(LL *data, LL lef, LL mid, LL rig);

int main()
{
    LL n;
    int i;
    while(scanf("%lld", &n) == 1)
    {
        for(i = 0; i < n; i++)
            scanf("%lld", &data[i]);
        moves = 0;
        merge_sort(data, 0, n - 1);
        printf("%lld\n", moves);
    }
    return 0;
}

void merge_sort(LL *data, LL lef, LL rig)
{
    LL mid = (lef + rig) >> 1;
    if(lef < rig)
    {
        merge_sort(data, lef, mid);
        merge_sort(data, mid + 1, rig);
        merg(data, lef, mid, rig);
    }
    return;
}

void merg(LL *data, LL lef, LL mid, LL rig)
{
    LL tem[rig - lef + 1], indx = 0;
    LL leftmost = lef, rightmost = mid + 1, total = mid - lef + 1;
    while(leftmost <= mid && rightmost <= rig)
    {
        if(data[leftmost] < data[rightmost])
        {
            tem[indx++] = data[leftmost++];
            total--;
        }
        else
        {
            tem[indx++] = data[rightmost++] ;
            moves += total;
        }
    }
    while(leftmost <= mid) tem[indx++] = data[leftmost++];
    while(rightmost <= rig) tem[indx++] = data[rightmost++];
    for(int i = 0; i < indx; i++)
        data[lef + i] = tem[i];
    return;
}

