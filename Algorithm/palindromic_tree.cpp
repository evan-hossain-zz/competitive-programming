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

#define MAX 1010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

struct node{
    int next[26], len, suffLink, num; ///num->count of palindromes associated with current letter as last letter
    void init()
    {
        clr(next, -1);
        suffLink = 2;
        num = 1;
        len = 0;
    }
};
int last, totNodes; ///last->current suffix link
node tree[MAX];

void addLetter(string &s, int pos)
{
    int cur = last, curLen = 0;
    int id = s[pos] - 'a';
    while(true) ///find suffix link including id, xAx
    {
        curLen = tree[cur].len;
        if(pos-1-curLen >= 0 && s[pos-1-curLen] == s[pos])
            break;
        cur = tree[cur].suffLink;
    }
    if(tree[cur].next[id] != -1) /// node already exists
    {
        last = tree[cur].next[id];
        return;
    }
    totNodes++;
    tree[totNodes].init(); ///create new node
    last = totNodes;
    tree[totNodes].len = tree[cur].len + 2;
    tree[cur].next[id] = totNodes;
    if(tree[totNodes].len == 1)
        return;
    while(true) ///find suffix link xBx for current new node, where B is suffix link of Ax
    {
        cur = tree[cur].suffLink;
        curLen = tree[cur].len;
        if(pos-1-curLen >= 0 && s[pos-1-curLen] == s[pos])
        {
            tree[totNodes].suffLink = tree[cur].next[id];
            break;
        }
    }
    tree[totNodes].num = 1+tree[tree[totNodes].suffLink].num;
}

void init()
{
    tree[1].init(), tree[2].init();
    totNodes = last = 2;
    tree[1].len = -1, tree[2].len = 0;
    tree[1].suffLink = tree[2].suffLink = 1;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    string s;
    while(cin >> s)
    {
        init();
        int ans = 0;
        for(int i = 0; i < SZ(s); i++)
        {
            addLetter(s, i);
            ans += tree[last].num;
        }
        cout << ans << "\n";
    }
    return 0;
}

