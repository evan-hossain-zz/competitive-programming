#include<stdio.h>
#include<string.h>
#include<ctype.h>

int alphbt[52];

int main()
{
    register int len, i, l;
    char ch[100000];
    while(gets(ch))
    {
        l = 0;
        for(i = 0; i < 52; ++i)
            alphbt[i] = 0;
        len = strlen(ch);
        for(i = 0; i < len; ++i)
        {
            switch(ch[i])
            {
            case ('a'):
            {
                alphbt[0]++;
                break;
            }
            case ('b'):
            {
                alphbt[1]++;
                break;
            }
            case ('c'):
            {
                alphbt[2]++;
                break;
            }
            case ('d'):
            {
                alphbt[3]++;
                break;
            }
            case ('e'):
            {
                alphbt[4]++;
                break;
            }
            case ('f'):
            {
                alphbt[5]++;
                break;
            }
            case ('g'):
            {
                alphbt[6]++;
                break;
            }
            case ('h'):
            {
                alphbt[7]++;
                break;
            }
            case ('i'):
            {
                alphbt[8]++;
                break;
            }
            case ('j'):
            {
                alphbt[9]++;
                break;
            }
            case ('k'):
            {
                alphbt[10]++;
                break;
            }
            case ('l'):
            {
                alphbt[11]++;
                break;
            }
            case ('m'):
            {
                alphbt[12]++;
                break;
            }
            case ('n'):
            {
                alphbt[13]++;
                break;
            }
            case ('o'):
            {
                alphbt[14]++;
                break;
            }
            case ('p'):
            {
                alphbt[15]++;
                break;
            }
            case ('q'):
            {
                alphbt[16]++;
                break;
            }
            case ('r'):
            {
                alphbt[17]++;
                break;
            }
            case ('s'):
            {
                alphbt[18]++;
                break;
            }
            case ('t'):
            {
                alphbt[19]++;
                break;
            }
            case ('u'):
            {
                alphbt[20]++;
                break;
            }
            case ('v'):
            {
                alphbt[21]++;
                break;
            }
            case ('w'):
            {
                alphbt[22]++;
                break;
            }
            case ('x'):
            {
                alphbt[23]++;
                break;
            }
            case ('y'):
            {
                alphbt[24]++;
                break;
            }
            case ('z'):
            {
                alphbt[25]++;
                break;
            }
            case ('A'):
            {
                alphbt[26]++;
                break;
            }
            case ('B'):
            {
                alphbt[27]++;
                break;
            }
            case ('C'):
            {
                alphbt[28]++;
                break;
            }
            case ('D'):
            {
                alphbt[29]++;
                break;
            }
            case ('E'):
            {
                alphbt[30]++;
                break;
            }
            case ('F'):
            {
                alphbt[31]++;
                break;
            }
            case ('G'):
            {
                alphbt[32]++;
                break;
            }
            case ('H'):
            {
                alphbt[33]++;
                break;
            }
            case ('I'):
            {
                alphbt[34]++;
                break;
            }
            case ('J'):
            {
                alphbt[35]++;
                break;
            }
            case ('K'):
            {
                alphbt[36]++;
                break;
            }
            case ('L'):
            {
                alphbt[37]++;
                break;
            }
            case ('M'):
            {
                alphbt[38]++;
                break;
            }
            case ('N'):
            {
                alphbt[39]++;
                break;
            }
            case ('O'):
            {
                alphbt[40]++;
                break;
            }
            case ('P'):
            {
                alphbt[41]++;
                break;
            }
            case ('Q'):
            {
                alphbt[42]++;
                break;
            }
            case ('R'):
            {
                alphbt[43]++;
                break;
            }
            case ('S'):
            {
                alphbt[44]++;
                break;
            }
            case ('T'):
            {
                alphbt[45]++;
                break;
            }
            case ('U'):
            {
                alphbt[46]++;
                break;
            }
            case ('V'):
            {
                alphbt[47]++;
                break;
            }
            case ('W'):
            {
                alphbt[48]++;
                break;
            }
            case ('X'):
            {
                alphbt[49]++;
                break;
            }
            case ('Y'):
            {
                alphbt[50]++;
                break;
            }
            case ('Z'):
            {
                alphbt[51]++;
                break;
            }
            }

        }
        for(i = 0; i < 52; ++i)
        {
            if(alphbt[i] > l)
                l = alphbt[i];
        }
        for(i = 26; i < 52; ++i)
        {
            if(l == alphbt[i])
                printf("%c", i + 39);
        }
        for(i = 0; i < 26; ++i)
        {

            if(l == alphbt[i])
                printf("%c", i + 97);
        }
        printf(" %d\n", l);
    }
    return 0;
}

