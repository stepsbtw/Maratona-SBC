#include <iostream>
#include <vector>
using namespace std;

// achar a maior subsequencia crescente em um array de n elementos.
// uma sequencia de elementos com tamanho maximo da esquerda pra direita.
/*
    achar uma posicao i < k, tal que array[i] < array[k] e comprimento[i] Ã© a maior possivel.
    se isso acontecer, comprimento(k) = comprimento(i)+1.

    caso nao exista posicao i tal que comprimento(k) =1, a subsequencia Ã© so array[k].

    COMO AS SUBSEQUENCIAS PODEM SER CALCULADAS DE SUBSUBSEQUENCIAS : DYNAMIC PROGRAMMING.
*/

int main(){
    int n = 10; // qt numeros
    //cin >> n;
    int array[] = {6,2,5,1,7,4,8,3};
    vector<int> tamanho;

    // forma bruteforce
    for(int i =0; i<n; i++){
        tamanho[i] = 1;
        for(int j = 0; j < i; j++){
            if(array[i] < array[j]){
                tamanho[j] = max(tamanho[j],tamanho[i]+1);
            }
        }
    }

}