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

#define MAX 110
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int dp[105][1<<15], N, M, K, id[6][6];
string letters[6];

int nc2(int k)
{
	return k*(k-1)/2;
}

int call(int indx, int mask)
{
	if(mask == (1<<nc2(K))-1)
		return 0;
	if(indx == N*M)
		return infinity;
	int &ret = dp[indx][mask];
	if(~ret) return ret;
	int cur_mask = mask;
	ret = call(indx+1, mask);
	for(int i = 0; i < K; i++)
		for(int j = i+1; j < K; j++)
		{
			if(letters[i][indx] != letters[j][indx])
				mask |= 1<<id[i][j];
		}
	ret = min(ret, call(indx+1, mask) + 1);
	return ret;
}

int main()
{
	// in;
	int i, j, k;
	string s;
	cin >> N >> M >> K;
	k=0;
	for(i = 0; i < K; i++)
		for(j = i+1; j < K; j++)
			id[i][j] = k++;
	for(k = 0; k < K; k++)
	{
		for(i = 0; i < N; i++)
		{
			cin >> s;
			letters[k] += s;
		}
	}
	clr(dp, -1);
	cout << call(0, 0) << "\n";
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 







/*
dbd6148f-ab72-415e-8f80-a21b9dd2ac15
*/







