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

int main()
{
    string s;
    int i;
    string a = "1", b = "14", c = "144";
    cin >> s;
    for(i  = 0; i < s.size(); i++)
    {
        if(s[i] == '1')
        {
            i++;
            while(s[i] == '1' && i < s.size()) i++;
            if(s[i] == '4' && i < s.size())
                i++;
            if(s[i] == '4' && i < s.size());
            else i--;
        }
        else
        {
//            cout << i << endl;
            break;
        }
    }
    if(i >= s.size())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

