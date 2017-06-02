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

int arr[27];

int main()
{
    int n, cnt, m;
    string s;
    scanf("%d", &n);
    while(getchar() != '\n');
    for(int i = 1; i <= n; i++)
    {
        m = cnt = 0;
        getline(cin, s);
        for(int j = 0; j < s.size(); j++)
        {
            s[j] = toupper(s[j]);
            if(s[j] >= 'A' && s[j] <= 'Z')
            {
                arr[s[j] - 65]++;
                m = max(arr[s[j] - 65], m);
            }
        }
        for(int mul = 26; m > 0; m--)
        {
            for(int j = 0; j < 27; j++)
            {
                if(arr[j] == m)
                {
                    cnt += (arr[j] * mul);
                    arr[j] = 0;
                    mul--;
                }
            }
        }
        cout << "Case #" << i << ": " << cnt << endl;
    }
    return 0;
}

