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

unsigned long long arr[21];
int cnt[91];

unsigned long long fact(long long unsigned n)
{
    if(n == 0)
        return 1;
    if(arr[n] != 0)
        return arr[n];
    return arr[n] = n * fact(n - 1);
}
void generate(void)
{
    for(int i = 0; i < 21; i++)
        arr[i] = fact(i);
}

int main()
{
    generate();
    string s;
    unsigned long long limit;
    int kase, i, n;
    scanf("%d", &n);
    for(kase = 1; kase <= n; kase++)
    {
        cin >> s;
        limit = s.size();
        for(i = 0; i < limit; i++)
            cnt[s[i]]++;
        limit = arr[limit];
        for(i = 'A'; i <= 'Z'; i++)
        {
            if(cnt[i] > 1)
                limit /= arr[cnt[i]];
            cnt[i] = 0;
        }
        printf("Data set %d: %llu\n", kase, limit);
    }
    return 0;
}

