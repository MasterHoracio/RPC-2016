#include <cstdio>
#include <cmath>

#define MAX 2505
#define error 1.0e-6

double fact[MAX];

using namespace std;

void compute(){
	fact[0] = 0.0;
	for(int i = 1; i <= MAX; i++)
		fact[i] = fact[i - 1] + log(i);
}

double multiplica(int n){
	double acum = 0.0;
	int pos;
	for(int i = 0; i < n; i++){
		scanf("%d",&pos);
		acum += fact[pos];
	}
	return acum;
}

bool isLarger(double a, double b, double c){
	if(a - b > error && a - c > error)
		return true;
	return false;
}


int main(){
	int cases, a, b, c;
	double proda, prodb, prodc;

	compute();

	scanf("%d",&cases);

	for(int i = 0; i < cases; i++){

		scanf("%d %d %d",&a,&b,&c);

		proda = multiplica(a);
		prodb = multiplica(b);
		prodc = multiplica(c);

		printf("Case #%d: ",i+1);

		if(isLarger(proda,prodb,prodc))
			printf("A\n");
		else if(isLarger(prodb,proda,prodc))
			printf("B\n");
		else if(isLarger(prodc,prodb,proda))
			printf("C\n");
		else
			printf("TIE\n");

	}

	return 0;
}