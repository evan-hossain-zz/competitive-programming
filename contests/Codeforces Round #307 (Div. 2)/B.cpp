#include <bits/stdc++.h>

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
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int a[200], b[200], c[200], cur[200];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    string A, B, C;
    cin >> A >> B >> C;
    for(auto x: A)
        a[x]++;
    for(auto x: B)
        b[x]++;
    for(auto x: C)
        c[x]++;
    int i, j, res = 0, bTaken = 0, cTaken = 0;
    for(i = 0; i * SZ(B) <= SZ(A); i++)
    {
        bool problem = 0;
        int takeC = infinity;
        for(j = 'a'; j <= 'z'; j++)
            cur[j] = a[j];
        for(j = 'a'; j <= 'z'; j++)
            cur[j] -= i*b[j], problem |= cur[j] < 0;
        for(j = 'a'; j <= 'z'; j++)
        {
            if(c[j])
                takeC = min(takeC, cur[j]/ c[j]);
        }
        if(problem) continue;
        if(res < i+takeC)
        {
            bTaken = i;
            cTaken = takeC;
            res = i+takeC;
        }
    }
    for(i = 0; i * SZ(C) <= SZ(A); i++)
    {
        bool problem = 0;
        int takeB = infinity;
        for(j = 'a'; j <= 'z'; j++)
            cur[j] = a[j];
        for(j = 'a'; j <= 'z'; j++)
            cur[j] -= i*c[j], problem |= cur[j] < 0;
        for(j = 'a'; j <= 'z'; j++)
        {
            if(b[j])
                takeB = min(takeB, cur[j]/ b[j]);
        }
        if(problem) continue;
        if(res < i+takeB)
        {
            cTaken = i;
            bTaken = takeB;
            res = i+takeB;
        }
    }
    while(bTaken--)
    {
        for(i = 0; i < SZ(B); i++)
            a[B[i]]--, cout << B[i];
    }
    while(cTaken--)
    {
        for(i = 0; i < SZ(C); i++)
            a[C[i]]--, cout << C[i];
    }
    for(i = 'a'; i <= 'z'; i++)
        while(a[i]--)
            cout << (char) i;
    return 0;
}
