#include<stdio.h>
#include<string.h>

int main()
{
    char cnt[100];
    int i, wrd, l;
    while(scanf(" %[^\n]", cnt) == 1)
    {
        wrd = 0;
        l = strlen(cnt);
        for(i = 0; i < l; i++)
        {
            if(((cnt[i] >= 'a' && cnt[i] <= 'z') ||
              (cnt[i] >= 'A' && cnt[i] <= 'Z')) &&
              !((cnt[i + 1] >= 'a' && cnt[i + 1] <= 'z') ||
              (cnt[i + 1] >= 'A' && cnt[i + 1] <= 'Z')))
                wrd++;
        }
        printf("%d\n", wrd);
    }
    return 0;
}
