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

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

vector <string> grid;
string s;


bool has_solution(int d)
{
    int nowd, i, k, col, l;
    for(i = 0; i < SZ(grid); i++)
    {
        for(col = 0; col < SZ(grid[i]); col++)
        {
            nowd = i + d;
            cout << "i" << i << endl;
            if(SZ(grid[i]) <= d + 1 || SZ(grid[nowd]) <= d + 1 ||
               SZ(grid[(2 * nowd) + 1]) <= d+1 || grid[i][col] != '.' ||
                grid[i][col + d + 1] != '.' || grid[nowd + 1][col] != '.' ||
                 grid[nowd + 1][col + d + 1] != '.' || grid[(2 * nowd) + 2][col] != '.' ||
                  grid[(2 * nowd) + 2][col + d + 1] != '.')
                {
                    cout << "got" << endl;
                    continue;
                }
            for(k = 1; k < d + 1; k++)
            {
                if(grid[i][k + col] != '-' || grid[nowd + 1][k + col] != '-' || grid[(2*nowd) + 2][k + col] != '-')
                {
                    cout << "broke";
                    break;
                }
            }
            cout << "i" << i << "k" << k << endl;
            if(k != d + 1)
                continue;
            cout << "came" << i << endl;
            bool flag = true;
            for(l = i + 1; l < 2 * nowd + 2; l++)
            {
                for(k = 0; k <= d + 1; k++)
                {
                    if(k == 0 || k == d + 1)
                    {
                        if(grid[l][k + col] != '|')
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if(grid[l][k + col] != '.')
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag)
                    break;
            }
            if(flag)
                return true;
        }
    }
    return false;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif

    int test, kase = 1, i, j, res, d;
    cin >> test;
    while(test--)
    {
        grid.clear();
        res = -1;
        while(cin >> s && s != "*") grid.pb(s);
//        for(d = 1; d < SZ(grid); d++)
//        {
//            if(2 * d + 3 > SZ(grid))
//                break;
//            if(2 * d + 3 <= SZ(grid) && has_solution(d))
//            {
//                res = d;
//                break;
//            }
//        }
        cout << has_solution(3) << endl;
        if(res == -1)
            printf("Case %d: Bad\n", kase++);
        else
            printf("Case %d: %d\n", kase++, res);
    }
    return 0;
}

/*
2
.---.
|...|
|...|
|...|
.---.
|...|
|...|
|...|
.---.
*
.---.
|...|
|...|
|...|
.---.
|...|
|...|
.---.
*
*/
