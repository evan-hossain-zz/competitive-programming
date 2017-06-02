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
#include <cstring>

#define out freopen("out.txt", "w", stdout);
#define in freopen("in.txt", "r", stdin);
#define pub push_back
#define pob pop_back

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

int main()
{
    //in;
    int maxi = 0, i;
    string s, ans, temp;
    while(cin >> s && s != "E-N-D")
    {
        temp.clear();
        for(i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
            if((s[i] >= 'a' && s[i] <= 'z')
                    || s[i] == '-')
                temp += s[i];
        }
        if(temp.size() > maxi)
        {
            maxi = temp.size();
            ans = temp;
        }
    }
    cout << ans << endl;
    return 0;
}
