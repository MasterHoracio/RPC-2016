#include <cstdio>
#include <cmath>

typedef long long ll;

using namespace std;

int main(){
	ll cases, N, K, sq, ans;
	scanf("%lld",&cases);
	while(cases--){
		scanf("%lld %lld",&N,&K);
		ans = 0;
		sq = floor(sqrt(N));
		for(ll i = 1; i <= sq; i++){
			if(N % i == 0){
				if(i % K != 0)
					ans += i;
				if( (N/i) % K != 0 && N/i != i)
					ans += N/i;
			}
		}
		printf("%lld\n",ans);	
	}
	return 0;
}