#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i=a; i<=b; ++i)
#define REP(i, a, b) for(auto i=a; i<b; ++i)
#define FORI(i, a, b) for(auto i=a; i!=b+1-2*(a>b); i+=1-2*(a>b))
#define REPI(i, a, b) for(auto i=a-(a>b); i!=b-(a>b); i+=1-2*(a>b))
#define ALL(v) v.begin(),v.end()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define eb(a, b) emplace_back(a, b)
#define fir first
#define sec second
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define type(x) typeid(x).name()
#define ms(arr, val) memset(arr, val, sizeof(arr))
#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)

using namespace std;

int dp_solve[110][110][110], S;


class CheeseSlicing
{
    public:
        int totalArea(int A, int B, int C, int s)
        {
        	S = s;
            ms(dp_solve, -1);
            return solve(A, B, C);
        }

        int solve(int A, int B, int C)
        {
            int max_1 = max3(A, B, C), max_2 = 0, minim = min3(A, B, C);
            
//            cout<<A<<" "<<B<<" "<<C<<endl;
            if(minim < S)
                return 0;

            if(A == max_1)
                max_2 = max(B, C);

            else if(B == max_1)
                max_2 = max(A, C);

            else if(C == max_1)
                max_2 = max(A, B);
            
            int &ret = dp_solve[A][B][C];
            
            if(ret != -1)
                return ret;
                
            ret = max_1 * max_2;
            
            FOR(i, 1, A-1)
                ret = max(ret, solve(i, B, C) + solve(A-i, B, C));
            
            FOR(i, 1, B-1)
                ret = max(ret, solve(A, i, C) + solve(A, B-i, C));
            
            FOR(i, 1, C-1)
                ret = max(ret, solve(A, B, i) + solve(A, B, C-i));
        
            return ret;
        }
};
