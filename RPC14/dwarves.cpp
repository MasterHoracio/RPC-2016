#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector <int> Grafo[10005];

void addEdge(int nodo1, int nodo2){
	Grafo[nodo1].push_back(nodo2);
}

void moveVertex(int current, set <int> &source, set <int> &destination){
	source.erase(current);
	destination.insert(current);
}

bool DFS(int current, set <int> &nodos, set <int> &explorados, set <int> &visitados){
	moveVertex(current, nodos, explorados);

	for(int i = 0; i < Grafo[current].size(); i++){

		if(visitados.find(Grafo[current].at(i)) != visitados.end()){
			continue;
		}

		if(explorados.find(Grafo[current].at(i)) != explorados.end()){
			return true;
		}

		if(DFS(Grafo[current].at(i),nodos,explorados,visitados)){
			return true;
		}

	}
	moveVertex(current, explorados, visitados);
	return false;
}

bool hasCycle(int dwarve){
	int current;
	set <int> nodos;
	set <int> explorados;
	set <int> visitados;
	set <int>::iterator it;

	for(int i = 1; i < dwarve; i++)
		nodos.insert(i);

	while(nodos.size() > 0){
		it = nodos.begin();
		current = *it;
		if(DFS(current,nodos,explorados,visitados)){
			return true;
		}
	}
	return false;
}

int main(){
	map <string, int> dwarves;
	int statements, dwarve;
	string nodo1, s, nodo2;

	cin >> statements;

	dwarve = 1;

	for(int i = 0; i < statements; i++){

		cin >> nodo1 >> s >> nodo2;

		if(!dwarves[nodo1]){
			dwarves[nodo1] = dwarve;
			dwarve++;
		}if(!dwarves[nodo2]){
			dwarves[nodo2] = dwarve;
			dwarve++;
		}

		if(s == ">")
			addEdge(dwarves[nodo1],dwarves[nodo2]);
		else
			addEdge(dwarves[nodo2],dwarves[nodo1]);
	}

	if(hasCycle(dwarve))
		cout << "impossible" << "\n";
	else
		cout << "possible" << "\n";

	return 0;
}