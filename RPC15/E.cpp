#include <cstdio>
#include <algorithm>

#define MAX 100010

using namespace std;

int main(){
	int students, ratings[MAX], pos, ans;

	scanf("%d",&students);

	for(int i = 0; i < students; i++)
		scanf("%d",&ratings[i]);

	sort(ratings, ratings + students);

	pos = (students / 2) - 1;

	ans = ratings[pos] + ratings[pos + 1];

	for(int i = 1; i < (students / 2); i++)
		if(ratings[pos - i] + ratings[(pos + 1) + i] < ans)
			ans = ratings[pos - i] + ratings[(pos + 1) + i];

	printf("%d\n",ans);
	
	return 0;
}