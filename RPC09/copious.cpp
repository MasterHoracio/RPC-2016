#include <iostream>
#include <vector>
#include <string>

#define MAX 21

using namespace std;

vector <string> vec[MAX];

int main(){
	int n, m, size, sizestr, ans;
	bool bien;
	string str, aux;
	while(cin>>n){
		for(int i = 0; i < MAX; i++)
			vec[i].clear();
		for(int i = 0; i < n; i++){
			cin >> str;
			vec[str.length()].push_back(str);
		}
		cin>>m;
		for(int i = 0; i < m; i++){
			cin>>str;
			cout<<"Word #"<<i+1<<": "<<str<<"\n";
			ans = 0;
			sizestr = str.length();
			size = vec[sizestr].size();
			for(int j = 0; j < size; j++){//palabras
				bien = true;
				aux = vec[sizestr].at(j);
				for(int k = 0; k < sizestr; k++){//letras
					if(str[k] == '-')
						continue;
					else{
						if(str[k] == aux[k])
							continue;
						else
							bien = false;
					}
				}
				if(bien){
					cout<<aux<<"\n";
					ans++;
				}
			}
			cout<<"Total number of candidate words = "<<ans<<"\n";
		}
	}

	return 0;
}