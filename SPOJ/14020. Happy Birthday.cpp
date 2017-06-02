#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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

#define out freopen("output.txt", "w", stdout);
#define in freopen("input.txt", "r", stdin);
#define pub push_back
#define pob pop_back
#define infinity 999999999
#define LL long long
#define Pi acos(-1)
#define SZ 1000000

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};
///int col[4] = {1, 0, -1, 0};
///int row[4] = {0, 1, 0, -1};

using namespace std;


//int main()
//{
//    int d, m;
//    while(scanf("%d %d", &d, &m) == 2)
//    {
//        if(d == 7 && m == 1)
//            printf("Happy Birthday To Shipu.\n");
//        else if(d == 29 && m == 4)
//            printf("Happy Birthday To Dipu Sir.\n");
//        else if(d == 30 && m == 5)
//            printf("Happy Birthday To Fahad vai.\n");
//        else if(d == 21 && m == 6)
//            printf("Happy Birthday To Sufian.\n");
//        else if(d == 11 && m == 12)
//            printf("Happy Birthday To Alim.\n");
//        else
//            printf("This is an ordinary day.\n");
//    }
//    return 0;
//}


#include<stdio.h>
int main()
{
    out;
    int d,m;
    while((scanf("%d%d",&d,&m))==2)
    {
        if( (d==7)&&(m==1) )
        {
            printf("Happy Birthday To Shipu.\n");
        }
        else if( (d==29)&&(m==4) )
        {
            printf("Happy Birthday To Dipu Sir.\n");
        }
        else if( (d==30)&&(m==5) )
        {
            printf("Happy Birthday To Fahad vai.\n");
        }
        else if( (d==21)&&(m==6) )
        {
            printf("Happy Birthday To Sufian.\n");
        }
        else if( (d==11)&&(m==12) )
        {
            printf("Happy Birthday To Alim.\n");
        }
        else
        {
            printf("This is an ordinary day.\n");
        }
    }

    return 0;
}

