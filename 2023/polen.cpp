#include <iostream>
#include <priority_queue>
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

int coleta(int k_pos, vector<int> flores){
    for(int i = 0; i < k_pos-1;i++){
        maior = flores.top();
        flores.pop()
        maior -= soma_digitos(maior);
        flores.push(maior)
    }
    return soma_digitos(flores.top());
}

int main(){
    int n_flores, k_pos;
    cin >> n_flores >> k_pos; // quero 0 based.
   
    priority_queue<int> flores;

    for(int i = 0; i < n_flores; i++){
        int x;
        cin >> x;
        flores.push(x)
    }

    cout << coleta(k_pos, flores_inicial);

}