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

#define MAX 105
/*************************************************HABIJABI ENDS HERE******************************************************/

struct info{
    int id, batting, bowling, fielding;
}arr[MAX];

int dp[MAX][8][6][5], n, res;
vector <int> batsmen, bowlers, allrounders;

int call(int indx, int batsman, int bowler, int allrounder)
{
    if(indx > n) return 0;

    int &ret = dp[indx][batsman][bowler][allrounder];
    if(ret != -1) return ret;
    ret = call(indx + 1, batsman, bowler, allrounder);

    if(batsman) ret = max(ret, call(indx + 1, batsman - 1, bowler, allrounder) +
                           + (int) (((arr[indx].batting * .8)
                           + (arr[indx].fielding * .2)) + .5 + eps));

    if(bowler) ret = max(ret, call(indx + 1, batsman, bowler - 1, allrounder)
                         + (int) (((arr[indx].bowling * .7)
                         +  (arr[indx].fielding * .2)
                         + (arr[indx].batting * .1)) + .5 + eps));

    if(allrounder) ret = max(ret, call(indx + 1, batsman, bowler, allrounder - 1)
                             + (int) (((arr[indx].batting * .4)
                             + (arr[indx].fielding * .2)
                             + (arr[indx].bowling * .4)) + .5 + eps));
    return ret;
}

void get_list(int indx, int batsman, int bowler, int allrounder, int got)
{
    if(indx > n) return;
    int score;

    if(call(indx + 1, batsman, bowler, allrounder) + got == res)
    {
        get_list(indx + 1, batsman, bowler, allrounder, got);
        return;
    }

    if(batsman)
    {
        score = (int) (((arr[indx].batting * .8) + (arr[indx].fielding * .2)) + .5 + eps);
        if(got + score + call(indx + 1, batsman - 1, bowler, allrounder) == res)
        {
            batsmen.pb(arr[indx].id);
            get_list(indx + 1, batsman - 1, bowler, allrounder, got + score);
            return;
        }
    }
    if(bowler)
    {
        score = (int) (((arr[indx].bowling * .7) + (arr[indx].fielding * .2) + (arr[indx].batting * .1)) + .5 + eps);
        if(got + score + call(indx + 1, batsman, bowler - 1, allrounder) == res)
        {
            bowlers.pb(arr[indx].id);
            get_list(indx + 1, batsman, bowler - 1, allrounder, got + score);
            return;
        }
    }
    if(allrounder)
    {
        score = (int) (((arr[indx].batting * .4) + (arr[indx].fielding * .2) + (arr[indx].bowling * .4)) + .5 + eps);
        if(got + score + call(indx + 1, batsman, bowler, allrounder - 1) == res)
        {
            allrounders.pb(arr[indx].id);
            get_list(indx + 1, batsman, bowler, allrounder - 1, got + score);
            return;
        }
    }
}

int main()
{
    int i, batsman, bowler, allrounder, kase = 1;
    while(scanf("%d", &n) == 1 && n)
    {
        if(kase > 1) puts("");
        clr(dp, -1);
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d %d", &arr[i].batting, &arr[i].bowling, &arr[i].fielding);
            arr[i].id = i;
        }
        scanf("%d %d %d", &batsman, &bowler, &allrounder);
        res = call(1, batsman, bowler, allrounder);
        printf("Team #%d\nMaximum Effective Score = %d\n", kase++, res);
        batsmen.clear();
        bowlers.clear();
        allrounders.clear();
        get_list(1, batsman, bowler, allrounder, 0);
        printf("Batsmen :");
        for(i = 0; i < SZ(batsmen); i++)
            printf(" %d", batsmen[i]);
        printf("\nBowlers :");
        for(i = 0; i < SZ(bowlers); i++)
            printf(" %d", bowlers[i]);
        printf("\nAll-rounders :");
        for(i = 0; i < SZ(allrounders); i++)
            printf(" %d", allrounders[i]);
        puts("");
    }
    return 0;
}

