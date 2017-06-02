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

int hp[5005], indx;

int getmin(void);
void insert(int n);

int main()
{
    int total_numbers, cost, i, num, newcost;
    while(scanf("%d", &total_numbers) == 1 && total_numbers)
    {
        cost = newcost = indx = 0;
        for(i = 0; i < total_numbers; i++)
        {
            scanf("%d", &num);
            insert(num);
        }
        while(indx > 1)
        {
            cost += newcost = getmin() + getmin();
                insert(newcost);
        }
        printf("%d\n", cost);
    }
    return 0;
}

void insert(int n)
{
    hp[++indx] = n;
    int cur = indx;
    while(hp[cur >> 1] > hp[cur] && cur > 1)
    {
        swap(hp[cur], hp[cur >> 1]);
        cur = cur >> 1;
    }
}

int getmin(void)
{
    int cur = 1, child, ret = hp[cur], last_element = hp[indx--];
    while(cur << 1 <= indx)
    {
        child = cur << 1;
        if(child != indx && hp[child + 1] < hp[child])
            child++;
        if(last_element > hp[child])
        {
            hp[cur] = hp[child];
            cur = child;
        }
        else
            break;
    }
    hp[cur] = last_element;
    return ret;
}
