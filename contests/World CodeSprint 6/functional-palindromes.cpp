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

#define MAX 100010
/*************************Forget the risk, take the fall*If it's what u want, it's worth it all*************************/

struct node{
    LL next[26], len, suffLink, num; ///num->count of palindromes associated with current letter as last letter
    void init()
    {
        clr(next, -1);
        suffLink = 2;
        num = 1;
        len = 0;
    }
};
LL last, totNodes;
LL cnt[MAX], cum[MAX]; ///last->current suffix link
node tree[MAX];
pair<LL,LL> mapped[MAX];
vector<tuple<LL,LL,LL>> palin;

void addLetter(string &s, LL pos)
{
    LL cur = last, curLen = 0;
    LL id = s[pos] - 'a';
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
    palin.pb(mt(pos-1-curLen, pos, totNodes));
    mapped[totNodes] = mp(pos-1-curLen, pos);
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

struct info
{
    LL tup[2], indx; //tup[0] = prev rank, tup[1] = new rank
}arr[MAX];

LL sorted[18][MAX], step;
string text;

bool comp(const info &a, const info &b)
{
    return a.tup[0] != b.tup[0]? a.tup[0] < b.tup[0] : a.tup[1] < b.tup[1];
}

void build_suffix_array(void)
{
    LL i, n = SZ(text), jump;
    for(i = 0; i < n; i++)
        sorted[0][i] = text[i] - 'a'; //rank suffixes according to 1st char
    for(step = 1, jump = 1; jump <= n; step++, jump <<= 1)
    {
        for(i = 0; i <=n; i++)
        {
            arr[i].indx = i;
            arr[i].tup[0] = sorted[step - 1][i]; // what i was in prev step
            arr[i].tup[1] = i + jump < n? sorted[step - 1][i + jump] : -1;
        }
        sort(arr, arr + n, comp);
        sorted[step][arr[0].indx] = 0;
        for(i = 1; i < n; i++)
            sorted[step][arr[i].indx] = arr[i].tup[0] == arr[i - 1].tup[0] &&
            arr[i].tup[1] == arr[i - 1].tup[1] ? sorted[step][arr[i - 1].indx] : i;
    }
}

LL LCP(LL id1, LL id2)
{
    LL n = SZ(text), i, j, lcp = 0;
    for(j = step - 1; j >= 0; j--)
        if(sorted[j][id1] == sorted[j][id2])
        {
            lcp += 1<<j;
            id1 += (1 << j);
            id2 += (1 << j);
        }
    return lcp;
}

bool cmp(const tuple<LL,LL,LL>&a, const tuple<LL,LL,LL> &b)
{
    LL al = get<0> (a), bl = get<0> (b), ar = get<1> (a), br = get<1> (b);
    LL lcp = LCP(al, bl), l1 = ar-al+1, l2 = br-bl+1;
    if(lcp == 0)
        return text[al] < text[bl];
    if(lcp >= min(l1, l2))
        return l1 < l2;
    return text[al+lcp] < text[bl+lcp];
}

LL hashVal[MAX], mod = 1e9+7, P[MAX];

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    LL i, q, x;
    string s;
    cin >> s >> q >> s;
    init();
    for(i = 0; i < SZ(s); i++)
    {
        addLetter(s, i);
        cnt[last]++;
    }
    for(i = totNodes; i; i--)
        cnt[tree[i].suffLink] += cnt[i];
    text = s;
    build_suffix_array();
    sort(all(palin), cmp);
    cum[0] = cnt[get<2>(palin[0])];
    for(i = 1; i < SZ(palin); i++)
        cum[i] = cum[i-1] + cnt[get<2> (palin[i])];
    P[0] = 1;
    hashVal[SZ(s)-1] = s[SZ(s)-1];
    LL a = 100001;
    for(i = 1; i < SZ(s); i++)
        P[i] = (P[i-1]*a)%mod;
    for(i = SZ(s)-1; i >= 0; i--)
        hashVal[i] = (hashVal[i+1] + P[SZ(s)-i-1]*s[i])%mod;
    while(q--)
    {
        cin >> x;
        LL indx = lower_bound(cum, cum+SZ(palin), x) - cum;
        if(indx >= SZ(palin))
        {
            cout << "-1\n";
            continue;
        }
        auto mpp = mapped[get<2>(palin[indx])];
        LL res = (hashVal[mpp.first]-hashVal[mpp.second+1]+mod)*bigmod(P[SZ(s)-1-mpp.second], mod-2, mod);
        res %= mod;
        cout << res << "\n";
    }
    return 0;
}
