#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;


#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 40500
#define twoL(X) (((ll)(1))<<(X))

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}

template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

struct SAdata{
    paii val;
    int pos;
    SAdata() {}
    SAdata(paii x, int y)
    {
        val=x;pos=y;
    }
}SADT[MAX];/// temporary Data Structure for building SA
bool comSA(SAdata a, SAdata b)
{
    return a.val<b.val;
}

string input_text;/// Input String for SA to build
int SA[MAX],revSA[MAX];      /// Found SA and reverse SA
int lcp[MAX]; /// longest common prfix array for adjacent suffixes found in SA
int left_limit, right_limit, seg_tree[MAX * 4], pos_seg_tree[MAX * 4], lim, mx, mxindx;


/// SA returns the start positions  of the suffixes which are stored in lexicographical order
/// revSA returns for every suffix starting at 0 its position in SA

void update_segment_tree(int l, int r, int indx, int cur, int val)
{
    if(l == r)
    {
        seg_tree[cur] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(indx <= mid)
        update_segment_tree(l, mid, indx, cur * 2, val);
    else
        update_segment_tree(mid + 1, r, indx, cur * 2 + 1, val);
    seg_tree[cur] = min(seg_tree[cur * 2], seg_tree[cur * 2 + 1]);
}

void update_pos_segment_tree(int l, int r, int indx, int cur, int val)
{
    if(l == r)
    {
        pos_seg_tree[cur] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(indx <= mid)
        update_pos_segment_tree(l, mid, indx, cur * 2, val);
    else
        update_pos_segment_tree(mid + 1, r, indx, cur * 2 + 1, val);
    pos_seg_tree[cur] = max(pos_seg_tree[cur * 2], pos_seg_tree[cur * 2 + 1]);
}

void buildSA()
{
    for(int i=0;i<lim;i++) revSA[i]=input_text[i];
    int prv_rank;

    for(int cnt=1;cnt<lim;cnt*=2)
    {
        for(int i=0;i<lim;i++)
        {
            SADT[i].pos=i;
            SADT[i].val.fs=revSA[i];
            SADT[i].val.sc= (i+cnt<lim) ? revSA[i+cnt] : -1;
        }
        sort(SADT,SADT+lim,comSA);

        for(int i=0;i<lim;i++)
        {
            revSA[ SADT[i].pos ]= (i-1>=0 && SADT[i].val==SADT[i-1].val) ? prv_rank : i ;
            prv_rank=revSA[ SADT[i].pos ];
        }
    }
    for(int i=0;i<lim;i++) SA[revSA[i]]=i;
    for(int i=0;i<lim;i++) update_pos_segment_tree(0, lim - 1, i, 1, SA[i]);
}

void printSA()
{
    cout<<"SA: \n";
    for(int i=0;i<SZ(input_text);i++) printf("%d %d %s %d\n", i, SA[i], input_text.substr(SA[i]).c_str(), lcp[i]);
    puts("");
    return ;
}

int query(int L, int R, int cur)
{
    if(L > right_limit || R < left_limit)
        return (1 << 28);
    if(L >= left_limit && R <= right_limit)
        return seg_tree[cur];
    int mid = (L + R) >> 1;
    return min(query(L, mid, cur * 2), query(mid + 1, R, cur * 2 + 1));
}

int pos_query(int L, int R, int cur)
{
    if(L > right_limit || R < left_limit)
        return -1;
    if(L >= left_limit && R <= right_limit)
        return pos_seg_tree[cur];
    int mid = (L + R) >> 1;
    return max(pos_query(L, mid, cur * 2), pos_query(mid + 1, R, cur * 2 + 1));
}

void buildLCP()
{
    int mx_mtch=0,SApos,j;
    update_segment_tree(0, lim - 1, 0, 1, 0);
    for(int i=0;i<lim;i++)
    {
        SApos=revSA[i];
        if(SApos==0) continue;
        if(mx_mtch>0) mx_mtch--;

        j=SA[SApos-1];

        while( (i+mx_mtch)<lim && (j+mx_mtch)<lim && input_text[i+mx_mtch]==input_text[j+mx_mtch])
            mx_mtch++;

        lcp[SApos]=mx_mtch;
        update_segment_tree(0, lim - 1, SApos, 1, lcp[SApos]);
    }
    lcp[0]=0;

    return ;
}

void get_result(int high)
{
    int low = 0, tem;
    mx = 0;
    mxindx = -1;
    while(high < lim)
    {
        left_limit = low + 1;
        right_limit = high;
        tem = query(0, lim - 1, 1);
        if(tem > max(1, mx))
        {
            mx = tem;
            left_limit = low;
            mxindx = pos_query(0, lim - 1, 1);
        }
        else if(tem == max(1, mx))
        {
            mx = tem;
            left_limit = low;
            mxindx = max(mxindx, pos_query(0, lim - 1, 1));
        }
        low++;
        high++;
    }
}

char str[MAX];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);cin.tie(0);
    int m, i;
    while(scanf("%d", &m) == 1 && m)
    {
        scanf(" %s", str);
        input_text = str;
        lim = SZ(input_text);
        if(m == 1)
        {
//            cout << lim << ' ' << 0 << "\n";
            printf("%d 0\n", lim);
            continue;
        }
        for(i = 0; i <= lim; i++)
        {
            update_pos_segment_tree(0, lim - 1, i, 1, -1);
            update_segment_tree(0, lim - 1, i, 1, (1 << 28));
        }
        buildSA();
        buildLCP();
        get_result(m - 1);
//        printSA();
        if(!mx)
//            cout << "none\n";
            printf("none\n");
        else
//            cout << mx << ' ' << mxindx << "\n";
            printf("%d %d\n", mx, mxindx);
    }
    return 0;
}

