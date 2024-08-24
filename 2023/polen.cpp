#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N <= 10^6, K <= 10^9

int soma_digitos(int x){
    int soma = 0;
    while(x > 0){
        soma += x%10;
        x /= 10;
    }
    return soma;
}

int coleta(int k_pos, int n_flores, vector<int>& flores){
    for(int i = 0; i < k_pos-1; i++){
        sort(flores.begin(),flores.end(),greater<int>());
        flores.front() -= soma_digitos(flores.front());
    }
    sort(flores.begin(),flores.end(),greater<int>());
    return soma_digitos(flores.front());
}

int main(){
    int n_flores, k_pos;
    cin >> n_flores >> k_pos; // quero 0 based.
    k_pos--;
    vector<int> flores_inicial(n_flores);

    for(int i = 0; i < n_flores; i++){
        int x;
        cin >> x;
        flores_inicial[i] = x;
    }

    int resposta = coleta(k_pos,n_flores, flores_inicial);
    cout << resposta;

}