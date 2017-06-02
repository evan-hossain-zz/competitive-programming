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
#include <assert.h>

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
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 100010
/*************************************************HABIJABI ENDS HERE******************************************************/

int trie[MAX][26], last, have[MAX];
char str[MAX];

void add(char *str)
{
    int i, id, cur = 0;
    for(i = 0; str[i]; i++)
    {
        have[cur] = 1;
        id = str[i] - 'a';
        if(trie[cur][id] == -1)
        {
            trie[cur][id] = ++last;
            clr(trie[last], -1);
        }
        cur = trie[cur][id];
    }
}

bool call(int cur)
{
    if(!have[cur]) return false;
    bool ret = true;
    for(int i = 0; i < 26; i++)
        if(trie[cur][i] != -1)
            ret &= !(call(trie[cur][i]));
    return ret;
}

bool call2(int cur)
{
    if(!have[cur]) return false;
    bool ret = false;
    for(int i = 0; i < 26; i++)
        if(trie[cur][i] != -1)
            ret |= !(call2(trie[cur][i]));
    return ret;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    clr(trie[0], -1);
    last = 0;
    CF
    int n, k, i;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> str, add(str);
    bool first_player_always_wins = call(0);
    bool first_player_may_win = call2(0);

    if(first_player_may_win)
    {
        if(!first_player_always_wins) cout << "First\n";
        else if(k % 2)
            cout << "First\n";
        else
            cout << "Second\n";
    }
    else
        cout << "Second\n";
    return 0;
}


