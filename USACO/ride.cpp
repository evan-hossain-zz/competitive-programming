/*
ID: contest1
PROG: ride
LANG: C++
*/
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
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int main()
{
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string a, b;
    long long c, g;
    while(cin >> a >> b)
    {
        c = g = 1;
        for(int i = 0; i < a.size(); i++)
            c *= (a[i] - 64);
        c %= 47;
        for(int i = 0; i < b.size(); i++)
            g *= (b[i] - 64);
        g %= 47;
        if(c == g)
            printf("GO\n");
        else
            printf("STAY\n");
    }
    return 0;
}

