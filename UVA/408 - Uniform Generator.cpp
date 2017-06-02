#include <bits/stdc++.h>

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pub push_back
#define pob pop_back
#define infinity 2147483647
#define LL long long
#define Pi acos(-1)
#define SZ 10000010
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

using namespace std;

bool found[SZ];
int seed_arr[SZ];
int step, mod, i;

void seed(int x)
{
    seed_arr[0] = 0;
    for(int i = 1; i <= mod; i++)
    {
        seed_arr[i] = (seed_arr[i - 1] + step) % mod;
        found[seed_arr[i]] = 1;
    }
}

int main()
{
    _
//    out;
    while(cin >> step >> mod){
        clr(found, 0);
        seed(mod);
        for(i = 0; i < mod; i++)
            if(!found[i])
                break;
        printf("%10d%10d", step, mod);
        if(i == mod)
            printf("    Good Choice\n\n");
        else
            printf("    Bad Choice\n\n");
    }
    return 0;
}

