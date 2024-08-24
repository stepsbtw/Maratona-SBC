#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void dijkstra(int no, int n_nos,
vector<pair<int,int>> adj
){
   vector<bool> foiProcessado;
   priority_queue<int> fila;
   for (int i = 1; i <= n; i++) {
       dists[i] = INF;
   }
   dists[no] = 0;
   fila.push({0,no});
   while (!fila.empty()) {
      int no1 = fila.top().second; fila.pop();
      if (foiProcessado[no1]) continue;
      foiProcessado[no1] = true;
      for (pair<int,int> u : adj[a]) {
         int no2 = u.first, peso = u.second;
         if (dists[no1]+peso < dists[no2]) {
            dists[no2] = dists[no1]+peso;
            fila.push({-dists[no2],no2});
         }
      }
   }
}


void bellman_ford(int no, int n_nos,
vector<tuple<int,int,int>> arestas
vector<int>& dists
){
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


int main(){
  int n; // tamanho do grafo
  cin >> n;
  vector<vector<int>> adj(n); // o grafo em si
  for(int i = 0; i<n; i++){
    int x;
    cin >> x;
    adj.pushback(x); // inicializando grafo
  }
  // dfs precisa do "visitados" fora da funcao, pq é recursivo.
  vector<bool> visitado(n);

}
