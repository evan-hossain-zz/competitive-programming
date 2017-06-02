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
#define sz(name) (int)(name.size())

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

#define SZ 1000010
/*************************************************HABIJABI ENDS HERE******************************************************/

int main()
{
    _
//    out;
    int v[25][22], L[25][22], R[25][22];
    int n, i, j, Lcount[25][25],Rcount[25][25],sZ,bosabo;
    bool flag=false;
    while(cin >> n)
    {
        clr(Lcount,0);
        clr(Rcount,0);
        clr(v,0);
        clr(L,0);
        clr(R,0);
        if(flag) cout<<endl<<endl;
        flag=true;
        for(i = 1; i <= n; i++)
        {
            sZ=1;
            while(cin >> j && j)
            {
                v[i][sZ++]=j;
                Lcount[i][j]++;
            }
            v[i][sZ++]=0;
            for(int j=v[i][1]-1;j>0;j--) Lcount[i][j]+=Lcount[i][j+1];
        }
        for(int i=1;i<=n;i++)
        {
            sZ=v[i][1];
            for(int j=1;v[i][j]!=0;j++)
            {
                bosabo=v[i][j]-v[i][j+1];
                while(bosabo--)
                {
                    L[sZ--][i]=Lcount[i][v[i][j]];
                }
            }
        }
        for(int i=1;;i++)
        {
            for(int j=1;L[i][j]!=0;j++)
            {
                if(j^1) cout<<" ";
                cout<<L[i][j];
            }

            if(L[i][1]==0) break;cout<<endl;
        }
        cout<<endl;
        for(int i=1;;i++)
        {
            for(int j=1;v[j][i]!=0;j++)
            {
                Rcount[v[j][i]][i]++;
            }
            for(int j=v[1][i]-1;j>0;j--) Rcount[j][i]+=Rcount[j+1][i];
            if(v[1][i]==0) break;
        }
        for(int i=1;v[1][i]!=0;i++)
        {
            sZ=v[1][i];
            for(int j=1;v[j][i]!=0;j++)
            {
                bosabo=v[j][i]-v[j+1][i];
                while(bosabo--)
                {
                    R[i][sZ--]=Rcount[v[j][i]][i];
                }
            }
        }
        for(int i=1;;i++)
        {
            for(int j=1;R[i][j]!=0;j++)
            {
                if(j^1) cout<<" ";
                cout<<R[i][j];
            }

            if(R[i][1]==0) break;cout<<endl;
        }
    }
    return 0;
}
/*

3
3 3 1 0
3 1 0
2 0

6
6 5 5 4 3 3 0
6 4 3 3 1 0
6 4 3 1 1 0
4 2 2 1 0
3 1 1 0
1 1 1 0

*/

//                cout<<"bosabo : "<<bosabo<<" value : "<<v[i][j]<<" Lcount : "<<Lcount[i][v[i][j]]<<endl;
//            cout<<"::::::::::::"<<endl;

