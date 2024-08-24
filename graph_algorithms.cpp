#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

//int vector<int> dijkstra(int no_inicial, int n_nos, vector<vector<pair<int, int>>> adj) {
vector<int> dijkstra(int no_inicial, int n_nos, vector<vector<pair<int, int>>> adj) {
    // encontrar os menores caminhos possiveis para todo os nós ou um especifico.
    vector<bool> foiProcessado(n_nos, false);
    vector<int> dists(n_nos, INF);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    // priority queue inversa!

    dists[no_inicial] = 0;
    fila.push({0, no_inicial});

    while (!fila.empty()) {
        int no1 = fila.top().second;
        fila.pop();

        // if (no1 == no_destino){ return dist[no1] }; // caso queira parar no no_destino
        if (foiProcessado[no1]) continue;
        foiProcessado[no1] = true;

        for (pair<int, int> u : adj[no1]) {
          int no2 = u.first;
          int peso = u.second;
          if (dist[no1] + peso < dists[no2]) {
              dists[no2] = dist[no1] + peso;
              fila.push({dists[no2], no2});
          }
        }

    }
    // return -1; // caso nao tenha caminho para o no_destino
    return dists;
}

//int bellman_ford(int no_inicial, int no_destino, int n_nos, vector<tuple<int,int,int>> arestas){
vector<int> bellman_ford(int no_inicial, int n_nos, vector<tuple<int,int,int>> arestas){
    vector<int> dists(n_nos,INF);
    dists[no_inicial] = 0;

    for(int i = 0; i< n_nos-1; i++){
        for(tuple<int,int,int> a : arestas){
            int x,y,dist;
            tie(x,y,dist) = a;
            if(dists[y] < INF) { dists[y] = min(dists[y],dists[x]+dist); }
        }
    }
    //return dists[no_destino];
    return dists;
}   

void dfs(int no, vector<vector<int>> adj, vector<bool>& visitado){
    if(visitado[no]) { return; }
  
    visitado[no] = true;
    for(int filho : adj[no]){
        dfs(filho,adj,visitado);
    }
  
}

void bfs(vector<vector<int>> adj, vector<bool>& visitado){
    queue<int> fila;
    // vector<int> distancia;
  
    visitado[0] = true; // caso comece em outro no, pode alterar.
    distancia[0] = 0; // nao precisa comecar pelo zero.
    fila.push(0);
    
    while(!fila.empty()){
        int atual = q.front(); q.pop();
        for(int filho : adj[atual]){
            if(visitado[filho]) { continue; }

            visitado[filho] = true;
            fila.push(filho);
        }
    }
  
}