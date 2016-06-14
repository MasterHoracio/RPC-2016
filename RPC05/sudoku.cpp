#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int cases, n, cuadro, cua, pivx, pivy, ax,ay;
    bool bien;
    vector<int> vec;

    scanf("%d",&cases);

    while(cases--){
        scanf("%d",&n);
        bien = true;
        int matrix[n][n];
        for(int i = 0; i < n; i++){//renglones
            for(int j = 0; j < n; j++){//columnas
                scanf("%d",&matrix[i][j]);
                //checamos renglones
                if( find(vec.begin(),vec.end(),matrix[i][j]) == vec.end())//si no lo encontro
                    vec.push_back(matrix[i][j]);
                else//si lo encontro
                    bien = false;
            }
            vec.clear();
        }
        if(!bien)//si estan mal los renglones
            printf("no\n");
        else{
            //checamos columnas
            vec.clear();
            for(int i = 0; i < n; i ++){
                for(int j = 0; j < n; j++){
                    if( find(vec.begin(),vec.end(),matrix[j][i]) == vec.end())//si no lo encontro
                        vec.push_back(matrix[j][i]);
                    else{//si lo encontro
                        bien = false;
                        break;
                    }
                }
                vec.clear();
            }
            if(!bien)//si estan mal las columnas
                printf("no\n");
            else{
                //checamos los cuadros
                vec.clear();
                cuadro = (int) sqrt(n);
                cua = n / cuadro;
                pivx = pivy = 0;
                for(int i = 0; i < cua; i++){//para cada renglon (en cuadro)
                    for(int j = 0; j < cua; j++){//para cada columna
                        pivx = j * cua;
                        pivy = i * cua;
                        ax = pivx + cua;
                        ay = pivy + cua;
                        //busca en cuadro
                        for(pivy = i * cua;pivy < ay;pivy++){
                            for(pivx = j * cua; pivx < ax; pivx++){
                                if( find(vec.begin(),vec.end(),matrix[pivy][pivx]) == vec.end())//si no lo encontro
                                    vec.push_back(matrix[pivy][pivx]);
                                else{//si lo encontro
                                    bien = false;
                                    break;
                                }
                            }
                        }
                        vec.clear();
                    }
                }
                if(!bien)
                    printf("no\n");
                else
                    printf("yes\n");
            }

        }
    }
    return 0;
}
