#include<stdio.h>
#include<string.h>

int main()
{
    char ch, dummy;
    int tst, i = 0;
    while(scanf("%d", &tst) == 1 && tst != 0)
    {
        printf("Case %d:\n#include<string.h>\n#include<stdio.h>\nint main()\n{", ++i);
        while(tst--)
        {
            printf("\nprintf(\"");
            dummy = getchar();
            if(dummy != '\n')
                putchar(dummy);
            while((ch = getchar()) != '\n')
            {
                if(ch == '\"')
                    printf("\\\"");
                else if(ch == '\\')
                    printf("\\\\");
                else
                    putchar(ch);
            }
            printf("\\n\");");
        }
        printf("\nprintf(\"\\n\");\nreturn 0;\n}\n");
    }
    return 0;
}
