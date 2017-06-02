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

using namespace std;

int seg[10000000], child[35];

int main()
{
    int n, k, l, i, j, m, cnt;
    scanf("%d %d", &n, &k);
    for(i = 1; i <= k; i++)
    {
        scanf("%d", &m);
        child[i] = m;
        seg[m] = 1;
    }
    l = n * k;
    for(int j = 1; j <= k; j++)
    {
        for(i = 1, cnt = 1; i <= l && cnt < n; i++)
        {
            if(seg[i] == 0)
            {
                seg[i] = 1;
                cout << i << " ";
                cnt++;
            }
        }
        cout << child[j] << endl;
    }
    return 0;
}
