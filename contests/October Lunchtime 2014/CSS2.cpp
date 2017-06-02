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
#define mp(a, b) make_pair(a, b)
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
template <class T> void show(T a){cout << a << endl;}
template <class T> void show(T a, T b){cout << a << ' ' << b << endl;}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/*************************************************HABIJABI ENDS HERE******************************************************/

struct obj{
    int id, att, priority, indx, val;
    obj(){}
    obj(int _id, int a, int p, int i, int v)
    {
        id = _id;
        att = a;
        priority = p;
        indx = i;
        val = v;
    }
};

int n;
obj arr[MAX];

bool comp(const obj &a, const obj &b)
{
    if(a.id != b.id)
        return a.id < b.id;
    if(a.att != b.att)
        return a.att < b.att;
    if(a.priority != b.priority)
        return a.priority > b.priority;
    return a.indx > b.indx;
}

int getatt(int low, int high, int att)
{
    int mid, ret = high;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid].att < att)
        {
            low = mid + 1;
        }
        else if(arr[mid].att > att)
        {
            high = mid - 1;
        }
        else
        {
            ret = min(ret, mid);
            high = mid - 1;
        }
    }
    return arr[ret].val;
}

int get(int id, int att)
{
    int low = 0, high = n - 1, mid, nlow, nhigh;

    nlow = high;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid].id > id)
        {
            high = mid - 1;
        }
        else if(arr[mid].id < id)
            low = mid + 1;
        else
        {
            high = mid - 1;
            nlow = min(mid, nlow);
        }
    }

    low = 0, high = n - 1;
    nhigh = 0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid].id < id)
        {
            low = mid + 1;
        }
        else if(arr[mid].id > id)
            high = mid - 1;
        else
        {
            low = mid + 1;
            nhigh = max(nhigh, mid);
        }
    }
    return getatt(nlow, nhigh, att);
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int m, id, att, i;
    cin >> n >> m;
    for(i = 0; i < n; i++)
    {
        cin >> arr[i].id;
        cin >> arr[i].att;
        cin >> arr[i].val;
        cin >> arr[i].priority;
        arr[i].indx = i;
    }
    sort(arr, arr + n, comp);
    while(m--)
    {
        cin >> id >> att;
        cout << get(id, att) << "\n";
    }
    return 0;
}


