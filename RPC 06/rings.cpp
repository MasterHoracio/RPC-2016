#include <cstdio>
#include <algorithm>
#include <string>

#define MAX 102

using namespace std;

int Board[MAX][MAX];

int main()
{
    int n, m, ring, len;
    char c;
    string spaces = "...";
    bool cRing;
    while(scanf("%d %d",&n,&m) != EOF){
        getchar();cRing = true;ring = 0;

        for(int i = 0; i < n + 2; i++)
            fill(Board[i],Board[i] + (m + 2), 0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                c = getchar();
                if(c == 'T')
                    Board[i][j] = -1;
            }getchar();
        }

        while(cRing){//calcula los anillos y los asigna
            ring++;
            cRing = false;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(Board[i][j] == -1){//en caso de tener una T
                        if( (Board[i + 1][j] == ring - 1) ||  (Board[i - 1][j] == ring - 1) ||
                            (Board[i][j + 1] == ring - 1) ||  (Board[i][j - 1] == ring - 1) ){//vemos la cruz (esto es para el contorno)
                            Board[i][j] = ring;
                            cRing = true;
                        }
                    }
                }
            }
        }

        if(ring >= 10)
            len = 3;
        else
            len = 2;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(Board[i][j] == 0)
                    printf("%s",spaces.substr(0,len).c_str());
                else if(Board[i][j] >= 10)
                    printf("%s%d",spaces.substr(0,len - 2).c_str(),Board[i][j]);
                else
                    printf("%s%d",spaces.substr(0,len - 1).c_str(),Board[i][j]);
            }printf("\n");
        }
    }
    return 0;
}
