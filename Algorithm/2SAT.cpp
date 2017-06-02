#include <bits/stdc++.h>

#define sz 100005
#define SZ(s) ((int)s.size())
#define pb(a) push_back(a)
#define clr(abc,z) memset(abc,z,sizeof(abc))
#define fr(i,a,b) for(i=a;i<=b;i++)
#define VI vector<int>
using namespace std;
//0 based
VI adj[2*sz]; //2*sz for true and false argument(only adj should be cleared)
int col[2*sz],low[2*sz],tim[2*sz],timer;
int group_id[2*sz],components;//components=number of components, group_id = which node belongs to which node
bool ans[sz]; //boolean assignment ans
stack<int>S;
void scc(int u)
{
    int i,v,tem;
    col[u]=1;
    low[u]=tim[u]=timer++;
    S.push(u);
    fr(i,0,SZ(adj[u])-1)
    {
        v=adj[u][i];
        if(col[v]==1)
            low[u]=min(low[u],tim[v]);
        else if(col[v]==0)
        {
            scc(v);
            low[u]=min(low[u],low[v]);
        }
    }
    //SCC checking...
    if(low[u]==tim[u])
    {
        do
        {
            tem=S.top();S.pop();
            group_id[tem]=components;
            col[tem]=2; //Completed...
        }while(tem!=u);
        components++;
    }
}
int TarjanSCC(int n) //n=nodes (some change may be required here)
{
    int i;
    timer=components=0;
    clr(col,0);
    while(!S.empty()) S.pop();
    fr(i,0,n-1) if(col[i]==0) scc(i);
    return components;
}
//double nodes needed normally
bool TwoSAT(int n) //n=nodes (some change may be required here)
{
    TarjanSCC(n);
    int i;
    for(i=0;i<n;i+=2)
    {
        if(group_id[i]==group_id[i+1])
            return false;
        if(group_id[i]<group_id[i+1]) //Checking who is lower in Topological sort
            ans[i/2]=true;
        else ans[i/2]=false;
    }
    return true;
}
void add(int ina,int inb)
{
    adj[ina].pb(inb);
}
int complement(int n)
{
    return n^1;
}
void initialize(int n)
{
    for(int i=0;i<n;i++)
        adj[i].clear();
}
int main()
{
    int n, m, i, u, v;
    while(~scanf("%d %d", &n, &m))
    {
        initialize(n<<1);
        fr(i,0,m-1)
        {
            scanf("%d %d", &u, &v);
            if(u>0) u = 2*u-2;
            else u = -2*u-1;
            if(v>0) v = 2*v-2;
            else v = -2*v-1;
            add(complement(u),v);
            add(complement(v),u);
        }
        if(TwoSAT(n<<1)) puts("YES");
        else puts("NO");
    }
    return 0;
}
