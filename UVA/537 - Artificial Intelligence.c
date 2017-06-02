#include<stdio.h>
#include<string.h>

int main()
{
    char s1[1000], s2[1000], c1, c2;
    double n1, n2;
    int tst, c, l1, l2;
    scanf("%d", &tst);
    for(c = 1; c <= tst; ++c)
    {
        scanf(" %[^\=]=%lf%c  %[^\=]=%lf%c", s1, &n1, &c1, s2, &n2, &c2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        switch(c1)
        {
        case 'M':
        {
            n1 *= 1000000;
            break;
        }
        case 'm':
        {
            n1 /= 1000;
            break;
        }
        case 'k':
        {
            n1 *= 1000;
            break;
        }
        }
        switch(c2)
        {
        case 'M':
        {
            n2 *= 1000000;
            break;
        }
        case 'm':
        {
            n2 /= 1000;
            break;
        }
        case 'k':
        {
            n2 *= 1000;
            break;
        }
        }
        if((s1[l1 - 1] == 'U'
                && s2[l2 - 1] == 'I')
                || (s1[l1-1] == 'I'
                    && s2[l2 - 1] == 'U'))
            printf("Problem #%d\nP=%.2lfW\n\n", c, n1 * n2);
        else if(s1[l1 - 1] == 'U'
                && s2[l2 - 1] == 'P')
            printf("Problem #%d\nI=%.2lfA\n\n", c, n2 / n1);
        else if(s1[l1 - 1] == 'P'
                && s2[l2 - 1] == 'U')
            printf("Problem #%d\nI=%.2lfA\n\n", c, n1 / n2);
        else if(s1[l1 - 1] == 'P'
                && s2[l2 - 1] == 'I')
            printf("Problem #%d\nU=%.2lfV\n\n", c, n1 / n2);
        else if(s1[l1 - 1] == 'I'
                && s2[l2 - 1] == 'P')
            printf("Problem #%d\nU=%.2lfV\n\n", c, n2 / n1);
    }
    return 0;
}
