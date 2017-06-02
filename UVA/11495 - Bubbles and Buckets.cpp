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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int data[100005], moves;

void merge_sort(int *data, int lef, int rig);
void merg(int *data, int lef, int mid, int rig);

int main()
{
    int n, i;
    while(scanf("%d", &n) == 1 && n)
    {
        moves = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &data[i]);
        merge_sort(data, 0, n - 1);
        if(moves & 1)
            printf("Marcelo\n");
        else
            printf("Carlos\n");
    }
    return 0;
}

void merge_sort(int *data, int lef, int rig)
{
    int mid = (lef + rig)>> 1;
    if(lef < rig)
    {
        merge_sort(data, lef, mid);
        merge_sort(data, mid + 1, rig);
        merg(data, lef, mid, rig);
    }
    return;
}

void merg(int *data, int lef, int mid, int rig)
{
    int temp[rig - lef + 1], indx = 0;
    int leftmost = lef, rightmost = mid + 1, total = mid - lef + 1;
    while(leftmost <= mid && rightmost <= rig)
    {
        if(data[leftmost] < data[rightmost])
        {
            temp[indx++] = data[leftmost++];
            total--;
        }
        else
        {
            temp[indx++] = data[rightmost++];
            moves += total;
        }
    }
    while(leftmost <= mid) temp[indx++] = data[leftmost++];
    while(rightmost <= mid) temp[indx++] = data[rightmost++];
    for(int i = 0; i < indx; i++)
        data[lef + i] = temp[i];
    return;
}
