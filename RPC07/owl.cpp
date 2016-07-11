#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	char str[10];
	int len;
	bool zero;
	while(gets(str)){
		zero = true;
		if(str[0] == 'E')
			break;
		len = strlen(str);
		for(int i = len - 1; i >= 0; i--){
			if(str[i] != '0'){
				str[i]--;
				break;
			}
		}
		for(int i = 0; i < len; i++)
			if(str[i] != '0')
				zero = false;
		if(zero)
			printf("0\n");
		else
			printf("%s\n",str);
	}

}