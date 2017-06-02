#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define infinity 2147483647
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define SZ(v) (int)(v.size())

#define F(i, n) for(i = 0; i < n; i++)

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
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str;}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
//LL bigmod(LL B,LL P,LL M){  LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 10010
/*************************************************HABIJABI ENDS HERE******************************************************/
bool is_a_point[MAX], visited[MAX];
stack < pair<int, int> > S, tem;
pair <int, int> current;
vector <int> adj[MAX];
int discovered[MAX], low[MAX], timer;

void bcc(int from, int par)
{
    visited[from] = 1;
    discovered[from] = low[from] = timer++;
    int to, n = SZ(adj[from]), i;
    F(i, n)
    {
        to = adj[from][i];
        if(to == par) continue;
        if(!visited[to])
        {
            S.push(make_pair(from, to));
            bcc(to, from);
            if(discovered[from] <= low[to])
            {
                current = make_pair(from, to);
                while(!tem.empty()) tem.pop();
                do
                {
                    tem.push(S.top());
                    S.pop();
                }while(tem.top() != current);
                if(tem.size() % 2 && tem.size() > 1)
                {
                    while(!tem.empty())
                    {
                        is_a_point[tem.top().first] = is_a_point[tem.top().second] = 1;
                        tem.pop();
                    }
                }
            }
            low[from] = min(low[from], low[to]);
        }
        else if(discovered[to] < discovered[from])
        {
            S.push(make_pair(from, to));
            low[from] = min(discovered[to], low[from]);
        }
    }
}

void find_bcc(int n)
{
    int i;
    timer = 1;
    while(!S.empty()) S.pop();
    F(i, n)
    {
        if(!visited[i])
            bcc(i, -1);
    }
}

int main()
{
    _
    int test, kase, n, m, i, a, b;
    cin >> test;
    for(kase = 1; kase <= test; kase++)
    {
        cin >> n >> m;
        F(i, n)
            adj[i].clear(), is_a_point[i] = visited[i] = 0;
        F(i, m)
        {
            cin >> a >> b;
            adj[a].pb(b), adj[b].pb(a);
        }
        find_bcc(n);
        a = 0;
        F(i, n)
            a += is_a_point[i] == 1;
        printf("Case %d: %d\n", kase, a);
    }
    return 0;
}

