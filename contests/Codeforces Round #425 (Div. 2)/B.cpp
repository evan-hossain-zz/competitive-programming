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

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int good[222];
string s, text, pat;

bool ok(int text_indx, int pat_indx)
{
	if(pat_indx >= SZ(pat))
	{
		if(text_indx >= SZ(text))
			return true;
		if(text_indx + 1 == SZ(text) && text[text_indx] == '*')
			return true;
		return false;
	}
	if(text_indx >= SZ(text))
		return false;
	if(text[text_indx] == pat[pat_indx])
		return ok(text_indx+1, pat_indx+1);
	if(good[pat[pat_indx]])
	{
		if(text[text_indx] == '?')
			return ok(text_indx+1, pat_indx+1);
		if(text[text_indx] == '*')
			return ok(text_indx+1, pat_indx);
		return false;
	}
	if(text[text_indx] == '*')
		return ok(text_indx, pat_indx+1);
	return false;
}

int main()
{
	// in;
	cin >> s;
	for(auto ch: s)
		good[ch] = 1;
	cin >> text;
	string tem;
	for(int i = 0; i < SZ(text); i++)
	{
		if(text[i] == '?' || text[i] == '*' || good[text[i]])
			tem += text[i];
		else if(!tem.empty() && tem[SZ(tem)-1] == '*')
			continue;
		else
			tem += text[i];
	}
	text = tem;
	int q;
	cin >> q;
	while(q--)
	{
		cin >> pat;
		if(ok(0, 0))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
    return 0;
}
// clang++ -std=c++11 -stdlib=libc++ 















