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
#include <assert.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 30
/*************************************************HABIJABI ENDS HERE******************************************************/

LL dp[MAX][MAX][2], n, len;
char str[30];

LL call(int boro, int chhoto, bool from_boro)
{
    if(boro + chhoto == 0)
        return 1;
    LL &ret = dp[boro][chhoto][from_boro];
    if(ret != -1) return ret;
    ret = 0;
    int i;
    if(from_boro)
    {
        for(i = 1; i <= boro; i++)
            ret += call(boro - i, chhoto + i - 1, !from_boro);
        return ret;
    }
    for(i = 1; i <= chhoto; i++)
        ret += call(boro + i - 1, chhoto - i, !from_boro);
    return ret;
}

string print_res(int boro, int chhoto, bool from_boro, int last, int mask, LL need)
{
    if(boro + chhoto == 0)
        return "";
    int i;
    if(from_boro)
    {
        for(i = 1; i <= boro; i++)
        {
            if(need <= call(boro - i, chhoto + i - 1, !from_boro))
            {
                for(int k = last + 1, gone = 0; k < len; k++)
                {
                    if(!(mask & (1 << k))) gone++;
                    if(gone == i)
                    {
                        cout << " boro" << str[k] << endl;
                        return str[k] + print_res(boro - i, chhoto + i - 1, !from_boro, k, mask | (1 << k), need);
                    }
                }
            }
            else
                need -= call(boro - i, chhoto + i - 1, !from_boro);
        }
    }
    for(i = 1; i <= chhoto; i++)
    {
        if(need <= call(boro + i - 1, chhoto - i, !from_boro))
        {
            for(int k = 0, gone = 0; k < last; k++)
            {
                if(!(mask & (1 << k))) gone++;
                if(gone == i)
                {
                    cout << "chhoto" << str[k] << endl;
                    return str[k] + print_res(boro + i - 1, chhoto - i, !from_boro, k, mask | (1 << k), need);
                }
            }
        }
        else
            need -= call(boro + i - 1, chhoto - i, !from_boro);
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    clr(dp, -1);
    int test, kase = 1, i;
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s %lld", str, &n);
        len = strlen(str);
        sort(str, str + len);
        LL res = 0;
        for(i = 1; i <= len; i++)
            res += call(len - i, i - 1, 1);
        cout << res << endl;
        for(i = 1; i <= len; i++)
        {
            if(n <= call(len - i, i - 1, 1))
            {
                cout << str[i - 1] << endl;
                printf("Case %d: %s\n", kase++, (str[i - 1] + print_res(len - i, i - 1, 1, i - 1, 1 << (i-1), n)).c_str());
                break;
            }
            else
                n -= call(len - i, i - 1, 1);
        }
    }
    return 0;
}

