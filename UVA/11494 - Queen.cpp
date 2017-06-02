#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int sr, sc, er, ec;
    while(scanf("%d %d %d %d", &sc, &sr, &ec, &er) == 4)
    {
        if(!(sc | sr | ec | er))
            break;
        if(sc == ec && sr == er)
            printf("0\n");
        else if((sc == ec || sr == er)\
        || (abs(sc - ec) == abs(sr - er)))
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
