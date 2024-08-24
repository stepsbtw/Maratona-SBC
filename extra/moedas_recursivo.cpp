#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 1e9;

int solve(int troco, vector<bool>& foiCalculado, vector<int>& qtMoeda, set<int>& moedas) {
    if (troco < 0) return INF;
    if (troco == 0) return 0;
    if (foiCalculado[troco]) return qtMoeda[troco];
    
    int best = INF;
    for (int moeda : moedas) {
        best = min(best, solve(troco-moeda,foiCalculado,qtMoeda,moedas)+1);
    }
    foiCalculado[troco] = true;
    qtMoeda[troco] = best;
    return best;
}


int main(){
    int n;
    cin >> n;
    set<int> moedas;
    for(int i = 0; i<n ; i++){
        int x;
        cin >> x;
        moedas.insert(x);
    }
    int troco;
    cin >> troco;
    // por conta da recursividade, troco < 10^5
    vector<bool> foiCalculado(troco,false);
    vector<int> qtMoeda(troco,0);
    cout << solve(troco,foiCalculado,qtMoeda,moedas);
}

