#include <cstdio>
#include <algorithm>

#define MAX 110

using namespace std;

int camino[MAX][MAX];
int costo[MAX][MAX];

typedef struct point{
	int x, y;
}P;

int main(){
	int cases, rows, columns, ans;
	char ca[4];
	scanf("%d",&cases);
	ans = 0;
	while(cases--){
		scanf("%d %d",&rows,&columns);
		ans++;
		camino[0][0] = 0;
		camino[rows-1][columns-1] = 0;
		getchar();
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < columns; j++){
				if(i == 0 && j == 0)
					scanf("%c",ca);
				else if(i == (rows - 1) && j == (columns - 1) )
					scanf("%c",ca);
				else
					scanf("%d",&camino[i][j]);
			}
		}
		getchar();

		for(int i = rows - 1; i >= 0; i--)
			for(int j = columns - 1; j >= 0; j--)
				costo[i][j] = camino[i][j] + max( (j + 1 < columns ? costo[i][j+1]: 0), (i + 1 < rows ? costo[i+1][j]: 0) );

		printf("Game Board #%d: %d\n",ans,costo[0][0]);
	}
	return 0;
}