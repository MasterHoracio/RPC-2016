#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#define MAX 1005

using namespace std;

struct pos{
	int x, y;
};

char frameUno[MAX][MAX], frameDos[MAX][MAX], resultado[MAX][MAX];

int main(){
	int renglones, columnas;
	char falcon[10], c;
	vector<pos> first, second, third;
	pos temp, primero, segundo, diferencia;
	while(scanf("%d %d %s",&renglones,&columnas,falcon)){
		getchar(); c = falcon[1];

		if(renglones == 0 && columnas == 0 && strlen(falcon) == 1)
			break;

		for(int i = 0; i < renglones; i++){
			for(int j = 0; j < columnas; j++){
				frameUno[i][j] = getchar();
				if(frameUno[i][j] == c){
					temp.x = j; temp.y = i;
					first.push_back(temp);
				}
			}getchar();
		}getchar();

		for(int i = 0; i < renglones; i++){
			for(int j = 0; j < columnas; j++){
				frameDos[i][j] = getchar();
				if(frameDos[i][j] == c){
					temp.x = j; temp.y = i;
					second.push_back(temp);
				}
			}getchar();
		}getchar();

		primero = first.front(); segundo = second.front();
		diferencia.x = segundo.x - primero.x;
		diferencia.y = segundo.y - primero.y;

		for(int i = 0; i < second.size(); i++){
			temp.x = second.at(i).x + diferencia.x;
			temp.y = second.at(i).y + diferencia.y;
			third.push_back(temp);
		}

		for(int i = 0; i < renglones; i++){
			for(int j = 0; j < columnas; j++){
				if(frameUno[i][j] == c)
					resultado[i][j] = frameDos[i][j];
				else
					resultado[i][j] = frameUno[i][j];
			}
		}

		for(int i = 0; i < third.size(); i++)
			if(third.at(i).x < columnas && third.at(i).x >= 0 && third.at(i).y < renglones && third.at(i).y >= 0)
				resultado[third.at(i).y][third.at(i).x] = c;
		
		for(int i = 0; i < renglones; i++){
			for(int j = 0; j < columnas; j++){
				printf("%c",resultado[i][j]);
			}printf("\n");
		}printf("\n");

		first.clear();
		second.clear();
		third.clear();
	}

	return 0;
}