#include <cstdio>

using namespace std;

int main(){
	int cases, num, ant;
	bool bien;
	scanf("%d",&cases);
	while(cases--){
		bien = true;
		scanf("%d",&ant);
		for(int i = 1; i < 5; i++){
			scanf("%d",&num);
			if(num != ant + 1)
				bien = false;
			ant = bien;
		}
		if(!bien)
			printf("N\n");
		else
			printf("Y\n");
	}

	return 0;
}