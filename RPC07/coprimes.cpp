#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int gcd(int a,int b){
   return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));
}

int main(){
	int len, n1, n2, mcd, a, b;
	long long cases, ans = 0;
	char str[20];
	string l, r;
	bool relative;
	scanf("%lld",&cases);
	getchar();
	while(cases--){
		ans++;
		relative = false;
		gets(str);
		len = strlen(str);
		for(int i = 1; i < len; i++){
			l = r = "";
			for(int j = 0; j < i; j++)
				l += str[j];
			for(int j = i; j < len; j++)
				r += str[j];
			n1 = stoi(l);
			n2 = stoi(r);
			mcd = gcd(n1,n2);
			if(mcd == 1){
				relative = true;
				break;
			}
		}
		printf("Ticket #%lld:\n",ans);
		if(relative)
			printf("%d %d\n",n1,n2);
		else
			printf("Not relative\n");
	}
	return 0;
}