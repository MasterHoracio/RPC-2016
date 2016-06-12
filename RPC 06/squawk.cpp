#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n, m, s, t, x, y;
    long long count;

    while(scanf("%d %d %d %d",&n,&m,&s,&t) != EOF){

        count = 0;

        int Grafo[n][n];
        for(int i = 0; i < n; i++)
            fill(Grafo[i], Grafo[i] + n, 0);

        for(int i = 0; i < m; i++){
            scanf("%d %d",&x,&y);
            Grafo[x][y] = 1;
            Grafo[y][x] = 1;
        }

        long long nodos[t + 1][n];

        for(int i = 0; i <= t; i++)
            fill(nodos[i], nodos[i] + n, 0);

        nodos[0][s] = 1;//nodo de inicio

        for(int i = 1; i <= t; i++)//para cada minuto
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                        nodos[i][j] += nodos[i - 1][k] * Grafo[j][k];//calculamos numero de nodos infectados

        /* EXPLICACION:
            iniciamos en la posicion [0][s] de los minutos con: 1
            ¿porque? R = aqui comienza el recorrido
            desde el inicio
            Para cada minto (iniciamos con 1):
                calcular la sumatoria de el numero de nodos conectados dentro del grafo 
                (es necesario multiplicar los nodos anteriores con la matriz del grafo)
                esto sirve para calcular el numero de computadoras con virus
        */

        for(int i = 0; i < n; i++)//al final sumamos las conexiones totales
            count += nodos[t][i];

        printf("%lld\n",count);
    }
    return 0;
}