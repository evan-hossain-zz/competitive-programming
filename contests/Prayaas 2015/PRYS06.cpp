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
#define no_of_ones __builtin_popcountll // __builtin_popcountll for LL
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

unsigned LL orgblocks[320][1700], infblocks[320][1700], first[1700], second[1700];
int org[MAX], inf[MAX], limit;

void ready(int n)
{
    int i, cnt = 0, tem = 0, j;
    for(i = 1; i <= n; i++)
    {
        if(tem == 320)
            cnt++, tem = 0;
        orgblocks[cnt][org[i]>>6] |= 1LL << (org[i]&63);
        tem++;
    }
    for(i = 1; i < cnt; i++)
    {
        for(j = 0; j < limit; j++)
            orgblocks[i][j] |= orgblocks[i-1][j];
    }
    cnt = 0, tem = 0;
    for(i = 1; i <= n; i++)
    {
        if(tem == 320)
            cnt++, tem = 0;
        infblocks[cnt][inf[i]>>6] |= 1LL << (inf[i]&63);
        tem++;
    }
    for(i = 1; i < cnt; i++)
    {
        for(j = 0; j < limit; j++)
            infblocks[i][j] |= infblocks[i-1][j];
    }
}

void getfirst(int l, int r)
{
    int block_no = l / 320;
    while(l/320 == block_no && l <= r)
    {
        first[org[l]>>6] |= 1LL << (org[l]&63);
        l++;
    }
    block_no = r / 320;
    while(l <= r && r/320 == block_no)
    {
        first[org[r]>>6] |= 1LL << (org[r]&63);
        r--;
    }
    if(l > r) return;
    int a = l/320;
    a -= 2;
    int b = r/320;
    if(a < 0) return;
    for(int i = 0; i < limit; i++)
        first[i] |= (orgblocks[b][i]^orgblocks[a][i]);
}

void getsecond(int l, int r)
{
    int block_no = l / 320;
    while(l/320 == block_no && l <= r)
    {
        second[inf[l]>>6] |= 1LL << (inf[l]&63);
        l++;
    }
    block_no = r / 320;
    while(l <= r && r/320 == block_no)
    {
        second[inf[r]>>6] |= 1LL << (inf[r]&63);
        r--;
    }
    if(l > r) return;
    int a = l/320;
    a -= 2;
    int b = r/320;
    if(a < 0) return;
    for(int i = 0; i < limit; i++)
        second[i] |= (infblocks[b][i]^infblocks[a][i]);
}

int count_bit(unsigned LL x)
{
  x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
  x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
  x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
  x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
  x = (x & 0x0000FFFF) + ((x >> 16)& 0x0000FFFF);
  x = (x & 0xFFFFFFFF) + ((x >> 32)& 0xFFFFFFFF);
  return x;
}

int match()
{
    int cnt = 0;
    for(int i = 0; i < limit; i++)
    {
        cnt += count_bit(first[i]&second[i]);
        first[i] = second[i] = 0;
    }
    return cnt;
}

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    int n, i, q, a, b, c, d;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
        scanf("%d", &org[i]);
    for(i = 1; i <= n; i++)
        scanf("%d", &inf[i]);
    ready(n);
    limit = (n >> 6)+2;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        getfirst(a, a+b);
        getsecond(c, c+d);
        printf("%d\n", b+d+2-2*match());
//        cout << b+d+2 - 2*match() << "\n";
    }
    return 0;
}


