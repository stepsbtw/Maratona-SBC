#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
DETERMINE A QUANTIDADE DE MANEIRAS POSSIVEIS DE SOMAR OS PESOS.

mais um problema de dynamic programming,
ja que eu posso calcular a partir das possiveis somas do anterior.

n pesos
max soma = sum(pesos)

possivel(soma,idx) = possivel(soma-peso[idx],idx-1)
ou possivel(soma,idx) = possivel(soma,idx-1)

-> basicamente, usar ou nao usar o peso na soma.

*/

int main(){
    int n_pesos = 4;
    int pesos[] = {1,3,3,5};

    int max_soma = 0;
    for(int i = 0; i<n_pesos; i++){
        max_soma += pesos[i];
    }

    vector<vector<bool>> possiveis_somas(
        n_pesos,
        vector<bool>(max_soma+1, false)
    );
    possiveis_somas[0][0] = true; // é possivel fazer 0 com 0.

    for(int i = 1; i < n_pesos; i++){
        for(int soma = 0; soma < max_soma; soma++){
            if(possiveis_somas[soma][i-1]){
                // caso ja funcionava, ainda funciona
                possiveis_somas[soma][i] = true;
            }
            
            if(soma - pesos[i-1] >= 0){
                if(possiveis_somas[soma-pesos[i-1]][i-1]){
                    possiveis_somas[i][soma] = true;
                }
            }
        }
    }

}