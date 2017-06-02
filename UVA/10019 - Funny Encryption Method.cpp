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

int to_bin(int n);
int to_hex(int n);

int main()
{
    int test, n;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        printf("%d %d\n", to_bin(n), to_hex(n));
    }
    return 0;
}

int to_bin(int n)
{
    int cnt = 0;
    do
    {
        if(n % 2 == 1)
            cnt++;
        n /= 2;
    }
    while(n);
    return cnt;
}

int to_hex(int n)
{
    int cnt = 0;
    do
    {
        cnt += to_bin(n % 10);
        n /= 10;
    }
    while(n);
    return cnt;
}
