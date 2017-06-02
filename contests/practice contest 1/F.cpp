#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

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
#define no_of_ones __builtin_popcount // count 1's in a numbers binary representation
#define SZ(v) (int)(v.size())
#define eps 10e-7

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
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}    // convert a number to string
template <class T> inline T Mod(T n,T m) {return (n%m+m)%m;}    // negative mod
template <class T> void print_all(T v) {for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';};
template <class T> void print_all(T &v, int len) {for(int i = 0; i < len; i++) cout << v[i] << ' ';}     // prints all elements in a vector or array
template <class T> void print_pair(T v, int len) {for(int i = 0; i < len; i++) cout << v[i].first << ' ' << v[i].second << endl;} // prints pair vector
LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/*************************************************HABIJABI ENDS HERE******************************************************/

int num[10], n, val;
string s, express;

vector<int>v;

map<char,int> pres, chew;


void infix_to_postfix(string P)
{
    stack<char>S;
    string Q;
    int i = 0;
    char element;
    while(i<P.size())
    {
        element = P[i++];
        if(isalpha(element)) Q=Q+element;
        else if(element == '(' ||S.empty()) S.push(element);
        else if(element == ')')
        {
            while(S.top()!='(')
            {
                Q=Q+S.top();
                S.pop();
            }
            S.pop();
        }
        else
        {
            while(!S.empty() &&pres[S.top()] >= pres[element])
            {
                Q=Q+S.top();
                S.pop();
            }
            S.push(element);
        }
    }


    while(!S.empty())
    {
        Q=Q+S.top();
        S.pop();
    }
    express = Q;
    return;
}

int eval_postfix()
{
    stack<int>S;
    int len = express.size();
    cout<<express<<endl;
    for (int i = 0; i<len; i++)
    {
        if(isalpha(express[i])) S.push(v[ chew [express[i] ] ]);
        else if(express[i]=='*')
        {
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            cout<<a<<":"<<b<<endl;
            S.push(a*b);
        }
        else if(express[i]=='+')
        {
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            S.push(a+b);
        }
        else if(express[i]=='-')
        {
            int a = S.top();
            S.pop();
            int b = S.top();
            S.pop();
            S.push(a-b);
        }
    }
    return S.top();
}



bool rec(int mask)
{
    if(mask==(1<<n)-1)
    {
        int kk  = eval_postfix();

//        for (int i = 0; i<express.size(); i++)
//            if(isalpha(express[i]))cout<<v[ chew[ express[i] ] ]<<" ";cout<<endl;

        cout<<val<<"val = "<<kk<<endl;
        return kk==val;
    }
    for (int i = 0; i<n; i++)
    {
        if(mask&(1<<i)) continue;
        v.pb(num[i]);
        if(rec(mask|(1<<i))) return true;
        v.pop_back();
    }
    return false;
}


int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif

    pres['*'] = 2;
    pres['+'] = 1;
    pres['-'] = 1;

    string now;
    char line[100000];
    while(~scanf("%d", &n))
    {
        if(n==0)
        {
            scanf("%d", &n);
            break;
        }
        chew.clear();
        v.clear();
        set<int>sss;
        for (int i = 0; i<n; i++)
            scanf("%d", &num[i]), sss.insert(num[i]);
        scanf("%d %s", &val, line);
        now = line;

        infix_to_postfix(now);
        //cout<<isalpha('+')<<endl;
        for (int i = 0, kk = 0; i<express.size(); i++)
            if(isalpha(express[i])) chew[ express[i] ] = kk++;

//        cout<<express<<endl;
        if(rec(0)) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}


