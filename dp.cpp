#include <iostream>
using namespace std;
ios_base::sync_with_stdio(false);

// Problema das moedas.
// MSC - Maior Subsequencia Crescente
// Problema da mochila!

void troco(){ 
// qtd minima de numeros p chegar na soma
    int n;
    cin >> n;
    int nums[n];
    int objetivo;
    cin >> objetivo;
    vector<int> qt_nums(objetivo+1);

    valor[0] = 0;
    for (int sub = 1; sub <= objetivo; sub++) {
        qt_nums[sub] = inf;
        for (int num : nums) {
            if (sub-num >= 0) {
                valor[sub] = min(valor[sub], valor[sub-num]+1);
            }
        }
    }
    cout << qt_nums[objetivo];
}

int main(){

}
