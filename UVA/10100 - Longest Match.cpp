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
#define Pi 2*acos(0)

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;

int arr[120][120];

int main()
{
    string s, t, tem;
    int i, j, kase = 0;
    while(getline(cin, s) && getline(cin, t))
    {
        vector <string> v1, v2;
        if(s.size() == 0 || t.size() == 0)
        {
            printf("%2d. Blank!\n", ++kase);
            continue;
        }
        for(i = 0; i < s.size(); i++)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= '0' && s[i] <= '9'))
                tem += s[i];
            else if(tem.size() > 0)
            {
                v1.pub(tem);
                tem.clear();
            }
        }
        if(tem.size())
        {
            v1.pub(tem);
            tem.clear();
        }
        for(i = 0; i < t.size(); i++)
        {
            if((t[i] >= 'A' && t[i] <= 'Z') ||
                (t[i] >= 'a' && t[i] <= 'z') ||
               (t[i] >= '0' && t[i] <= '9'))
                tem += t[i];
            else if(tem.size() > 0)
            {
                v2.pub(tem);
                tem.clear();
            }
        }
        if(tem.size())
        {
            v2.pub(tem);
            tem.clear();
        }
        i = j = 1;
        for(i = 1; i <= v1.size(); i++)
        {
            for(j = 1; j <= v2.size(); j++)
            {
                if(v1[i - 1] == v2[j - 1])
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                else
                {
                    if(arr[i - 1][j] > arr[i][j - 1])
                        arr[i][j] = arr[i - 1][j];
                    else
                        arr[i][j] = arr[i][j - 1];
                }
            }
        }
        printf("%2d. Length of longest match: %d\n", ++kase, arr[i - 1][j - 1]);
        j = max(v1.size(), v2.size());
        for(i = 0; i <= j; i++)
            arr[i][0] = arr[0][i] = 0;
    }
    return 0;
}
