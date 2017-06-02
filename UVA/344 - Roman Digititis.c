#include<stdio.h>

int main()
{
    int n, j, c, l, x, v, i, res, rem, input;
    while(scanf("%d", &input) == 1 && input != 0)
    {
        i = 0; v = 0; x = 0; l = 0; c = 0;
        rem = 0;res = 0;
        for(n = 1; n <= input; n++)
        {
            if (n >= 1 && n < 4)
            {
                res = n / 1;

                for (j = 1; j <= res; j++)
                    i++;

            }

            else if (n >= 4 && n < 5)
            {
                res = n / 4;

                for (j = 1; j <= res; j++)
                {
                    i++;
                    v++;
                }

            }
            else if (n >= 5 && n < 9)
            {
                res = n / 5;

                for (j = 1; j <= res; j++)
                {
                    v++;
                    i++;
                }

            }
            else if (n >= 9 && n < 10)
            {
                res = n / 9;;

                for (j = 1; j <= res; j++)
                {
                    i++;
                    x++;
                }

            }
            else if (n == 10)
            {
                res = n / 10;

                for (j = 1; j <= res; j++)
                    x++;

            }
            else if (n > 10 && n < 40)
            {
                res = n / 10;

                for (j = 1; j <= res; j++)
                    x++;

            }

            else if (n >= 40 && n < 50)
            {
                res = n / 40;

                for (j = 1; j <= res; j++)
                {
                    x++;
                    l++;
                }

            }
            else if (n >= 50 && n < 90)
            {
                res = n / 50;

                for (j = 1; j <= res; j++)
                    l++;

            }
            else if (n >= 90 && n < 100)
            {
                res = n / 90;

                for (j = 1; j <= res; j++)
                {
                    x++;
                    c++;
                }

            }
            else if (n == 100)
            {
                res = n / 100;

                for (j = 1; j <= res; j++)
                    c++;

            }

        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", input, i, v, x, l, c);
    }
}
