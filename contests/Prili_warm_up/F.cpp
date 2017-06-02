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
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;


int main()
{
    int sum, test, n, m, k, i, j, on[55], mn, indx;
    cin >> test;
    char c;
    while(test--)
    {
        cin >> n >> m >> k;
        for(i = 1; i <= n; i++)
        {
            sum = 0;
            for(j = 1; j <= m; j++)
            {
                cin >> c;
                if(c == '*')
                    sum++;
            }
            on[i] = sum;
        }
        while(k)
        {
            mn = infinity;
            for(i = 1; i <= n; i++)
            {
                if(on[i] < mn)
                {
                    mn = on[i];
                    indx = i;
                }
            }
            if(on[indx] * 2 > m)
            {
                if(k % 2 == 0)
                    break;
                else
                {
                    on[indx] = m - on[indx];
                    break;
                }
            }
            else
            {
                on[indx] = m - on[indx];
                k--;
            }
        }
        sum = 0;
        for(i = 1; i <= n; i++)
            sum += on[i];
        cout << sum << endl;
    }
    return 0;
}

