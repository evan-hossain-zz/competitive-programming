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

#define MAX 100005
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

struct node{
    int x_max, x_min, y_max, y_min;
}area[MAX];
int cnt[MAX];
int main()
{
    int n, m, i, j, x;
    cin >> n >> m;
    clr(area, -1);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
        {
            cin >> x;
            cnt[x]++;
            if(area[x].x_min == -1)
                area[x].x_min = i;
            else
                area[x].x_min = min(area[x].x_min, i);


            if(area[x].y_min == -1)
                area[x].y_min = j;
            else
                area[x].y_min = min(area[x].y_min, j);


            if(area[x].x_max == -1)
                area[x].x_max = i;
            else
                area[x].x_max = max(area[x].x_max, i);

            if(area[x].y_max == -1)
                area[x].y_max = j;
            else
                area[x].y_max = max(area[x].y_max, j);
        }
    for(i = 0; i < MAX; i++)
    {
        if(cnt[i] == 0)
            continue;
        LL expected_area = 1LL*(area[i].x_max-area[i].x_min+1)*(area[i].y_max-area[i].y_min+1);
        // cout << "here " << i << ' ' << expected_area << ' ' << cnt[i] << endl;
        // cout << area[i].x_min << ' ' << area[i].x_max << ' ' << area[i].y_min << ' ' << area[i].y_max << endl;
        if((area[i].x_max - area[i].x_min == area[i].y_max - area[i].y_min) && expected_area == cnt[i])
            continue;
        else
        {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1;
    return 0;
}
