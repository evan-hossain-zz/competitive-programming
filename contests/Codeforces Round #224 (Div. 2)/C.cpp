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
#define fast_input_output ios_base::sync_with_stdio(0);cin.tie(0);
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

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};    // for coordinates;

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

#define MAX 500010
/*************************************************HABIJABI ENDS HERE******************************************************/

LL arr[MAX], d;
vector <LL> ans;

int main()
{
    fast_input_output
    int n, i, same = 1;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    if(n == 1)
    {
        cout << "-1" << endl;
        return 0;
    }
    for(i = 1; i < n; i++)
        if(arr[i - 1] == arr[i]) same++;
    if(same == n)
    {
        cout << 1 << endl << arr[0] << endl;
        return 0;
    }
    if(n == 2)
    {
        d = arr[1] - arr[0];
        if(!d)
        {
            cout << "0\n";
            return 0;
        }
        ans.pb(arr[0] - d);
        ans.pb(arr[1] + d);
        if(d % 2 == 0)
            ans.pb(arr[0] + (d / 2));
        sort(all(ans));
        cout << SZ(ans) << endl;
        print_all(ans);
        return 0;
    }
    d = arr[1] - arr[0];
    for(i = 2; i < n; i++)
        d = min(d, arr[i] - arr[i - 1]);
    if(!d)
    {
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    for(i = 1; i < n; i++)
    {
        if(arr[i] - arr[i - 1] > d)
        {
            cnt++;
            if(cnt > 1 || (arr[i] - arr[i - 1]) != 2 * d || !d)
            {
                cout << "0" << endl;
                return 0;
            }
            ans.pb(arr[i - 1] + d);
        }
    }
    if(cnt == 0)
    {
        ans.pb(arr[0] - d);
        ans.pb(arr[n - 1] + d);
    }
    sort(all(ans));
    cout << SZ(ans) << endl;
    print_all(ans);
    return 0;
}


