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

#define MAX 400010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/
struct info
{
    int tup[2], indx; //tup[0] = prev rank, tup[1] = new rank
}arr[MAX];

int n, sorted[20][MAX], step;
string text, s;

bool comp(const info &a, const info &b)
{
    return a.tup[0] != b.tup[0]? a.tup[0] < b.tup[0] : a.tup[1] < b.tup[1];
}

void build_suffix_array(void)
{
    int i, jump;
    for(i = 0; i < n; i++)
    {
        sorted[0][i] = text[i] - 'a'; //rank suffixes according to 1st char
//        clr(arr[i].tup, 0);
    }
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
//    cout << "Suffix Array : \n\n";
//    for(i = 0; i < n; i++)
//        cout<<arr[i].indx<<' '<<text.substr(arr[i].indx)<<endl;
}

int LCP(int id1, int id2)
{
    int ret = 0;
    int j;
    for(j = step - 1; j >= 0 && id1 < n && id2 < n; j--)
        if(sorted[j][id1] == sorted[j][id2])
        {
            ret += (1 << j);
            id1 += (1 << j);
            id2 += (1 << j);
        }
    return ret;
//    for(i = 0; i < n; i++)
//        cout << i << ' ' << LCP[i] << endl;
}

bool ok(int l, int r, int len)
{
    if(LCP(l, r) >= len)
        return true;
    if(len % 2)
        return false;
    if(ok(l, r+(len/2), len/2) && ok(l+(len/2), r, len/2))
        return true;
    if(ok(l, r, len/2) && ok(l+(len/2), r + (len/2), len/2))
        return true;
    return false;
}

int main()
{
    cin >> text >> s;
    text += s;
    n = SZ(text);
    build_suffix_array();
    if(ok(0, SZ(s), SZ(s)))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
