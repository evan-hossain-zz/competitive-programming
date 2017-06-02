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
#define infinity 2147483647.0
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

struct point{int i, x, y, r;};    // for coordinates;

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

#define MAX 50010
/*************************************************HABIJABI ENDS HERE******************************************************/

point arr[MAX], sortedY[MAX];
bool flag[MAX];

bool compareX(const point &a, const point &b){
    return a.x < b.x;
}
bool compareY(const point &a, const point &b){
    return a.y < b.y;
}

double closest_pair(point X[], point Y[], int n)
{
    double left_call, right_call, mindist;
    if(n == 1) return infinity;
    if(n == 2)
        return getdist(X[0], X[1]) - (X[0].r + X[1].r);
    int n1, n2, ns, j, m = n / 2, i;
    point xL[m + 1], xR[m + 1], yL[m + 1], yR[m + 1], Xm = X[m - 1], yS[n];
    for(i = 0; i < m; i++)
    {
        xL[i] = X[i];
        flag[X[i].i] = 0;
    }
    for(; i < n; i++)
    {
        xR[i - m] = X[i];
        flag[X[i].i] = 1;
    }
    for(i = n2 = n1 = 0; i < n; i++)
    {
        if(!flag[Y[i].i]) yL[n1++] = Y[i];
        else yR[n2++] = Y[i];
    }
    left_call = closest_pair(xL, yL, n1);
    right_call = closest_pair(xR, yR, n2);
    mindist = min(left_call, right_call);
    cout << Xm.x << ' ' << Xm.y << endl;
    for(i = ns = 0; i < n; i++)
    {
        cout << Y[i].x << ' ' << Y[i].y << endl;
        if((Y[i].x - Xm.x - Y[i].r - Xm.r) < mindist)
            yS[ns++] = Y[i];
    }
    for(i = 0; i < ns; i++)
        for(j = i + 1; j < ns && (yS[j].y - yS[i].y - yS[j].r - yS[i].r) < mindist; j++)
        mindist = min(mindist, getdist(yS[i], yS[j]) - yS[i].r - yS[j].r);
    return mindist;
}


int main()
{
    int t, i, n;
    double ans;
    scanf("%d", &t);
    while(t--)
    {
        ans = infinity;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].r);
            arr[i].i = i;
            sortedY[i] = arr[i];
        }
        sort(arr, arr + n, compareX);
        sort(sortedY, sortedY + n, compareY);
        ans = closest_pair(arr, sortedY, n);
        printf("%.6lf\n", ans);
    }
    return 0;
}

