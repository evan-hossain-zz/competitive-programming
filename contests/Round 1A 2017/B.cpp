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
#define out freopen("output.out", "w", stdout);
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
#define SZ(v) (LL)(v.size())
#define eps 1e-7

LL col8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
LL row8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
LL col4[4] = {1, 0, -1, 0};
LL row4[4] = {0, 1, 0, -1};
//LL months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

//struct poLL{LL x, y; poLL () {} poLL(LL a, LL b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(LL i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast{fast(){ios_base::sync_with_stdio(0);cin.tie(0);}}cincout;

#define MAX 55
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/
LL R[MAX], N, P, Q[MAX][MAX];
pair <LL,LL> can_take[MAX][MAX];

bool ok(LL n, LL have)
{
	return 100*have >= 90*n && 100*have <= 110*n;
}

bool dfs(LL r, LL c, LL low, LL high)
{
}

int main()
{
	in;
	// out;
	LL test, kase = 1, i, j, k;
	cin >> test;
	while(test--)
	{
		cin >> N >> P;
		for(i = 0; i < N; i++)
			cin >> R[i];
		for(i = 0; i < N; i++)
			for(j = 0; j < P; j++)
			{
				cin >> Q[i][j];
				LL low = Q[i][j]/(R[i]*1.1);
				LL high = Q[i][j]/(R[i]*.9);
				can_take[i][j] = mp(0, 0);
				while(low <= high)
				{
					if(ok(low*R[i], Q[i][j]))
					{
						can_take[i][j].first = low;
						can_take[i][j].second = low;
						break;
					}
					low++;
				}
				while(low <= high)
				{
					if(ok(high*R[i], Q[i][j]))
					{
						can_take[i][j].second = max(can_take[i][j].second, high);
						break;
					}
					high--;
				}
				// cout << Q[i][j] << "," << R[i] << '=' << can_take[i][j].first << '-' << can_take[i][j].second << endl;
			}
		flow = new Dinic(N*P+2);
		LL source = N*P, sink = N*P+1;
		for(j = 0; j < P; j++)
		{
			if(bfs(1, j, can_take[0][j].first, can_take[0][j].second))
		}
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















