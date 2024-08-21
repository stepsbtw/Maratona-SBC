#include <iostream>
#include <vector>
using namespace std;

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

  dfs(adj);
  bfs(adj);
