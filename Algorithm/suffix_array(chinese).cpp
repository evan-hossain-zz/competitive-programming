#include <bits/stdc++.h>

#define in freopen("input.txt", "r", stdin);
#define out freopen("input.txt", "w", stdout);
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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

/// warning!! warning!! warning!!
/// ভুল আছে

int N;
int cnt[MAX];
string text;
int phi[MAX], lcp[MAX];
int RA[MAX], SA[MAX], revSA[MAX], tmpRA[MAX], tmpSA[MAX];

void buildLCP()
{
    int L=0;
    phi[SA[0]] = -1;
    for(int i=1; i<N; i++) phi[SA[i]] = SA[i-1];
    for(int i=0; i<N; i++)
    {
        if(phi[i]==-1)
        {
            lcp[revSA[i]]=0;
            continue;
        }
        while(i+L < N && phi[i]+L < N && text[i+L]==text[phi[i]+L]) L++;
        lcp[revSA[i]] = L;
        if(L) L--;
    }
}

void csort(int k)
{
    int cub = max(N, 128);
    clr(cnt, 0);
    for(int i=0; i<N; i++) cnt[i+k<N?RA[i+k]:0]++;
    for(int i = 1; i < cub; i++) cnt[i] += cnt[i-1];
    for(int i=cub-1; i>=1; i--) cnt[i] = cnt[i-1];
    cnt[0] = 0;
    for(int i=0; i<N; i++) tmpSA[ cnt[SA[i]+k<N?RA[SA[i]+k]:0]++ ] = SA[i];
    for(int i=0; i<N; i++) SA[i] = tmpSA[i];
}

void buildSA()
{
    for(int i = 0; i < N; i++)
    {
        RA[i] = text[i];
        SA[i] = i;
    }
    int k = 1;
    while(k<N)
    {
        csort(k);
        csort(0);
        int r = 0;
        tmpRA[SA[0]] = 0;
        for(int i = 1; i < N; i++)
        {
            if(RA[SA[i]]!=RA[SA[i-1]] || RA[SA[i]+k]!=RA[SA[i-1]+k]) r++;
            tmpRA[SA[i]] = r;
        }
        for(int i = 0; i < N; i++) RA[i] = tmpRA[i];
        if(RA[SA[N-1]]==N-1) break;
        k <<= 1;
    }
    for(int i = 0; i < N; i++)  revSA[SA[i]] = i;
}

void printSA()
{
    for(int i=0;i<SZ(text);i++) printf("%d %d %d %s %d\n", i, SA[i], revSA[SA[i]], text.substr(SA[i]).c_str(), lcp[i]);
    puts("");
    return ;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    text = "banana";
    N = SZ(text);
    buildSA();
    buildLCP();
    printSA();
    return 0;
}
