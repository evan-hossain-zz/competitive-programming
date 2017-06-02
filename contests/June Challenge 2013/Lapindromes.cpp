#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <time.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int L[150], R[150];

int main()
{
    int i, test, j;
    string s;
    scanf("%d", &test);
    while(test--)
    {
        clr(L, 0), clr(R, 0);
        cin >> s;
        for(i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
            L[s[i]]++, R[s[j]]++;
        for(i = 'a'; i <= 'z'; i++)
            if(L[i] != R[i])
                break;
        if(i > 'z')
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
