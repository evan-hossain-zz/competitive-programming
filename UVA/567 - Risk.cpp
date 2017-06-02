#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void push(int a);
void pop(void);
int qempty(void);
void bfs(int start, int end);

char grid[22][22], color[22];
int path[22], front, rare, q[22], f;

int main()
{
    int n, i, j, k, l, a, b, kase = 0;
    while(cin >> i)
    {
        memset(grid, 0, sizeof(grid));
        for(k = 1; k <= i; k++)
        {
            cin >> j;
            grid[1][j] = 1;
            grid[j][1] = 1;
        }
        for(l = 2; l <= 19; l++)
        {
            cin >> i;
            for(k = 1; k <= i; k++)
            {
                cin >> j;
                grid[l][j] = 1;
                grid[j][l] = 1;
            }
        }
        cin >> n;
        cout << "Test Set #" << ++kase << "\n";
        while(n--)
        {
            memset(color, 0, sizeof(color));
            memset(path, 0, sizeof(path));
            memset(q, 0, sizeof(q));
            front = rare = 1;
            cin >> a >> b;
            color[a] = 1;
            bfs(a, b);
            printf("%2d to %2d: %d\n", a, b, path[b]);
        }
        printf("\n");
    }
    return 0;
}

void push(int a)
{
    q[rare] = a;
    rare++;
}

void pop(void)
{
    f = q[front];
    front++;
}

int qempty(void)
{
    return rare - front;
}

void bfs(int start, int end)
{
    int i, j;
    push(start);
    path[start] = 0;
    while(qempty())
    {
        pop();
        for(i = 1; i <= 20; i++)
        {
            if(grid[f][i] == 1 && color[i] == 0)
            {
                path[i] = path[f] + 1;
                if(i == end)
                    return;
                color[i] = 1;
                push(i);
            }
        }
    }
}
