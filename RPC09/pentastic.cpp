#include <iostream>
#include <string>

#define MAX 1000000

using namespace std;
int main(){
	int N,pen[5],pos,min,left,rig,ants;
	bool positivo;
	cin>>N;
	for(int i=0;i<N;i++){
		min=MAX;
		for(int j=0;j<5;j++){
			cin>>pen[j];
			if(pen[j]<min){
				min=pen[j];
				pos=j;
			}
		}
		positivo=false;
		while(!positivo){
			if(pos==0){
				left=4;
				rig=1;
			}
			else if(pos==4){
				left=3;
				rig=0;
			}
			else{
				left=pos-1;
				rig=pos+1;
			}
			pen[left]=pen[left]+pen[pos];
			pen[rig]=pen[rig]+pen[pos];
			pen[pos]=pen[pos]*-1;
			min=MAX;
			ants=0;
			for(int j=0;j<5;j++){
				if(pen[j]<min){
				min=pen[j];
				pos=j;
				}
				if(pen[j]>=0)
					ants++;
			}
			if(ants ==5)
				positivo=true;
		}
		cout<<"Pentagon #"<<i+1<<":\n";
		for(int j=0;j<4;j++){
			cout<<pen[j]<<" ";
		}
		cout<<pen[4]<<"\n";
	}

}