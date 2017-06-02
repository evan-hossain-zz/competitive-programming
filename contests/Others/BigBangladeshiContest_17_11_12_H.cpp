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

#define pub push_back
#define pob pop_back

using namespace std;

int main()
{
    unsigned long long k, grid[51][51];
    int n, test, kase;
    cin >> test;
    for(kase = 1; kase <= test; kase++)
    {
        cin >> k >> n;
        k--;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                scanf("%llu", &grid[i][j]);
        }
        printf("Region #%d:\n", kase);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << grid[i][j] + k << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
