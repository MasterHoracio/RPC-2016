#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n,aux;
	char letras[10][10];
	char giro[10][10];
	char resultado[10][10];
	char str[110];
	bool mat,b;
	bool check[10][10];
	string sresultado;

	while(scanf("%d",&n) != EOF){
		mat = true;b = true;
		sresultado = "";
		if(n == 0){
			mat = false;
		}
		else{

			getchar();
			for(int i = 0; i < n; i ++){
				for(int j = 0; j < n; j++){
					letras[i][j] = getchar();
				}getchar();
			}
			gets(str);

			for(int i = 0; i < n; i++)
				fill(check[i],check[i]+n,false);

			aux = 0;

			for(int i = 0; i < 4; i++){//giro
				int w = (n - 1);
				if(mat){
					for(int j = 0; j < n; j++){
						for(int k = 0; k < n; k++){
							giro[k][w] = letras[j][k];
							if(letras[j][k] == '.'){
								resultado[j][k] = str[aux++];
								if(check[j][k] == true)
									b = false;
								check[j][k] = true;
							}
						}
						w--;
					}
					mat = false;
				}
				else{
					for(int j = 0; j < n; j++){
						for(int k = 0; k < n; k++){
							letras[k][w] = giro[j][k];
							if(giro[j][k] == '.'){
								if(check[j][k] == true)
									b = false;
								resultado[j][k] = str[aux++];
								check[j][k] = true;
							}
						}
						w--;
					}
					mat=true;
				}
			}
			mat = true;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(check[i][j] == false){
						mat = false;
						break;
					}
				}
				if(!mat)
					break;
			}
			if(n == 1){
				if(letras[0][0] == '.'){
					mat = true;
					sresultado += str[0];
				}
				else
					mat = false;
			}
		}

		if(!mat || b == false)
			printf("invalid grille\n");
		else{
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					sresultado += resultado[i][j];
				}
			}
			printf("%s\n",sresultado.c_str());
		}

	}
	return 0;
}