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

vector <int> flips, input, cur, temp;

struct info
{
    int val, pos;
};

int sorted(void);
info findmax(void);

int main()
{
    string s;
    stack <int> st;
    int n, i;
    info most;
    while(getline(cin, s))
    {
        stringstream ss(s);
        while(ss >> n)
        {
            input.pub(n);
            cur.pub(n);
        }
        while(!sorted())
        {
            most = findmax();
            if(most.pos != 1)
            {
                if(most.pos == cur.size())
                {
                    cur.pob();
                    continue;
                }
                flips.pub(input.size() - most.pos + 1);
                temp = cur;
                cur.clear();
                for(i = most.pos - 1; i >= 0; i--)
                    cur.pub(temp[i]);
                for(i = most.pos; i < temp.size(); i++)
                    cur.pub(temp[i]);
            }
            else if(most.pos == 1)
            {
                flips.pub(input.size() - cur.size() + 1);
                temp = cur;
                cur.clear();
                for(i = temp.size() - 1; i > 0; i--)
                    cur.pub(temp[i]);
            }
        }
        for(i = 0; i < input.size() - 1; i++)
            cout << input[i] << " ";
        cout << input[i] << endl;
        if(flips.size())
        {
            for(i = 0; i < flips.size() - 1; i++)
                cout << flips[i] << " ";
            cout << flips[i] << " 0\n";
        }
        else
            cout << "0\n";
        input.clear();
        cur.clear();
        flips.clear();
    }
    return 0;
}

int sorted(void)
{
    int i;
    for(i = 0; i < cur.size() - 1; i++)
    {
        if(cur[i] > cur[i + 1])
            return 0;
    }
    return 1;
}

info findmax(void)
{
    int i;
    info m;
    m.val = 0;
    for(i = 0; i < cur.size(); i++)
    {
        if(m.val < cur[i])
        {
            m.val = cur[i];
            m.pos = i + 1;
        }
    }
    return m;
}
