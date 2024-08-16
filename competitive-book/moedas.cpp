#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int inf = 1e9;

int main(){
    int n;
    cin >> n;
    set<int> moedas;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        moedas.insert(x);
    }
    int troco;
    cin >> troco;
    vector<int> valor(troco);
    vector<int> resposta(troco);

    valor[0] = 0;
    for (int subtroco = 1; subtroco <= troco; subtroco++) {
        valor[subtroco] = inf;
        for (int moeda : moedas) {
            if (subtroco-moeda >= 0) {
                valor[subtroco] = min(valor[subtroco], valor[subtroco-moeda]+1);
            }
        }
    }
    cout << valor[troco];
    
}