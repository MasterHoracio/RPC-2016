#include <cstdio>

using namespace std;

int main(){
	long long ans = 1, money, sum = 0, ndiv;
	while(scanf("%lld",&money) && money != 0){
		sum += money;
		if(sum >= 50){
			ndiv = sum / 50;
			if(ndiv == 1)
				printf("Input #%lld: Sweet!\n",ans);
			else
				printf("Input #%lld: Totally Sweet!\n",ans);
			sum %= 50;
		}
		ans++;
	}
	return 0;
}