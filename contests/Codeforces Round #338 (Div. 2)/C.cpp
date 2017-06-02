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

#define MAX 5110
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

int trie[2][MAX*26][26], last, mem[2][MAX*26];
string s, t, ulta;

void add(string &s, int tn)
{
    int i, id, cur = 0;
    for(i = 0; i < SZ(s); i++)
    {
        id = s[i] - 'a';
        if(trie[tn][cur][id] == -1)
        {
            trie[tn][cur][id] = ++last;
            clr(trie[tn][last], -1);
        }
        cur = trie[tn][cur][id];
        mem[tn][cur] = i;
    }
}
/// do clr(trie[0], -1) and last = 0 for every case

int dp[MAX];

int call(int indx)
{
    if(indx == SZ(t))
        return 0;
    int &ret = dp[indx];
    if(ret != -1) return ret;
    int cur = 0, i;
    ret = infinity;
    for(i = indx; i < SZ(t); i++)
    {
        int id = t[i] - 'a';
        if(trie[0][cur][id] == -1)
            break;
        cur = trie[0][cur][id];
        ret = min(ret, call(i+1)+1);
    }
    for(i = indx; i < SZ(t); i++)
    {
        int id = t[i] - 'a';
        if(trie[1][cur][id] == -1)
            break;
        cur = trie[1][cur][id];
        ret = min(ret, call(i+1)+1);
    }
    return ret;
}

void go(int indx)
{
    if(indx == SZ(t))
        return;
    int cur = 0, i;
    for(i = indx; i < SZ(t); i++)
    {
        int id = t[i] - 'a';
        if(trie[0][cur][id] == -1)
            break;
        cur = trie[0][cur][id];
        if(dp[indx] == call(i+1)+1)
        {
            cout << 0 << ' ' << mem[0][cur]-(i-indx)+1 << ' ' << mem[0][cur]+1 << endl;
            go(i+1);
            return;
        }
    }
    for(i = indx; i < SZ(t); i++)
    {
        int id = t[i] - 'a';
        if(trie[1][cur][id] == -1)
            break;
        cur = trie[1][cur][id];
        if(dp[indx] == call(i+1)+1)
        {
            cout << 1 << ' ' << mem[1][cur]-(i-indx)+1 << ' ' << mem[1][cur]+1 << endl;
            go(i+1);
            return;
        }
    }
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    clr(trie[0][0], -1);
    clr(trie[1][0], -1);
    cin >> s >> t;
    int i;
    for(i = 0; i < SZ(s); i++)
    {
        string tem = s.substr(i);
        add(tem, 0);
    }
    ulta = s;
    reverse(all(ulta));
//    last = 0;
    for(i = 0; i < SZ(ulta); i++)
    {
        string tem = ulta.substr(i);
        add(tem, 1);
    }
    clr(dp, -1);
    int res = call(0);
    if(res >= SZ(t))
    {
        cout << -1;
        return 0;
    }
    cout << res << "\n";
    go(0);
    return 0;
}
