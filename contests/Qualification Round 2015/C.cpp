#include <bits/stdc++.h>

#define in freopen("C-small-attempt1.in", "r", stdin);
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

#define MAX 10010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[9][9], dp[3][9][MAX];
string s;

int get(char ch)
{
    if(ch == 'i') return 2;
    if(ch == 'j') return 3;
    return 4;
}

int call(int part, int cur, int indx)
{
    if(indx == SZ(s))
        return part == 3 && cur == 1;
    if(part > 2)
        return 0;
    int &ret = dp[part][cur][indx];
    if(ret != -1) return ret;
    cur = arr[cur][get(s[indx])];
    ret = call(part, cur, indx+1);
    if(part == 0 && cur == 2)
        ret = max(ret, call(part+1, 1, indx+1));
    if(part == 1 && cur == 3)
        ret = max(ret, call(part+1, 1, indx+1));
    if(part == 2 && cur == 4)
        ret = max(ret, call(part+1, 1, indx+1));
    return ret;
}

int main()
{
//    #ifdef Evan
        in;
        out;
//    #endif
    arr[1][1] = 1;
    arr[1][2] = 2;
    arr[1][3] = 3;
    arr[1][4] = 4;
    arr[1][5] = 5;
    arr[1][6] = 6;
    arr[1][7] = 7;
    arr[1][8] = 8;

    arr[2][1] = 2;
    arr[2][2] = 8;
    arr[2][3] = 4;
    arr[2][4] = 6;
    arr[2][5] = 1;
    arr[2][6] = 7;
    arr[2][7] = 3;
    arr[2][8] = 5;

    arr[3][1] = 3;
    arr[3][2] = 7;
    arr[3][3] = 8;
    arr[3][4] = 2;
    arr[3][5] = 4;
    arr[3][6] = 1;
    arr[3][7] = 5;
    arr[3][8] = 6;

    arr[4][1] = 4;
    arr[4][2] = 3;
    arr[4][3] = 5;
    arr[4][4] = 8;
    arr[4][5] = 6;
    arr[4][6] = 2;
    arr[4][7] = 1;
    arr[4][8] = 7;

    arr[5][1] = 5;
    arr[5][2] = 1;
    arr[5][3] = 7;
    arr[5][4] = 3;
    arr[5][5] = 8;
    arr[5][6] = 4;
    arr[5][7] = 6;
    arr[5][8] = 2;

    arr[6][1] = 6;
    arr[6][2] = 4;
    arr[6][3] = 1;
    arr[6][4] = 5;
    arr[6][5] = 7;
    arr[6][6] = 8;
    arr[6][7] = 2;
    arr[6][8] = 3;

    arr[7][1] = 7;
    arr[7][2] = 6;
    arr[7][3] = 2;
    arr[7][4] = 1;
    arr[7][5] = 3;
    arr[7][6] = 5;
    arr[7][7] = 8;
    arr[7][8] = 4;

    arr[8][1] = 8;
    arr[8][2] = 5;
    arr[8][3] = 6;
    arr[8][4] = 7;
    arr[8][5] = 2;
    arr[8][6] = 3;
    arr[8][7] = 4;
    arr[8][8] = 1;
    int test, i, t, kase = 1;
    cin >> test;
    string l;
    while(test--)
    {
        int d;
        s.clear();
        cin >> d >> t >> l;
        while(t--)
            s += l;
        clr(dp, -1);
        cout << "Case #" << kase++ << ": ";
        if(call(0, 1, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

