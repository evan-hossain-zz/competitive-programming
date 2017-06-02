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
#include <queue>
#include <string.h>

using namespace std;

class ArcadeManao
{
public:
    int shortestLadder(vector <string>, int, int);
};

int col[4] = {1, 0, -1, 0};
int row[4] = {0, 1, 0, -1};

int path[55][55];
queue <int> q;

int ArcadeManao::shortestLadder(vector <string> level, int cr, int cc)
{
    memset(path, 0, sizeof path);
    int nr, nc, r, c, i;
    int M = level[level.size() - 1].size(), N = level.size();
    for(i = 0; i < M; i++)
        q.push(N - 1), q.push(i);
    while(!q.empty())
    {
        r = q.front(), q.pop();
        c = q.front(), q.pop();
        for(int i = 0; i < 4; i++)
        {
            nr = row[i] + r;
            nc = col[i] + c;
            if(nr >= 0 && nr < N && nc >= 0 && nc < M && path[nr][nc] != 1)
            {
                q.push(nr), q.push(nc);
                if(level[nr][nc] == '.')
                    path[nr][nc] = path[r][c] + 1;
                else
                    path[nr][nc] = path[r][c];
                if(nr == cr && nc == cc)
                {
                    int val = path[cr][cc];
                    for(i = 0; i < 25; i++)
                    {
                        for(int j = 0; j < 25; j++)
                            cout << path[i][j] << ' ';
                        cout << endl;
                    }
                    return val;
                }
            }
        }
    }
}


double test0()
{
    string t0[] = {"XXXX....",
                   "...X.XXX",
                   "XXX..X..",
                   "......X.",
                   "XXXXXXXX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 2;
    int p2 = 4;
    ArcadeManao * obj = new ArcadeManao();
    clock_t start = clock();
    int my_answer = obj->shortestLadder(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    string t0[] = {"XXXX",
                   "...X",
                   "XXXX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 1;
    ArcadeManao * obj = new ArcadeManao();
    clock_t start = clock();
    int my_answer = obj->shortestLadder(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 1;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    string t0[] = {"..X..",
                   ".X.X.",
                   "X...X",
                   ".X.X.",
                   "..X..",
                   "XXXXX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 3;
    ArcadeManao * obj = new ArcadeManao();
    clock_t start = clock();
    int my_answer = obj->shortestLadder(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 4;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    string t0[] = {"X"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 1;
    ArcadeManao * obj = new ArcadeManao();
    clock_t start = clock();
    int my_answer = obj->shortestLadder(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 0;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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
    string t0[] = {"XXXXXXXXXX",
                   "...X......",
                   "XXX.......",
                   "X.....XXXX",
                   "..XXXXX..X",
                   ".........X",
                   ".........X",
                   "XXXXXXXXXX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 1;
    ArcadeManao * obj = new ArcadeManao();
    clock_t start = clock();
    int my_answer = obj->shortestLadder(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 2;
    cout <<"Desired answer: " <<endl;
    cout <<"\t" << p3 <<endl;
    cout <<"Your answer: " <<endl;
    cout <<"\t" << my_answer <<endl;
    if (p3 != my_answer)
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

    if (!errors)
        cout <<"You're a stud (at least on the example cases)!" <<endl;
    else
        cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
