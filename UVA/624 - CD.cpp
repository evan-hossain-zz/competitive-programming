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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

void backtrack(int i, int sum);

long long ans;
int N, tr, store[21];

vector <int> res, maxi;

int main()
{
    int cur, i, sum;
    while(scanf("%d %d", &N, &tr) == 2)
        {
            for(i = 0; i < tr; i++)
                scanf("%d", &store[i]);
            ans = 0;
            backtrack(0, 0);
            sum = 0;
            for(int i = 0; i < maxi.size(); i++)
            {
                cout << maxi[i] << " ";
                sum += maxi[i];
            }
            printf("sum:%d\n", sum);
            res.clear();
            maxi.clear();
        }
    return 0;
}

void backtrack(int i, int sum)
{
    if(i <= tr)
        {
            if(sum > ans)
                {
                    maxi = res;
                    ans = sum;
                }
        }
    for(; i < tr; i++)
        {
            if(sum + store[i] <= N)
                {
                    res.pub(store[i]);
                    backtrack(i + 1, sum + store[i]);
                    res.pob();
                }
        }
}
