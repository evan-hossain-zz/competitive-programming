#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 10
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

LL arr[MAX], tem[MAX];
LL score[33] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0};
int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int i, more = 0;
    for(i = 0; i < MAX; i++)
        cin >> arr[i], more += arr[i] >= 100;
//    if(more == 10)
//    {
//        cout << -1;
//        return 0;
//    }
    sort(arr, arr+10);
    for(int cur = 30; cur >= 0; cur--)
    {
        LL my = score[cur];
        bool ok = 1;
        do{
            LL mn = 1LL<<60;
            for(i = 0; i < MAX; i++)
                mn = min(mn, arr[i]+score[i+(i >= cur)]);
            if(mn >= my)
            {
                ok = 0;
                break;
            }
        }while(next_permutation(arr, arr+10));
        if(ok)
        {
            cout << cur+1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
/*
10 45 26 32 40 40 36 32 29 26
*/
