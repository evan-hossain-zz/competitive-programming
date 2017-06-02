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

string agerta;

void jog(string &b);
void gun(string &a, string &b);

int main()
{
    string a, b;
    while(cin >> a && cin >> b)
    {
        if(a == "0" || b == "0")
            printf("0\n");
        else
        {
            gun(a, b);
            printf("%s\n", agerta.c_str());
            agerta = "0";
        }
    }
    return 0;
}

void gun(string &a, string &b)
{
    int i, j, zerocount = 0, gf, carry = 0;
    string tem, sss;
    for(i = b.size() - 1; i >= 0; i--)
    {
        carry = 0;
        for(int z = 0; z < zerocount; z++)
            tem += '0';
        for(j = a.size() - 1; j >= 0; j--)
        {
            gf = (b[i] - '0') * (a[j] - '0') + carry;
            tem += ((gf % 10) + '0');
            carry = gf / 10;
        }
        if(carry)
            tem += (carry + '0');
        reverse(tem.begin(), tem.end());
        jog(tem);
        tem.clear();
        zerocount++;
    }
    return;
}

void jog(string &b)
{
    int i, j, carry= 0, t;
    string ret;
    for(i = agerta.size() - 1, j = b.size() - 1; i > -1 || j > -1; i--, j--)
    {
        if(i < 0)
            t = (b[j] - '0') + carry;
        else if(j < 0)
            t = (agerta[i] - '0') + carry;
        else
            t = (agerta[i] - '0') + (b[j] - '0') + carry;
        carry = 0;
        if(t > 9)
        {
            carry = t / 10;
            ret += (t % 10 + '0');
        }
        else
            ret += (t + '0');
    }
    if(carry)
        ret += (carry + '0');
    reverse(ret.begin(), ret.end());
    agerta = ret;
}
