#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("input.in", "r", stdin);
#define out freopen("output.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define CF ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 5010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL arr[MAX], L[MAX], R[MAX], cum[MAX];
int L_indices[MAX], R_indices[MAX];

LL get_sum(int i, int j)
{
    if(i > j)
        return 0;
    if(i == 0)
        return cum[j];
    return cum[j] - cum[i-1];
}

int main()
{
    // in;
    int n, i, j;
    while(cin >> n)
    {
        LL res = LONG_MIN;
        for(i = 0; i < MAX; i++)
            L[i] = R[i] = LONG_MIN;

        for(i = 0; i < n; i++)
            cin >> arr[i];

        cum[0] = arr[0];
        for(i = 1; i < n; i++)
            cum[i] = cum[i-1] + arr[i];

        for(i = 0; i <= n; i++)
            for(j = i; j <= n; j++)
            {
                LL cur = get_sum(0, i-1) - get_sum(i, j-1);
                if(cur > L[j])
                {
                    L[j] = cur;
                    L_indices[j] = i;
                }
            }

        for(i = n; i >= 0; i--)
        {
            for(j = i; j >= 0; j--)
            {
                LL cur = get_sum(j, i-1) - get_sum(i, n-1);
                if(cur > R[j])
                {
                    R[j] = cur;
                    R_indices[j] = i;
                }
            }
        }

        tuple<int, int, int> res_indices;
        for(i = 0; i <= n; i++)
        {
            if(L[i] + R[i] > res)
            {
                res = L[i] + R[i];
                res_indices = {L_indices[i], i, R_indices[i]};
            }
        }
        // cout << res << "\n";
        cout << get<0>(res_indices) << ' ' << get<1>(res_indices) << ' ' << get<2>(res_indices) << "\n";
    }
    return 0;
}
