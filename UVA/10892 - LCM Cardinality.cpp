#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 100010
#define VI vector <int>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};
///int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

struct point{int x, y;};

template <class T> T sqr(T a){return a * a;};
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
template <class T> T GCD(T a, T b) {if(b == 0) return a; return GCD(b, a % b);}
template <class T> T LCM(T a, T b) {return (a * b) / GCD(a, b);}

using namespace std;

set <LL> S;

void divisors(LL n)
{
    LL limit = sqrt(n), i;
    for(i = 2; i <= limit; i++)
    {
        if(n % i == 0)
        {
            S.insert(i);
            S.insert(n / i);
        }
    }
    return;
}

int main()
{
    _
    int i, j;
    LL n, a, b;
    while(cin >> n && n)
    {
        map <pair <LL, LL>, int> mapped;
        int cnt = 0;
        S.clear();
        S.insert(1);
        S.insert(n);
        divisors(n);
        for(set <LL> :: iterator it = S.begin(); it != S.end(); it++){
            for(set <LL> :: iterator jt = S.begin(); jt != S.end(); jt++){
                    a = *it;
                    b = *jt;
                    if(a > b) swap(a, b);
                if(mapped.find(make_pair(a, b)) != mapped.end())
                    continue;
                if(LCM(a, b) == n)
                    cnt++;
                mapped[make_pair(a, b)] = 1;
            }
        }
        printf("%lld %d\n", n, cnt);
    }
    return 0;
}
