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
    string s;
    int n, i, j;
    cin >> n;
    while(getchar() != '\n');
    for(int kase = 1; kase <= n; kase++)
    {
        stack <char> st;
        getline(cin, s);
        for(i = 0; i < s.size();)
        {
            if(s[i] == ':')
                st.push(':');
            else if(s[i] == ')')
            {
                if(st.top() == '(' || st.top() == ':')
                {
                    st.pop();
                    i++;
                }
            }
            else if(s[i] == '(')
            {
                if(st.top() == ':')
                        st.pop();
                else
                    st.push('(');
                i++;
            }
            else
                i++;
        }
        if(st.empty())
            printf("Case #%d: YES\n", kase);
        else
            printf("Case #2: NO\n", kase);
    }
    return 0;
}

