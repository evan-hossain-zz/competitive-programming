#include <bits/stdc++.h>

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
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7

//int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int col[4] = {1, 0, -1, 0};
//int row[4] = {0, 1, 0, -1};
//int months[13] = {0, ,31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;

struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
template <class T> T sqr(T a){return a * a;}
template <class T> T power(T n, T p) { T res = 1; for(int i = 0; i < p; i++) res *= n; return res;}
template <class T> double getdist(T a, T b){return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}    // distance between a and b
template <class T> T extract(string s, T ret) {stringstream ss(s); ss >> ret; return ret;}
template <class T> string tostring(T n) {stringstream ss; ss << n; return ss.str();}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

#define MAX 200010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

string add(string a,string b); //add any two string
string multiply(string a,string b); //multiply between a and b
string multiply(string a,int k);  //multiply between a and int k
string substract(string a,string b);  // substract from a to b(a always >=b)
string divide(string a,string b); //divide return a/b
string divide(string a,int k);    //divide return a/k
string mod(string a,string b);  //Modulus of divide a%b
int    mod(string a,int k);     //Modulus of divide a%k
string cut_leading_zero(string a);  //leading zero cut 001 -> 1
int    compare(string a,string b);  //(1 means a>b) (-1 means a<b) (0 means a=b)
string power(string s, int a);        //Calculate powerer s^a
string GCD(string a,string b);     //Calculate GCD between a and b
string LCM(string a,string b);     //Calculate LCM between a and b

string bigmod(string B,string P,LL M)
{
    string R="1";
    while(P>"0")
    {
        if(mod(P,2)==1)
        {
            R=tostring(mod(multiply(R,B),M));
        }
        P = divide(P, 2);
        B = tostring(mod(multiply(B, B), M));
    }
    return R;
}

vector <string> arr;

int main()
{
    #ifdef Evan
//        in;
//        out;
    #endif
    CF
    int test, i;
    string exp, num, res;
    LL m;
    cin >> test;
    while(test--)
    {
        res = "1";
        arr.clear();
        num.clear();
        cin >> m >> exp;
        for(i = 0; i < SZ(exp); i++)
        {
            if(isdigit(exp[i]))
                num += exp[i];
            else if(!num.empty())
            {
                arr.pb(num);
                num.clear();
            }
        }
        arr.pb(num);
        for(i = 0; i < SZ(arr); i += 2)
            res = tostring(mod(multiply(res, bigmod(arr[i], arr[i+1], m)), m));
        cout << res << "\n";
    }
    return 0;
}

string LCM(string a,string b)
{
    return divide(multiply(a,b),GCD(a,b));
}
string GCD(string a,string b)
{
    return (b=="0")?a:GCD(b,mod(a,b));
}
string power(string B,int P)
{
    string R="1";
    while(P>0)
    {
        if(P%2==1)
            R=multiply(R,B);
        P/=2;
        B=multiply(B,B);
    }
    return R;
}
string multiply(string a,string b)
{
    int i,j,multi,carry;
    string ans,temp;

    ans="0";
    for(j = SZ(b)-1; j >= 0; j--)
    {
        temp="";
        carry=0;
        for(i = SZ(a)-1; i >= 0; i--)
        {
            multi=(a[i]-'0')*(b[j]-'0')+carry;
            temp+=(multi%10+'0');
            carry=multi/10;
        }
        if(carry)   temp+=(carry+'0');
        reverse(all(temp));
        temp+=string(SZ(b)-j-1,'0');
        ans=add(ans,temp);
    }
    ans=cut_leading_zero(ans);
    return ans;
}
string multiply(string a,int k)
{
    string ans;
    int i,sum,carry=0;

    for(i = SZ(a)-1; i >= 0; i--)
    {
        sum=(a[i]-'0')*k+carry;
        carry=sum/10;
        ans+=(sum%10)+'0';
    }
    while(carry)    {ans+=(carry%10)+'0';carry/=10;}
    reverse(all(ans));
    ans=cut_leading_zero(ans);
    return ans;
}
string add(string a,string b)
{
    int carry=0,i;
    string ans;

    if(SZ(a)>SZ(b)) b=string(SZ(a)-SZ(b),'0')+b;
    if(SZ(b)>SZ(a)) a=string(SZ(b)-SZ(a),'0')+a;
    ans.resize(SZ(a));
    for(i = SZ(a)-1; i >= 0; i--)
    {
        int sum=carry+a[i]+b[i]-96;
        ans[i]=(char)(sum%10+'0');
        carry=sum/10;
    }
    if(carry)   ans.insert(0,string(1,carry+'0'));
    ans=cut_leading_zero(ans);
    return ans;
}
string substract(string a,string b)
{
    int borrow=0,i,sub;
    string ans;
    if(SZ(b)<SZ(a)) b=string(SZ(a)-SZ(b),'0')+b;
    for(i = SZ(a)-1; i >= 0; i--)
    {
        sub=a[i]-b[i]-borrow;
        if(sub<0)
        {
            sub+=10;
            borrow=1;
        }
        else borrow=0;
        ans+=sub+'0';
    }
    reverse(all(ans));
    ans=cut_leading_zero(ans);
    return ans;
}
string divide(string a,string b)
{
    string mod,temp,ans="0";
    int i,j;

    for(i = 0; i < SZ(a); i++)
    {
        mod+=a[i];
        mod=cut_leading_zero(mod);
        for(j = 0; j < 10; j++)
        {
            temp=multiply(b,j);
            if(compare(temp,mod)==1)
                break;
        }
        temp=multiply(b,j-1);
        mod=substract(mod,temp);
        ans+=(j-1)+'0';
    }
    mod=cut_leading_zero(mod);
    ans=cut_leading_zero(ans);
    return ans;
}
string divide(string a,int k)
{
    int i,sum=0;
    string ans="0";

    for(i = 0; i < SZ(a); i++)
    {
        sum=(sum*10+(a[i]-'0'));
        ans+=(sum/k)+'0';
        sum=sum%k;
    }
    ans=cut_leading_zero(ans);
    return ans;
}
string mod(string a,string b)
{
    string mod,temp,ans="0";
    int i,j;

    for(i = 0; i < SZ(a); i++)
    {
        mod+=a[i];
        mod=cut_leading_zero(mod);
        for(j = 0; j < 10; j++)
        {
            temp=multiply(b,j);
            if(compare(temp,mod)==1)
                break;
        }
        temp=multiply(b,j-1);
        mod=substract(mod,temp);
        ans+=(j-1)+'0';
    }
    mod=cut_leading_zero(mod);
    ans=cut_leading_zero(ans);
    return mod;
}
int mod(string a,int k)
{
    int i,sum=0;

    for(i = 0; i < SZ(a); i++)
        sum=(sum*10+(a[i]-'0'))%k;
    return sum;
}

int compare(string a,string b)
{
    int i;
    a=cut_leading_zero(a);
    b=cut_leading_zero(b);
    if(SZ(a)>SZ(b)) return 1;   //bigger
    if(SZ(a)<SZ(b)) return -1;  //smaller
    for(i = 0; i < SZ(a); i++)
        if(a[i]>b[i])   return 1;   //bigger
        else if(a[i]<b[i])  return -1; //smaller
    return 0;   //equal
}
string cut_leading_zero(string a)
{
    string s;
    int i;
    if(a[0]!='0')   return a;
    for(i = 0; i < SZ(a)-1; i++)  if(a[i]!='0')   break;
    for(;i < SZ(a); i++)  s+=a[i];
    return s;
}


