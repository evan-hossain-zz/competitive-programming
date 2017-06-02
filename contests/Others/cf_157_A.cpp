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

int main()
{
    int i, b = 0, cnt = 8, paisi = 0, bl = 0, w = 0;
    char x;
    string s;
    while(cnt--)
        {
            getline(cin, s);
            b = bl = w =0;
            for(i = 0; i < s.size(); i++)
                {
                    if(b == 1 && s[i] == 'B')
                    {
                        paisi = 1;
                        bl++;
                        break;
                    }
                    if(s[i] == 'B')
                    {
                        b++;
                        bl++;
                    }
                    else
                    {
                        w++;
                        b = 0;
                    }
                }
            if(bl != w)
                paisi = 1;
        }
    if(paisi)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}

