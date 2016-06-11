#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define inf 1000000001

using namespace std;

struct player{
	char name[1000000];
	long long de;
	long long ki;
	long double kda;
};

int main(){
	char str[1000000];
	long long cases,k,d;
	vector<player> p;
	player aux;
	long double kda,a=1,b=3,w =a/b ,l = 0.5,aux2;
	scanf("%lld",&cases);
	getchar();
	while(cases--){
		aux2 = inf;
		for(int i = 0; i < 10; i++){
			gets(str);
			sscanf(str,"%s %lld %lld",aux.name,&k,&d);
			if(d == 0)
				kda = inf;
			else
				kda = (double)k / (double)d;

			if(i > 4){
				if(kda < aux2)
					aux2 = kda;
			}

			aux.de = d;
			aux.ki = k;
			aux.kda = kda;

			p.push_back(aux);

			if(i == 4){//ganadores
				for(int i = 0; i < 5; i++){
					if(p.at(i).kda < w)
						printf("%s plz uninstall\n",p.at(i).name);
				}
				p.clear();
			}

			if(i == 9){//perdedores
				//aux2 = p.at(0).kda;
				for(int i = 0; i < 5; i++){
					if(p.at(i).kda == aux2)
						printf("%s plz uninstall\n",p.at(i).name);
					else{
						if(p.at(i).kda < l)
							printf("%s plz uninstall\n",p.at(i).name);
					}
				}
				p.clear();
			}
		}
	}
}