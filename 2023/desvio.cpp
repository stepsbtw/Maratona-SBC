#include <iostream>
#include <vector>
using namespace std;

// 1 <= N <= 300
// M -> numero de linhas

// L -> comprimento (peso)
// U e V -> nós

// 1 <= U <= N, 1 <= L <= 10^6

// SAIDA : M linhas, -1 se nao for possivel desvio
// ou o comprimento do desvio mais curto;

const int INF = 1e9;

void belforoxo(int no, int n_nos, vector<tuple<int,int,int>> arestas_bi,vector<int>& dists){
    for(int i = 0; i<n_nos; i++){
        dists[i] = INF;
    }
    dists[no] = 0;
    for(int i = 0; i<n_nos-1;i++){
        for(auto a : arestas_bi){
            int x,y,dist;
            tie(x,y,dist) = a;
            dists[y] = min(dists[y],dists[x]+dist);
        }
    }
}   

void solution(vector<tuple<int,int,int>> arestas_bi, int n_arestas, int n_nos){
    //for(tuple<int,int,int> a : arestas_bi){
    for(int i = 0; i < n_arestas; i++){
        vector<int> dists(n_nos);
        int no1,no2,dist;
        tie(no1,no2,dist) = arestas_bi[i];

        arestas_bi[i] = {no1,no2,INF};
        arestas_bi[i+n_arestas] = {no2,no1,INF};

        belforoxo(no1,n_nos,arestas_bi,dists);
        cout << dists[no2] << endl;

        arestas_bi[i] = {no1,no2,dist};
        arestas_bi[i+n_arestas] = {no2,no1,dist};
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n_nos, n_arestas;
    cin >> n_nos;
    cin >> n_arestas;
    vector<tuple<int,int,int>> arestas_bi(n_arestas*2);
    
    for(int i=0; i<n_arestas; i++){
        int no1,no2,dist;
        cin >> no1 >> no2 >> dist;
        arestas_bi[i] = {no1-1,no2-1,dist}; // 0 based
        arestas_bi[i+n_arestas] = {no2-1,no1-1,dist}; // 1->2 e 2->1
    }

    solution(arestas_bi,n_arestas, n_nos);
    
}