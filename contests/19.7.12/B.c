#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char in[150], out[150];
    int i, j, l, m, n, jav, cpp, err, boro, undr;
    while(scanf("%s", in) == 1)
    {
        l = strlen(in);
        jav = cpp = boro = undr = err = 0;
        for(i = 0, j = 0; i < l; i++)
        {
            if(in[i] == '_')
            {
                if(i == 0 || i == (l - 1) || boro == 1 || jav == 1)
                {
                    err = 1;
                    break;
                }
                boro = 1;
                cpp = 1;
            }
            else if(in[i] >= 'A' && in[i] <= 'Z')
            {
                if(i == 0 || cpp == 1)
                {
                    err = 1;
                    break;
                }
                undr = 1;
                jav = 1;
            }
            else if(boro == 1)
            {
                out[j++] = toupper(in[i]);
                boro = 0;
            }
            else
                out[j++] = in[i];
            if(undr == 1)
            {
                out[j++] = '_';
                out[j++] = tolower(in[i]);
                undr = 0;
            }
        }
        if(err == 1)
            printf("Error!\n");
        else
        {
            out[j] = 0;
            printf("%s\n", out);
        }
    }
    return 0;
}
