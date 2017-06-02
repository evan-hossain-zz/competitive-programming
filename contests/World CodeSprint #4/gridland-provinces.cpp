#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt make_tuple
#define infinity (1 << 28)
#define LL unsigned long long
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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}}cincout;

#define MAX 1210
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

string s[2];
set <int> ss;
int n;
bool color[2][601];
int P[MAX][2], mod[2] = {1e9+7, 1e9+9};
int precal[2][601][1201][2][2];

void rec(int pos, int indx, int *lef, int p, int *rig)
{
    if(indx == n)
        return;
    color[pos][indx] = 1;
    lef[0] = (lef[0] + 1LL*(s[pos][indx]-'a')*P[p][0]) % mod[0];
    lef[1] = (lef[1] + 1LL*(s[pos][indx]-'a')*P[p][1]) % mod[1];
    rig[0] = (rig[0] + 1LL*P[2*n-p-1][0]*(s[pos][indx] - 'a')) % mod[0];
    rig[1] = (rig[1] + 1LL*P[2*n-p-1][1]*(s[pos][indx] - 'a')) % mod[1];
    int hval[2];
    int i;
    hval[0] = (lef[0] + 1LL*P[p+1][0]*precal[pos][indx][p][0][0])% mod[0];
    hval[1] = (lef[1] + 1LL*P[p+1][1]*precal[pos][indx][p][0][1])% mod[1];
    ss.insert(mp(hval[0], hval[1]));
    hval[0] = (precal[pos][indx][p][1][0] + rig[0]) % mod[0];
    hval[1] = (precal[pos][indx][p][1][1] + rig[1]) % mod[1];
    ss.insert(mp(hval[0], hval[1]));
    if(color[!pos][indx] == 0)
        rec(!pos, indx, lef, p+1, rig);
    else
        rec(pos, indx+1, lef, p+1, rig);
}

void doPrecal(int pos, int indx, int seen)
{
    if(indx == n)
        return;
    color[pos][indx] = 1;
    int i;
    int hval[2] = {0}, p = 0;
    for(i = indx + 1; i < n; i++, p++)
    {
        hval[0] = (hval[0] + 1LL*P[p][0]*(s[pos][i]-'a')) % mod[0];
        hval[1] = (hval[1] + 1LL*P[p][1]*(s[pos][i]-'a')) % mod[1];
    }
    for(i = n-1; i >= indx+color[!pos][i]; i--, p++)
    {
        hval[0] = (hval[0] + 1LL*P[p][0]*(s[!pos][i]-'a')) % mod[0];
        hval[1] = (hval[1] + 1LL*P[p][1]*(s[!pos][i]-'a')) % mod[1];
    }
    precal[pos][indx][seen][0][0] = hval[0];
    precal[pos][indx][seen][0][1] = hval[1];
    hval[0] = hval[1] = p = 0;
    for(i = indx+color[!pos][indx]; i < n; i++, p++)
    {
        hval[0] = (hval[0] + 1LL*P[p][0]*(s[!pos][i]-'a')) % mod[0];
        hval[1] = (hval[1] + 1LL*P[p][1]*(s[!pos][i]-'a')) % mod[1];
    }
    for(i = n-1; i > indx; i--, p++)
    {
        hval[0] = (hval[0] + 1LL*P[p][0]*(s[pos][i]-'a')) % mod[0];
        hval[1] = (hval[1] + 1LL*P[p][1]*(s[pos][i]-'a')) % mod[1];
    }
    precal[pos][indx][seen][1][0] = hval[0];
    precal[pos][indx][seen][1][1] = hval[1];
    if(color[!pos][indx] == 0)
        doPrecal(!pos, indx, seen+1);
    else
        doPrecal(pos, indx+1, seen+1);
}

void doIt()
{
    clr(color, 0);
    doPrecal(0, 0, 0);
    clr(color, 0);
    doPrecal(1, 0, 0);
    int i, j;
    for(i = 0; i < n; i++)
    {
        clr(color, 0);
        int lef[2] = {0}, p = 0, rig[2] = {0};
        for(j = i-1; j >= 0; j--, p++)
        {
            lef[0] = (lef[0] + 1LL*P[p][0]*(s[0][j]-'a')) % mod[0];
            lef[1] = (lef[1] + 1LL*P[p][1]*(s[0][j]-'a')) % mod[1];
            rig[0] = (rig[0] + 1LL*P[2*n-p-1][0]*(s[0][j] - 'a')) % mod[0];
            rig[1] = (rig[1] + 1LL*P[2*n-p-1][1]*(s[0][j] - 'a')) % mod[1];
            color[0][j] = 1;
        }
        for(j = 0; j < i; j++, p++)
        {
            lef[0] = (lef[0] + 1LL*P[p][0]*(s[1][j]-'a')) % mod[0];
            lef[1] = (lef[1] + 1LL*P[p][1]*(s[1][j]-'a')) % mod[1];
            rig[0] = (rig[0] + 1LL*P[2*n-p-1][0]*(s[1][j] - 'a')) % mod[0];
            rig[1] = (rig[1] + 1LL*P[2*n-p-1][1]*(s[1][j] - 'a')) % mod[1];
        }
        rec(1, i, lef, p, rig);
    }
    for(i = 0; i < n; i++)
    {
        clr(color, 0);
        int lef[2] = {0}, p = 0, rig[2] = {0};
        for(j = i-1; j >= 0; j--, p++)
        {
            lef[0] = (lef[0] + 1LL*P[p][0]*(s[1][j]-'a')) % mod[0];
            lef[1] = (lef[1] + 1LL*P[p][1]*(s[1][j]-'a')) % mod[1];
            rig[0] = (rig[0] + 1LL*P[2*n-p-1][0]*(s[1][j] - 'a')) % mod[0];
            rig[1] = (rig[1] + 1LL*P[2*n-p-1][1]*(s[1][j] - 'a')) % mod[1];
        }
        for(j = 0; j < i; j++, p++)
        {
            lef[0] = (lef[0] + 1LL*P[p][0]*(s[0][j]-'a')) % mod[0];
            lef[1] = (lef[1] + 1LL*P[p][1]*(s[0][j]-'a')) % mod[1];
            rig[0] = (rig[0] + 1LL*P[2*n-p-1][0]*(s[0][j] - 'a')) % mod[0];
            rig[1] = (rig[1] + 1LL*P[2*n-p-1][1]*(s[0][j] - 'a')) % mod[1];
        }
        rec(0, i, lef, p, rig);
    }
}

int main()
{
    #ifdef Evan
        in;
        out;
    #endif
    int test, i, j;
    P[0][0] = P[0][1] = 1;
    for(i = 1; i < MAX; i++)
    {
        P[i][0] = (1LL*P[i-1][0]*29) % mod[0];
        P[i][1] = (1LL*P[i-1][1]*29) % mod[1];
    }
    scanf("%d", &test);
    char str1[601], str2[601];
    while(test--)
    {
        cerr<<test<<endl;
        ss.clear();
        scanf("%d %s %s", &n, str1, str2);
        s[0] = str1;
        s[1] = str2;
        doIt();
        reverse(all(s[0]));
        reverse(all(s[1]));
        doIt();
        printf("%d\n", SZ(ss));
    }
    return 0;
}
