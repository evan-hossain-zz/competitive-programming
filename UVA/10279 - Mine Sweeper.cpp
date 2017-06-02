#include <iostream>
#include <cstdio>

using namespace std;

char grid1[11][11], grid2[11][11];

int out[11][11], n;
int row[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int col[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void count_mines(void);
void print_mined(void);
void print_out(void);

int main()
{
    int games, i, j, brk;
    scanf("%d", &games);
    while(games--)
    {
        brk = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf(" %c", &grid1[i][j]);
                out[i][j] = 0;
            }
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                scanf(" %c", &grid2[i][j]);
        }
        count_mines();
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(grid2[i][j] == 'x' && grid1[i][j] == '*')
                {
                    print_mined();
                    brk = 1;
                    break;
                }
                else if(grid2[i][j] == '.')
                    out[i][j] = -1;
            }
            if(brk)
                break;
        }
        if(!brk)
            print_out();
        if(games)
            printf("\n");
    }
    return 0;
}

void count_mines(void)
{
    int i, j, R, C, p;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid1[i][j] == '*')
            {
                for(p = 0; p < 8; p++)
                {
                    R = i + row[p];
                    C = j + col[p];
                    if((R >= 0 && R < n) &&
                            (C >= 0 && C < n))
                        out[R][C]++;
                }
            }
        }
    }
}

void print_out(void)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(out[i][j] == -1)
                printf(".");
            else
                printf("%d", out[i][j]);
        }
        printf("\n");
    }
}

void print_mined(void)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid1[i][j] == '*')
                printf("*");
            else if(grid2[i][j] == '.')
                printf(".");
            else
                printf("%d", out[i][j]);
        }
        printf("\n");
    }
}
