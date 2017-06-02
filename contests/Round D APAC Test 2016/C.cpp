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
//struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int trie[MAX][2], cnt[MAX], last;

void add(string str)
{
    int i, id, cur = 0;
    for(i = 0; i < SZ(str); i++)
    {
        id = str[i] - '0';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            clr(trie[last], -1);
            cnt[last] = 0;
        }
        cur = trie[cur][id];
    }
    cnt[cur]++;
}
/// do clr(trie[0], -1) and last = 0 for every case


LL toDec(string s)
{
    LL ret = 0;
    reverse(all(s));
    for(int i = 0; i < SZ(s); i++)
    {
        ret += (1LL<<i) * (s[i]-'0');
    }
    return ret;
}

set <tuple <int,int,int,int,int>> res;

void get(int cur, int len, string s)
{
    int id, i;
    if(cur && (cnt[cur] || (trie[cur][0] != -1 && trie[cur][1] != -1)))
    {
        cout << cnt[cur] << ' '  << len << endl;
        while(SZ(s) < 32) s += "0";
        string x = s;
        int a, b, c, d;
        a = toDec(x.substr(0, 8));
        b = toDec(x.substr(8, 8));
        c = toDec(x.substr(16, 8));
        d = toDec(x.substr(24, 8));
        res.insert(make_tuple(a, b, c, d, last));
        return;
    }
    if(trie[cur][0] != -1)
        cur = trie[cur][0], get(cur, len+1, s+"0");
    else
        cur = trie[cur][0], get(cur, len+1, s+"1");
}

string toBin(int n)
{
    string ret;
    for(int i = 0;i < 8;i++)
    {
        if(n&(1<<i))
            ret+="1";
        else
            ret+="0";
    }
    reverse(all(ret));
    return ret;
}


int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int test, kase = 1, i, n, a, b, c, d, p;
    cin >> test;
    while(test--)
    {
        clr(trie[0], -1);
        last = 0;
        clr(cnt, 0);
        cin >> n;
        vector <string> input;
        res.clear();
        for(i = 0; i < n; i++)
        {
            scanf("%d.%d.%d.%d/%d", &a, &b, &c, &d, &p);
            string s = toBin(a);
            s += toBin(b);
            s += toBin(c);
            s += toBin(d);
            if(p == 0)
            {
                res.insert(make_tuple(0, 0, 0, 0, 0));
                continue;
            }
            if(d = 0)
                p = min(p, 24);
            if(c + d == 0)
                p = min(p, 16);
            if(b+c+d == 0)
                p = min(p, 8);
            if(a+b+c+d == 0)
                p = 0;
            if(p == 0)
            {
                res.insert(make_tuple(0, 0, 0, 0, 0));
                continue;
            }
            s.resize(p);
            add(s);
        }
        get(0, 0, "");
        printf("Case #%d:\n", kase++);
        for(auto x: res)
        {
            a = get <0> (x);
            b = get <1> (x);
            c = get <2> (x);
            d = get <3> (x);
            p = get <4> (x);
            printf("%d.%d.%d.%d/%d\n", a, b, c, d, p);
        }
    }
    return 0;
}
