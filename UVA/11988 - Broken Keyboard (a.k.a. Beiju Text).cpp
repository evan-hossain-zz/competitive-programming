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
#define infinity 2147483647

///int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};
///int row[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using namespace std;

char arr[100005];
int now;

struct node
{
    char x;
    node *next;
};

node *mh;

void print(void);
void home(void);

int main()
{
    node *head, *tail;
    char c;
    mh = NULL;
    while(scanf("%c", &c) == 1)
    {
        if(c == '[')
            home();
        else if(c == ']')
            continue;
        else if(c == '\n')
        {
            print();
        }
        else
            arr[now++] = c;
    }
    return 0;
}

void home(void)
{
    node *head, *tail;
    head = tail = NULL;
    char c;
    while(scanf("%c", &c) == 1)
    {
        if(c == '[')
        {
            if(head != NULL)
            {
                tail ->next = mh;
                mh = head;
            }
            home();
            return;
        }
        if(c == ']')
        {
            if(head != NULL)
            {
                tail ->next = mh;
                mh = head;
            }
            return;
        }
        if(c == '\n')
        {
            if(head != NULL)
            {
                tail ->next = mh;
                mh = head;
            }
            print();
            return;
        }
        node *temp = new node;
        if(head == NULL)
        {
            temp ->x = c;
            temp ->next = NULL;
            head = tail = temp;
        }
        else
        {
            temp ->x = c;
            temp ->next = NULL;
            tail ->next = temp;
            tail = temp;
        }
    }
}

void print(void)
{
    while(mh)
        {
            printf("%c", mh ->x);
            mh = mh -> next;
        }
    for(int i = 0; i < now; i++)
        {
            printf("%c", arr[i]);
            arr[i] = 0;
        }
    printf("\n");
    mh = NULL;
    now = 0;
    return;
}
