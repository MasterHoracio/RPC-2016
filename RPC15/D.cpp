#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(string operation, int operand, int value){
	if(operation == "ADD")
		return value + operand;
	else if(operation == "SUBTRACT")
		return value - operand;
	else if(operation == "MULTIPLY")
		return value * operand;
	else
		return value / operand;
}

int main(){
	int OP, operand, ans, res, ant;
	string operation;
	vector < pair<string,int> > trick;

	cin >> OP;

	ans = 0;

	for(int i = 0; i < OP; i++){
		cin >> operation >> operand;
		trick.push_back(make_pair(operation,operand));
	}

	for(int i = 1; i <= 100; i++){
		res = i;
		for(int j = 0; j < trick.size(); j++){
			ant = res;
			res = solve(trick[j].first, trick[j].second, res);
			if(res < 0){
				ans++;
				break;
			}if(trick[j].first == "DIVIDE"){
				if((res * trick[j].second) != ant){
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << "\n";


	return 0;
}