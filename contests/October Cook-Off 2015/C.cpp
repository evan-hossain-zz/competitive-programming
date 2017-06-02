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

#define MAX 1000010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int trie[MAX*15][26], uptill[MAX*30], below[MAX*30], last;
unsigned LL P[MAX], hashF[MAX], hashR[MAX], mod = 1e9+9;
string arr[MAX];

bool is_palin(string &str, int l, int r)
{
    if(l > r) return false;
    int ll = SZ(str) - r, rr = SZ(str) - l;
    LL L = (hashF[r] - hashF[l-1]) * P[ll];
    LL R = (hashR[rr] - hashR[ll-1]) * P[l];
    return L == R;
}

void add(string &str)
{
    int i, id, cur = 0;
    for(i = 1; i < SZ(str); i++)
    {
        id = str[i] - 'a';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            clr(trie[last], -1);
        }
        cur = trie[cur][id];
        below[cur] += is_palin(str, i+1, SZ(str)-1);
    }
    uptill[cur]++;
}
/// do clr(trie[0], -1) and last = 0 for every case

int get(string &str)
{
    int id, i, cur = 0, ret = 0;
    for(i = SZ(str) - 1; i > 0; i--)
    {
        id = str[i] - 'a';
        if(trie[cur][id] == -1)
            return 0;
        cur = trie[cur][id];
        if(i==1)
            ret += below[cur],
            ret += uptill[cur];
        else
            ret += uptill[cur] * is_palin(str, 1, i-1);
    }
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, n, i, j, len;
    P[0] = 1;
    for(i = 1; i < MAX; i++)
        P[i] = P[i-1]*mod;
    cin >> test;
    while(test--)
    {
        clr(trie[0], -1), last = 0;
        cin >> n;
        LL res = 0;
        for(i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] = "#" + arr[i];
            res += get(arr[i]);
            len = SZ(arr[i]);
            hashF[len] = hashR[len] = 0;
            for(j = 1; j < len; j++)
            {
                hashF[j] = hashF[j-1] + P[j]*(arr[i][j]-'a');
                hashR[j] = hashR[j-1] + P[j]*(arr[i][len-j]-'a');
            }
            add(arr[i]);
        }
        while(last)
            uptill[last] = below[last] = 0, last--;
        uptill[last] = below[last] = 0;
        clr(trie[0], -1);
        for(i = n-1; i>=0; i--)
        {
            res += get(arr[i]);
            len = SZ(arr[i]);
            hashF[len] = hashR[len] = 0;
            for(j = 1; j < len; j++)
            {
                hashF[j] = hashF[j-1] + P[j]*(arr[i][j]-'a');
                hashR[j] = hashR[j-1] + P[j]*(arr[i][len-j]-'a');
            }
            add(arr[i]);
        }
        while(last)
            uptill[last] = below[last] = 0, last--;
        uptill[last] = below[last] = 0;
        cout << res << "\n";
    }
    return 0;
}
