#include <stdio.h>
#include <string.h>

char grid[10][10];
char a, b;
int front, rare, p, q, arr[129], qu[150], cnt, r, c, path[10][10];
void push(int m, int n);

int main()
{
    arr['a'] = 1, arr['b'] = 2, arr['c'] = 3, arr['d'] = 4,\
    arr['e'] = 5, arr['f'] = 6, arr['g'] = 7, arr['h'] = 8;
    while(scanf(" %c%d %c%d", &a, &p, &b, &q) == 4)
    {
        char grid[10][10] = {0};
        memset(path, 0, sizeof(path));
        memset(qu, 0, sizeof(qu));
        front = rare = 1;
        r = arr[a];
        c = p;
        printf("To get from %c%d to %c%d takes ", a, p, b, q);
        path[r][c] = 0;
        push(r, c);
        grid[r][c] = 1;
        while(front != rare)
        {
            r = qu[front];
            c = qu[front + 1];
            front += 2;
            if(r == arr[b] && c == q) break;
            if(r - 1 >= 1 && c + 2 < 9)
            {
                if(grid[r - 1][c + 2] == 0)
                {
                    push(r - 1, c + 2);
                    grid[r - 1][c + 2] = 1;
                    path[r - 1][c + 2] = path[r][c] + 1;
                }
            }
            if(r - 1 >= 1 && c - 2 >= 1)
            {
                if(grid[r - 1][c - 2] == 0)
                {
                    push(r - 1, c - 2);
                    grid[r - 1][c - 2] = 1;
                    path[r - 1][c - 2] = path[r][c] + 1;
                }
            }
            if(r - 2 >= 1 && c - 1 >= 1)
            {
                if(grid[r - 2][c - 1] == 0)
                {
                    push(r - 2, c - 1);
                    grid[r - 2][c - 1] = 1;
                    path[r - 2][c - 1] = path[r][c] + 1;
                }
            }
            if(r - 2 >= 1 && c + 1 < 9)
            {
                if(grid[r - 2][c + 1] == 0)
                {
                    push(r - 2, c + 1);
                    grid[r - 2][c + 1] = 1;
                    path[r - 2][c + 1] = path[r][c] + 1;
                }
            }
            if(r + 2 < 9 && c - 1 >= 1)
            {
                if(grid[r + 2][c - 1] == 0)
                {
                    push(r + 2, c - 1);
                    grid[r + 2][c - 1] = 1;
                    path[r + 2][c - 1] = path[r][c] + 1;
                }
            }
            if(r + 2 < 9 && c + 1 < 9)
            {
                if(grid[r + 2][c + 1] == 0)
                {
                    push(r + 2, c + 1);
                    grid[r + 2][c + 1] = 1;
                    path[r + 2][c + 1] = path[r][c] + 1;
                }
            }
            if(r + 1 < 9 && c + 2 < 9)
            {
                if(grid[r + 1][c + 2] == 0)
                {
                    push(r + 1, c + 2);
                    grid[r + 1][c + 2] = 1;
                    path[r + 1][c + 2] = path[r][c] + 1;
                }
            }

            if(r + 1 < 9 && c - 2 >= 1)
            {
                if(grid[r + 1][c - 2] == 0)
                {
                    push(r + 1, c - 2);
                    grid[r + 1][c - 2] = 1;
                    path[r + 1][c - 2] = path[r][c] + 1;
                }
            }
        }
        printf("%d knight moves.\n", path[arr[b]][q]);
    }
    return 0;
}

void push(int m, int n)
{
    qu[rare] = m;
    qu[rare + 1] = n;
    rare += 2;
}
