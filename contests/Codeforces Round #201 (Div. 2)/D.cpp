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
#define eps 10e-7

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

#define MAX 110
/*************************************************HABIJABI ENDS HERE******************************************************/

//vector < int > lcs[MAX][MAX];
string lcs[MAX][MAX];
bool baad[MAX][MAX];

int main()
{
    _
    string A, B, V, tem, mx = "";
    int i, j, k, mxlen = 0;
    cin >> A >> B >> V;
    for(i = 1; i <= A.size(); i++)
    {
        for(j = 1; j <= B.size(); j++)
        {
            if(A[i - 1] == B[j - 1])
            {
                lcs[i][j] += lcs[i - 1][j - 1] + A[i - 1];
//                lcs[i][j] = lcs[i - 1][j - 1];
//                lcs[i][j].pb(i - 1);
            }
            else if(lcs[i - 1][j].size() > lcs[i][j - 1].size())
                lcs[i][j] = lcs[i - 1][j];
            else
                lcs[i][j] = lcs[i][j - 1];
        }
    }
    for(i = 0; i <= A.size(); i++)
    {
        for(j = 0; j <= B.size(); j++)
        {
//            cout << i << j << endl;
            tem.clear();
//            for(k = 0; k < lcs[i][j].size(); k++)
//                tem += A[lcs[i][j][k]];
            tem = lcs[i][j];
            int t = 0, l;
            bool flag = 0;
            for(l = 0; l < tem.size(); l++)
            {
                int t = l;
                for(k = 0; k < V.size() && t < tem.size(); k++)
                {
                    if(V[k] == tem[t])
                        t++;
                }
                if(t >= l + V.size())
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0 && tem.size() > mx.size())
                mx = tem;
        }
    }
    cout << mx.size() << endl;
    if(mx.size() == 0)
        cout << 0 << endl;
    else
        cout << mx << endl;
    return 0;
}

