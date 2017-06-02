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
#include <string.h>

//{"_X_X_",
// "XX__X",
// "_XXX_",
// "___X_",
// "_X_XX"}
using namespace std;

class EllysFigurines
{
public:
    int getMoves(vector <string>, int, int);
};

int row[20], col[20];

int EllysFigurines::getMoves(vector <string> board, int R, int C)
{
    int i, j, k, mx, mr, mc, sum,sr, sc, dr, dc;
    int r = board.size();
    int c = board[0].size();
    int cnt = 0;
    while(1)
    {
        cout << endl;
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                cout << board[i][j];
                if(board[i][j] == 'X')
                {
                    row[i]++;
                    col[j]++;
                }
            }
            cout << endl;
        }
        for(i = 0; i < r; i++)
            if(row[i])
                break;
        if(i == r)
            return cnt;
//        for(i = 0; i < r; i++)
//            cout << row[i] << ' ';
//        cout << endl;
//        for(i = 0; i < c; i++)
//            cout << col[i] << ' ';
//        cout << endl;
        mr = mc = sr = sc = dr = dc = 0;
        for(i = 0; i <= r - R; i++)
        {
            sum = 0;
            for(j = i; j < i + R; j++)
                sum += row[j];
            if(sum > mr)
            {
                mr = sum;
                sr = i, dr = j;
            }
        }
        for(i = 0; i <= c - C; i++)
        {
            sum = 0;
            for(j = i; j < i + C; j++)
                sum += col[j];
            if(sum > mc)
            {
                mc = sum;
                sc = i, dc = j;
            }
        }
        if(mr > mc)
        {
            for(i = sr; i < dr; i++)
                for(j = 0; j < c; j++)
                    board[i][j] = '.';
        }
        else
        {
            for(i = sc; i < dc; i++)
                for(j = 0; j < r; j++)
                    board[j][i] = '.';
        }
        cnt++;
    }
}


double test0()
{
    string t0[] = {".X.X.",
                   "XX..X",
                   ".XXX.",
                   "...X.",
                   ".X.XX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 2;
    EllysFigurines * obj = new EllysFigurines();
    clock_t start = clock();
    int my_answer = obj->getMoves(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 3;
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
    string t0[] = {".X.X.",
                   "XX..X",
                   ".X.X.",
                   "...X.",
                   ".X.XX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 2;
    int p2 = 2;
    EllysFigurines * obj = new EllysFigurines();
    clock_t start = clock();
    int my_answer = obj->getMoves(p0, p1, p2);
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
double test2()
{
    string t0[] = {"XXXXXXX"};
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 2;
    int p2 = 3;
    EllysFigurines * obj = new EllysFigurines();
    clock_t start = clock();
    int my_answer = obj->getMoves(p0, p1, p2);
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
double test3()
{
    string t0[] = {"XXXXX",
                   "X....",
                   "XXX..",
                   "X....",
                   "XXXXX"
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 1;
    EllysFigurines * obj = new EllysFigurines();
    clock_t start = clock();
    int my_answer = obj->getMoves(p0, p1, p2);
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
double test4()
{
    string t0[] = {"XXX..XXX..XXX.",
                   ".X..X....X...X",
                   ".X..X....X...X",
                   ".X..X....X...X",
                   ".X...XXX..XXX.",
                   "..............",
                   "...XX...XXX...",
                   "....X......X..",
                   "....X....XXX..",
                   "....X......X..",
                   "...XXX..XXX..."
                  };
    vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
    int p1 = 1;
    int p2 = 2;
    EllysFigurines * obj = new EllysFigurines();
    clock_t start = clock();
    int my_answer = obj->getMoves(p0, p1, p2);
    clock_t end = clock();
    delete obj;
    cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
    int p3 = 7;
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
