#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    int res = 0, tem;
    cin >> s >> s;
    for(char a = 'a'; a <= 'z'; a++)
    {
        for(char b = 'a'; b <= 'z'; b++)
        {
            if(a == b) continue;
            tem = 0;
            bool ca = 1;
            for(auto ch: s)
            {
                if(ch == a || ch == b)
                {
                    if(ca && ch == a)
                    {
                        tem++;
                    }
                    else if(!ca && ch == b)
                    {
                        tem++;
                    }
                    else
                    {
                        tem = 0;
                        break;
                    }
                    ca = !ca;
                }
            }
            res = max(res, tem);
        }
    }
    if(res < 2) res = 0;
    cout << res;
    return 0;
}
