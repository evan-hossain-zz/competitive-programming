#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <queue>

using namespace std;


int col[55], cost[55];
vector <int> adj[55];
queue <int> q;

class Egalitarianism
{
public:
    int maxDifference(vector <string>, int);
    void dfs(int u)
    {
        col[u] = 1;
        int i, v;
        for(i = 0; i < adj[u].size(); i++)
        {
            v = adj[u][i];
            if(col[v] == 0)
                dfs(v);
        }
    }
    void bfs(int u)
    {
        while(!q.empty()) q.pop();
        int i, v;
        cost[u] = 0;
        q.push(u);
        while(!q.empty())
        {
            u = q.front();
            cout << "u" << u << endl;
            q.pop();
            col[u] = 1;
            for(i = 0; i < adj[u].size(); i++)
            {
                v = adj[u][i];
                if(col[v] == 0)
                {
                    cost[v] = cost[u] + 1;
                    q.push(v);
                }
            }
        }
    }
};



int Egalitarianism::maxDifference(vector <string> isFriend, int d)
{
    int i, j, f = -1;
    for(i = 0; i < isFriend.size(); i++)
        adj[i].clear();
    for(i = 0; i < isFriend.size(); i++)
    {
        for(j = 0; j < isFriend.size(); j++)
        {
            if(isFriend[i][j] == 'Y')
            {
                if(f == -1)
                    f = i;
                adj[i].push_back(j);
            }
        }
    }
    if(f == -1)
        return -1;
    memset(col, 0, sizeof col);
    dfs(f);
    for(i = 0; i < isFriend.size(); i++)
    {
        if(col[i] == 0)
        {
            return -1;
        }
    }
    int mx = 0;
    for(i = 0; i < isFriend.size(); i++)
    {
        memset(col, 0, sizeof col);
        bfs(i);
        for(j = 0; j < isFriend.size(); j++)
            cout << cost[j] << ' ',mx = max(mx, cost[j]);
        cout << endl;
    }
    return mx * d;
}


double test0()
{
    string t0[] = {"NYN",
                   "YNY",
                   "NYN"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 10;
    Egalitarianism * obj = new Egalitarianism();
    clock_t start = clock();
    int my_answer = obj->maxDifference(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 20;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test1()
{
    string t0[] = {"NN",
                   "NN"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    Egalitarianism * obj = new Egalitarianism();
    clock_t start = clock();
    int my_answer = obj->maxDifference(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = -1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test2()
{
    string t0[] = {"NNYNNN",
                   "NNYNNN",
                   "YYNYNN",
                   "NNYNYY",
                   "NNNYNN",
                   "NNNYNN"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1000;
    Egalitarianism * obj = new Egalitarianism();
    clock_t start = clock();
    int my_answer = obj->maxDifference(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 3000;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test3()
{
    string t0[] = {"NNYN",
                   "NNNY",
                   "YNNN",
                   "NYNN"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 584;
    Egalitarianism * obj = new Egalitarianism();
    clock_t start = clock();
    int my_answer = obj->maxDifference(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = -1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test4()
{
    string t0[] = {"NYNYYYN",
                   "YNNYYYN",
                   "NNNNYNN",
                   "YYNNYYN",
                   "YYYYNNN",
                   "YYNYNNY",
                   "NNNNNYN"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 5;
    Egalitarianism * obj = new Egalitarianism();
    clock_t start = clock();
    int my_answer = obj->maxDifference(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 20;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test5()
{
    string t0[] = {"NYYNNNNYYYYNNNN",
                   "YNNNYNNNNNNYYNN",
                   "YNNYNYNNNNYNNNN",
                   "NNYNNYNNNNNNNNN",
                   "NYNNNNYNNYNNNNN",
                   "NNYYNNYNNYNNNYN",
                   "NNNNYYNNYNNNNNN",
                   "YNNNNNNNNNYNNNN",
                   "YNNNNNYNNNNNYNN",
                   "YNNNYYNNNNNNNNY",
                   "YNYNNNNYNNNNNNN",
                   "NYNNNNNNNNNNNNY",
                   "NYNNNNNNYNNNNYN",
                   "NNNNNYNNNNNNYNN",
                   "NNNNNNNNNYNYNNN"
                  }
                  ;
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 747;
    Egalitarianism * obj = new Egalitarianism();
    clock_t start = clock();
    int my_answer = obj->maxDifference(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 2988;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}
double test6()
{
    string t0[] = {"NY",
                   "YN"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 0;
    Egalitarianism * obj = new Egalitarianism();
    clock_t start = clock();
    int my_answer = obj->maxDifference(p0, p1);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p2 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p2 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p2 != my_answer)
    {
        cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
        return -1;
    }
    else
    {
        cout <<"Match :-)" <<endl <<endl;
        return (double)(end-start)/CLOCKS_PER_SEC;
    }
}

int main()
{
    int time;
    bool errors = false;

    time = test0();
    if (time < 0)
        errors = true;

    time = test1();
    if (time < 0)
        errors = true;

    time = test2();
    if (time < 0)
        errors = true;

    time = test3();
    if (time < 0)
        errors = true;

    time = test4();
    if (time < 0)
        errors = true;

    time = test5();
    if (time < 0)
        errors = true;

    time = test6();
    if (time < 0)
        errors = true;

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
