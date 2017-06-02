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
#define infinity 2147483647

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

long long arr[110];

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int test, i, cnt, j;
    long long ans;
    string s;
    scanf("%d ", &test);
    while(test--)
    {
        i = cnt = ans = 0;
        getline(cin, s);
        istringstream ss(s);
        while(ss >> arr[i++])
            cnt++;
        cnt--;
        for(i = 0; i < cnt ; i++)
            for(j = i + 1; j <= cnt; j++)
                ans = max(ans, gcd(arr[i], arr[j]));
        printf("%d\n", ans);
    }
    return 0;
}

