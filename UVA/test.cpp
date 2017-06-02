#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <string.h>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>

#define clr(arr,key) memset(arr,key,sizeof arr);
#define pb push_back
#define LL long long
#define PI acos(-1)
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(), v.end()
#define SZ(v) (int) v.size()

using namespace std;

struct fastio{fastio(){ios_base::sync_with_stdio(0);cin.tie(0);}} cincout;

#define MAX 100010

map <int,int> mpp;
pair <int,int> N[MAX];
vector <int> Q[MAX];
set <int> ss;

int main()
{
    LL n, i, l, r, q, x, j;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> l >> r;
        ss.insert(l), ss.insert(r);
        N[i] = {l, r};
    }
    cin >> q;
    for(i = 1; i <= q; i++)
    {
        cin >> l;
        while(l--)
        {
            cin >> x;
            ss.insert(x);
            Q[i].pb(x);
        }
    }
    i = 1;
    for(auto x: ss)
        mpp[x] = i++;
    vector <pair<int,int>> arr;
    for(i = 1; i <= n; i++)
    {
        N[i].first = mpp[N[i].first];
        N[i].second = mpp[N[i].second];
        arr.pb({N[i].first, -2});
        arr.pb({N[i].second, N[i].first});
    }
    for(i = 1; i <= q; i++)
        for(j = 0; j < SZ(Q[i]); j++)
        {
            Q[i][j] = mpp[Q[i][j]];
            arr.pb({Q[i][j], -1});
        }
    multiset <int> MS;
    map <int,int> res;
    sort(all(arr));
    for(auto x: arr)
    {
        if(x.second == -1)
            res[x.first] = SZ(MS), cout << x.first << ' ' << SZ(MS) << endl;
        else if(x.second == -2)
            MS.insert(x.first);
        else
        {
            auto it = MS.lower_bound(x.second);
            auto it2 = it;
            MS.erase(it, ++it2);
        }
    }
    for(i = 1; i <= q; i++)
    {
        LL tem = 0;
        for(auto x: Q[i])
            tem += res[x];
        cout << tem << "\n";
    }
    return 0;
}
