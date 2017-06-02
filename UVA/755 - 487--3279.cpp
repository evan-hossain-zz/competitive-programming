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

char toint(char x)
{
    if(x >= 'A' && x <= 'C')
        return '2';
    if(x >= 'D' && x <= 'F')
        return '3';
    if(x >= 'G' && x <= 'I')
        return '4';
    if(x >= 'J' && x <= 'L')
        return '5';
    if(x >= 'M' && x <= 'O')
        return '6';
    if(x == 'P' || x == 'R' || x == 'S')
        return '7';
    if(x >= 'T' && x <= 'V')
        return '8';
    if(x >= 'W' && x <= 'Y')
        return '9';
}

int main()
{
    int test, i, n, j, cnt;
    string s, mul;
    scanf("%d", &test);
    while(test--)
    {
        map <string, int> mp;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
                cin >> s;
            mul.clear();
            for(j = 0; j < s.size(); j++)
            {
                if(s[j] >= '0' && s[j] <= '9')
                    mul += s[j];
                else if((s[j] >= 'A' && s[j] <= 'P') ||
                    (s[j] >= 'R' && s[j] <= 'Y'))
                    mul += (toint(s[j]));
            }
            mp[mul]++;
        }
        map <string, int> :: iterator it;
        cnt = 0;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            if(it ->second > 1)
            {
                mul = it->first;
                for(i = 0; i < 3; i++)
                    cout << mul[i];
                cout << "-";
                for(i = 3; i < 7; i++)
                    cout << mul[i];
                cout << " " << it->second << endl;
            }
            else
                cnt++;
        }
        if(cnt == n)
            printf("No duplicates.\n");
        if(test)
            printf("\n");
    }
    return 0;
}

