#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int cases, n; 
	scanf("%d",&cases);
	for(int i = 0; i < cases;i++){
		scanf("%d",&n);
		int spree[n];
		for(int j = 0; j < n; j++)
			scanf("%d",&spree[j]);
		if(n == 1){
			printf("Spree #%d: %d\n",i+1,spree[0]);
			continue;
		}
		int compute[n][n/2+1];
		for(int j = 0; j < n; j++)
			fill(compute[j],compute[j]+(n/2)+1,0);

		compute[0][1] = spree[0];

		for(int j = 1; j < n; j++)
			for(int k = 1; k <= max(1,(j+1)/2); k++)
				compute[j][k] = max(compute[j][k-1],max(compute[j-1][k],compute[j-1][k-1]+spree[j]));
			
		printf("Spree #%d: %d\n",i+1,compute[n-1][n/2]);

	}

	return 0;
}