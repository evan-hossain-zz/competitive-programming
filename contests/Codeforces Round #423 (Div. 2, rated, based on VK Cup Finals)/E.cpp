#include <algorithm>
#include <iostream>
#include <sstream>
#include <climits>
#include <cstring>
#include <cassert>
#include <utility>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>
#include <queue>
#include <set>
#include <map>

#define in freopen("input.in", "r", stdin);
#define out freopen("control.out", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define mt       make_tuple
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

int col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int col4[4] = {1, 0, -1, 0};
int row4[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 100010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

LL tree[11][11][4][MAX];
int dna[200];

LL read(int T, int start, int strand, int idx)
{
    LL sum = 0;
    while(idx > 0){
        sum += tree[T][start][strand][idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int T, int start, int strand, int idx, LL val, int n)
{
    while(idx <= n)
    {
        tree[T][strand][start][idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{
	in;
	string s, e;
	char c;
	int q, i, l, r, t, x;
	cin >> s;
	s = "#" + s;
	dna['A'] = 0;
	dna['T'] = 1;
	dna['C'] = 2;
	dna['G'] = 3;

	for(int T = 1; T <= 10; T++)
	{
		string tem = "ATCG";
		for(auto strand: tem)
		{
			for(int start = 1; start <= 10; start++)
				for(int i = start; i < SZ(s); i += T)
					if(strand == s[i])
						update(T, start, dna[strand], i, 1, SZ(s));
		}
	}
	cin >> q;
	while(q--)
	{
		cin >> t;
		if(t == 1)
		{
			cin >> x >> c;
			for(int T = 1; T <= 10; T++)
			{

				for(int start = 1; start <= 10; start++)
					if((x-1) % T == 0)
					{
						update(T, start, dna[s[x]], x, -1, SZ(s));
						update(T, start, dna[c], x, 1, SZ(s));
					}
			}
			s[x] = c;
		}
		else
		{
			cin >> l >> r >> e;
			int res = 0;
			for(int start = 1; start <= SZ(e); start++)
				for(i = 0; i < SZ(e); i++)
				{
					res += read(SZ(e), start, dna[e[i]], r-i) - read(SZ(e), start, dna[e[i]], l-1+i);
				}
			cout << res << "\n";
		}
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















