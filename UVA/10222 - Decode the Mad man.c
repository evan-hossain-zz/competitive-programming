#include<stdio.h>
#include<string.h>


int main()
{
    char ch[10000];
    int i, l;
    while(gets(ch))
    {
        l = strlen(ch);
        for(i = 0; i < l; ++i)
        {
            switch(ch[i])
            {
            case 'A':
            {
                printf("A");
                break;
            }
            case 'Q':
            {
                printf("[");
                break;
            }
            case 'Z':
            {
                printf(".");
                break;
            }
            case '1':
            {
                printf("1");
                break;
            }
            case '2':
            {
                printf("`");
                break;
            }
            case '3':
            {
                printf("1");
                break;
            }
            case '4':
            {
                printf("2");
                break;
            }
            case '5':
            {
                printf("3");
                break;
            }
            case '6':
            {
                printf("4");
                break;
            }
            case '7':
            {
                printf("5");
                break;
            }
            case '8':
            {
                printf("6");
                break;
            }
            case '9':
            {
                printf("7");
                break;
            }
            case '0':
            {
                printf("8");
                break;
            }
            case '-':
            {
                printf("9");
                break;
            }
            case '=':
            {
                printf("0");
                break;
            }
            case 'W':
            {
                printf("]");
                break;
            }
            case 'E':
            {
                printf("q");
                break;
            }
            case 'R':
            {
                printf("w");
                break;
            }
            case 'T':
            {
                printf("e");
                break;
            }
            case 'Y':
            {
                printf("r");
                break;
            }
            case 'U':
            {
                printf("t");
                break;
            }
            case 'I':
            {
                printf("y");
                break;
            }
            case 'O':
            {
                printf("u");
                break;
            }
            case 'P':
            {
                printf("i");
                break;
            }
            case '[':
            {
                printf("o");
                break;
            }
            case '\\':
            {
                printf("\\");
                break;
            }
            case 'S':
            {
                printf("'");
                break;
            }
            case 'D':
            {
                printf("a");
                break;
            }
            case 'F':
            {
                printf("s");
                break;
            }
            case 'G':
            {
                printf("d");
                break;
            }
            case 'H':
            {
                printf("f");
                break;
            }
            case 'J':
            {
                printf("g");
                break;
            }
            case 'K':
            {
                printf("h");
                break;
            }
            case 'L':
            {
                printf("j");
                break;
            }
            case ';':
            {
                printf("k");
                break;
            }
            case '\'':
            {
                printf("l");
                break;
            }
            case 'X':
            {
                printf("/");
                break;
            }
            case 'q':
            {
                printf("[");
                break;
            }
            case 'z':
            {
                printf(".");
                break;
            }
            case 'C':
            {
                printf("z");
                break;
            }

            case 'V':
            {
                printf("x");
                break;
            }
            case 'B':
            {
                printf("c");
                break;
            }
            case 'N':
            {
                printf("v");
                break;
            }
            case 'M':
            {
                printf("b");
                break;
            }
            case 'w':
            {
                printf("]");
                break;
            }
            case 'e':
            {
                printf("q");
                break;
            }
            case 'r':
            {
                printf("w");
                break;
            }
            case 't':
            {
                printf("e");
                break;
            }
            case 'y':
            {
                printf("r");
                break;
            }
            case 'u':
            {
                printf("t");
                break;
            }
            case 'i':
            {
                printf("y");
                break;
            }
            case 'o':
            {
                printf("u");
                break;
            }
            case 'p':
            {
                printf("i");
                break;
            }
            case ']':
            {
                printf("p");
                break;
            }
            case 's':
            {
                printf("'");
                break;
            }
            case 'd':
            {
                printf("a");
                break;
            }
            case 'f':
            {
                printf("s");
                break;
            }
            case 'g':
            {
                printf("d");
                break;
            }
            case 'h':
            {
                printf("f");
                break;
            }
            case 'j':
            {
                printf("g");
                break;
            }
            case 'k':
            {
                printf("h");
                break;
            }
            case 'l':
            {
                printf("j");
                break;
            }

            case 'x':
            {
                printf("/");
                break;
            }
            case 'c':
            {
                printf("z");
                break;
            }

            case 'v':
            {
                printf("x");
                break;
            }
            case 'b':
            {
                printf("c");
                break;
            }
            case 'n':
            {
                printf("v");
                break;
            }
            case 'm':
            {
                printf("b");
                break;
            }
            case ',':
            {
                printf("n");
                break;
            }
            case '.':
            {
                printf("m");
                break;
            }
            case '/':
            {
                printf(",");
                break;
            }
            default:
            {
                putchar(ch[i]);
                break;
            }
            }
        }
        printf("\n");
    }
    return 0;
}
