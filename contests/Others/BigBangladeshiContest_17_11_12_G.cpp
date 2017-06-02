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
#define pob pop_back

using namespace std;

int main()
{
    long long s, p, coffee;
    while(cin >> s >> p)
    {
        p = p - s;
        if(p >= 60 * 30)
            printf("4\n");
        else if(p >= 60 * 15)
            printf("3\n");
        else if(p >= 60 * 5)
            printf("2\n");
        else if(p > 0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
