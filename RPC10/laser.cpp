#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

int eulers_totient(int n){
	float result = n;
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			while(n % i == 0)
				n /= i;
			result *= (1.0 - (1.0 / float(i)));
		}
	}
	if(n > 1)
		result *= (1.0 - (1.0 / float(n)));
	return (int) result;
}

int main(){
	int cases, N;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		printf("%d\n",eulers_totient(N));
	}
	return 0;
}