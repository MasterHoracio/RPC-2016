#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int cases, tam, peso, aux;
    scanf("%d",&cases);
    while(cases--){
        aux = 0;
        scanf("%d %d",&tam,&peso);
        int matrix[tam];
        for(int i = 0; i < tam; i++){
            scanf("%d",&matrix[i]);
        }
        sort(matrix,matrix+tam);
        for(int i = 0; i < tam; i++){
            peso -= matrix[i];
            if(peso >= 0)
                aux++;
            else
                break;
        }
        printf("%d\n",aux);
    }
    return 0;
}
