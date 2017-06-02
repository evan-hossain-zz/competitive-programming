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
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

#define F(i, n) for(i = 0; i < n; i++)

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

template <class T> T sqr(T a){return a * a;}    // square
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}     //  n  to the power p
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}    // extract words or numbers from a line
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

int par[MAX];

void computeLPSarray(string pat)
{
    int m = SZ(pat);
    int len = 0;
    int i;
    par[0] = 0, i = 1;
    // calculate lps[i] for i = 1 to m - 1
    while(i < m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            par[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
                len = par[len - 1];
            else
            {
                par[i] = 0;
                i++;
            }
        }
    }
}

int kmp_match(string pat, string text)
{
//    vector <int> v;
    int ret = 0;
    int m = SZ(pat), n = SZ(text);
    clr(par, 0);
    computeLPSarray(pat);
    int j = 0, i = 0;
    while(i < n)
    {
        if(pat[j] == text[i])
            i++, j++;
        if(j == m)
        {
//            v.pb(i - m + 1); // starting index in text of a match
            ret++;
            j = par[j - 1];
        }
        else if(pat[j] != text[i])
        {
            if(j != 0)
                j = par[j - 1];
            else
                i++;
        }
    }
    return ret;
}

int main()
{
    int test, kase, i;
    scanf("%d", &test);
    char arr[MAX];
    string pat, text;
    for(kase  = 1; kase <= test; kase++)
    {
        scanf("%s", arr);
        text = arr;
        scanf("%s", arr);
        pat = arr;
        printf("Case %d: %d\n", kase, kmp_match(pat, text));
    }
    return 0;
}


