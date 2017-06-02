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

struct point
{
    int x, y;
    point () {} point(int a, int b)
    {
        x = a, y = b;
    }
};
template <class T> T sqr(T a)
{
    return a * a;
}
template <class T> T power(T n, T p)
{
    T res = 1;
    for(int i = 0; i < p; i++) res *= n;
    return res;
}
template <class T> double getdist(T a, T b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));   // distance between a and b
}
template <class T> T extract(string s, T ret)
{
    stringstream ss(s);
    ss >> ret;
    return ret;
}
template <class T> string tostring(T n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}
//LL bigmod(LL B,LL P,LL M){LL R=1; while(P>0)  {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
struct fast
{
    fast()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    }
} cincout;

#define MAX 2010
/***********************************THE GRASS IS ALWAYS GREENER ON THE OTHER SIDE***********************************/

int arr[MAX], val[MAX];

class ParenthesesDiv1Medium
{
public:
    int minSwaps(string s, vector <int> L, vector <int> R)
    {
        int j, i;
        clr(arr, 0);
        clr(val, 0);
        for(i = 0; i < SZ(L); i++)
            arr[L[i]]++, arr[R[i]+1]--;
        vector <pair<int,int>> seq;
        for(i = 1; i < SZ(s); i++)
            arr[i] += arr[i-1];
        int extraPos = 0, extraNeg = 0;
        for(i = 0; i < SZ(s); i++)
        {
            if(arr[i] == 0)
            {
                extraPos += s[i] == '(';
                extraNeg += s[i] == ')';
                continue;
            }
            for(j = i+1; j < SZ(s); j++)
            {
                if(arr[j] == 0)
                    break;
            }
            seq.pb(mp(i, j-1));
            i = j-1;
        }
        j = 0;
        for(auto segment: seq)
        {
            for(i = segment.first; i <= segment.second; i++)
                val[j] += s[i] == '('? 1:-1;
            j++;
        }
        int ret = 0, k, mn;
        stack <int> st;
        for(i = 0; i < SZ(seq); i++)
        {
            for(j = i+1; val[i] != 0 && j < SZ(seq); j++)
            {
                if(val[j] == 0) continue;
                if(val[i]>0 == val[j]>0) continue;
                mn = min(abs(val[i]), abs(val[j]));
                int tem = mn;
                for(k = seq[i].first; k <= seq[i].second; k++)
                {
                    if(st.empty())
                    {
                        st.push(k);
                        continue;
                    }
                    if(s[k] == ')' && s[st.top()] == '(')
                        st.pop();
                    else
                        st.push(k);
                }
                while(!st.empty())
                {
                    if(tem && s[st.top()] == '(' && val[i] > 0)
                        val[i]--, s[st.top()] = ')', tem--;
                    else if(tem && s[st.top()] == ')' && val[i] < 0)
                        val[i]--, s[st.top()] = '(', tem--;
                    st.pop();
                }
                tem = mn;
                for(k = seq[j].first; k <= seq[j].second; k++)
                {
                    if(st.empty())
                    {
                        st.push(k);
                        continue;
                    }
                    if(s[k] == ')' && s[st.top()] == '(')
                        st.pop();
                    else
                        st.push(k);
                }
                while(!st.empty())
                {
                    if(tem && s[st.top()] == '(' && val[j] > 0)
                        val[j]--, s[st.top()] = ')', tem--;
                    else if(tem && s[st.top()] == ')' && val[j] < 0)
                        val[j]--, s[st.top()] = '(', tem--;
                    st.pop();
                }
                ret += mn;
            }
            if(val[i]>0)
                mn = min(abs(val[i]), extraNeg);
            else
                mn = min(abs(val[i]), extraPos);
            int tem = mn;
            ret += mn;
            for(k = seq[i].first; k <= seq[i].second; k++)
            {
                if(st.empty())
                {
                    st.push(k);
                    continue;
                }
                if(s[k] == ')' && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(k);
            }
            while(!st.empty())
            {
                if(tem && s[st.top()] == '(' && val[i] > 0)
                    val[i]--, s[st.top()] = ')', tem--, extraNeg--;
                else if(tem && s[st.top()] == ')' && val[i] < 0)
                    val[i]--, s[st.top()] = '(', tem--, extraPos--;
                st.pop();
            }
            if(val[i] != 0)
                return -1;
        }
        for(i = 0; i < SZ(seq); i++)
        {
            for(k = seq[i].first; k <= seq[i].second; k++)
            {
                if(st.empty())
                {
                    st.push(k);
                    continue;
                }
                if(s[k] == ')' && s[st.top()] == '(')
                    st.pop();
                else
                    st.push(k);
            }
            ret += SZ(st)/2;
        }
        return ret;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, vector <int> p1, vector <int> p2, bool hasAnswer, int p3)
{
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}";
    cout << "]" << endl;
    ParenthesesDiv1Medium *obj;
    int answer;
    obj = new ParenthesesDiv1Medium();
    clock_t startTime = clock();
    answer = obj->minSwaps(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p3;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    bool disabled;
    bool tests_disabled;
    all_right = true;
    tests_disabled = false;

    string p0;
    vector <int> p1;
    vector <int> p2;
    int p3;

    // ----- test 0 -----
    disabled = false;
    p0 = ")(";
    p1 = {0,0,0,0};
    p2 = {1,1,1,1};
    p3 = 1;
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
    disabled = false;
    p0 = "(())";
    p1 = {0,2};
    p2 = {1,3};
    p3 = 1;
    all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 2 -----
    disabled = false;
    p0 = "(((())";
    p1 = {0,2};
    p2 = {1,3};
    p3 = 2;
    all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 3 -----
    disabled = false;
    p0 = "(((((((((";
    p1 = {0,2};
    p2 = {1,3};
    p3 = -1;
    all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 4 -----
    disabled = false;
    p0 = "()()()()";
    p1 = {0,0,0,0,2,2,2,4,4,6};
    p2 = {1,3,5,7,3,5,7,5,7,7};
    p3 = 0;
    all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 5 -----
    disabled = false;
    p0 = ")()(()()((())()()()()()()))(()())()()()(";
    p1 = {3,5,17,25,35};
    p2 = {12,10,30,30,38};
    p3 = 3;
    all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, p2, true, p3) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    if (all_right)
    {
        if (tests_disabled)
        {
            cout << "You're a stud (but some test cases were disabled)!" << endl;
        }
        else
        {
            cout << "You're a stud (at least on given cases)!" << endl;
        }
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
