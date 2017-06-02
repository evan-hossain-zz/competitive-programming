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

#define pub push_back

using namespace std;

int main()
{
    string s;
    vector <string> v;
    int test, len, one;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &len, &one);
        for(int i = 0; i < (len - one); i++)
            s += "0";
        for(int i = 0; i < one; i++)
            s += "1";
        v.pub(s);
        while(next_permutation(s.begin(), s.end()))
            v.pub(s);
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
        s.clear();
        v.clear();
    }
    return 0;
}
