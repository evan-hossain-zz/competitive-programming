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

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int isop(string s);
int calculate(int num, int n, string s);

int main()
{
    int i, n, party, qu, kase, a, b;
    while(scanf("%d %d", &party, &qu) == 2)
        {
            kase = 0;
            int arr[51];
            string s;
            map <string, int> mp;
            for(i = 0; i < party; i++)
                {
                    cin >> s;
                    mp[s] = i;
                    scanf("%d.%d", &a, &b);
                    arr[i] = a * 10 + b;
                }
            for(i = 1; i <= qu; i++)
                {
                    int res = 0, d;
                    while(cin >> s)
                        {
                            if(isop(s))
                                {
                                    scanf("%d", &d);
                                    if(calculate(res, d * 10, s))
                                        printf("Guess #%d was correct.\n", ++kase);
                                    else
                                        printf("Guess #%d was incorrect.\n", ++kase);
                                    break;
                                }
                            if(s != "+")
                                res += arr[mp[s]];
                        }
                }
        }
    return 0;
}

int isop(string s)
{
    if(s == ">" || s == "<" || s == "=" || s == ">=" || s == "<=")
        return 1;
    return 0;
}

int calculate(int num, int n, string s)
{
    if(s == ">" && num > n)
        return 1;
    if(s == "<" && num < n)
        return 1;
    if(s == ">=" && num >= n)
        return 1;
    if(s == "<=" && num <= n)
        return 1;
    if(s == "=" && num == n)
        return 1;
    return 0;
}
